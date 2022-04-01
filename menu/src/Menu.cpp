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

        this->_map[0][0] = Shape::CIRCLE;
        std::cerr << (int)this->_map[3][0] << std::endl;
    // for (int i = 0; i < tempX / 2; i++) {
        // this->_map[0][i] = (unsigned char)(Shape::SQUARE | GameColor::G_CYAN);
        // this->_map[tempY / 2][i] = (unsigned char)(Shape::SQUARE | GameColor::G_CYAN);
    // }
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
