#include "Shape.h"
#include "vector.h"

#ifndef POLYLINE_H
#define POLYLINE_H

class Polyline : public Shape
{
public:
    /*!
     * \brief Polyline
     * \param device QPaintDevice
     * \param id id to assign to shape
     */
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}

    ~Polyline() override { }
    
    /*!
     * \brief set_point
     * \param point to add to points vector
     */
    void set_point(const QPoint& point);

    /*!
     * \brief set_points replaces points vector with a new one
     * \param newPoints
     */
    void set_points(const gp::vector<QPoint> &newPoints);

    /*!
     * \brief draw draws the Polyline
     * \param device QPaintDevice
     * \param translate_x unused TODO delete
     * \param translate_y unused TODO delete
     */
    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    /*!
     * \brief id_pos
     * \return QPoint location to draw nametag
     */
    QPoint id_pos() const override;

    /*!
     * \brief perimeter
     * \return 0 (not applicable)
     */
    double perimeter() const override {return 0;}

    /*!
     * \brief area
     * \return 0 (not applicable)
     */
    double area() const override {return 0;}

    /*!
     * \brief get_point
     * \return first point of Polyline
     */
    QPoint get_point() const override {return points[0];}


private:

    gp::vector<QPoint> points;
};

#endif
