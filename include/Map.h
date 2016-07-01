#ifndef Map_H
#define Map_H
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Tile.h"

class Map
{
    public:
        Map();
        virtual ~Map();

        bool loadMap(std::string levelName);

        void drawMap();

        void saveMap();

        int scroll_X;
        int scroll_Y;

    protected:

    private:
        std::ofstream saveGame;

        Tile tiles[10000];


};

#endif // Map_H
