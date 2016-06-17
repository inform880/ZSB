#include "Environment.h"

Environment::Environment()
{
    //ctor
}

Environment::~Environment()
{
    //dtor
}

bool Environment::insertitem(Item item, int x, int y)
{
    for(int i = 0; i < 100; i++)
    {
        if(groundItems[i].identifier == -1)
        {
            groundItems[i].createItem( item );
            groundItems[i].status = GROUND;
            groundItems[i].objImage = item.objImage;
            groundItems[i].x = x;
            groundItems[i].y = y;
            return true;
        }
    }
    return false;
}

bool Environment::removeitem(Item item)
{

    return true;
}

void Environment::updateItems()
{
    for(int i = 0; i < 100; i++)
    {
        groundItems[i].updateItem();
    }
}

void Environment::checkCollision(Character *character)
{
    for(int i = 0; i < 100; i++)
    {
        if(groundItems[i].identifier != -1)
        {
            int diffX = pow(character->rect.x - groundItems[i].rect.x, 2);
            int diffY = pow(character->rect.y - groundItems[i].rect.y, 2);
            int distance = sqrt(diffX + diffY);
            if (distance < 100)
            {
                character->hotbar.insertitem(groundItems[i]);

                groundItems[i].identifier = -1;
                groundItems[i].status = -1;
                groundItems[i].name = " ";
                groundItems[i].type = -1;
                return;

            }
        }
    }
}
