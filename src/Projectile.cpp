#include "Projectile.h"

Projectile::Projectile()
{
    //ctor
    velX = 0;
    velY = 0;
    rect.h = 5;
    rect.w = 5;
    rect.x = 0;
    rect.y = 0;
    isVisible = false;
}

Projectile::~Projectile()
{
    //dtor
}

bool Projectile::createProjectile(int x, int y)
{
    return true;
}

void Projectile::update()
{
    rect.x =+ velX;
    rect.y =+ velY;
    return;
}
