/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "sdl.hpp"

static const int keyTab[] {
    SDLK_KP_ENTER,
    SDLK_BACKSPACE,
    SDLK_SPACE,
    SDLK_UP,
    SDLK_DOWN,
    SDLK_LEFT,
    SDLK_RIGHT,
    SDLK_a,
    SDLK_b,
    SDLK_c,
    SDLK_d,
    SDLK_e,
    SDLK_f,
    SDLK_g,
    SDLK_h,
    SDLK_i,
    SDLK_j,
    SDLK_k,
    SDLK_l,
    SDLK_m,
    SDLK_n,
    SDLK_o,
    SDLK_p,
    SDLK_q,
    SDLK_r,
    SDLK_s,
    SDLK_t,
    SDLK_u,
    SDLK_v,
    SDLK_w,
    SDLK_x,
    SDLK_y,
    SDLK_z,
    SDLK_1,
    SDLK_2,
    SDLK_3,
    SDLK_4,
    SDLK_5,
    SDLK_6,
    SDLK_7,
    SDLK_8,
    SDLK_9,
    SDLK_0,
    SDLK_F1,
    SDLK_F2,
    SDLK_F3,
    SDLK_F4,
    SDLK_F5,
    SDLK_F6,
    SDLK_F7,
    SDLK_F8,
    SDLK_F9,
    SDLK_F10,
    SDLK_F11,
    SDLK_F12
};

static const SDL_Color_t colorTab[] {
    {255,   0,   0, 255},
    {  0,   0, 255, 255},
    {  0, 128,   0, 255},
    {255, 255, 255, 255},
    {255, 128,   0, 255},
    {  0, 255, 255, 255},
    {128,   0, 128, 255},
    {255, 255,   0, 255},
    {  0, 255,   0, 255},
    {128,   0,   0, 255},
    {255, 105, 147, 255},
    {128, 128, 128, 255},
};

arc::DisplayKey arc::sdl::findEventKey(int key)
{
    for (int i = 0; i < (int)arc::DisplayKey::D_KEY_SIZE; i++)
        if (keyTab[i] == key)
            return (arc::DisplayKey)i;
    return arc::DisplayKey::D_KEY_SIZE;
}

SDL_Color_t arc::sdl::findColor(unsigned char color)
{
    for (int i = 1; i <= 12; i++) {
        if (color == i * 16)
            return colorTab[i];
    }
    return colorTab[0];
}

arc::sdl::sdl(void)
{

}

arc::sdl::~sdl()
{

}

void arc::sdl::initDisplay(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Arcade");
    this->_isOpen = true;
}

void arc::sdl::destroyDisplay(void)
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void arc::sdl::display(void)
{
    SDL_RenderPresent(this->_renderer);
    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->_renderer);
}

void arc::sdl::drawSquare(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_rect.x = posX * 50;
    this->_rect.y = posY * 50;
    SDL_Color_t col = findColor(color);

    SDL_SetRenderDrawColor(this->_renderer, col.r, col.g, col.b, col.a);
    SDL_RenderFillRect(this->_renderer, &this->_rect);
}

void arc::sdl::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{

}

void arc::sdl::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{

}

void arc::sdl::drawFdp(unsigned char color, std::size_t posX, std::size_t posY)
{

}

std::vector<arc::DisplayKey> arc::sdl::getKeys(void)
{
    if (this->_eventVector.size())
        this->_eventVector.clear();
    while (SDL_PollEvent(&this->_events)) {
        if  (this->_events.type == SDL_QUIT)
            this->_isOpen = false;
        if  (this->_events.type == SDL_KEYDOWN)
            this->_eventVector.push_back(findEventKey(this->_events.key.keysym.sym));
    }
    return this->_eventVector;
}
