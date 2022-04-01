/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

arc::Nibbler::Nibbler(void)
{
    this->_map = new unsigned char *[51];
    for (int i = 0; i < 50; i++) {
        this->_map[i] = new unsigned char[51];
        for (int j = 0; j < 51; j++) {
            this->_map[i][j] = '\0';
        }
    }
    this->_map[50] = nullptr;
}

void arc::Nibbler::initGame(void)
{
    for (int i = 0; i < 50; i++) {
        this->_map[0][i] = -(Shape::SQUARE | GameColor::G_CYAN);
        this->_map[50][i] = -(Shape::SQUARE | GameColor::G_CYAN);
        this->_map[i][0] = -(Shape::SQUARE | GameColor::G_CYAN);
        this->_map[i][50] = -(Shape::SQUARE | GameColor::G_CYAN);
    }
}

void arc::Nibbler::destroyGame(void)
{

}

void arc::Nibbler::update(std::vector<GameKey> keys)
{

}

void arc::Nibbler::setGameState(State state)
{

}

arc::State arc::Nibbler::getGameState(void)
{

}

std::vector<std::vector<int>> arc::Nibbler::getMap(void)
{

}


std::size_t arc::Nibbler::getScore(void)
{

}
