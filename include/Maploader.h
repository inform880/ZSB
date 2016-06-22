#ifndef MAPLOADER_H
#define MAPLOADER_H
#include <iostream>
#include <fstream>
#include "Item.h"
class Maploader
{
    public:
        Maploader();
        virtual ~Maploader();

        bool loadMap(std::string levelName);

        void saveMap();

    protected:

    private:
        std::ofstream saveGame;
};

#endif // MAPLOADER_H
