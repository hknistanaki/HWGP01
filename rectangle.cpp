#include "Shape.h"
#include "Rectangle.h"

void Rectangle::set_point(const QPoint& point)
{
    origin.setX(point.x());
    origin.setY(point.y());
}

void Rectangle::set_dimensions(const int &lIn, const int &wIn)
{
    l = lIn;
    w = wIn;
}

void Rectangle::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 15);

    paint->setPen(Qt::black);
    paint->drawText(temp.x(), temp.y(), nameTag("Rectangle"));

    paint->setPen(get_pen());
    paint->setBrush(get_brush());

    paint->save();
    paint->translate(translate_x, translate_y);

    paint->drawRect(origin.x(), origin.y(), l, w);

    paint->restore();
}
