/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

std::map<arc::GameKey, std::function<void (arc::Nibbler *)>> arc::Nibbler::keys = {
    {arc::GameKey::G_UP_ARROW, &Nibbler::goUp},
    {arc::GameKey::G_LEFT_ARROW, &Nibbler::goLeft},
    {arc::GameKey::G_DOWN_ARROW, &Nibbler::goDown},
    {arc::GameKey::G_RIGHT_ARROW, &Nibbler::goRight},
};

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
        this->_map[0][i] = (unsigned char)(Shape::SQUARE | GameColor::G_CYAN);
        this->_map[50][i] = (unsigned char)(Shape::SQUARE | GameColor::G_CYAN);
        this->_map[i][0] = (unsigned char)(Shape::SQUARE | GameColor::G_CYAN);
        this->_map[i][50] = (unsigned char)(Shape::SQUARE | GameColor::G_CYAN);
    }
    this->_snake.push_back({24, 24});
    this->_direction = RIGHT;
}

void arc::Nibbler::destroyGame(void)
{

}

bool arc::Nibbler::checkWallCollision(void)
{
    if (this->_snake[0].x == 0 || this->_snake[0].x == 50 || this->_snake[0].y == 0 || this->_snake[0].y == 50)
        return true;
    return false;
}

void arc::Nibbler::update(std::vector<GameKey> keys)
{

}

void arc::Nibbler::setGameState(State state)
{
    this->_gameState = state;
}

arc::State arc::Nibbler::getGameState(void)
{
    return this->_gameState;
}

std::vector<std::vector<int>> arc::Nibbler::getMap(void)
{
    return this->_map;
}

std::size_t arc::Nibbler::getScore(void)
{
    return this->_score;
}

void arc::Nibbler::goUp(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    this->_map[last.y][last.x] = (unsigned char)();
    last.y = head.y - 1;
    last.x = head.x;
    this->_map[last.y][last.x] = (unsigned char)(Shape::SQUARE | GameColor::G_CYAN);
}

void arc::Nibbler::goLeft(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    last.y = head.y;
    last.x = head.x - 1;
}

void arc::Nibbler::goDown(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    last.y = head.y + 1;
    last.x = head.x;
}

void arc::Nibbler::goRight(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    last.y = head.y;
    last.x = head.x + 1;
}

void arc::Nibbler::drawFood(void)
{

}

void arc::Nibbler::drawSnake(void)
{

}
