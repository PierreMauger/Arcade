/*
** EPITECH PROJECT, 2022
** Include
** File description:
** qix
*/

#ifndef QIX_HPP
#define QIX_HPP

#include "IGame.hpp"

#include <map>
#include <functional>
#include <memory>

namespace arc
{
    class Qix : public IGame {
        public:
            Qix(void);
            ~Qix() = default;

            void initGame(void);
            void destroyGame(void);

            void update(std::vector<GameKey> keys);

            void setGameState(State state);
            State getGameState(void);

            std::vector<std::vector<int>> getMap(void);

            std::size_t getScore(void);
        private:

    };

    extern "C" std::unique_ptr<Qix> entryPoint(void)
    {
        return std::make_unique<Qix>();
    }
}

#endif // QIX_HPP
