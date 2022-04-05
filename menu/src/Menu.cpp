/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "Menu.hpp"

arc::Menu::Menu(void) :
_scoreList("./ressources/scores.conf"),
_graphList("./ressources/graphics.conf"),
_gameList("./ressources/games.conf"),
_map(std::vector<std::vector<int>>(50, std::vector<int>(50, 0)))
{
}

void arc::Menu::initGame(void)
{
    int tempX = 50;
    int tempY = 50;

    // this->_map[3][3] = Shape::SQUARE << 8 | GameColor::G_RED << 16;
    // this->_map[0][1] = Shape::CIRCLE << 8 | GameColor::G_CYAN << 16;
    // this->_map[0][2] = Shape::CROSS << 8 | GameColor::G_CYAN << 16;
    // this->_map[2][3] = 'a' | GameColor::G_GREEN << 16;
    for (int i = 0; i < tempX / 2; i++) {
        this->_map[2][i] = Shape::SQUARE << 8 | GameColor::G_RED << 16;
        this->_map[3][i] = Shape::CIRCLE << 8 | GameColor::G_LIME << 16;
        this->_map[4][i] = 'm' | GameColor::G_LIME << 16;
    }
}

void arc::Menu::destroyGame(void)
{
}

void arc::Menu::update(std::vector<GameKey> keys)
{
    // does nothing
}

void arc::Menu::setGameState(State state)
{
    // no game state
}

arc::State arc::Menu::getGameState(void)
{
    // no game state
    return arc::State::START;
}

std::vector<std::vector<int>> arc::Menu::getMap(void)
{
    return this->_map;
}

std::size_t arc::Menu::getScore(void)
{
    // no score
    return 0;
}
