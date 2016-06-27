#include "Maploader.h"

Maploader::Maploader()
{
    //ctor
}

Maploader::~Maploader()
{
    //dtor
}

bool Maploader::loadMap(std::string levelName)
{
    saveGame.open("savegame.txt");
    std::string num[100];
    num[0] = "testitem.bmp";
    num[1] = 101;
    num[2] = WEAPON;
    num[3] = HOTBAR;
    num[4] = 500;
    num[5] = 500;
    for( int i = 0; i < 100; ++i )
    {
        saveGame << "test \n";
    }
    saveGame.close();
    for(int i = 0; i < 100; i++)
        std::cout << num[i] << std::endl;
    return true;
}

void Maploader::saveMap()
{
    //for()
}
