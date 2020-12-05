#include "circle.h"

void Circle::set_point(const QPoint& point)
{
    center.setX(point.x());
    center.setY(point.y());
}

void Circle::set_radius(const int &rIn)
{
    r = rIn;
}

void Circle::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 15);

    paint->setPen(Qt::black);
    paint->drawText(temp.x(), temp.y(), nameTag("Circle"));

    paint->setPen(get_pen());
    paint->setBrush(get_brush());

    paint->save();
    paint->translate(translate_x, translate_y);
    paint->drawEllipse(center.x(), center.y(), r, r);

    paint->restore();
}
