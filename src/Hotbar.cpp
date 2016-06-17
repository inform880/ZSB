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


    for(int i = 0; i < 5; i ++)
    {
        //std::cout << i << ": " << slot[i].identifier << std::endl;
        slot[i].updateItem(i);
    }
}

bool Hotbar::insertitem(Item item, int slotnum)
{
    if(slot[slotnum].status == -1)
    {
        slot[slotnum] = item;

        slot[slotnum].createItem( item );
        slot[slotnum].identifier = item.identifier;
        slot[slotnum].type = item.type;
        slot[slotnum].name = item.name;
        slot[slotnum].status = HOTBAR;
        slot[slotnum].objImage = item.objImage;

        //std::cout << slot[slotnum].rect.x << std::endl;
        //std::cout << slot[slotnum].rect.y << std::endl;


        return true;
    }
    else
        return false;

}
bool Hotbar::insertitem(Item item)
{

    for(int i = 0; i < 5; i++)
    {
        if(slot[i].identifier == -1)
        {
            slot[i] = item;

            slot[i].createItem( item );
            slot[i].identifier = item.identifier;
            slot[i].type = item.type;
            slot[i].name = item.name;
            slot[i].status = HOTBAR;
            slot[i].objImage = item.objImage;

            return true;

            //std::cout << slot[slotnum].rect.x << std::endl;
            //std::cout << slot[slotnum].rect.y << std::endl;
        }


    }
  return false;
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
        return true;
    }
}

Item Hotbar::getactiveItem()
{
    return slot[itemSelected];
}
