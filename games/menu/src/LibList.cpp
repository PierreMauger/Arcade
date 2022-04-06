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

void arc::LibList::verifLibName(std::string libName)
{
    std::smatch match;
    std::regex reg("(\\S+)(\\.so)");
    std::regex_search(libName, match, reg);

    if (match.size() != 3) {
        throw FileError("FileError: Bad file format.");
    }
}

void arc::LibList::getConf(void)
{
    std::string file(this->_file.file);
    std::smatch match;
    std::regex reg("(\\S+)([^-]+)?");

    while (std::regex_search(file, match, reg))
    {
        try {
            verifLibName(match[1].str());
            this->_libs.push_back(match[1].str());
        } catch (FileError const &error) {
            std::cerr << error.what() << std::endl;
        }
        file = match[2].str();
    }
}

void arc::LibList::saveConf(void)
{

}
