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
_map(std::vector<std::vector<int>>(MAP_SIZE, std::vector<int>(MAP_SIZE, 0))),
_qix(std::vector<pos_t>(MAP_SIZE, {0, 0})),
_enemies(std::vector<pos_t>(MAP_SIZE, {MAP_SIZE / 2, 0}))
{

}

void arc::Qix::createQix(void)
{
    for (std::size_t y = 0; y < this->_qix.size() / 2; y++) {
        for (std::size_t x = 0; x < this->_qix.size() / 2; x++) {
            this->_qix[x + y * (this->_qix.size() / 2)] = {(MAP_SIZE / 2) + x, (MAP_SIZE / 2) + y};
        }
    }
}

void arc::Qix::createLines(void)
{
    for (std::size_t i = 0; i < MAP_SIZE; i++) {
        this->_map[0][i] = ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8));
        this->_map[MAP_SIZE - 1][i] = ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8));
        this->_map[i][0] = ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8));
        this->_map[i][MAP_SIZE - 1] = ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8));
    }
}

void arc::Qix::initGame(void)
{
    this->createQix();
    this->createLines();
    this->_player = {(MAP_SIZE / 2) - 1, MAP_SIZE - 1};
    this->_gameState = State::STOP;
}

void arc::Qix::destroyGame(void)
{

}

void arc::Qix::update(std::vector<GameKey> keys)
{
    if (keys.size() != 0) {
        this->_gameState = State::START;
    } else if (this->_gameState == State::START) {
        for (auto key : keys) {
            if (this->keys.find(key) != this->keys.end())
                this->keys[key](this);
        }

        // if (this->checkFoodCollision()) {
        //     this->addSnakePart();
        //     this->_map[this->_food.y][this->_food.x] = 0;
        //     this->putFood();
        //     this->_score += 1000;
        // }
        // if (this->checkSelfCollision() || this->checkWallCollision()) {
        //     this->_gameState = State::STOP;
        // }
    }
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

std::string arc::Qix::getPlayerName(void)
{
    return "";
}

std::string arc::Qix::getGameName(void)
{
    return "Qix";
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
