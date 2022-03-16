/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>

namespace arc
{
    enum class Shape {
        SQUARE = (1 << 0),
        CROSS = (1 << 1),
        CIRCLE = (1 << 2),
        FDP = (1 << 3),
    };

    enum class Color {
        RED = (1 << 4),
        BLUE = (2 << 4),
        GREEN = (3 << 4),
        WHITE = (4 << 4),
        ORANGE = (5 << 4),
        CYAN = (6 << 4),
        PURPLE = (7 << 4),
        YELLOW = (8 << 4),
        LIME = (9 << 4),
        BROWN = (10 << 4),
        PINK = (11 << 4),
        GRAY = (12 << 4),
    };

    enum class Key {
		ENTER,
		BACKSPACE,
		SPACE,
		ESCAPE,
		UP_ARROW,
		DOWN_ARROW,
		LEFT_ARROW,
		RIGHT_ARROW,
		A_KEY,
		B_KEY,
		C_KEY,
		D_KEY,
		E_KEY,
		F_KEY,
		G_KEY,
		H_KEY,
		I_KEY,
		J_KEY,
		K_KEY,
		L_KEY,
		M_KEY,
		N_KEY,
		O_KEY,
		P_KEY,
		Q_KEY,
		R_KEY,
		S_KEY,
		T_KEY,
		U_KEY,
		V_KEY,
		W_KEY,
		X_KEY,
		Y_KEY,
		Z_KEY,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,

        EVENTYPE_SIZE
    };

    enum class State {
        STOP = 0,
        START = 1,
        PAUSE = 2
    };

    class IGame
    {
        public:
            virtual ~IGame() = default;
            virtual void init_game(void);
            virtual void destroy_game(void);
            virtual void update(std::vector<Key>) = 0;
            virtual void setGameState(State state) = 0;
            virtual State getGameState(void) = 0;
            virtual unsigned char **getMap(void) = 0;
            virtual std::size_t getScore(void) = 0;
    };
} // namespace arc

#endif // GAME_HPP
