#include "square.h"

void Square::set_point(const QPoint& point)
{
    origin.setX(point.x());
    origin.setY(point.y());
}

void Square::set_dimension(const int &wIn)
{
    w = wIn;
}

void Square::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 15);

    paint->setPen(Qt::black);
    paint->drawText(temp.x(), temp.y(), nameTag("Square"));

    paint->setPen(get_pen());
    paint->setBrush(get_brush());

    paint->save();
    paint->translate(translate_x, translate_y);
    paint->drawRect(origin.x(), origin.y(), w, w);

    paint->restore();
}
