#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} {}
    ~Ellipse() override { }

    void set_point(const QPoint& point);

    void draw(const int translate_x = 0, const int translate_y = 0) override;    

private:
    vector<QPoint> points;
    
};

#endif // ELLIPSE_H
