/*
** EPITECH PROJECT, 2022
** Include
** File description:
** qix
*/

#ifndef QIX_HPP
#define QIX_HPP

#define MAP_SIZE (50)

#include "IGame.hpp"

#include <map>
#include <functional>
#include <memory>
#include <algorithm>

namespace arc
{
    typedef struct {
        std::size_t x;
        std::size_t y;
    } pos_t;

    typedef struct {
        pos_t pos;
        int value;
    } cell_t;

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
            std::string getPlayerName(void);
            std::string getGameName(void);

        private:
            static std::map<arc::GameKey, std::function<void (arc::Qix *)>> keys;
            std::vector<GameKey> keysPressed;

            std::vector<std::vector<int>> _map;
            std::size_t _score = 0;
            State _gameState;

            std::vector<pos_t> _qix;
            std::vector<pos_t> _enemies;

            pos_t _player;
            cell_t _savedCell;
            cell_t _lastCell;

            void createQix(void);
            void createLines(void);

            void setCellValue(cell_t &cell, int x, int y, int value);
            bool canPlayerMoveToPos(pos_t pos);

            void drawTrail(pos_t pos, cell_t lastCell);

            void moveUp(void);
            void moveLeft(void);
            void moveDown(void);
            void moveRight(void);
    };

    extern "C" Qix *entryPoint(void)
    {
        return new Qix();
    }
}

#endif // QIX_HPP
