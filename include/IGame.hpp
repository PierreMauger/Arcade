/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

/////////////////////////////////////////////////
//  @file   IGame.hpp
//  @brief  Game interface, used by all games libraries.
//
//	Game interface, used by all games libraries.
//	Each functions is mandatory for the good
//	working of the program.
//	If you want to create a new game, you must
//	implement all function of the interface.
/////////////////////////////////////////////////

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>

namespace arc
{

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents Shapes
	///
	///	Will be in the map to precise the shapes.
	///
	////////////////////////////////////////////////////////////
    enum Shape {
        SQUARE = -1,
        CROSS = -2,
        CIRCLE = -3,
    };

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents Colors
	///
	///	Will be in the map to precise the shapes colors.
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
	///	Will be send in the update function.
	///
	////////////////////////////////////////////////////////////
    enum Key {
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
		KEY_0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,

        EVENTYPE_SIZE
    };

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents States
	///
	///	Correspond to the three states of the games.
	///
	////////////////////////////////////////////////////////////
    enum State {
		/// @var The game hasn't started yet or is finished
        STOP = 0,
		/// @var Start the game
        START = 1,
		/// @var Pause the game or resume it
        PAUSE = 2
    };

	////////////////////////////////////////////////////////////
	///	@brief Interface Game, inherited by all games to precise
	///	the functions used by the core
	///
	////////////////////////////////////////////////////////////
    class IGame {
        public:

			////////////////////////////////////////////////////////////
    		/// \brief Default destructor
    		///
    		///	Will be overrided by your class destructor.
    		///
    		////////////////////////////////////////////////////////////
            virtual ~IGame() = default;

			////////////////////////////////////////////////////////////
    		/// \brief Initialisation of your game
    		///
    		///	Is the first function to be called by the core.
    		///	It initialize your game library.
    		///
    		////////////////////////////////////////////////////////////
            virtual void init_game(void);

			////////////////////////////////////////////////////////////
    		/// \brief Destruction of your game
    		///
    		///	Is the last function to be called by the core.
    		///	It destroy your game library.
    		///
    		////////////////////////////////////////////////////////////
            virtual void destroy_game(void);

			////////////////////////////////////////////////////////////
    		/// \brief Update your game
    		///
    		/// This function is used to simulate one tick of your game.
    		///	It takes a key input list and must create the consequences,
    		///	like a direction changement in your game when arrow is sended.
    		///
    		/// \param keys correspond to the user's inputs, sended by the graphical library
    		///
    		////////////////////////////////////////////////////////////
            virtual void update(std::vector<Key> keys) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Set the game state to State var
    		///
    		/// This function is used to set the game state,
    		///	like start or stop. To see the different State of the game,
    		///	check the Status enumeration documentation.
    		///
    		/// \param state correspond to the game's state you whant to set
    		///
    		////////////////////////////////////////////////////////////
            virtual void setGameState(State state) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Return the current game's state
    		///
    		/// \return current game's state
    		///
    		////////////////////////////////////////////////////////////
            virtual State getGameState(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Return the game's map
    		///
    		///	This function return the game's map previously setted by
    		///	the update function. The element in the map correspond to
    		///	the differents shapes and colors to load at this index.
    		///
    		/// \return the current map
    		///
    		////////////////////////////////////////////////////////////
            virtual unsigned char **getMap(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Return the current game's score
    		///
    		///	This function return the current score of the player.
    		///
    		/// \return the current player score
    		///
    		////////////////////////////////////////////////////////////
            virtual std::size_t getScore(void) = 0;
    };
} // namespace arc

#endif // GAME_HPP
