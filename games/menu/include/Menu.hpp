/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "IGame.hpp"

namespace arc
{
    class Menu : virtual public IGame
    {
        private:
            unsigned char **_map;

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
} // namespace arc

#endif // MENU_HPP
