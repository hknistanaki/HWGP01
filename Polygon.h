#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <cmath>
#include "vector.h"

class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polygon} {}
    ~Polygon() override { }

    void set_point(const QPoint& point);

    /*!
     * \brief set_points replace vector of points with a new one
     * \param newPointsVec vector of new points to set
     */
    void set_points(const gp::vector<QPoint> &newPointsVec);

    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    QPoint id_pos() const override;

    double perimeter() const override;

    double area() const override;

    QPoint get_point() const override {return points[0];}

private:
    gp::vector<QPoint> points;
};

#endif // POLYGON_H
