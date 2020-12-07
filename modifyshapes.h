#ifndef MODIFYSHAPES_H
#define MODIFYSHAPES_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

#include "vector.h"
#include "Shape.h"
#include "Line.h"
#include "circle.h"
#include "Polygon.h"
#include "polyline.h"
#include "Rectangle.h"
#include "square.h"
#include "Ellipse.h"
#include "Text.h"


namespace Ui {
class ModifyShapes;
}

class ModifyShapes : public QDialog
{
    Q_OBJECT

public:
    ModifyShapes(QWidget *parent, gp::vector<Shape*> shapeVec);
    ~ModifyShapes();

    /*!
     * \brief getModShape
     * \return modified shape created in this class
     */
    Shape* getModShape() const {return modShape;}

    /*!
     * \brief getModIndex
     * \return index of shape to modify in array
     */
    int getModIndex() const {return indexModShape;}


private slots:
    void on_shapesComboBox_currentIndexChanged(int index);

    void on_buttonBox_accepted();

private:
    typedef Shape::ShapeType sType;

    /*!
     * \brief getShapeName
     * \param shape Shape::ShapeType enum value
     * \return QString corresponding to ShapeType value (ex ShapeType::Circle returns "Circle")
     */
    QString getShapeName(Shape::ShapeType shape) const;

    /*!
     * \brief disableAll disables all fields
     */
    void disableAll() const;

    /*!
     * \brief enableShape enables fields in the parameter tabs available to shape
     * \param shape Shape::ShapeType enum value
     */
    void enableAll(Shape::ShapeType shape) const;

    void addShapeToCanvas();

    void addLine();
    void addPolyline();
    void addPolygon();
    void addRectangle();
    void addSquare();
    void addEllipse();
    void addCircle();
    void addText();

    Qt::GlobalColor getStringColor();
    Qt::AlignmentFlag getStringFlag();
    QString getTextFontFamily();
    Qt::GlobalColor getBrushColor();

    Shape::ShapeType  getShapeType(QString shape);
    Qt::GlobalColor   getColor();
    Qt::GlobalColor getFontColor();

    /*!
     * \brief getPenCapStyle
     * \return Qt::PenCapStyle enum value
     */
    Qt::PenCapStyle   getPenCapStyle();

    /*!
     * \brief getPenStyle (no param, pulls from ui element)
     * \return
     */

    /*!
     * \brief getPenStyle
     * \return Qt::PenStyle enum value
     */
    Qt::PenStyle      getPenStyle();

    /*!
     * \brief getPenJointStyle
     * \return Qt::PenJoinStyle enum value
     */
    Qt::PenJoinStyle  getPenJointStyle();

    /*!
     * \brief getBrushStyle
     * \return Qt::BrushStyle enum value
     */
    Qt::BrushStyle    getBrushStyle();

    QFont::Style      getFontStyle();
    QFont::Weight     getFontWeight();

    Shape* modShape;
    int indexModShape;

    Ui::ModifyShapes *ui;

    gp::vector<Shape*> localVec;
};

#endif // MODIFYSHAPES_H
