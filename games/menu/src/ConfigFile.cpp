/*
** EPITECH PROJECT, 2022
** ConfFile
** File description:
** ConfFile
*/

#include "ConfigFile.hpp"

arc::ConfigFile::ConfigFile(std::string fileName)
{
    this->_fileName = fileName;
    this->_file.readFile(this->_fileName);
}
