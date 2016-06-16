#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include <iostream>

class Gameobject
{
    public:
        Gameobject();
        virtual ~Gameobject();

        SDL_Texture* loadSurface( std::string path, SDL_Surface* screensurface, SDL_Renderer* renderer);

        SDL_Texture* objImage;

        SDL_Rect rect;

        bool isVisible;

    protected:

    private:


};

#endif // GAMEOBJECT_H
