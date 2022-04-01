/*
** EPITECH PROJECT, 2022
** Include
** File description:
** nib
*/

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include "IGame.hpp"

#include <map>
#include <functional>

namespace arc
{
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

    typedef struct {
        std::size_t x;
        std::size_t y;
    } pos_t;

    class Nibbler : public IGame {
        public:
            Nibbler(void);
            ~Nibbler() = default;

            void initGame(void);
            void destroyGame(void);

            void update(std::vector<GameKey> keys);

            void setGameState(State state);
            State getGameState(void);

            std::vector<std::vector<int>> getMap(void);

            std::size_t getScore(void);

        private:
            static std::map<arc::GameKey, std::function<void (arc::Nibbler *)>> keys;

            std::vector<std::vector<int>> _map;
            std::size_t _score;
            State _gameState;

            std::vector<pos_t> _snake;
            Direction _direction;

            pos_t _food;

            void goUp(void);
            void goLeft(void);
            void goDown(void);
            void goRight(void);

            bool checkWallCollision(void);

            void setFoodPos(void);

            void drawFood(void);
            void drawSnake(void);
    };
}

#endif // NIBBLER_HPP
