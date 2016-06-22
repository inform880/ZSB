#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "Item.h"
#include "math.h"
#include "Character.h"
#include "Maploader.h"

class Environment
{
    public:
        Environment();
        virtual ~Environment();

        Item groundItems[100];

        bool insertitem(Item item, int x, int y);

        bool removeitem(Item item);

        void updateItems();

        void checkCollision(Character *character);

        bool loadEnvironment();

        Maploader maploader;

    protected:

    private:
};

#endif // ENVIRONMENT_H
