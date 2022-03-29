/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Error
*/

#ifndef SCORE_HPP
#define SCORE_HPP

#define MAX_SCORE_NUMBER 10

#include "ConfigFile.hpp"

namespace arc
{
    typedef struct {
        std::string gameName;
        std::string playerName;
        std::size_t score;
    } score_t;

    class Score : public ConfigFile {
        public:
            Score(std::string fileName = "./ressources/scores.conf");
            ~Score() = default;

            void getConf(void);
            void saveConf(void);

            std::vector<score_t> _scoreList;

        private:
            std::size_t getScoreNumer(std::string score);
    };
}

#endif // SCORE_HPP
