/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "IGame.hpp"
#include "Score.hpp"
#include "LibList.hpp"

namespace arc
{
    class Menu : virtual public IGame
    {
        private:
            Score _scoreList;
            LibList _graphList;
            LibList _gameList;
            std::vector<std::vector<int>> _map;

            void drawRectangle(int x, int y, int width, int height, int color);
        public:
            Menu(void);
            ~Menu() = default;
            void initGame(void);
            void destroyGame(void);
            void update(std::vector<GameKey> keys);
            void setGameState(State state);
            State getGameState(void);
            std::vector<std::vector<int>> getMap(void);
            std::size_t getScore(void);
            std::string getPlayerName(void);
            std::string getGameName(void);
    };

    extern "C" std::unique_ptr<Menu> entryPoint(void)
    {
        return std::make_unique<Menu>();
    }
} // namespace arc

#endif // MENU_HPP
