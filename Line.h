#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    /*!
     * \brief Line
     * \param A QPoint of first point
     * \param B QPoint of second point
     * \param id int id to assign to Line
     */
    Line(const QPoint& A = {}, const QPoint& B = {}, const QPen &pen = {}, int id = 0);

    ~Line() override;

    /*!
     * \brief set_points
     * \param point_begin new beginning point
     * \param point_end new end point
     */
    void set_points(const QPoint& point_begin, const QPoint& point_end);

    /*!
     * \brief draw draws Line obj
     * \param device QPaintDevice ptr
     * \param translate_x unused TODO delete
     * \param translate_y unused TODO delete
     */
    void draw(QPaintDevice* device, const int translate_x, const int translate_y) const override;

    /*!
     * \brief id_pos
     * \return position to draw nametag
     */
    QPoint id_pos() const override;

    /*!
     * \brief perimeter
     * \return 0 (line does not have a perimeter)
     */
    double perimeter() const override {return 0;}

    /*!
     * \brief area
     * \return 0 (line does not have an area)
     */
    double area() const override {return 0;}

    /*!
     * \brief get_point
     * \return first point of line
     */
    QPoint get_point() const override {return point_begin;}

private:
    QPoint point_begin;
    QPoint point_end;

};

#endif // LINE_H
