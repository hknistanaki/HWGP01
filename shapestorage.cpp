#include "shapestorage.h"

shapeStorage::~shapeStorage()
{
    for(auto i : shapes) {
        delete i;
    }

}
