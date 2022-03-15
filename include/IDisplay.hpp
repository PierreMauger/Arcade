/*
** EPITECH PROJECT, 2022
** Include
** File description:
** Interfaces
*/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <vector>

#include "Generic.hpp"

namespace arc
{
    class IDisplay {
        public:
            virtual ~IDisplay() = default;
            virtual void initDisplay(void) = 0;
            virtual void destroyDisplay(void) = 0;
            virtual void display(Style **) = 0;
            virtual std::vector<EventType> getEvent(void) = 0;
    };
} // namespace arc

#endif // DISPLAY_HPP
