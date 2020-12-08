#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    /*!
     * \brief Rectangle
     * \param device QPaintDevice
     * \param id id to assign to Rectangle
     */
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Rectangle} {}

    ~Rectangle() override { }
    
    /*!
     * \brief set_point
     * \param point new rectangle top left point
     */
    void set_point(const QPoint& point);

    /*!
     * \brief set_dimensions
     * \param l new length
     * \param w new width
     */
    void set_dimensions(const int &l, const int &w);

    /*!
     * \brief id_pos
     * \return QPoint position to draw nametag
     */
    QPoint id_pos() const override {return origin;}

    /*!
     * \brief draw draws Rectangle
     * \param device QPaintDevice
     * \param translate_x unused TODO delete
     * \param translate_y unused TODO delete
     */
    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    /*!
     * \brief perimeter
     * \return perimeter of Rectangle 2l+2w
     */
    double perimeter() const override {return (2*l)+(2*w);}

    /*!
     * \brief area
     * \return area of Rectangle lw
     */
    double area() const override {return l*w;}

    /*!
     * \brief get_point
     * \return top left point of Rectangle
     */
    QPoint get_point() const override {return origin;}

private:
    QPoint origin;
    int l;
    int w;

};


#endif // RECTANGLE_H
