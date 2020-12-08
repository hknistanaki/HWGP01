#ifndef SQUARE_H
#define SQUARE_H

#include <Shape.h>

class Square : public Shape
{
public:
    /*!
     * \brief Square
     * \param device QPaintDevice
     * \param id id to assign to Square
     */
    Square(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Square} {}

    ~Square() override { }

    /*!
     * \brief set_point
     * \param point new top left point of Square
     */
    void set_point(const QPoint& point);

    /*!
     * \brief set_dimension
     * \param w new width/length of Square
     */
    void set_dimension(const int &w);

    /*!
     * \brief id_pos
     * \return QPoint position to draw nametag
     */
    QPoint id_pos() const override {return origin;}

    /*!
     * \brief draw draws the Square
     * \param device QPaintDevice
     * \param translate_x unused TODO delete
     * \param translate_y unused TODO delete
     */
    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    /*!
     * \brief perimeter
     * \return perimeter of Square 4w
     */
    double perimeter() const override {return 4*w;}

    /*!
     * \brief area
     * \return area of square w^2
     */
    double area() const override {return w*w;}

    /*!
     * \brief get_point
     * \return top left point of rectangle
     */
    QPoint get_point() const override {return origin;}

private:
    QPoint origin;
    int w;
};

#endif // SQUARE_H
