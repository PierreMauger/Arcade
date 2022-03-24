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

            Score _scoreList;
            std::size_t _score;
            std::string _playerName;

            LibList _graphList;
            LibList _gameList;

            static std::map<Shape, std::function<void (void)>> _shapes;

            void browseMap(void);
    };
} // namespace arc

#endif // CORE_HPP
