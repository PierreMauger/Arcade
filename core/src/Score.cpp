/*
** EPITECH PROJECT, 2022
** code
** File description:
** score
*/

#include "Score.hpp"

arc::Score::Score(std::string fileName) : ConfigFile(fileName)
{

}

void arc::Score::getConf(void)
{
    std::string file(this->_file.file);

    // regex : (graphics:\n)([\\s\\S]*?)((\n.+:\n)|$)
    // regex : (games:\n)([\\s\\S]*?)((\n.+:\n)|$)

    // TODO
}

void arc::Score::saveConf(void)
{

}
