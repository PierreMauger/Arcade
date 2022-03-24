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

#include "IDisplay.hpp"
#include "IGame.hpp"

#include "Score.hpp"

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

            std::string _playerName;
            Score _score;

            std::vector<std::string> _graphList;
            std::vector<std::string> _gameList;

            void getLibList(void);
    };
} // namespace arc

#endif // CORE_HPP
