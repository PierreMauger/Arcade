/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Qix
*/

#include "Qix.hpp"

std::map<arc::GameKey, std::function<void (arc::Qix *)>> arc::Qix::keys = {
    {arc::GameKey::G_UP_ARROW, &Qix::moveUp},
    {arc::GameKey::G_LEFT_ARROW, &Qix::moveLeft},
    {arc::GameKey::G_DOWN_ARROW, &Qix::moveDown},
    {arc::GameKey::G_RIGHT_ARROW, &Qix::moveRight},
};

arc::Qix::Qix(void) :
_map(std::vector<std::vector<int>>(50, std::vector<int>(50, 0))),
_qix(std::vector<pos_t>(50, {0, 0})),
_enemies(std::vector<pos_t>(50, {24, 0}))
{

}

void arc::Qix::createQix(void)
{
    for (std::size_t y = 0; y < this->_qix.size() / 2; y++) {
        for (std::size_t x = 0; x < this->_qix.size() / 2; x++) {
            this->_qix[x + y * (this->_qix.size() / 2)] = {25 + x, 25 + y};
        }
    }
}

void arc::Qix::initGame(void)
{

    for (int i = 0; i < 50; i++) {
        this->_map[0][i] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
        this->_map[50][i] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
        this->_map[i][0] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
        this->_map[i][50] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
    }
    this->createQix();
    this->_player = {24, 49};
    this->_gameState = State::STOP;
}

void arc::Qix::destroyGame(void)
{

}

void arc::Qix::update(std::vector<GameKey> keys)
{

}

void arc::Qix::setGameState(State state)
{
    this->_gameState = state;
}

arc::State arc::Qix::getGameState(void)
{
    return this->_gameState;
}

std::vector<std::vector<int>> arc::Qix::getMap(void)
{
    return this->_map;
}

std::size_t arc::Qix::getScore(void)
{
    return this->_score;
}

void arc::Qix::moveUp(void)
{

}

void arc::Qix::moveLeft(void)
{

}

void arc::Qix::moveDown(void)
{

}

void arc::Qix::moveRight(void)
{

}
