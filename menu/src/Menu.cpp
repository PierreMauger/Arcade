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

void arc::Menu::drawRectangle(int x, int y, int width, int height, int color)
{
    for (int i = 0; i < width; i++) {
        this->_map[y + 0][x + i] = Shape::SQUARE << 8 | color << 16;
        this->_map[y + height - 1][x + i] = Shape::SQUARE << 8 | color << 16;
    }
    for (int i = 1; i < height - 1; i++) {
        this->_map[y + i][x + 0] = Shape::SQUARE << 8 | color << 16;
        this->_map[y + i][x + width - 1] = Shape::SQUARE << 8 | color << 16;
    }
}

void arc::Menu::initGame(void)
{
    drawRectangle(0, 0, 25, 25, GameColor::G_CYAN);
    drawRectangle(0, 25, 25, 25, GameColor::G_YELLOW);
    drawRectangle(25, 0, 25, 25, GameColor::G_RED);
    drawRectangle(25, 25, 25, 25, GameColor::G_LIME);
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
