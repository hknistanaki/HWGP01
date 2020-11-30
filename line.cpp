#include "Shape.h"
#include "Line.h"

void Line::set_points(cosnt QPoint& point_begin, const QPoint& point_end)
{
    this->point_begin = point_begin;
    this->point_end = point_end;
}

void Line::draw(const int translate_x, const int translate_y)
{
    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());

    get_painter().save();
    get_qpainter().translate(translate_x, translate_y);

    get_qpainter().drawLine(point_begin, point_end);

    get_qpainter().restore();
}