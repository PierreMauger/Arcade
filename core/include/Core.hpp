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

            std::function<IGame *(void)> _menuEntryPoint;

            std::size_t _gameIdx = 0;
            std::vector<std::function<IGame *(void)>> _gameEntryPoint;

            std::size_t _graphIdx = 0;
            std::vector<std::function<IDisplay *(void)>> _graphEntryPoint;

            bool _exit = false;

            Score _scoreList;
            std::size_t _score = 0;
            std::string _gameName = std::string("");
            std::string _playerName = std::string("");

            LibList _graphList;
            LibList _gameList;

            static std::map<arc::Shape, std::function<void (arc::IDisplay *, unsigned char, std::size_t, std::size_t)>> shapes;
            static std::map<arc::DisplayKey, std::function<void (arc::Core *)>> coreEvent;

            std::string getRawLibName(std::string libName);
            void getGraphLibByName(std::string graphLibName);

            void getMenuEntryPoint(void);
            void getGamesEntryPoint(void);
            void getGraphsEntryPoint(void);
            void loadGameLib(std::function<IGame *(void)> entryPoint);
            void loadGraphLib(std::function<IDisplay *(void)> entryPoint);
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

    template<class T>
    std::unique_ptr<T> entryPoint(void)
    {
        return std::make_unique<T>;
    }

} // namespace arc

#endif // CORE_HPP
