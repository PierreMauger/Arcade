/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <functional>

#include "IDisplay.hpp"
#include "IGame.hpp"

#include "Score.hpp"
#include "LibList.hpp"

namespace arc
{
    class Core {
        public:
            Core(std::shared_ptr<IDisplay> graph, std::shared_ptr<IGame> game);
            ~Core() = default;

            void coreLoop(void);
        private:
            std::shared_ptr<IDisplay> _graph;
            std::shared_ptr<IGame> _game;

            bool _exit = false;

            Score _scoreList;
            std::size_t _score;
            std::string _playerName;

            LibList _graphList;
            LibList _gameList;

            static std::map<arc::Shape, std::function<void (arc::IDisplay *, unsigned char, std::size_t, std::size_t)>> shapes;
            static std::map<arc::DisplayKey, std::function<void (arc::Core *)>> coreEvent;

            void browseMap(void);
            void coreKey(void);
            void drawIdx(unsigned char idx, std::size_t x, std::size_t y);

            // Core event
            void previousGame(void);
            void nextGame(void);
            void restartGame(void);
            void menuGame(void);
            void exitGame(void);
            void previousGraph(void);
            void nextGraph(void);
    };

    template<class T>
    std::unique_ptr<T> entryPoint(void)
    {
        return std::make_unique<T>;
    }

} // namespace arc

#endif // CORE_HPP
