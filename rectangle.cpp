#include "Shape.h"
#include "Rectangle.h"

void Rectangle::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Rectangle::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
//    get_qpainter().setPen(get_pen());
//    get_qpainter().setBrush(get_brush());

//    get_qpainter().save();
//    get_qpainter().translate(translate_x, translate_y);

//    get_qpainter().restore();
}
