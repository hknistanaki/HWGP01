#include "Shape.h"


Shape::Shape(QPaintDevice* device, int shapeID, Shape::ShapeType shape) : id{shapeID}, shapeType{shape}
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

void Shape::set_pen(QColor color, int penWidth, PenStyle penStyle, PenCapStyle penCapStyle, PenJoinStyle penJoinStyle)
{
    pen.setColor(color);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);
}

void Shape::set_brush(QColor color, BrushStyle brushStyle)
{
    brush.setColor(color);
    brush.setStyle(brushStyle);
}

QString Shape::nameTag(const QString &shapename) const
{

    QString nametag;

    // construct a QString to be drawn above the shape
    nametag = QString(shapename) + QString(" ID: ") + QString::number(get_shapeID());

    return nametag;

}

std::unique_ptr<QPainter> Shape::getPainter(QPaintDevice* device) const
{
    std::unique_ptr<QPainter> paint{new QPainter{device}};

    paint->setBrush(brush);
    paint->setPen(pen);

    return paint;
}
