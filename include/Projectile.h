#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Gameobject.h"
//#include "Character.h"
class Character;

class Projectile : public Gameobject
{
    public:
        Projectile();
        virtual ~Projectile();

        bool createProjectile(int x, int y);

        void update();

        double velX;
        double velY;

    protected:

    private:

};

#endif // PROJECTILE_H
