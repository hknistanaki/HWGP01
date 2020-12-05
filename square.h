#ifndef SQUARE_H
#define SQUARE_H

#include <Shape.h>

class Square : public Shape
{
public:
    Square(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Rectangle} {}
    ~Square() override { }

    void set_point(const QPoint& point);
    void set_dimension(const int &w);

    QPoint id_pos() const override {return origin;}

    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    double perimeter() const override {return 4*w;}

    double area() const override {return w*w;}

private:
    QPoint origin;
    int w;
};

#endif // SQUARE_H
