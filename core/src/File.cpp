/*
** EPITECH PROJECT, 2022
** File
** File description:
** File
*/

#include "File.hpp"

std::string &arc::File::getFileBuff(void)
{
    return this->_file;
}

void arc::File::readFile(std::string fileName)
{
    std::ifstream fileBuff;

    fileBuff.open(fileName);
    if (!fileBuff.is_open()) {
        throw arc::FileError("FileError: Cannot open file.");
    } else {
        std::getline(fileBuff, this->_file, '\0');
        fileBuff.close();
    }
}
