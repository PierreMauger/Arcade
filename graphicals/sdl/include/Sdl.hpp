/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#ifndef SDL_HPP
#define SDL_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "IDisplay.hpp"

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} SDL_Color_t;

namespace arc
{
    class sdl : virtual public IDisplay
    {
        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Event _events;
            std::vector<arc::DisplayKey> _eventVector;
            SDL_Rect _rect;
            TTF_Font *_font;
            SDL_Surface *_textSurface;
            SDL_Texture *_textTexture;

        private:
            arc::DisplayKey findEventKey(int key);
            SDL_Color_t findColor(unsigned char color);

        public:
            sdl(void);
            ~sdl() = default;
            void initDisplay(void);
            void destroyDisplay(void);
            void display(void);
            void drawSquare(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCircle(unsigned char color, std::size_t posX, std::size_t posY);
            void drawCross(unsigned char color, std::size_t posX, std::size_t posY);
            void drawLetter(unsigned char letter, std::size_t posX, std::size_t posY);
            std::vector<DisplayKey> getKeys(void);
    };

    extern "C" std::unique_ptr<sdl> entryPoint(void)
    {
        return std::make_unique<sdl>();
    }
} // namespace arc

#endif // MENU_HPP
