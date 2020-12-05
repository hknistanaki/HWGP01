#include "Shape.h"
#include "Ellipse.h"

void Ellipse::set_point(const QPoint& point)
{
    center.setX(point.x());
    center.setY(point.y());
}

void Ellipse::set_dimensions(const int &lIn, const int &wIn)
{
    l = lIn;
    w = wIn;
}

void Ellipse::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 15);

    paint->drawText(temp.x(), temp.y(), nameTag("Ellipse"));

    paint->setPen(get_pen());
    paint->setBrush(get_brush());

    paint->save();
    paint->translate(translate_x, translate_y);
    paint->drawEllipse(center.x(), center.y(), l, w);

    paint->restore();
}

double Ellipse::perimeter() const
{
    // using https://www.mathsisfun.com/geometry/ellipse-perimeter.html

    double a = std::abs(w) / 2.0;
    double b = std::abs(l) / 2.0;

    double h = ((a - b) * (a - b)) / ((a + b) * (a + b));

    return 3.14 * (a + b) * (1 + (3 * h) / (10 + std::sqrt(4 - 3 * h)));
}

double Ellipse::area() const
{
    double a = std::abs(w) / 2.0;
    double b = std::abs(l) / 2.0;

    return 3.14 * a * b;
}
