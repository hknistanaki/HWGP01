#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <cmath>

class Ellipse : public Shape
{
public:
    /*!
     * \brief Ellipse
     * \param device QPaintDevice
     * \param id id to assign to Ellipse obj
     */
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} {}

    ~Ellipse() override { }

    /*!
     * \brief set_point
     * \param point new center point for ellipse
     */
    void set_point(const QPoint& point);

    /*!
     * \brief set_dimensions
     * \param l new semi minor axis
     * \param w new semi major axis
     */
    void set_dimensions(const int &l, const int &w);

    /*!
     * \brief draw
     * \param device QPaintDevice
     * \param translate_x unused TODO remove
     * \param translate_y unused TODO remove
     */
    void draw(QPaintDevice* device, const int translate_x = 0, const int translate_y = 0) const override;

    /*!
     * \brief id_pos
     * \return position to draw nametag
     */
    QPoint id_pos() const override {return center;}

    /*!
     * \brief perimeter
     * \return perimeter of Ellipse
     *  note: unsure if this is accurate, math is hard :(
     */
    double perimeter() const override;

    /*!
     * \brief area
     * \return area of ellipse (math hard)
     */
    double area() const override;

    /*!
     * \brief get_point
     * \return QPoint center of Ellipse
     */
    QPoint get_point() const override {return center;}

private:
    QPoint center;
    int l; // semi minor
    int w; // semi major
    
};

#endif // ELLIPSE_H
