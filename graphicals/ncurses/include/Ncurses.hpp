/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#ifndef NCURSES_HPP
#define NCURSES_HPP

#include <ncurses.h>
#include "IDisplay.hpp"

namespace arc
{
    class ncurses : virtual public IDisplay
    {
        private:

        public:
            ncurses(void);
            ~ncurses() = default;
            void initDisplay(void);
            void destroyDisplay(void);
            void display(void);
            void drawSquare(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCircle(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCross(unsigned char color, std::size_t posX, std::size_t posY);
            void drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY);
            std::vector<DisplayKey> getKeys(void);
    };

    extern "C" std::unique_ptr<ncurses> entryPoint(void)
    {
        return std::make_unique<ncurses>();
    }
} // namespace arc

#endif // NCURSES_HPP
