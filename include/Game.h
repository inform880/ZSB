#ifndef GAME_H
#define GAME_H
#include "Game.h"
#include "Gameobject.h"
#include "Character.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

class Game
{
    public:
        Game(int, int);
        virtual ~Game();

        bool CreateObjects();

        bool Loop();

        bool Exit();

    protected:

    private:

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* screensurface;

        Character player;
};

#endif // GAME_H
