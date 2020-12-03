#include "Shape.h"
#include "Ellipse.h"

void Ellipse::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Ellipse::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{

}
