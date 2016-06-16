#ifndef CHARACTER_H
#define CHARACTER_H
#include "Gameobject.h"
#include "Hotbar.h"

class Character : public Gameobject
{
    public:
        Character();

        int velX;
        int velY;

        Hotbar hotbar;

        float angle;

        void updateCharacter();

    private:

};

#endif // CHARACTER_H
