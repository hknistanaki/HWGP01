#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>

class Circle : public Shape
{
public:
public:
    Circle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} {}
    ~Circle() override { }

    void set_point(const QPoint& point);
    void set_radius(const int &r);

    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) const override;

    QPoint id_pos() const override {return center;}

private:
    QPoint center;
    int r;
};

#endif // CIRCLE_H
