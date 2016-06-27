#include "WeaponData.h"

WeaponData::WeaponData(int identifier)
{
    switch(identifier)
    {
    case 101:
        clipSize = 5;
        bulletspeed = 15;
        shootingspeed = 10;
        break;
    case 102:
        clipSize = 5;
        bulletspeed = 10;
        shootingspeed = 100;
        break;
    }
}

WeaponData::~WeaponData()
{
    //dtor
}

//void WeaponData::setData(identifier)
//{

//}
