#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"

class Text : public Shape
{
public:
    Text(QPaintDevice * device = nullptr, int id = -1) : Shape{device, id, ShapeType::Text} { }
    ~Text() override { }

    void set_point(const QPoint& point);

    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

private:
    vector<QPoint> points;

};

#endif // TEXT_H
