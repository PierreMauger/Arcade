/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "Ncurses.hpp"
#include <iostream>

#define COLOR_ORANGE 8
#define COLOR_LIME 9
#define COLOR_BROWN 10
#define COLOR_PINK 11
#define COLOR_GRAY 12

static const int keyTab[] {
    1,
    7,
    32,
    27,
    3,
    2,
    4,
    5,
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    KEY_F(10),
    KEY_F(11),
    KEY_F(12)
};

arc::ncurses::ncurses(void)
{
}

void arc::ncurses::initDisplay(void)
{
    initscr();
    timeout(10);
    raw();
    keypad(stdscr, TRUE);
    noecho();
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
    init_pair(D_PINK, COLOR_PINK, COLOR_BLACK);
    init_pair(D_GRAY, COLOR_GRAY, COLOR_BLACK);
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
    attron(A_REVERSE);
    mvprintw(posY, posX, " ");
    attroff(A_REVERSE);
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
    char input = getch();

    if (input == ERR)
        return std::vector<arc::DisplayKey>();
    if (this->_eventVector.size())
        this->_eventVector.clear();
    for (int i = 0; i < (int)arc::DisplayKey::D_KEY_SIZE; i++)
        if (keyTab[i] == input) {
            this->_eventVector.push_back((arc::DisplayKey)i);
            break;
        }
    flushinp();
    return this->_eventVector;
}
