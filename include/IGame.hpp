/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>

#include "Generic.hpp"

namespace arc
{
    enum class State {
        STOP = 0,
        START = 1,
        PAUSE = 2
    };

    class IGame
    {
        public:
            virtual ~IGame() = default;
            virtual void init_game(void);
            virtual void destroy_game(void);
            virtual void update(std::vector<EventType>) = 0;
            virtual void setGameState(State state) = 0;
            virtual State getGameState(void) = 0;
            virtual Style **getMap(void) = 0;
            virtual std::size_t getScore(void) = 0;
    };
} // namespace arc

#endif // GAME_HPP
