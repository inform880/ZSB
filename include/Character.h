#ifndef CHARACTER_H
#define CHARACTER_H
#include "Gameobject.h"
#include "Hotbar.h"
#include "Item.h"
#include "Projectile.h"
#include "WeaponData.h"

class Character : public Gameobject
{
    public:
        Character();

        int velX;
        int velY;
        int itemDelay;

        Hotbar hotbar;
        Item activeitem;
        Projectile project[100];

        float angle;

        void updateCharacter();
        void useItem();

    private:

};

#endif // CHARACTER_H
