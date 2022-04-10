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
    enum Direction {
        UP_LEFT,
        UP_RIGHT,
        DOWN_LEFT,
        DOWN_RIGHT,

        SIZE_DIR
    };

    typedef struct {
        std::size_t x;
        std::size_t y;
    } pos_t;

    typedef struct {
        int x;
        int y;
        int idx;
    } vector_t;

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
            static std::map<arc::Direction, arc::vector_t> pos;
            std::vector<GameKey> keysPressed;

            std::vector<std::vector<int>> _map;
            std::size_t _score = 0;
            State _gameState;

            std::vector<pos_t> _qix;
            std::vector<pos_t> _qixNoise;
            Direction _directionQix;
            std::size_t _lastRand = 0;

            std::vector<pos_t> _lines;
            std::vector<pos_t> _gray;
            std::vector<pos_t> _enemies;

            bool _wasDrawing = false;
            pos_t _player;
            cell_t _savedCell;

            void createQix(void);
            void createLines(void);

            bool canPlayerMoveToPos(pos_t pos);
            void setCellValue(cell_t &cell, pos_t pos, int value);
            void restoreCellValue(void);

            void replaceGray(void);
            void fillArea(void);

            void moveUp(void);
            void moveLeft(void);
            void moveDown(void);
            void moveRight(void);

            bool canQixMoveToPos(pos_t pos);
            void changeQixCoord(vector_t vector);
            void defineNoisePos(void);
            bool updatePosQix(vector_t toMove);
            void eraseQix(void);
            void eraseQixNoise(void);
            void drawQix(void);
            void drawQixNoise(void);
            void moveQix(void);
    };

    extern "C" Qix *entryPoint(void)
    {
        return new Qix();
    }
}

#endif // QIX_HPP
