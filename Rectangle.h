#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Rectangle} {}
    ~Rectangle() override { }
    
    void set_point(const QPoint& point);

    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

private:
    vector<QPoint> points;

};


#endif // RECTANGLE_H
