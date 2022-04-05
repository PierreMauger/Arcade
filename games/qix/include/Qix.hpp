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
    typedef struct {
        std::size_t x;
        std::size_t y;
    } pos_t;

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
            static std::map<arc::GameKey, std::function<void (arc::Qix *)>> keys;

            std::vector<std::vector<int>> _map;
            std::size_t _score;
            State _gameState;

            std::vector<pos_t> _qix;
            std::vector<pos_t> _enemies;
            pos_t _player;

            void createQix(void);

            void moveUp(void);
            void moveLeft(void);
            void moveDown(void);
            void moveRight(void);
    };

    extern "C" std::unique_ptr<Qix> entryPoint(void)
    {
        return std::make_unique<Qix>();
    }
}

#endif // QIX_HPP
