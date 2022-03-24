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

std::size_t arc::Score::getScoreNumer(std::string score)
{
    std::stringstream sstream(score);
    size_t res = 0;

    sstream >> res;
    return res;
}

void arc::Score::getConf(void)
{
    std::string file(this->_file.file);
    std::smatch match;
    std::regex reg("((\\S+)(:)(\\S+)(:)(\\d+))([^-]+)?");

    while (std::regex_search(file, match, reg))
    {
        try {
            if (match.size() != 8) {
                throw FileError("FileError: Bad scores file format.");
            }
            this->_score.push_back((score_t) {
                match[2].str(),
                match[4].str(),
                getScoreNumer(match[6].str()),
            });
            file = match[7].str();
        } catch (FileError const &error) {
            std::cerr << error.what() << std::endl;
            break;
        }
    }
}

void arc::Score::saveConf(void)
{
    std::ofstream file;

    file.open(this->_fileName);
    if (file.is_open() == false) {
        throw FileError("FileError: Failed to saves scores.");
    }
    for(const auto &value: this->_score) {
        file << value.gameName << ":" << value.playerName << ":" << value.score << std::endl;
    }
    file.close();
}
