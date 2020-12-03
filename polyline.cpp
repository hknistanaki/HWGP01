#include "Shape.h"
#include "polyline.h"

void Polyline::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Polyline::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 15);

    paint->setPen(get_pen());

    paint->save();
    paint->translate(translate_x, translate_y);

    paint->drawText(temp.x(), temp.y(), nameTag("Polyline"));
    paint->drawPolyline(&points[0], points.size());

    paint->restore();

}

QPoint Polyline::id_pos() const
{
    int x;
    int y;

    // Determine where to draw the id string
    points[0].x() < points[points.size()].x() ? x = points[0].x() : x = points[points.size()].x();

    points[0].y() < points[points.size()].y() ? y = points[0].y() : y = points[points.size()].y();

    return(QPoint(x,y));
}
