/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

#include "Sdl.hpp"

static const int keyTab[] {
    SDLK_KP_ENTER,
    SDLK_BACKSPACE,
    SDLK_SPACE,
    SDLK_ESCAPE,
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
    {255,   0,   0, 255},   // RED
    {  0,   0, 255, 255},   // BLUE
    {  0, 128,   0, 255},   // GREEN
    {255, 255, 255, 255},   // WHITE
    {255, 128,   0, 255},   // ORANGE
    {  0, 255, 255, 255},   // CYAN
    {128,   0, 128, 255},   // PURPLE
    {255, 255,   0, 255},   // YELLOW
    {  0, 255,   0, 255},   // LIME
    {128,   0,   0, 255},   // BROWN
    {255, 105, 147, 255},   // PINK
    {128, 128, 128, 255}    // GRAY
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
    for (int i = 0; i < (int)arc::DisplayColor::D_COLOR_SIZE - 1; i++)
        if (color == i + 1)
            return colorTab[i];
    return colorTab[0];
}

arc::sdl::sdl(void)
{
    this->_rect = {0, 0, 20, 20};
}

void arc::sdl::initDisplay(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(1000, 1000, SDL_WINDOW_SHOWN, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Arcade");
    TTF_Init();
    this->_font = TTF_OpenFont("ressources/arial.ttf", 200);
}

void arc::sdl::destroyDisplay(void)
{
    TTF_CloseFont(this->_font);
    TTF_Quit();
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
    SDL_Color_t col = findColor(color);

    this->_rect.x = posX * 20;
    this->_rect.y = posY * 20;
    SDL_SetRenderDrawColor(this->_renderer, col.r, col.g, col.b, col.a);
    SDL_RenderFillRect(this->_renderer, &this->_rect);
}

static void SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius)
{
    int x_pos = radius;
    int y_pos = 0;
    int err = 0;

    while (x_pos >= y_pos) {
        SDL_RenderDrawPoint(renderer, x + x_pos, y + y_pos);
        SDL_RenderDrawPoint(renderer, x + y_pos, y + x_pos);
        SDL_RenderDrawPoint(renderer, x - y_pos, y + x_pos);
        SDL_RenderDrawPoint(renderer, x - x_pos, y + y_pos);
        SDL_RenderDrawPoint(renderer, x - x_pos, y - y_pos);
        SDL_RenderDrawPoint(renderer, x - y_pos, y - x_pos);
        SDL_RenderDrawPoint(renderer, x + y_pos, y - x_pos);
        SDL_RenderDrawPoint(renderer, x + x_pos, y - y_pos);
        y_pos++;
        err += 1 + 2 * y_pos;
        if (2 * (err - x_pos) + 1 > 0) {
            x_pos--;
            err += 1 - 2 * x_pos;
        }
    }
}

void arc::sdl::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{
    SDL_Color_t col = findColor(color);

    SDL_SetRenderDrawColor(this->_renderer, col.r, col.g, col.b, col.a);
    SDL_RenderFillCircle(this->_renderer, posX * 20 + 10, posY * 20 + 10, 10);
}

void arc::sdl::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{
    SDL_Color_t col = findColor(color);

    this->_rect.x = posX * 20;
    this->_rect.y = posY * 20;
    SDL_SetRenderDrawColor(this->_renderer, col.r, col.g, col.b, col.a);
    SDL_RenderDrawLine(this->_renderer, this->_rect.x, this->_rect.y, this->_rect.x + 20, this->_rect.y + 20);
    SDL_RenderDrawLine(this->_renderer, this->_rect.x, this->_rect.y + 20, this->_rect.x + 20, this->_rect.y);
}

void arc::sdl::drawLetter(unsigned char letter, std::size_t posX, std::size_t posY)
{
    char str[] = "\0\0";
    str[0] = letter;

    this->_rect.x = posX * 20;
    this->_rect.y = posY * 20;
    this->_textSurface = TTF_RenderText_Blended(this->_font, str, {255, 255, 255, 255});
    this->_textTexture = SDL_CreateTextureFromSurface(this->_renderer, this->_textSurface);
    SDL_RenderCopy(this->_renderer, this->_textTexture, NULL, &this->_rect);
    SDL_FreeSurface(this->_textSurface);
    SDL_DestroyTexture(this->_textTexture);
}

std::vector<arc::DisplayKey> arc::sdl::getKeys(void)
{
    if (this->_eventVector.size())
        this->_eventVector.clear();
    while (SDL_PollEvent(&this->_events)) {
        if (this->_events.type == SDL_QUIT)
            this->_eventVector.push_back(arc::DisplayKey::D_F7);
        if (this->_events.type == SDL_KEYDOWN)
            this->_eventVector.push_back(findEventKey(this->_events.key.keysym.sym));
    }
    return this->_eventVector;
}
