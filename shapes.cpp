#include "shapes.h"

Shape::Shape(QPaintDevice* device, int id, ShapeType shape)
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

QPainter& Shape::get_qpainter()
{
    return qpainter;
}

Shape::ShapeType Shape::get_shape() const
{
    return shape;
}

const QPen& Shape::get_pen() const
{
    return pen;
}

const QBrush& Shape::get_brush() const
{
    return brush;
}

void Shape::set_shape(ShapeType shape)
{
    this->shape = shape;
}

void Shape::set_pen(Qt::GlobalColor color, int width, Qt::PenStyle penStyle, Qt::PenCapStyle penCapStyle, Qt::PenJoinStyle penJoinStyle)
{
    pen = QPen(color, width, penStyle, penCapStyle, penJoinStyle);
}

void Shape::set_pen(Qt::GlobalColor color)
{
    pen = QPen(color);
}

void Shape::set_brush(const Qt::GlobalColor color, const Qt::BrushStyle brushStyle)
{
    brush = QBrush(color, brushStyle);
}

void Shape::default_Style()
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;

    qpainter.setPen(pen);
    qpainter.setBrush(brush);
}

void Shape::draw_rect(int width, int height)
{
    qpainter.drawRect(QRect(0, 0, width, height))
}

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

void Polyline::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Polyline::draw(const int translate_x, const int translate_y)
{
    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());

    get_qpainter().save();
    get_qpainter().translate(translate_x, translate_y);

    get_qpainter().drawPolyline(points.begin(), points.size());

    get_qpainter().restore();
}

void Polygon::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Polygon::draw(const int translate_x, const int translate_y)
{
    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());

    get_qpainter().save();
    get_qpainter().translate(translate_x, translate_y);

    get_qpainter().restore();
}