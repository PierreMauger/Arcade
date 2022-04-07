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
_qix(std::vector<pos_t>(4, {MAP_SIZE / 2, MAP_SIZE / 2})),
_enemies(std::vector<pos_t>(2, {MAP_SIZE / 2, 0}))
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
    this->_map[this->_player.y][this->_player.x] = ((GameColor::G_LIME << 16) | (Shape::SQUARE << 8));
    this->setCellValue(this->_savedCell, this->_player, (GameColor::G_WHITE << 16) | (Shape::SQUARE << 8));
    this->_gameState = State::STOP;
}

void arc::Qix::destroyGame(void)
{

}

void arc::Qix::update(std::vector<GameKey> keys)
{
    if (this->_gameState == State::START) {
        for (auto key : keys) {
            if (this->keys.find(key) != this->keys.end() && std::find(keysPressed.begin(), keysPressed.end(), key) == keysPressed.end()) {
                this->keys[key](this);
                keysPressed.push_back(key);
            }
        }
        keysPressed.clear();
    }
    if (keys.size() != 0 && this->_gameState != State::STOP) {
        this->_gameState = State::START;
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

bool arc::Qix::canPlayerMoveToPos(pos_t pos)
{
    if (pos.x >= MAP_SIZE || pos.y >= MAP_SIZE)
        return false;
    if (this->_map[pos.y][pos.x] == ((GameColor::G_BLUE << 16) | (Shape::SQUARE << 8)) ||
        this->_map[pos.y][pos.x] == ((GameColor::G_RED << 16) | (Shape::SQUARE << 8)) ||
        this->_map[pos.y][pos.x] == ((GameColor::G_GRAY << 16) | (Shape::SQUARE << 8)))
        return false;
    return true;
}

void arc::Qix::setCellValue(cell_t &cell, pos_t pos, int value)
{
    cell.pos = pos;
    cell.value = value;
}

void arc::Qix::restoreCellValue(void)
{
    if (this->_savedCell.value == 0) {
        this->_map[this->_player.y][this->_player.x] = ((GameColor::G_GRAY << 16) | (Shape::SQUARE << 8));
        this->_wasDrawing = true;
    } else {
        this->_map[this->_player.y][this->_player.x] = this->_savedCell.value;
    }
}

void arc::Qix::replaceGray(void)
{
    for (auto &yLine : this->_map) {
        for (int &cell : yLine) {
            if (cell == ((GameColor::G_GRAY << 16) | (Shape::SQUARE << 8))) {
                cell = ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8));
            }
        }
    }
    this->_wasDrawing = false;
}

void arc::Qix::fillArea(void)
{
    if (this->_savedCell.value == ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8)) && this->_wasDrawing == true) {
        this->replaceGray();
    }
}

void arc::Qix::moveUp(void)
{
    if (this->canPlayerMoveToPos({this->_player.x, this->_player.y - 1}) == false) {
        return;
    }
    this->restoreCellValue();
    this->_player.y--;
    this->setCellValue(this->_savedCell, this->_player, this->_map[this->_player.y][this->_player.x]);
    this->fillArea();
    this->_map[this->_player.y][this->_player.x] = ((GameColor::G_LIME << 16) | (Shape::SQUARE << 8));
}

void arc::Qix::moveLeft(void)
{
    if (this->canPlayerMoveToPos({this->_player.x - 1, this->_player.y}) == false) {
        return;
    }
    this->restoreCellValue();
    this->_player.x--;
    this->setCellValue(this->_savedCell, this->_player, this->_map[this->_player.y][this->_player.x]);
    this->fillArea();
    this->_map[this->_player.y][this->_player.x] = ((GameColor::G_LIME << 16) | (Shape::SQUARE << 8));
}

void arc::Qix::moveDown(void)
{
    if (this->canPlayerMoveToPos({this->_player.x, this->_player.y + 1}) == false) {
        return;
    }
    this->restoreCellValue();
    this->_player.y++;
    this->setCellValue(this->_savedCell, this->_player, this->_map[this->_player.y][this->_player.x]);
    this->fillArea();
    this->_map[this->_player.y][this->_player.x] = ((GameColor::G_LIME << 16) | (Shape::SQUARE << 8));
}

void arc::Qix::moveRight(void)
{
    if (this->canPlayerMoveToPos({this->_player.x + 1, this->_player.y}) == false) {
        return;
    }
    this->restoreCellValue();
    this->_player.x++;
    this->setCellValue(this->_savedCell, this->_player, this->_map[this->_player.y][this->_player.x]);
    this->fillArea();
    this->_map[this->_player.y][this->_player.x] = ((GameColor::G_LIME << 16) | (Shape::SQUARE << 8));
}
