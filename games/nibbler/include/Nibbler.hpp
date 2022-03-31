/*
** EPITECH PROJECT, 2022
** Include
** File description:
** nib
*/

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include "IGame.hpp"

namespace arc
{
    class Nibbler : public IGame {
        public:
            Nibbler(void);
            ~Nibbler() = default;

            void initGame(void);
            void destroyGame(void);

            void update(std::vector<GameKey> keys);

            void setGameState(State state);
            State getGameState(void);

            unsigned char **getMap(void);

            std::size_t getScore(void);

        private:
            unsigned char **_map;

            std::size_t _score;

    };
}

#endif // NIBBLER_HPP
