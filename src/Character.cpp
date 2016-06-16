#include "Character.h"
#include "Hotbar.h"
#include <SDL2/SDL.h>
#include <cmath>

Character::Character()
{
    velX = 0;
    velY = 0;
    angle = 45;
}

void Character::updateCharacter()
{
    rect.x-=velX;
    rect.y-=velY;

    int x, y;
    SDL_GetMouseState( &x, &y );
    float xDiff = rect.x - x;
    float yDiff = rect.y - y;
    angle = atan2(yDiff,xDiff) * (180 / M_PI);
    hotbar.updateHotbar();

    x = rect.x + 100;
    y = rect.y + 100;
}
