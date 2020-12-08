#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    Line(const QPoint& A = {}, const QPoint& B = {}, const QPen &pen = {}, int id = 0);
    ~Line() override;

    void set_points(const QPoint& point_begin, const QPoint& point_end);

    void draw(QPaintDevice* device, const int translate_x, const int translate_y) const override;

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

    QPoint get_point() const override {return point_begin;}

private:
    QPoint point_begin;
    QPoint point_end;

};

#endif // LINE_H
