/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

/////////////////////////////////////////////////
//  @file   IDisplay.hpp
//  @brief  Display Interface, used by all graphical libraries.
//  @author pierre.hamel@epitech.eu
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
	///	@brief Enumeration corresponding to the different Keys.
	///
	///	Will be returned by the event checker.
	///
	////////////////////////////////////////////////////////////
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
    		/// \brief Display the elements previously drawn.
    		///
    		///	Refresh the window. Will be called after draws.
    		///
    		////////////////////////////////////////////////////////////
			virtual void display(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a clored square at the given positions
    		///
    		/// A window is active only on the current thread, if you want to
    		/// make it active on another thread you have to deactivate it
    		/// on the previous thread first if it was active.
    		/// Only one window can be active on a thread at a time, thus
    		/// the window previously active (if any) automatically gets deactivated.
    		/// This is not to be confused with requestFocus().
    		///
    		/// \param color byte, will be between 0 and 16 (see documentation about Color byte)
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawSquare(unsigned char color, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a clored circle at the given positions
    		///
    		/// A window is active only on the current thread, if you want to
    		/// make it active on another thread you have to deactivate it
    		/// on the previous thread first if it was active.
    		/// Only one window can be active on a thread at a time, thus
    		/// the window previously active (if any) automatically gets deactivated.
    		/// This is not to be confused with requestFocus().
    		///
    		/// \param color byte, will be between 0 and 16 (see documentation about Color byte)
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawCircle(unsigned char color, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a clored cross at the given positions
    		///
    		/// A window is active only on the current thread, if you want to
    		/// make it active on another thread you have to deactivate it
    		/// on the previous thread first if it was active.
    		/// Only one window can be active on a thread at a time, thus
    		/// the window previously active (if any) automatically gets deactivated.
    		/// This is not to be confused with requestFocus().
    		///
    		/// \param color byte, will be between 0 and 16 (see documentation about Color byte)
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawCross(unsigned char color, std::size_t posX, std::size_t posY) = 0;


			////////////////////////////////////////////////////////////
    		/// \brief Draw a clored fdp at the given positions
    		///
    		/// A window is active only on the current thread, if you want to
    		/// make it active on another thread you have to deactivate it
    		/// on the previous thread first if it was active.
    		/// Only one window can be active on a thread at a time, thus
    		/// the window previously active (if any) automatically gets deactivated.
    		/// This is not to be confused with requestFocus().
    		///
    		/// \param color byte, will be between 0 and 16 (see documentation about Color byte)
    		/// \param posX X index in the map
    		/// \param posY Y index in the map
    		///
    		////////////////////////////////////////////////////////////
			virtual void drawFdp(unsigned char color, std::size_t posX, std::size_t posY) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Draw a clored circle at the given positions
    		///
    		/// A window is active only on the current thread, if you want to
    		/// make it active on another thread you have to deactivate it
    		/// on the previous thread first if it was active.
    		/// Only one window can be active on a thread at a time, thus
    		/// the window previously active (if any) automatically gets deactivated.
    		/// This is not to be confused with requestFocus().
			///
			///	\return Keys vector corresponding to the event key list (see documentation about Key)
    		////////////////////////////////////////////////////////////
			virtual std::vector<Key> getKeys(void) = 0;
	};
} // namespace arc

#endif // DISPLAY_HPP
