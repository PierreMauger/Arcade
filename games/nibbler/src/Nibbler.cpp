/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

std::map<arc::GameKey, std::function<void (arc::Nibbler *)>> arc::Nibbler::keys = {
    {arc::GameKey::G_UP_ARROW, &Nibbler::changeDirUp},
    {arc::GameKey::G_LEFT_ARROW, &Nibbler::changeDirLeft},
    {arc::GameKey::G_DOWN_ARROW, &Nibbler::changeDirDown},
    {arc::GameKey::G_RIGHT_ARROW, &Nibbler::changeDirRight},
};

arc::Nibbler::Nibbler(void) :
_map(std::vector<std::vector<int>>(50, std::vector<int>(50, 0)))
{

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
    this->_gameState = State::STOP;
}

void arc::Nibbler::destroyGame(void)
{

}

void arc::Nibbler::update(std::vector<GameKey> keys)
{
    for (auto key : keys) {
        if (this->keys.find(key) != this->keys.end())
            this->keys[key](this);
    }
    if (keys.size() != 0) {
        this->_gameState = State::START;
    } else if (this->_gameState == State::START) {
        this->move();
        if (this->checkFoodCollision()) {
            this->addSnakePart();
            this->_map[this->_food.y][this->_food.x] = 0;
            this->putFood();
            this->_score += 1000;
        }
        if (this->checkSelfCollision() || this->checkWallCollision()) {
            this->_gameState = State::STOP;
        }
    }
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

void arc::Nibbler::changeDirUp(void)
{
    this->_direction = arc::Direction::UP;
}

void arc::Nibbler::changeDirLeft(void)
{
    this->_direction = arc::Direction::LEFT;
}

void arc::Nibbler::changeDirDown(void)
{
    this->_direction = arc::Direction::DOWN;
}

void arc::Nibbler::changeDirRight(void)
{
    this->_direction = arc::Direction::RIGHT;
}

void arc::Nibbler::move(void)
{
    switch (this->_direction) {
        case arc::Direction::UP:
            this->moveUp();
            break;
        case arc::Direction::LEFT:
            this->moveLeft();
            break;
        case arc::Direction::DOWN:
            this->moveDown();
            break;
        case arc::Direction::RIGHT:
            this->moveRight();
            break;
    }
}

void arc::Nibbler::moveUp(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    this->_map[last.y][last.x] = 0;
    last.y = head.y - 1;
    last.x = head.x;
    this->_map[last.y][last.x] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
}

void arc::Nibbler::moveLeft(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    this->_map[last.y][last.x] = 0;
    last.y = head.y;
    last.x = head.x - 1;
    this->_map[last.y][last.x] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
}

void arc::Nibbler::moveDown(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    this->_map[last.y][last.x] = 0;
    last.y = head.y + 1;
    last.x = head.x;
    this->_map[last.y][last.x] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
}

void arc::Nibbler::moveRight(void)
{
    pos_t last = this->_snake.back();
    pos_t head = this->_snake.front();

    this->_map[last.y][last.x] = 0;
    last.y = head.y;
    last.x = head.x + 1;
    this->_map[last.y][last.x] = ((GameColor::G_CYAN << 16) | (Shape::SQUARE << 8));
}

bool arc::Nibbler::checkWallCollision(void)
{
    if (this->_snake[0].x == 0 || this->_snake[0].x == 50 || this->_snake[0].y == 0 || this->_snake[0].y == 50)
        return true;
    return false;
}

bool arc::Nibbler::checkSelfCollision(void)
{
    auto head = this->_snake.front();

    for (std::size_t i = 1; i < this->_snake.size(); i++) {
        if (head.x == this->_snake[i].x && head.y == this->_snake[i].y)
            return true;
    }
    return false;
}

bool arc::Nibbler::checkFoodCollision(void)
{
    if (this->_snake[0].x == this->_food.x && this->_snake[0].y == this->_food.y)
        return true;
    return false;
}

void arc::Nibbler::addSnakePart(void)
{
    pos_t newPart = {0, 0};

    newPart.x = this->_snake.back().x;
    newPart.y = this->_snake.back().y;
    this->_snake.push_back(newPart);
}

void arc::Nibbler::putFood(void)
{
    int x = rand() % 50;
    int y = rand() % 50;

    while (this->_map[y][x] != 0) {
        x = rand() % 50;
        y = rand() % 50;
    }
    this->_food.x = x;
    this->_food.y = y;
    this->_map[y][x] = ((GameColor::G_RED << 16) | (Shape::SQUARE << 8));
}
