#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <cmath>
#include "vector.h"

class Polygon : public Shape
{
public:
    /*!
     * \brief Polygon
     * \param device QPaintDevice
     * \param id id to assign to Polygon
     */
    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polygon} {}
    ~Polygon() override { }

    /*!
     * \brief set_point
     * \param point new point to add to points
     */
    void set_point(const QPoint& point);

    /*!
     * \brief set_points replace vector of points with a new one
     * \param newPointsVec vector of new points to set
     */
    void set_points(const gp::vector<QPoint> &newPointsVec);

    /*!
     * \brief draw draws the Polygon
     * \param device QPaintDevice
     * \param translate_x unused TODO delete
     * \param translate_y unused TODO delete
     */
    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    /*!
     * \brief id_pos
     * \return QPoint location of nametag
     */
    QPoint id_pos() const override;

    /*!
     * \brief perimeter
     * \return double perimeter of Polygon
     */
    double perimeter() const override;

    /*!
     * \brief area
     * \return area of Polygon using String Theorem. accuracy not guaranteed.
     */
    double area() const override;

    /*!
     * \brief get_point
     * \return first point of polygon
     */
    QPoint get_point() const override {return points[0];}

private:
    gp::vector<QPoint> points;
};

#endif // POLYGON_H
