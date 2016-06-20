#include "WeaponData.h"

WeaponData::WeaponData(int identifier)
{
    switch(identifier)
    {
    case 101:
        clipSize = 5;
        bulletspeed = 5;
        break;
    case 102:
        clipSize = 5;
        bulletspeed = 1;
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
