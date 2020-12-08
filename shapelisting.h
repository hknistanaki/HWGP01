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

    /*!
     * \brief getShapeName
     * \param shape Shape::ShapeType enum value
     * \return QString value corresponding to ShapeType enum value
     */
    QString getShapeName(Shape::ShapeType shape) const;

    ~ShapeListing();

private:
    Ui::ShapeListing *ui;
    gp::vector<Shape*> areaVec;
    gp::vector<Shape*> periVec;

};

// used with std::sort
bool compPerimeter(Shape* i, Shape* j);

bool compArea(Shape* i, Shape* j);


#endif // SHAPELISTING_H
