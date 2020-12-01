#ifndef SHAPESTORAGE_H
#define SHAPESTORAGE_H

#include "vector.h"
#include "Shape.h"


struct shapeStorage
{
    //shapeStorage();
    ~shapeStorage();

    /*!
     * \brief shapes vector of Shape ptrs
     */
    gp::vector<Shape*> shapes;
};

#endif // SHAPESTORAGE_H
