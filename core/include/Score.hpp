/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Error
*/

#ifndef SCORE_HPP
#define SCORE_HPP

#include <iostream>

#include "Error.hpp"

namespace arc
{


    class Score {
        public:
            Score(std::string scoreFile);
            ~Score() = default;

            void getScores(void);
            void saveScores(void);

        private:
            std::string fileName;


    };
}

#endif // SCORE_HPP
