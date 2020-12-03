#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    Line(const QPoint& A = {}, const QPoint& B = {}, const QBrush &brush = {}, const QPen &pen = {}, int id = 0);
    ~Line() override;

    void set_points(const QPoint& point_begin, const QPoint& point_end);

    void draw(QPaintDevice* device, const int translate_x, const int translate_y) const override;

    QPoint id_pos() const;

private:
    QPoint point_begin;
    QPoint point_end;

};

#endif // LINE_H
