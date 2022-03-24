/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

arc::Core::Core(std::shared_ptr<IDisplay> graph, std::shared_ptr<IGame> game) : _score("./ressources/scores.conf"), _graphList("./ressources/graphics.conf"), _gameList("./ressources/games.conf")
{
    this->_graph = graph;
    this->_game = game;
    this->_graphList.getConf();
    this->_gameList.getConf();
    this->_score.getConf();
}

void arc::Core::coreLoop(void)
{

}
