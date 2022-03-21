/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "IDisplay.hpp"

namespace arc
{
    class sfml : virtual public IDisplay {
        private:
            sf::RenderWindow _window;
            sf::Event _event;
            std::vector<arc::Key> _eventVector;
            sf::RectangleShape _rect;
            sf::CircleShape _circle;

        private:
            arc::Key findEventKey(sf::Keyboard::Key key);
            sf::Color findColor(unsigned char color);

        public:
            sfml(void);
            ~sfml();
            void initDisplay(void);
            void destroyDisplay(void);
            void display(void);
            void drawSquare(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCircle(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCross(unsigned char color, std::size_t posX, std::size_t posY);
            void drawFdp(unsigned char color, std::size_t posX, std::size_t posY);
            std::vector<Key> getKeys(void);
    };

} // namespace arc
