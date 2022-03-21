/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <vector>

namespace arc
{
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

    class IDisplay {
        public:
            virtual ~IDisplay() = default;
            virtual void initDisplay(void) = 0;
            virtual void destroyDisplay(void) = 0;
            virtual void display(void) = 0;
            virtual void drawSquare(unsigned char color, std::size_t posX, std::size_t posY) = 0;
            virtual void drawCircle(unsigned char color, std::size_t posX, std::size_t posY) = 0;
            virtual void drawCross(unsigned char color, std::size_t posX, std::size_t posY) = 0;
            virtual void drawFdp(unsigned char color, std::size_t posX, std::size_t posY) = 0;
            virtual std::vector<Key> getKeys(void) = 0;
    };
} // namespace arc

#endif // DISPLAY_HPP
