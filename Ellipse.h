#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <cmath>

class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} {}
    ~Ellipse() override { }

    void set_point(const QPoint& point);
    void set_dimensions(const int &l, const int &w);

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) const override;

    QPoint id_pos() const override {return center;}

    double perimeter() const override;

    double area() const override;

    QPoint get_point() const override {return center;}

private:
    QPoint center;
    int l;
    int w;
    
};

#endif // ELLIPSE_H
