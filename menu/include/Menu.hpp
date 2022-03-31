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
            unsigned char **_map;
            Score _scoreList;
            LibList _graphList;
            LibList _gameList;

        public:
            Menu(void);
            ~Menu();
            void initGame(void);
            void destroyGame(void);
            void update(std::vector<GameKey> keys);
            void setGameState(State state);
            State getGameState(void);
            unsigned char **getMap(void);
            std::size_t getScore(void);
    };

    extern "C" std::unique_ptr<Menu> entryPoint(void)
    {
        return std::make_unique<Menu>();
    }
} // namespace arc

#endif // MENU_HPP
