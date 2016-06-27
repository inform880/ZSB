#include "Character.h"
#include "Hotbar.h"
#include <SDL2/SDL.h>
#include <cmath>


Character::Character()
{
    velX = 0;
    velY = 0;
    angle = 45;
    itemDelay = 10000;
}

void Character::updateCharacter()
{
    rect.x = x - 25;
    rect.y = y - 25;

    x-=velX;
    y-=velY;

    itemDelay++;

    int mx, my;
    SDL_GetMouseState( &mx, &my );
    float xDiff = x - mx;
    float yDiff = y - my;
    angle = atan2(yDiff,xDiff) * (180 / M_PI);
    hotbar.updateHotbar();

    activeitem = hotbar.getactiveItem();

    for(int i = 0; i < 100; i++)
    {
        if(project[i].isVisible)
        {
            project[i].update();
        }
    }
}

void Character::useItem()
{
    switch(activeitem.type)
    {
        case WEAPON:                    //WEAPONS are in the 100s
            {
                WeaponData weapon(activeitem.identifier);
                for(int i = 0; i < 100; i++)
                {
                    if(project[i].isVisible == false && itemDelay > weapon.shootingspeed)
                    {
                        //Shoot Bullet
                        project[i].x = x;
                        project[i].y = y;
                        project[i].isVisible = true;
                        project[i].velX = cos(angle*M_PI/180)*weapon.bulletspeed;
                        project[i].velY = sin(angle*M_PI/180)*weapon.bulletspeed;
                        itemDelay = 0;
                        break;
                    }
                }
                break;
            }
        case FOOD:                      //FOODs are 200s
            break;
        case TOOL:                      //TOOLs are 300s
            break;
        case MATERIAL:                  //MATERIALs are 400s
            break;
    }
    return;
}
