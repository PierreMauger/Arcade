/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "Ncurses.hpp"

#define COLOR_ORANGE 8
#define COLOR_LIME 9
#define COLOR_BROWN 10
#define COLOR_PINK 11
#define COLOR_GRAY 12

arc::ncurses::ncurses(void)
{
}

void arc::ncurses::initDisplay(void)
{
    initscr();
    start_color();
    init_color(COLOR_ORANGE, 1000, 500, 0);
    init_color(COLOR_LIME, 0, 1000, 0);
    init_color(COLOR_BROWN, 500, 0, 0);
    init_color(COLOR_PINK, 1000, 411, 576);
    init_color(COLOR_GRAY, 500, 500, 500);
    init_pair(D_RED, COLOR_RED, COLOR_BLACK);
    init_pair(D_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(D_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(D_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(D_ORANGE, COLOR_ORANGE, COLOR_BLACK);
    init_pair(D_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(D_PURPLE, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(D_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(D_LIME, COLOR_LIME, COLOR_BLACK);
    init_pair(D_BROWN, COLOR_BROWN, COLOR_BLACK);
    init_pair(D_PINK, COLOR_RED, COLOR_BLACK);
    init_pair(D_GRAY, COLOR_WHITE, COLOR_BLACK);
}

void arc::ncurses::destroyDisplay(void)
{
    endwin();
}

void arc::ncurses::display(void)
{
    refresh();
    clear();
}

void arc::ncurses::drawSquare(unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR(color));
    mvprintw(posY, posX, "#");
    attroff(COLOR_PAIR(color));
}

void arc::ncurses::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR(color));
    mvprintw(posY, posX, "O");
    attroff(COLOR_PAIR(color));
}

void arc::ncurses::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR(color));
    mvprintw(posY, posX, "X");
    attroff(COLOR_PAIR(color));
}

void arc::ncurses::drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR(color));
    mvprintw(posY, posX, (char *)&letter);
    attroff(COLOR_PAIR(color));
}

std::vector<arc::DisplayKey> arc::ncurses::getKeys(void)
{
    return std::vector<arc::DisplayKey>();
}
