#include "Shape.h"


Shape::Shape(QPaintDevice* device, int shapeID, Shape::ShapeType shape) : id{shapeID}, shapeType{shape}
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

void Shape::set_pen(GlobalColor color, int penWidth, PenStyle penStyle, PenCapStyle penCapStyle, PenJoinStyle penJoinStyle)
{
    pen.setColor(color);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);
}

void Shape::set_brush(GlobalColor color, BrushStyle brushStyle)
{
    brush.setColor(color);
    brush.setStyle(brushStyle);
}
