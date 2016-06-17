#ifndef CHARACTER_H
#define CHARACTER_H
#include "Gameobject.h"
#include "Hotbar.h"
#include "Item.h"

class Character : public Gameobject
{
    public:
        Character();

        int velX;
        int velY;

        Hotbar hotbar;
        Item activeitem;

        float angle;

        void updateCharacter();

        void useItem();

    private:

};

#endif // CHARACTER_H
