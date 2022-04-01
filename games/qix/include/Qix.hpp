/*
** EPITECH PROJECT, 2022
** Include
** File description:
** qix
*/

#ifndef QIX_HPP
#define QIX_HPP

#include "IGame.hpp"

#include <map>
#include <functional>
#include <memory>

namespace arc
{
    class Qix : public IGame {
        public:

        private:

    };

    extern "C" std::unique_ptr<Qix> entryPoint(void)
    {
        return std::make_unique<Qix>();
    }
}

#endif // QIX_HPP
