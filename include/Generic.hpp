/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

#ifndef GENERIC_HPP
#define GENERIC_HPP

namespace arc
{
    enum class Style {
        BLUE_SQUARE,
        RED_SQUARE,
        GREEN_SQUARE,
        BLUE_CIRCLE,
        RED_CIRCLE,
        GREEN_CIRCLE,
        BLUE_CROSS,
        RED_CROSS,
        GREEN_CROSS,

        STYLE_SIZE
    };

    enum class EventType {
        PREV_LIB,
        NEXT_LIB,
        PREV_GAME,
        NEXT_GAME,
        RESTART_GAME,
        MENU,
        EXIT,
        ARROW_UP,
        ARROW_LEFT,
        ARROW_DOWN,
        ARROW_RIGHT,
        PAUSE,

        EVENTYPE_SIZE
    };
} // namespace arc

#endif // GENERIC_HPP
