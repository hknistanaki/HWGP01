#ifndef CIRCLE_H
#define CIRCLE_H

#include <Shape.h>

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

    /*!
     * \brief perimeter
     * \return 2r * 3.14
     */
    double perimeter() const override {return (r*2)*3.14;}

    /*!
     * \brief area
     * \return 3.14 * r^2
     */
    double area() const override {return (3.14*(r*r));}

private:
    QPoint center;
    int r;
};

#endif // CIRCLE_H
