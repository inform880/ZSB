#include <iostream>
#include <SDL2/SDL.h>

#include "Game.h"

int main ( int argc, char** argv )
{
    Game game(800, 600);

    game.CreateObjects();

    game.Loop();

    game.Exit();

    return 0;
}
