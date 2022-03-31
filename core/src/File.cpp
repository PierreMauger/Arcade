/*
** EPITECH PROJECT, 2022
** File
** File description:
** File
*/

#include "File.hpp"

void arc::File::readFile(std::string fileName)
{
    std::ifstream fileBuff;

    fileBuff.open(fileName);
    if (!fileBuff.is_open()) {
        throw arc::FileError("FileError: Cannot open \"" + fileName + "\" file.");
    } else {
        std::getline(fileBuff, this->file, '\0');
        fileBuff.close();
    }
}
