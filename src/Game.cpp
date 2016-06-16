#include <Game.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

const int SCREEN_TICKS_PER_FRAME = 1000/60;

Game::Game(int WIDTH, int HEIGHT)
{
// initialize SDL video
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        std::cout << "Unable to init SDL video: "<< SDL_GetError() << std::endl;
    }
// make sure SDL cleans up before exit
    //atexit(SDL_Quit);

// create a new window
    window = NULL;
    window = SDL_CreateWindow("ZBS",
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          WIDTH,HEIGHT,
                          /* SDL_WINDOW_FULLSCREEN | */
                          SDL_WINDOW_OPENGL);

    if ( NULL == window )
    {
        std::cout << "Unable to create window: "<< SDL_GetError() << std::endl;
    }

// Create a new renderer
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, 0);

    if ( NULL == renderer )
    {
        std::cout << "Unable to create renderer: "<< SDL_GetError() << std::endl;
    }

    screensurface = SDL_GetWindowSurface(window);
}

Game::~Game()
{
    //dtor
}

bool Game::Loop()
{
    bool done = false;
    while (!done)
    {
    Uint32 starttime = SDL_GetTicks();
    Uint32 time = SDL_GetTicks() - starttime;
    // drawing
    SDL_RenderClear(renderer);
    SDL_RenderCopyEx(renderer, player.objImage, NULL, &player.rect, player.angle, NULL, SDL_FLIP_NONE);
    SDL_RenderCopy(renderer, player.hotbar.objImage, NULL, &player.hotbar.rect);
    SDL_RenderPresent(renderer);

        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
            // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

            // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;

                    if (event.key.keysym.sym == SDLK_w)
                       player.velY = 10;

                    if (event.key.keysym.sym == SDLK_s)
                        player.velY = -10;

                    if (event.key.keysym.sym == SDLK_a)
                        player.velX = 10;

                    if (event.key.keysym.sym == SDLK_d)
                        player.velX = -10;

                    break;
                }
                case SDL_KEYUP:
                {
                    if (event.key.keysym.sym == SDLK_w)
                        player.velY = 0;

                    if (event.key.keysym.sym == SDLK_s)
                        player.velY = 0;

                    if (event.key.keysym.sym == SDLK_a)
                        player.velX = 0;

                    if (event.key.keysym.sym == SDLK_d)
                        player.velX = 0;

                        break;
                }
                case SDL_MOUSEMOTION:
                {

                }
            } // end switch
        } // end of message processing

        //Update Gameobjects
        player.updateCharacter();


        //Update Framerate
        if( time < SCREEN_TICKS_PER_FRAME )
        {
            SDL_Delay( SCREEN_TICKS_PER_FRAME - time );
        }
    } // end main loop
    return true;
}

bool Game::Exit()
{ Character();
    //SDL_DestroyTexture(player.);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return true;
}

bool Game::CreateObjects()
{
    player.objImage = player.loadSurface("test.bmp", screensurface, renderer);
    player.hotbar.loadSurface("hotbar.bmp", screensurface, renderer);
    return true;
}


