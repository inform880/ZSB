#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Gameobject.h"

enum{WEAPON, FOOD, TOOL, MATERIAL};

class Item : public Gameobject
{
    public:
        Item( int Sidentifier, int Stype, std::string Sname );
        virtual ~Item();

        int identifier;
        int type;

        std::string name;

    protected:

    private:
};

#endif // ITEM_H
