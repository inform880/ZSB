#include "Item.h"

Item::Item( int Sidentifier, int Stype, std::string Sname )
{
    //ctor
    identifier = Sidentifier;
    type = Stype;
    name = Sname;
    isVisible = false;
}

Item::~Item()
{
    //dtor
}
