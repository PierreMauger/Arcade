/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

#define PATH_LIBS "./lib/"

#define FRAME_RATE (200)

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <functional>
#include <chrono>
#include <thread>
#include <cstdint>

#include "IDisplay.hpp"
#include "IGame.hpp"

#include "Score.hpp"
#include "LibList.hpp"
#include "LibLoader.hpp"

namespace arc
{
    class Core {
        public:
            Core(std::string graphLibName);
            ~Core();

            void coreLoop(void);
        private:
            std::unique_ptr<IDisplay> _graph;
            std::unique_ptr<IGame> _game;

            LibLoader _libLoader;

            std::size_t _gameIdx = 0;
            LibList _gameList;
            std::size_t _graphIdx = 0;
            LibList _graphList;

            bool _exit = false;

            Score _scoreList;
            std::size_t _score = 0;
            std::string _gameName = std::string("");
            std::string _playerName = std::string("");

            static std::map<arc::Shape, std::function<void (arc::IDisplay *, unsigned char, std::size_t, std::size_t)>> shapes;
            static std::map<arc::DisplayKey, std::function<void (arc::Core *)>> coreEvent;

            std::string getRawLibName(std::string libName);
            void getGraphLibByName(std::string graphLibName);

            std::unique_ptr<IGame> execGameEntryPoint(std::string gameLibName);
            std::unique_ptr<IDisplay> execGraphEntryPoint(std::string graphLibName);
            void loadGameLib(std::unique_ptr<IGame> gameLib);
            void loadGraphLib(std::unique_ptr<IDisplay> graphLib);
            void unloadGameLib(void);
            void unloadGraphLib(void);

            void browseMap(void);
            void coreKey(void);
            void drawIdx(int idx, std::size_t x, std::size_t y);

            char getLetter(int mapIdx);
            Shape getShape(int mapIdx);
            GameColor getColor(int mapIdx);

            void changePlayerName(void);

            // Core event
            void previousGame(void);
            void nextGame(void);
            void restartGame(void);
            void menuGame(void);
            void previousGraph(void);
            void nextGraph(void);
            void exit(void);
            void pauseGame(void);
    };

} // namespace arc

#endif // CORE_HPP
