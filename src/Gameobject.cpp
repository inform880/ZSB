#include "Gameobject.h"

Gameobject::Gameobject()
{
    rect.h = 50;
    rect.w = 50;
    rect.x = 0;
    rect.y = 0;
}

Gameobject::~Gameobject()
{
    //dtor
}

SDL_Texture* Gameobject::loadSurface( std::string path, SDL_Surface* screensurface, SDL_Renderer* renderer)
{
    SDL_Surface* optimizedSurface = NULL;

    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL)
    {
        std::cout << "unable to load image" << path.c_str(), SDL_GetError();
    }
    else
    {
        optimizedSurface = SDL_ConvertSurface( loadedSurface, screensurface->format, NULL);
        if(optimizedSurface == NULL)
        {
            std::cout << "unable to optimize image!" << std::endl;
        }
        SDL_FreeSurface( loadedSurface );
    }

    SDL_Texture* texture = NULL;
    texture = SDL_CreateTextureFromSurface(renderer, optimizedSurface);

    return texture;
}
