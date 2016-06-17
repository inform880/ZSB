#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Gameobject.h"

enum types {WEAPON, FOOD, TOOL, MATERIAL};
enum status {INVENTORY, GROUND, HOTBAR};

class Item : public Gameobject
{
    public:
        Item();
        virtual ~Item();

        int identifier;
        int type;

        std::string name;

        int status;

        bool createItem(Item item);

        void updateItem(int hotbarlocation);
        void updateItem();

        int delay;
        int timer;

        int numUses;

    protected:

    private:
};

#endif // ITEM_H
