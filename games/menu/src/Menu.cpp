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
    this->_scoreList.getConf();
    this->_graphList.getConf();
    this->_gameList.getConf();
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

    std::string title1 = "Game librairies";
    std::string title2 = "Graphic librairies";
    std::string title3 = "Scores";
    std::string title4 = "Enter name:";

    for (std::size_t i = 0; i < title1.size(); i++)
        this->_map[1][i + 1] = title1[i] | GameColor::G_BLUE << 16;
    for (std::size_t i = 0; i < title2.size(); i++)
        this->_map[26][i + 1] = title2[i] | GameColor::G_ORANGE << 16;
    for (std::size_t i = 0; i < title3.size(); i++)
        this->_map[1][i + 26] = title3[i] | GameColor::G_BROWN << 16;
    for (std::size_t i = 0; i < title4.size(); i++)
        this->_map[26][i + 26] = title4[i] | GameColor::G_GREEN << 16;

    for (std::size_t i = 0; i < this->_gameList._libs.size() && i < 20; i++)
        for (std::size_t j = 0; j < this->_gameList._libs[i].size(); j++)
            this->_map[i * 2 + 3][j + 1] = this->_gameList._libs[i][j] | GameColor::G_WHITE << 16;
    for (std::size_t i = 0; i < this->_graphList._libs.size() && i < 20; i++)
        for (std::size_t j = 0; j < this->_graphList._libs[i].size(); j++)
            this->_map[i * 2 + 28][j + 1] = this->_graphList._libs[i][j] | GameColor::G_WHITE << 16;

    std::size_t delay = 0;
    for (std::size_t i = 0; i < this->_scoreList._scoreList.size() && i < 20; i++) {
        for (std::size_t j = 0; j < this->_scoreList._scoreList[i].gameName.size() && j + 26 < 49; j++)
            this->_map[i + 3][j + 26] = this->_scoreList._scoreList[i].gameName[j] | GameColor::G_WHITE << 16;
        delay = this->_scoreList._scoreList[i].gameName.size() + 1;
        for (std::size_t j = 0; j < this->_scoreList._scoreList[i].playerName.size() && j + 26 + delay < 49; j++)
            this->_map[i + 3][j + 26 + delay] = this->_scoreList._scoreList[i].playerName[j] | GameColor::G_WHITE << 16;
        delay = std::to_string(this->_scoreList._scoreList[i].score).size();
        for (std::size_t j = 0; j < std::to_string(this->_scoreList._scoreList[i].score).size() && j + 49 - delay < 49; j++)
            this->_map[i + 3][j + 49 - delay] = std::to_string(this->_scoreList._scoreList[i].score)[j] | GameColor::G_WHITE << 16;
    }
    for (std::size_t j = 0; j < this->_playerName.size(); j++)
        this->_map[28][j + 26] = this->_playerName[j] | GameColor::G_WHITE << 16;
}

void arc::Menu::destroyGame(void)
{
}

// unused params
void arc::Menu::update(std::vector<GameKey> __attribute__ ((unused))keys)
{
    for (GameKey &key : keys) {
        if (key >= GameKey::G_KEY_A && key <= GameKey::G_KEY_Z && this->_playerName.size() < 10)
            this->_playerName += key + 89;
        if (key >= GameKey::G_KEY_1 && key <= GameKey::G_KEY_9 && this->_playerName.size() < 10)
            this->_playerName += key + 15;
        if (key == GameKey::G_KEY_0 && this->_playerName.size() < 10)
            this->_playerName += key + 5;
        if (key == GameKey::G_BACKSPACE && this->_playerName.size() > 0)
            this->_playerName.pop_back();
    }
    if (keys.size()) {
        for (std::size_t j = 0; j < 10; j++) {
            if (j < this->_playerName.size())
                this->_map[28][j + 26] = this->_playerName[j] | GameColor::G_WHITE << 16;
            else
                this->_map[28][j + 26] = 0;
        }
    }
}

void arc::Menu::setGameState(State __attribute__ ((unused))state)
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

std::string arc::Menu::getPlayerName(void)
{
    return this->_playerName;
}

std::string arc::Menu::getGameName(void)
{
    return "Menu";
}

void arc::Menu::setPlayerName(__attribute__ ((unused))std::string name)
{

}
