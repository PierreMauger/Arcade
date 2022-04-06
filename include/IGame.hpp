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
        SQUARE = 1,
        CROSS,
        CIRCLE,
    };

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents Colors
	///
	///	Will be in the map to precise the shapes colors.
	///
	////////////////////////////////////////////////////////////
    enum GameColor {
        G_RED = 1,
        G_BLUE,
        G_GREEN,
        G_WHITE,
        G_ORANGE,
        G_CYAN,
        G_PURPLE,
        G_YELLOW,
        G_LIME,
        G_BROWN,
        G_PINK,
        G_GRAY,

        G_COLOR_SIZE
    };

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the differents Keys
	///
	///	Will be send in the update function.
	///
	////////////////////////////////////////////////////////////
    enum GameKey {
		G_ENTER,
		G_BACKSPACE,
		G_SPACE,
		G_ESCAPE,
		G_UP_ARROW,
		G_DOWN_ARROW,
		G_LEFT_ARROW,
		G_RIGHT_ARROW,
		G_A_KEY,
		G_B_KEY,
		G_C_KEY,
		G_D_KEY,
		G_E_KEY,
		G_F_KEY,
		G_G_KEY,
		G_H_KEY,
		G_I_KEY,
		G_J_KEY,
		G_K_KEY,
		G_L_KEY,
		G_M_KEY,
		G_N_KEY,
		G_O_KEY,
		G_P_KEY,
		G_Q_KEY,
		G_R_KEY,
		G_S_KEY,
		G_T_KEY,
		G_U_KEY,
		G_V_KEY,
		G_W_KEY,
		G_X_KEY,
		G_Y_KEY,
		G_Z_KEY,
		G_KEY_0,
		G_KEY_1,
		G_KEY_2,
		G_KEY_3,
		G_KEY_4,
		G_KEY_5,
		G_KEY_6,
		G_KEY_7,
		G_KEY_8,
		G_KEY_9,

        G_KEY_SIZE
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
            virtual void initGame(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Destruction of your game
    		///
    		///	Is the last function to be called by the core.
    		///	It destroy your game library.
    		///
    		////////////////////////////////////////////////////////////
            virtual void destroyGame(void) = 0;

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
            virtual void update(std::vector<GameKey> keys) = 0;

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
            virtual std::vector<std::vector<int>> getMap(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Return the current game's score
    		///
    		///	This function return the current score of the player.
    		///
    		/// \return the current player score
    		///
    		////////////////////////////////////////////////////////////
            virtual std::size_t getScore(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Return the name of the current player
    		///
    		///	This function return the current player's name.
    		///
    		/// \return the current player name
    		///
    		////////////////////////////////////////////////////////////
			virtual std::string getPlayerName(void) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Return the name of the current game
    		///
    		///	This function return the current game's name.
    		///
    		/// \return the current game name
    		///
    		////////////////////////////////////////////////////////////
			virtual std::string getGameName(void) = 0;
    };
} // namespace arc

#endif // GAME_HPP
