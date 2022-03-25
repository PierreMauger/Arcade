/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

arc::Core::Core(std::shared_ptr<IDisplay> graph, std::shared_ptr<IGame> game) :
_scoreList("./ressources/scores.conf"),
_graphList("./ressources/graphics.conf"),
_gameList("./ressources/games.conf")
{
    this->_graph = graph;
    this->_game = game;
    this->_graphList.getConf();
    this->_gameList.getConf();
    this->_scoreList.getConf();
    this->_graph->initDisplay();
    this->_game->initGame();

    // init shapes map
    shapes.emplace(Shape::SQUARE, &IDisplay::drawSquare);
    shapes.emplace(Shape::CIRCLE, &IDisplay::drawCircle);
    shapes.emplace(Shape::CROSS, &IDisplay::drawCross);

    // init coreEvent map
    coreEvent.emplace(DisplayKey::D_F1, &Core::previousGraph);
    // coreEvent.emplace(DisplayKey::D_F2, &Core::nextGraph);
    // coreEvent.emplace(DisplayKey::D_F3, &Core::previousGame);
    // coreEvent.emplace(DisplayKey::D_F4, &Core::nextGame);
    // coreEvent.emplace(DisplayKey::D_F5, &Core::restartGame);
    // coreEvent.emplace(DisplayKey::D_F6, &Core::menuGame);
    // coreEvent.emplace(DisplayKey::D_F7, &Core::exitGame);
    // coreEvent.emplace(DisplayKey::D_F8, &Core:: /* assign */ );
    // coreEvent.emplace(DisplayKey::D_F9, &Core:: /* assign */ );
    // coreEvent.emplace(DisplayKey::D_F10, &Core:: /* assign */ );
    // coreEvent.emplace(DisplayKey::D_F11, &Core:: /* assign */ );
    // coreEvent.emplace(DisplayKey::D_F12, &Core:: /* assign */ );
}

void arc::Core::drawIdx(unsigned char idx, std::size_t x, std::size_t y)
{
    for(auto it = shapes.cbegin(); it != shapes.cend(); ++it) {
        if ((it->first & idx) == it->first) {
            std::bind(it->second, this->_graph, idx ^ it->first, x, y);
        }
    }
}

void arc::Core::browseMap(void)
{
    unsigned char **map = this->_game->getMap();

    for (size_t i = 0; map[i] != nullptr; i++) {
        for (size_t j = 0; map[i][j] != '\0'; j++) {
            if ((map[i][j] & 0b10000000) == 0b10000000) {
                drawIdx(map[i][j], i, j);
            } else {
                this->_graph->drawLetter(map[i][j], i, j);
            }
        }
    }
}

void arc::Core::coreKey(void)
{
    std::vector<DisplayKey> keys = this->_graph->getKeys();

    for (auto key: keys) {
        if (key >= DisplayKey::D_F1 && key <= DisplayKey::D_F12) {
            auto keyPos = coreEvent.find(key);
            std::bind(keyPos->second, this->_graph);

            // filter elems TODO
            // keys.erase(key);
        }
    }
}

void arc::Core::coreLoop(void)
{
    this->_score = this->_game->getScore();

    while (this->_exit == false) {
        this->browseMap();
        this->coreKey();
    }
}
