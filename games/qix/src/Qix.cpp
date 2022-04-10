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

std::map<arc::Direction, arc::vector_t> arc::Qix::pos = {
    {arc::Direction::UP_LEFT, {-1, -1, 0}},
    {arc::Direction::UP_RIGHT, {1, -1, 1}},
    {arc::Direction::DOWN_LEFT, {-1, 1, 2}},
    {arc::Direction::DOWN_RIGHT, {1, 1, 3}},
};

arc::Qix::Qix(void) :
_map(std::vector<std::vector<int>>(MAP_SIZE, std::vector<int>(MAP_SIZE, 0))),
_visited(std::vector<std::vector<bool>>(MAP_SIZE, std::vector<bool>(MAP_SIZE, false))),
_qix(std::vector<pos_t>(4, {MAP_SIZE / 2, MAP_SIZE / 2})),
_qixNoise(std::vector<pos_t>(8, {0, 0})),
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
    this->_directionQix = UP_LEFT;
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
        this->updateQix();
        this->updateQix();
        this->checkWin();
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

bool arc::Qix::canQixMoveToPos(pos_t pos)
{
    if (pos.x >= MAP_SIZE || pos.y >= MAP_SIZE)
        return false;
    if (this->_map[pos.y][pos.x] == ((GameColor::G_BLUE << 16) | (Shape::SQUARE << 8)) ||
        this->_map[pos.y][pos.x] == ((GameColor::G_RED << 16) | (Shape::SQUARE << 8)) ||
        this->_map[pos.y][pos.x] == ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8)))
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

int arc::Qix::getNeighbor(pos_t actPos)
{
    if (canQixMoveToPos({actPos.x + 1, actPos.y}) && this->_visited[actPos.y][actPos.x + 1] == false) {
        return 1;
    }
    else if (canQixMoveToPos({actPos.x, actPos.y + 1}) && this->_visited[actPos.y + 1][actPos.x] == false) {
        return 2;
    }
    else if (canQixMoveToPos({actPos.x - 1, actPos.y}) && this->_visited[actPos.y][actPos.x - 1] == false) {
        return 3;
    }
    else if (canQixMoveToPos({actPos.x, actPos.y - 1}) && this->_visited[actPos.y - 1][actPos.x] == false) {
        return 4;
    }
    return 0;
}

void arc::Qix::checkEnd(pos_t actPos, pos_t goalPos)
{
    this->_visited[actPos.y][actPos.x] = true;
    if (actPos.x == goalPos.x && actPos.y == goalPos.y) {
        this->_found = true;
    }
}

void arc::Qix::recursive(pos_t actPos, pos_t goalPos)
{
    int neighbor = getNeighbor(actPos);

    this->checkEnd(actPos, goalPos);
    while (neighbor != 0 && this->_found == false) {
        switch (neighbor) {
        case 1: this->recursive({actPos.x + 1, actPos.y}, goalPos);
            break;
        case 2: this->recursive({actPos.x, actPos.y + 1}, goalPos);
            break;
        case 3: this->recursive({actPos.x - 1, actPos.y}, goalPos);
            break;
        case 4: this->recursive({actPos.x, actPos.y - 1}, goalPos);
            break;
        default:
            break;
        }
        neighbor = getNeighbor(actPos);
    }
}

bool arc::Qix::isWithQix(pos_t actPos, pos_t goalPos)
{
    this->_found = false;
    for (auto &line : this->_visited)
        std::fill(line.begin(), line.end(), false);
    this->recursive(actPos, goalPos);
    return this->_found;
}

void arc::Qix::copyVisited(void)
{
    int color = 0;

    if (this->_color == false) {
        color = ((GameColor::G_BLUE << 16) | (Shape::SQUARE << 8));
    } else {
        color = ((GameColor::G_RED << 16) | (Shape::SQUARE << 8));
    }
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (this->_visited[y][x] == true) {
                this->_map[y][x] = color;
            }
        }
    }
    this->_color = !this->_color;
}

void arc::Qix::fillBlank(void)
{
    for (std::size_t y = 0; y < this->_map.size(); y++) {
        for (std::size_t x = 0; x < this->_map[y].size(); x++) {
            if (this->_map[y][x] == 0 && this->_visited[y][x] == false && isWithQix({x, y}, this->_qix[0]) == false) {
                this->copyVisited();
                break;
            }
        }
    }
}

void arc::Qix::fillArea(void)
{
    if (this->_savedCell.value == ((GameColor::G_WHITE << 16) | (Shape::SQUARE << 8)) && this->_wasDrawing == true) {
        this->replaceGray();
        this->fillBlank();
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

void arc::Qix::eraseQix(void)
{
    for (auto &qix : this->_qix) {
        this->_map[qix.y][qix.x] = 0;
    }
}

void arc::Qix::eraseQixNoise(void)
{
    for (auto &qixNoise : this->_qixNoise) {
        if (this->canQixMoveToPos(qixNoise) == true) {
            this->_map[qixNoise.y][qixNoise.x] = 0;
        }
    }
}

void arc::Qix::drawQix(void)
{
    for (auto &qix : this->_qix) {
        this->_map[qix.y][qix.x] = ((GameColor::G_PURPLE << 16) | (Shape::SQUARE << 8));
    }
}

void arc::Qix::drawQixNoise(void)
{
    for (auto &qixNoise : this->_qixNoise) {
        if (this->canQixMoveToPos(qixNoise) == true) {
            this->_map[qixNoise.y][qixNoise.x] = ((((rand() % 7) + 5) << 16) | (((rand() % 4) + 1) << 8));
        }
    }
}

void arc::Qix::changeQixCoord(vector_t vector)
{
    for (auto &qix : this->_qix) {
        qix.x += vector.x;
        qix.y += vector.y;
    }
}

bool arc::Qix::updatePosQix(vector_t toMove)
{
    if (this->canQixMoveToPos({this->_qix[toMove.idx].x + toMove.x, this->_qix[toMove.idx].y + toMove.y}) == true) {
        this->changeQixCoord(toMove);
        return true;
    } else {
        this->_directionQix = (Direction)((this->_directionQix + 1) % SIZE_DIR);
        return false;
    }
}

void arc::Qix::moveQixNoise(void)
{
    for (auto &qixNoise : this->_qixNoise) {
        qixNoise.x = this->_qix[0].x + ((rand() % 8 - 4));
        qixNoise.y = this->_qix[0].y + ((rand() % 8 - 4));
    }
}

void arc::Qix::moveQix(void)
{
    if (this->_lastRand >= 10) {
        this->_lastRand = 0;
        this->_directionQix = (Direction)(rand() % SIZE_DIR);
    } else {
        this->_lastRand++;
    }
    for (size_t nbIt = 0; this->updatePosQix(this->pos.find(this->_directionQix)->second) == false && nbIt < SIZE_DIR; nbIt++);
}

void arc::Qix::checkQixCollisions(std::vector<pos_t> toCheck)
{
    for (size_t i = 0; i < toCheck.size(); i++) {
        if (this->canQixMoveToPos(toCheck[i]) == true && this->_map[toCheck[i].y][toCheck[i].x] != ((GameColor::G_LIME << 16) | (Shape::SQUARE << 8))) {
            if (toCheck[i].x == this->_player.x && toCheck[i].y == this->_player.y) {
                this->_gameState = State::STOP;
            }
            if (this->_map[toCheck[i].y][toCheck[i].x] == ((GameColor::G_GRAY << 16) | (Shape::SQUARE << 8))) {
                this->_gameState = State::STOP;
            }
        }
    }
}

void arc::Qix::updateQix(void)
{
    this->eraseQix();
    this->eraseQixNoise();
    this->moveQix();
    this->moveQixNoise();
    this->checkQixCollisions(this->_qix);
    this->checkQixCollisions(this->_qixNoise);
    this->drawQix();
    this->drawQixNoise();
}

void arc::Qix::setPlayerName(__attribute__ ((unused))std::string name)
{

}

void arc::Qix::checkWin(void)
{
    size_t nbBlank = 0;

    for (size_t i = 0; i < this->_map.size(); i++) {
        for (size_t j = 0; j < this->_map[i].size(); j++) {
            if (this->_map[i][j] == 0) {
                nbBlank++;
            }
        }
    }
    if (nbBlank < (0.25 * (this->_map.size() * this->_map.size()))) {
        this->_gameState = State::STOP;
    }
}
