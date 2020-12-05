#include "Shape.h"
#include "Polygon.h"

void Polygon::set_point(const QPoint& point)
{
    points.push_back(point);
}

void Polygon::draw(QPaintDevice *device, const int translate_x, const int translate_y) const
{
    auto paint = getPainter(device);

    QPoint temp = id_pos();
    temp.setY(temp.y() - 5);

    paint->setPen(Qt::black);
    paint->drawText(temp.x(), temp.y(), nameTag("Polygon"));

    paint->setPen(get_pen());
    paint->setBrush(get_brush());

    paint->save();
    paint->translate(translate_x, translate_y);

    paint->drawPolygon(&points[0], points.size());

    paint->restore();
}

QPoint Polygon::id_pos() const
{
    int x;
    int y;
    int highestVal = points[0].y();
    int highestIndex = 0;


    // Determine where to draw the id string
    for(int i = 0; i < points.size(); ++i) {

        if(points[i].y() < highestVal){
            highestVal = points[i].y();
            highestIndex = i;
        }
    }

    x = points[highestIndex].x();
    y = points[highestIndex].y();

    return(QPoint(x,y));
}

double Polygon::perimeter() const
{
    double perimeter = 0;
    double temp = 0;

        for (auto it = points.begin(); it != points.end(); ++it) {
           // find the distance between two points
            QPoint begin = *it;
            QPoint end = *(it+1);
            temp = 0;

            temp = (end.x() - begin.x()) * (end.x() - begin.x()) + (end.y() - begin.y()) * (end.y() - begin.y());
            perimeter += std::sqrt(temp);

        }
        // find the distance between the last point and the first point
        QPoint begin = *(points.end()-1);
        QPoint end = *(points.begin());
        temp = 0;

        temp = (end.x() - begin.x()) * (end.x() - begin.x()) + (end.y() - begin.y()) * (end.y() - begin.y());
        perimeter += std::sqrt(temp);


        return perimeter;
}

double Polygon::area() const
{
    // from https://brilliant.org/wiki/irregular-polygons/#area-coordinate-geometry
    double area = 0;

    for (auto it = points.begin(); it != points.end(); ++it) {
        const QPoint &start = *it;
        const QPoint &end = (it+1 != points.end() ? *(it+1) : points.front());
        area += (start.x() * end.y()) - (start.y() * end.x());
    }

    return area / 2;
}
