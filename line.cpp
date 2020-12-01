#include "Shape.h"
#include "Line.h"

Line::Line(const QPoint& A, const QPoint& B, const QBrush &brush, const QPen &pen, int id) : Shape(nullptr, -1, ShapeType::Line) {
    set_points(A, B);
}

Line::~Line() { }

void Line::set_points(const QPoint& point_begin, const QPoint& point_end)
{
    this->point_begin = point_begin;
    this->point_end = point_end;
}

void Line::draw(QPaintDevice* device) const
{
    auto paint = getPainter(device);

    paint->drawLine(point_begin, point_end);
}
