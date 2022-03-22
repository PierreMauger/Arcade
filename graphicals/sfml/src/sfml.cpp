/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "sfml.hpp"

static const sf::Keyboard::Key keyTab[] {
    sf::Keyboard::Enter,
    sf::Keyboard::BackSpace,
    sf::Keyboard::Space,
    sf::Keyboard::Escape,
    sf::Keyboard::Up,
    sf::Keyboard::Down,
    sf::Keyboard::Left,
    sf::Keyboard::Right,
    sf::Keyboard::A,
    sf::Keyboard::B,
    sf::Keyboard::C,
    sf::Keyboard::D,
    sf::Keyboard::E,
    sf::Keyboard::F,
    sf::Keyboard::G,
    sf::Keyboard::H,
    sf::Keyboard::I,
    sf::Keyboard::J,
    sf::Keyboard::K,
    sf::Keyboard::L,
    sf::Keyboard::M,
    sf::Keyboard::N,
    sf::Keyboard::O,
    sf::Keyboard::P,
    sf::Keyboard::Q,
    sf::Keyboard::R,
    sf::Keyboard::S,
    sf::Keyboard::T,
    sf::Keyboard::U,
    sf::Keyboard::V,
    sf::Keyboard::W,
    sf::Keyboard::X,
    sf::Keyboard::Y,
    sf::Keyboard::Z,
    sf::Keyboard::F1,
    sf::Keyboard::F2,
    sf::Keyboard::F3,
    sf::Keyboard::F4,
    sf::Keyboard::F5,
    sf::Keyboard::F6,
    sf::Keyboard::F7,
    sf::Keyboard::F8,
    sf::Keyboard::F9,
    sf::Keyboard::F10,
    sf::Keyboard::F11,
    sf::Keyboard::F12
};

static const sf::Color colorTab[] {
    sf::Color(255,   0,   0),
    sf::Color(  0,   0, 255),
    sf::Color(  0, 128,   0),
    sf::Color(255, 255, 255),
    sf::Color(255, 128,   0),
    sf::Color(  0, 255, 255),
    sf::Color(128,   0, 128),
    sf::Color(255, 255,   0),
    sf::Color(  0, 255,   0),
    sf::Color(128,   0,   0),
    sf::Color(255, 105, 147),
    sf::Color(128, 128, 128)
};

arc::Key arc::sfml::findEventKey(sf::Keyboard::Key key)
{
    for (int i = 0; i < (int)arc::Key::EVENTYPE_SIZE; i++)
        if (keyTab[i] == key)
            return (arc::Key)i;
    return arc::Key::EVENTYPE_SIZE;
}

sf::Color arc::sfml::findColor(unsigned char color)
{
    for (int i = 1; i <= 12; i++) {
        if (color == i * 16)
            return colorTab[i];
    }
    return colorTab[0];
}

arc::sfml::sfml(void)
{
    this->_rect.setPosition({0, 0});
    this->_rect.setSize({50, 50});
    this->_rect.setFillColor(sf::Color::White);
}

arc::sfml::~sfml()
{

}

void arc::sfml::initDisplay(void)
{
    this->_window.create(sf::VideoMode(720, 480), "Arcade");
}

void arc::sfml::destroyDisplay(void)
{

}

void arc::sfml::display(void)
{
    this->_window.display();
    this->_window.clear();
}

void arc::sfml::drawSquare(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_rect.setFillColor(findColor(color));
    this->_rect.setPosition({posX * 50, posY * 50});
    this->_window.draw(this->_rect);
}

void arc::sfml::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_circle.setFillColor(findColor(color));
    this->_circle.setPosition({posX * 50, posY * 50});
    this->_window.draw(this->_circle);
}

void arc::sfml::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{

}

void arc::sfml::drawFdp(unsigned char color, std::size_t posX, std::size_t posY)
{

}

std::vector<arc::Key> arc::sfml::getKeys(void)
{
    if (this->_eventVector.size())
        this->_eventVector.clear();
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window.close();
        if (this->_event.type == sf::Event::KeyPressed)
            this->_eventVector.push_back(findEventKey(this->_event.key.code));
    }
    return this->_eventVector;
}
