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
	///	@brief Enumeration corresponding to the different Shapes
	///
	///	Stored in the map to define the shapes to draw.
	///
	////////////////////////////////////////////////////////////
    enum Shape {
        SQUARE = 1,
        CROSS,
        CIRCLE,
    };

	////////////////////////////////////////////////////////////
	///	@brief Enumeration corresponding to the different Colors
	///
	///	Stored in the map to define the color of each shape to draw.
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
	///	Will be sent by the update function inside a vector.
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
		G_KEY_A,
		G_KEY_B,
		G_KEY_C,
		G_KEY_D,
		G_KEY_E,
		G_KEY_F,
		G_KEY_G,
		G_KEY_H,
		G_KEY_I,
		G_KEY_J,
		G_KEY_K,
		G_KEY_L,
		G_KEY_M,
		G_KEY_N,
		G_KEY_O,
		G_KEY_P,
		G_KEY_Q,
		G_KEY_R,
		G_KEY_S,
		G_KEY_T,
		G_KEY_U,
		G_KEY_V,
		G_KEY_W,
		G_KEY_X,
		G_KEY_Y,
		G_KEY_Z,
		G_KEY_1,
		G_KEY_2,
		G_KEY_3,
		G_KEY_4,
		G_KEY_5,
		G_KEY_6,
		G_KEY_7,
		G_KEY_8,
		G_KEY_9,
		G_KEY_0,

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
	///	@brief Interface Game, inherited by all games
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
    		/// This function is used to simulate a tick in your game.
    		///	It takes a key input vector and must generate the corresponding game events,
    		///	like a change of direction in your game when arrow is sent.
    		///
    		/// \param keys correspond to the user's inputs, sent by the graphical library
    		///
    		////////////////////////////////////////////////////////////
            virtual void update(std::vector<GameKey> keys) = 0;

			////////////////////////////////////////////////////////////
    		/// \brief Set the game state to State var
    		///
    		/// This function is used to set the game state,
    		///	like Start or Stop. To see the different State of the game,
    		///	check the Status enumeration documentation.
    		///
    		/// \param state correspond to the game's state of your choice
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
    		///	the update function. This map id composed of the
    		///	different shapes and colors to draw.
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
    		/// \brief Set the player's name
    		///
    		/// This function is used to set the player's name.
    		/// It is used by the core to save the score.
            ///
    		/// \param string correspond to the player's name to set
    		///
    		////////////////////////////////////////////////////////////
			virtual void setPlayerName(std::string) = 0;

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
