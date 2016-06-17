#ifndef HOTBAR_H
#define HOTBAR_H
#include "Item.h"
#include "Gameobject.h"

class Hotbar : public Gameobject
{
    public:
        Hotbar();
        virtual ~Hotbar();

        //C++ is base 0 arrrggg
        Item slot[5];

        bool insertitem(Item item, int slotnum);
        bool insertitem(Item item);

        bool removeitem( int slotnum );

        void updateHotbar();

        Item getactiveItem();

        int itemSelected;

        SDL_Texture* selectedimage;

        SDL_Rect selectedimagerect;

    private:


};

#endif // HOTBAR_H
