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
//	Each function is mandatory for the program to work properly.
/////////////////////////////////////////////////

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <vector>
#include <memory>

namespace arc
{

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the different Colors
	///
	///	Used in the different shape functions to define the
    /// color of the shape.
	///
	////////////////////////////////////////////////////////////
	enum DisplayColor {
        D_RED = 1,
        D_BLUE,
        D_GREEN,
        D_WHITE,
        D_ORANGE,
        D_CYAN,
        D_PURPLE,
        D_YELLOW,
        D_LIME,
        D_BROWN,
        D_PINK,
        D_GRAY,

        D_COLOR_SIZE
    };

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents Keys
	///
	///	Will be returned by the event checker inside a vector.
	///
	////////////////////////////////////////////////////////////
    enum class DisplayKey {
		D_ENTER,
		D_BACKSPACE,
		D_SPACE,
		D_ESCAPE,
		D_UP_ARROW,
		D_DOWN_ARROW,
		D_LEFT_ARROW,
		D_RIGHT_ARROW,
		D_KEY_A,
		D_KEY_B,
		D_KEY_C,
		D_KEY_D,
		D_KEY_E,
		D_KEY_F,
		D_KEY_G,
		D_KEY_H,
		D_KEY_I,
		D_KEY_J,
		D_KEY_K,
		D_KEY_L,
		D_KEY_M,
		D_KEY_N,
		D_KEY_O,
		D_KEY_P,
		D_KEY_Q,
		D_KEY_R,
		D_KEY_S,
		D_KEY_T,
		D_KEY_U,
		D_KEY_V,
		D_KEY_W,
		D_KEY_X,
		D_KEY_Y,
		D_KEY_Z,
		D_KEY_1,
		D_KEY_2,
		D_KEY_3,
		D_KEY_4,
		D_KEY_5,
		D_KEY_6,
		D_KEY_7,
		D_KEY_8,
		D_KEY_9,
		D_KEY_0,

		// Handled by the core
		D_F1,
		D_F2,
		D_F3,
		D_F4,
		D_F5,
		D_F6,
		D_F7,
		D_F8,
		D_F9,
		D_F10,
		D_F11,
		D_F12,

	    D_KEY_SIZE
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
    		///	Refresh the window. Will be called after draw calls.
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
			virtual void drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Handle the keys inputs from the user
    		///
    		/// This fonction is used to detect and return the Keys pressed
			///	by the user. (see the documentation about Key)
			///	You must return the available keys in the Key list.
			///	To proceed, create a vector of your graphical library keys
			///	linked to the Key enumeration keys.
			///
			///	\return Keys vector corresponding to the event key list
    		////////////////////////////////////////////////////////////
			virtual std::vector<DisplayKey> getKeys(void) = 0;
	};
} // namespace arc

#endif // DISPLAY_HPP
