#include "Shape.h"
#include "Line.h"

Line::Line(const QPoint& A, const QPoint& B, const QPen &pen, int id) : Shape(nullptr, -1, ShapeType::Line) {
    set_points(A, B);

    set_pen(pen.color(), pen.width(), pen.style(), pen.capStyle(), pen.joinStyle());


    set_shapeID(id);
}

Line::~Line() { }

void Line::set_points(const QPoint& point_begin, const QPoint& point_end)
{
    this->point_begin = point_begin;
    this->point_end = point_end;
}

void Line::draw(QPaintDevice* device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 15);

    paint->drawText(temp.x(), temp.y(), nameTag("Line"));

    paint->drawLine(point_begin, point_end);
}

QPoint Line::id_pos() const
{
    int x;
    int y;

    // Determine where to draw the id string
    point_begin.x() < point_end.x() ? x = point_begin.x() : x = point_end.x();

    point_begin.y() < point_end.y() ? y = point_begin.y() : y = point_end.y();

    return(QPoint(x,y));
}
