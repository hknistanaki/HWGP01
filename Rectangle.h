#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Rectangle} {}
    ~Rectangle() override { }
    
    void set_point(const QPoint& point);
    void set_dimensions(const int &l, const int &w);

    QPoint id_pos() const override {return origin;}

    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    double perimeter() const override {return (2*l)+(2*w);}

    double area() const override {return l*w;}

private:
    QPoint origin;
    int l;
    int w;

};


#endif // RECTANGLE_H
