#ifndef TILE_H
#define TILE_H
#include "Gameobject.h"


class Tile : public Gameobject
{
    public:
        Tile();
        virtual ~Tile();

    protected:

    private:
        int TileType;
};

#endif // TILE_H
