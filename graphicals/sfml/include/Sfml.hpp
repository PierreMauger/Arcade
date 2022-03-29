/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#include "IDisplay.hpp"

namespace arc
{
    class sfml : virtual public IDisplay
    {
        private:
            sf::RenderWindow _window;
            sf::Event _event;
            std::vector<arc::DisplayKey> _eventVector;
            sf::RectangleShape _rect;
            sf::CircleShape _circle;
            sf::RectangleShape _line1;
            sf::RectangleShape _line2;
            sf::Font _font;
            sf::Text _letter;

        private:
            arc::DisplayKey findEventKey(sf::Keyboard::Key key);
            sf::Color findColor(unsigned char color);

        public:
            sfml(void);
            ~sfml() = default;
            void initDisplay(void);
            void destroyDisplay(void);
            void display(void);
            void drawSquare(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCircle(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCross(unsigned char color, std::size_t posX, std::size_t posY);
            void drawLetter(unsigned char letter, std::size_t posX, std::size_t posY);
            std::vector<DisplayKey> getKeys(void);
    };
} // namespace arc

#endif // SFML_HPP
