/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

/////////////////////////////////////////////////
//  @file   IDisplay.hpp
//  @brief  Display Interface, used by all graphical libraries
//
//	Display Interface, used by all graphical libraries.
//	Each functions is mandatory for the good working of the program.
/////////////////////////////////////////////////

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <vector>

namespace arc
{

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents Colors
	///
	///	Will be send in the differents shapes functions and
	///	compared to determine the shape's color.
	///
	////////////////////////////////////////////////////////////
	enum Color {
        RED = -10,
        BLUE = -11,
        GREEN = -12,
        WHITE = -13,
        ORANGE = -14,
        CYAN = -15,
        PURPLE = -16,
        YELLOW = -17,
        LIME = -18,
        BROWN = -19,
        PINK = -20,
        GRAY = -21,
    };

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents Keys
	///
	///	Will be returned by the event checker.
	///
	////////////////////////////////////////////////////////////
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
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_0,

		// Handle by the core
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

	////////////////////////////////////////////////////////////
	///	@brief Interface inherited by all graphics library
	///
	////////////////////////////////////////////////////////////
	class IDisplay {
	    public:

			////////////////////////////////////////////////////////////
    		/// \brief Default destructor
    		///
    		///	Will be overrided by your class destructor.
    		///
    		////////////////////////////////////////////////////////////
	        virtual ~IDisplay() = default;

			////////////////////////////////////////////////////////////
    		/// \brief Initialisation of your graphical library
    		///
    		///	Is the first function to be called by the core.
    		///	It initialize your library and the ressources linked to it.
    		///
    		////////////////////////////////////////////////////////////
	        virtual void initDisplay(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Destruction of your graphical library
    		///
    		///	Is the last function to be called by the core.
    		///	It destroy all objects and close all ressources linked
    		///	to your library.
    		///
    		////////////////////////////////////////////////////////////
	        virtual void destroyDisplay(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Display the elements previously drawn
    		///
    		///	Refresh the window. Will be called after draws.
    		///
    		////////////////////////////////////////////////////////////
			virtual void display(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a colored square at the given positions
    		///
    		/// This function is used by the core to draw a square at the
    		///	given positions.
    		///
    		/// \param color color byte (see documentation about Color byte)
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawSquare(unsigned char color, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a colored circle at the given positions
    		///
    		/// This function is used by the core to draw a circle at the
    		///	given positions.
    		///
    		/// \param color color byte (see documentation about Color byte)
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawCircle(unsigned char color, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a colored cross at the given positions
    		///
    		/// This function is used by the core to draw a cross at the
    		///	given positions.
    		///
    		/// \param color color byte (see documentation about Color byte)
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawCross(unsigned char color, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a letter at the given positions
    		///
    		/// This function is used by the core to draw a letter at the
    		///	given positions.
    		///
    		/// \param letter letter to draw
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawLetter(unsigned char letter, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a colored circle at the given positions
    		///
    		/// This fonction is used to detect and return the Keys pressed
			///	by the user. (see the documentation about Key)
			///	You must return the available keys in the Key list.
			///	To proceed, create an array of your graphical library keys
			///	linked to the Key enumeration keys.
			///
			///	\return Keys vector corresponding to the event key list
    		////////////////////////////////////////////////////////////
			virtual std::vector<Key> getKeys(void) = 0;
	};
} // namespace arc

#endif // DISPLAY_HPP
