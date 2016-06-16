#ifndef HOTBAR_H
#define HOTBAR_H
#include "Item.h"
#include "Gameobject.h"
const int NUM_HOTBAR_ITEMS = 5;

class Hotbar : public Gameobject
{
    public:
        Hotbar();
        virtual ~Hotbar();

        //C++ is base 0 arrrggg
        //Item slot[NUM_HOTBAR_ITEMS - 1];
        Item slot[NUM_HOTBAR_ITEMS-1](int, int, std::string);

        bool insertitem(Item item, int slot);
        bool insertitem(Item item);

        bool removeitem(Item item, int slot);

    private:
        int itemSelected;

};

#endif // HOTBAR_H
