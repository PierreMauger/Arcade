/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "../include/Sfml.hpp"

static const sf::Keyboard::Key keyTab[] {
    sf::Keyboard::Enter,
    sf::Keyboard::Backspace,
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
    sf::Keyboard::Num1,
    sf::Keyboard::Num2,
    sf::Keyboard::Num3,
    sf::Keyboard::Num4,
    sf::Keyboard::Num5,
    sf::Keyboard::Num6,
    sf::Keyboard::Num7,
    sf::Keyboard::Num8,
    sf::Keyboard::Num9,
    sf::Keyboard::Num0,
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
    sf::Color(255,   0,   0),   // RED
    sf::Color(  0,   0, 255),   // BLUE
    sf::Color(  0, 128,   0),   // GREEN
    sf::Color(255, 255, 255),   // WHITE
    sf::Color(255, 128,   0),   // ORANGE
    sf::Color(  0, 255, 255),   // CYAN
    sf::Color(128,   0, 128),   // PURPLE
    sf::Color(255, 255,   0),   // YELLOW
    sf::Color(  0, 255,   0),   // LIME
    sf::Color(128,   0,   0),   // BROWN
    sf::Color(255, 105, 147),   // PINK
    sf::Color(128, 128, 128)    // GRAY
};

arc::DisplayKey arc::sfml::findEventKey(sf::Keyboard::Key key)
{
    for (int i = 0; i < (int)arc::DisplayKey::D_KEY_SIZE; i++)
        if (keyTab[i] == key)
            return (arc::DisplayKey)i;
    return arc::DisplayKey::D_KEY_SIZE;
}

sf::Color arc::sfml::findColor(unsigned char color)
{
    for (int i = 0; i < 12; i++)
        if (color == i + 1)
            return colorTab[i];
    return colorTab[0];
}

arc::sfml::sfml(void)
{
    this->_rect.setPosition({0, 0});
    this->_rect.setSize({50, 50});
    this->_rect.setFillColor(sf::Color::White);
    this->_circle.setPosition({0, 0});
    this->_circle.setRadius(50);
    this->_circle.setFillColor(sf::Color::White);
    this->_line1.setPosition({0, 0});
    this->_line1.setSize({std::sqrt(50 * 50 + 50 * 50), 5});
    this->_line1.setRotation(-45);
    this->_line1.setFillColor(sf::Color::White);
    // this->_line1.setOrigin({0, 3});
    this->_line2.setPosition({0, 50});
    this->_line2.setSize({std::sqrt(50 * 50 + 50 * 50), 5});
    this->_line2.setRotation(45);
    this->_line2.setFillColor(sf::Color::White);
    // this->_line2.setOrigin({0, 3});
    this->_font.loadFromFile("./graphicals/sfml/arial.ttf");
    this->_letter.setFont(this->_font);
    this->_letter.setPosition({0, 0});
    this->_letter.setString("a");
    this->_letter.setCharacterSize(15);
}

void arc::sfml::initDisplay(void)
{
    this->_window.create(sf::VideoMode(720, 480), "Arcade");
}

void arc::sfml::destroyDisplay(void)
{
    this->_window.close();
}

void arc::sfml::display(void)
{
    this->_window.display();
    this->_window.clear();
}

void arc::sfml::drawSquare(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_rect.setFillColor(findColor(color));
    this->_rect.setPosition({(float)posX * 50, (float)posY * 50});
    this->_window.draw(this->_rect);
}

void arc::sfml::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_circle.setFillColor(findColor(color));
    this->_circle.setPosition({(float)posX * 50, (float)posY * 50});
    this->_window.draw(this->_circle);
}

void arc::sfml::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_line1.setFillColor(findColor(color));
    this->_line2.setFillColor(findColor(color));
    this->_line1.setPosition({(float)posX * 50, (float)posY * 50});
    this->_line2.setPosition({(float)posX * 50, (float)posY * 50 + 50});
    this->_window.draw(this->_line1);
    this->_window.draw(this->_line2);
}

void arc::sfml::drawLetter(unsigned char letter, std::size_t posX, std::size_t posY)
{
    this->_letter.setPosition({(float)posX * 50, (float)posY * 50});
    this->_letter.setString((char *)&letter);
    this->_window.draw(this->_letter);
}

std::vector<arc::DisplayKey> arc::sfml::getKeys(void)
{
    if (this->_eventVector.size())
        this->_eventVector.clear();
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed) {
            this->_window.close();
            this->_eventVector.push_back(arc::DisplayKey::D_F7);
        }
        if (this->_event.type == sf::Event::KeyPressed)
            this->_eventVector.push_back(findEventKey(this->_event.key.code));
    }
    return this->_eventVector;
}
