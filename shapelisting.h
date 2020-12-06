#ifndef SHAPELISTING_H
#define SHAPELISTING_H

#include <QDialog>
#include <QDebug>
#include "vector.h"
#include "Shape.h"

namespace Ui {
class ShapeListing;
}

class ShapeListing : public QDialog
{
    Q_OBJECT

public:
    explicit ShapeListing(QWidget *parent, gp::vector<Shape*> shapeVec);

    QString getShapeName(Shape::ShapeType shape) const;

    ~ShapeListing();

private:
    Ui::ShapeListing *ui;
    gp::vector<Shape*> areaVec;
    gp::vector<Shape*> periVec;

};

bool compPerimeter(Shape* i, Shape* j);

bool compArea(Shape* i, Shape* j);


#endif // SHAPELISTING_H
