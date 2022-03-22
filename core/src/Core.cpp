/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

arc::Core::Core(std::shared_ptr<IDisplay> graph, std::shared_ptr<IGame> game)
{
    this->_graph = graph;
    this->_game = game;
}

void arc::Core::getScores(void)
{
    std::ofstream confFile;

    confFile.open("");
}
