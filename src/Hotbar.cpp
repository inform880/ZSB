#include "Hotbar.h"
#include "Item.h"

Hotbar::Hotbar()
{
    rect.x = 0;
    rect.y = 550;
    rect.w = 251;
    rect.h = 50;

    itemSelected = 0;

    selectedimagerect.x = 0;
    selectedimagerect.y = 550;
    selectedimagerect.w = 50;
    selectedimagerect.h = 50;
}

Hotbar::~Hotbar()
{
    //dtor
}

void Hotbar::updateHotbar()
{
    selectedimagerect.x = (itemSelected * 50);


    for(int i = 0; i < 4; i ++)
    {
        slot[i].updateItem(i);
    }
}

bool Hotbar::insertitem(Item item, int slotnum)
{
    if(slot[slotnum].status == -1)
        return false;
    else
    {
        slot[slotnum].createItem( item );
        slot[slotnum].identifier = item.identifier;
        slot[slotnum].type = item.type;
        slot[slotnum].name = item.name;
        slot[slotnum].status = HOTBAR;
        slot[slotnum].objImage = item.objImage;
        return true;
    }
}

bool Hotbar::removeitem( int slotnum )
{
    if(slot[slotnum].identifier == -1)
    {
        return false;
    }
    else
    {
        slot[slotnum].status = -1;
        slot[slotnum].objImage = NULL;
        slot[slotnum].identifier = -1;
        slot[slotnum].type = -1;
        slot[slotnum].name = " ";
    }
}
