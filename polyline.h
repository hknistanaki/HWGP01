#include "Shape.h"

#ifndef POLYLINE_H
#define POLYLINE_H

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}
    ~Polyline() override { }
    
    void set_point(const QPoint& point);

    void draw(QPaintDevice *device, const int translate_x = 0, const int translate_y = 0) const override;

    QPoint id_pos() const override;


private:

    vector<QPoint> points;

    QString shapeName = "Polyline";
};

#endif
