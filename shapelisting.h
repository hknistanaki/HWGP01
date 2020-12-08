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

/*!
 * \brief compPerimeter predicate, compares perimeters of Shape
 * \param i Shape*
 * \param j Shape*
 * \return true if i's perimeter is greater than j's perimeter
 */
bool compPerimeter(Shape* i, Shape* j);

/*!
 * \brief compArea predicate, compares area of Shape
 * \param i Shape*
 * \param j Shape*
 * \return true if i's area is greater than j's area
 */
bool compArea(Shape* i, Shape* j);


#endif // SHAPELISTING_H
