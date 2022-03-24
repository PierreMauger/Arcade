/*
** EPITECH PROJECT, 2022
** code
** File description:
** score
*/

#include "LibList.hpp"

arc::LibList::LibList(std::string fileName) : ConfigFile(fileName)
{

}

void arc::LibList::getConf(void)
{
    std::string file(this->_file.file);

    // regex : (graphics:\n)([\\s\\S]*?)((\n.+:\n)|$)
    // regex : (games:\n)([\\s\\S]*?)((\n.+:\n)|$)

    // TODO
}

void arc::LibList::saveConf(void)
{

}
