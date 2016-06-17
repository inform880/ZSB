#include "Item.h"

Item::Item( )
{
    //ctor
    identifier = -1;
    type = -1;
    name = " ";
    status = -1;
    isVisible = false;
    rect.h = 40;
    rect.w = 44;
    rect.x = 0;
    rect.y = 0;
}

Item::~Item()
{
    //dtor
}

bool Item::createItem(Item item)
{
    identifier = item.identifier;;
    type = item.type;
    name = item.name;
}

void Item::updateItem(int hotbarlocation)
{
    switch(status)
    {
    case -1:
        break;
    case GROUND:
        rect.x = x;
        rect.y = y;
        break;
    case INVENTORY:
        //rect.x = hotbarlocation * 50;
        //rect.y = hotbarlocation * 50;
        break;
    case HOTBAR:
        rect.x = (hotbarlocation * 50)+4;
        rect.y = 555;
        break;
    }
    return;
}
void Item::updateItem()
{
    switch(status)
    {
    case GROUND:
        rect.x = x-100;
        rect.y = y-100;
        break;
    case INVENTORY:
        //rect.x = hotbarlocation * 50;
        //rect.y = hotbarlocation * 50;
        break;
    }
    return;
}
