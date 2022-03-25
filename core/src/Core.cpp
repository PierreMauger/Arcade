/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

// TODO
std::map<arc::Shape, std::function<void (unsigned char, std::size_t, std::size_t)>> shapes;

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


    // TODO
    shapes.emplace(Shape::SQUARE, std::bind(&IDisplay::drawSquare, &this->_graph));
    // shapes.emplace(Shape::CIRCLE, &IDisplay::drawCircle);
    // shapes.emplace(Shape::CROSS, &IDisplay::drawCross);
}

void arc::Core::drawIdx(unsigned char idx, std::size_t x, std::size_t y)
{
    // TODO
    // for(auto it = shapes.cbegin(); it != shapes.cend(); ++it) {
    //     if ((it->first & idx) == it->first) {

    //     }
    // }

    if ((Shape::SQUARE & idx) == Shape::SQUARE) {
        this->_graph->drawSquare(idx ^ Shape::SQUARE, x, y);
    }
    if ((Shape::CIRCLE & idx) == Shape::CIRCLE) {
        this->_graph->drawCircle(idx ^ Shape::CIRCLE, x, y);
    }
    if ((Shape::CROSS & idx) == Shape::CROSS) {
        this->_graph->drawCross(idx ^ Shape::CROSS, x, y);
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
    // this->_graph->getKeys()
}

void arc::Core::coreLoop(void)
{
    this->_score = this->_game->getScore();

    while (this->_exit == false) {
        this->browseMap();

    }
}
