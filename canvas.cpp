#include "canvas.h"

canvas::canvas(QWidget *parent, shapeStorage* store)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    localStore = store;

}

int canvas::getShapeCount() const
{
    return localStore->shapes.size();
}

void canvas::setStorage(shapeStorage *store)
{
    localStore = store;
}

void canvas::paintEvent(QPaintEvent */*event*/)
{
    // use const pointer to iterate over all shapes in localStore
    for (const Shape* shape : localStore->shapes) {
        shape->draw(this);
    }
}
