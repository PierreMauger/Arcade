/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Error
*/

#ifndef SCORE_HPP
#define SCORE_HPP

#define MAX_SCORE_NUMBER 10

#include <iostream>
#include <vector>

#include "Error.hpp"
#include "File.hpp"

namespace arc
{
    typedef struct {
        std::string playerName;
        std::string gameName;
        std::size_t score;
    } score_t;

    class Score {
        public:
            Score(std::string scoreFile);
            ~Score() = default;

            std::vector<score_t> getScores(void);
            void saveScores(void);

        private:
            std::string _fileName;
            File _file;
            std::vector<score_t> _score;

            void getScoreFile(void);

    };
}

#endif // SCORE_HPP
