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
_gameList("./ressources/games.conf")
{
    this->_map = new unsigned char *[50];
    for (int i = 0; i < 50; i++)
        this->_map[i] = new unsigned char[50];
}

arc::Menu::~Menu()
{
    for (int i = 0; i < 50; i++)
        delete[] this->_map[i];
    delete[] this->_map;
}

void arc::Menu::initGame(void)
{
    int tempX = 50;
    int tempY = 50;

    for (int i = 0; i < tempX / 2; i++) {
        this->_map[0][i] = -(Shape::SQUARE | GameColor::G_CYAN);
        this->_map[tempY / 2][i] = -(Shape::SQUARE | GameColor::G_CYAN);
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

unsigned char **arc::Menu::getMap(void)
{
    return this->_map;
}

std::size_t arc::Menu::getScore(void)
{
    // no score
    return 0;
}
