#ifndef CIRCLE_H
#define CIRCLE_H

#include <Shape.h>

class Circle : public Shape
{
public:
    /*!
     * \brief Circle Circle constructor
     * \param device QPaintDevice
     * \param id id to assign to shape
     */
    Circle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Circle} {}

    ~Circle() override { }

    /*!
     * \brief set_point sets the Circle's center
     * \param point QPoint value holding the circle's center point
     */
    void set_point(const QPoint& point);

    /*!
     * \brief set_radius
     * \param r new radius for circle
     */
    void set_radius(const int &r);

    /*!
     * \brief draw draws the circle
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
     * \return 2r * 3.14
     */
    double perimeter() const override {return (r*2)*3.14;}

    /*!
     * \brief area
     * \return 3.14 * r^2
     */
    double area() const override {return (3.14*(r*r));}

    /*!
     * \brief get_point
     * \return circle's center point
     */
    QPoint get_point() const override {return center;}

private:
    QPoint center;
    int r;
};

#endif // CIRCLE_H
