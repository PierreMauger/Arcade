/*
** EPITECH PROJECT, 2022
** code
** File description:
** score
*/

#include "Score.hpp"

arc::Score::Score(std::string scoreFile)
{
    this->_fileName = scoreFile;
    this->_file.readFile(this->_fileName);

}

void arc::Score::getScoreFile(void)
{
    std::string file(this->_file.getFileBuff());

    // regex : (graphics:\n)([\\s\\S]*?)((\n.+:\n)|$)
    // regex : (games:\n)([\\s\\S]*?)((\n.+:\n)|$)
}

std::vector<arc::score_t> arc::Score::getScores(void)
{
    return this->_score;
}
