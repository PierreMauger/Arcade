/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

arc::Core::Core(std::shared_ptr<IDisplay> graph, std::shared_ptr<IGame> game) : _scoreList("./ressources/scores.conf"), _graphList("./ressources/graphics.conf"), _gameList("./ressources/games.conf")
{
    this->_graph = graph;
    this->_game = game;
    this->_graphList.getConf();
    this->_gameList.getConf();
    this->_scoreList.getConf();
    this->_graph->initDisplay();
    this->_game->initGame();


    // TODO
    // Fill the map

}

void drawIdx(unsigned char idx, std::size_t x, std::size_t y)
{

}

void arc::Core::browseMap(void)
{
    unsigned char **map = this->_game->getMap();

    for (size_t i = 0; map[i] != NULL; i++) {
        for (size_t j = 0; map[i][j] != NULL; j++) {
            if (map[i][j] & 0b10000000 == 0b10000000) {
                //
            }
        }
    }
}

void arc::Core::coreLoop(void)
{
    this->_score = this->_game->getScore();
    // this->
}
