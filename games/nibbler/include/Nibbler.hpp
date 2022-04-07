/*
** EPITECH PROJECT, 2022
** Include
** File description:
** nib
*/

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#define MAP_SIZE (50)

#include "IGame.hpp"

#include <map>
#include <functional>
#include <memory>

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
            std::string getPlayerName(void);
            std::string getGameName(void);

        private:
            static std::map<arc::GameKey, std::function<void (arc::Nibbler *)>> keys;

            std::vector<std::vector<int>> _map;
            std::size_t _score = 0;
            State _gameState;

            std::vector<pos_t> _snake;
            Direction _direction;

            pos_t _food;

            void move(void);
            void moveUp(void);
            void moveLeft(void);
            void moveDown(void);
            void moveRight(void);

            void changeDirUp(void);
            void changeDirLeft(void);
            void changeDirDown(void);
            void changeDirRight(void);

            bool checkWallCollision(void);
            bool checkSelfCollision(void);
            bool checkFoodCollision(void);

            void addSnakePart(void);

            void putFood(void);
    };

    extern "C" Nibbler *entryPoint(void)
    {
        return new Nibbler();
    }
}

#endif // NIBBLER_HPP
