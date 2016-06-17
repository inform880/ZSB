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
    SDL_RenderCopy(renderer, player.hotbar.selectedimage, NULL, &player.hotbar.selectedimagerect);
    for(int i = 0; i <= 4; i++)
    {
        if(player.hotbar.slot[i].identifier == -1)
            i = i;
        else
            SDL_RenderCopy(renderer, player.hotbar.slot[i].objImage, NULL, &player.hotbar.slot[i].rect);
    }
    for(int i = 0; i < 100 ; i++)
    {
        if(environment.groundItems[i].identifier != -1)
            SDL_RenderCopy(renderer,environment.groundItems[i].objImage,NULL, &environment.groundItems[i].rect);
    }
    for(int i = 0; i < 100 ; i++)
    {
        if(player.project[i].isVisible)
            SDL_RenderCopy(renderer,player.project[i].objImage,NULL, &player.project[i].rect);
    }
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
                case SDL_MOUSEWHEEL:
                {
                    if(event.wheel.y > 0 && player.hotbar.itemSelected != 0 )
                        player.hotbar.itemSelected--;
                    if(event.wheel.y < 0 && player.hotbar.itemSelected != 4 )
                        player.hotbar.itemSelected++;
                    break;
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                    if(event.button.button)
                    {
                        player.useItem();
                        break;
                    }
                }
            } // end switch
        } // end of message processing

        //Update Gameobjects
        player.updateCharacter();
        environment.updateItems();

        //Check for Collision
        environment.checkCollision(&player);
        environment.updateItems();

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
    testitem.objImage = testitem.loadSurface("testitem.bmp", screensurface, renderer);
    testitem.identifier = 101;
    testitem.type = WEAPON;
    testitem.status = HOTBAR;
    testitem.x = 500;
    testitem.y = 500;

    testitem2.objImage = testitem2.loadSurface("testitem.bmp", screensurface, renderer);
    testitem2.identifier = 102;
    testitem2.type = WEAPON;
    testitem2.status = GROUND;
    testitem2.x = 500;
    testitem2.y = 500;

    environment.insertitem(testitem, 500, 500);

    player.hotbar.insertitem(testitem2, 0);

    for(int i = 0; i < 100; i++)
    {
        player.project[i].objImage = player.project[i].loadSurface("bullet.bmp",screensurface,renderer);
    }

    player.objImage = player.loadSurface("test.bmp", screensurface, renderer);
    player.hotbar.objImage = player.hotbar.loadSurface("hotbar.bmp", screensurface, renderer);
    player.hotbar.selectedimage = player.hotbar.loadSurface("hotbarselected.bmp", screensurface, renderer);

    return true;
}


