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
    /*!
     * \brief on_shapesComboBox_currentIndexChanged handles shapesComboBox changing index
     * \param index new index of shapesTypeComboBox
     */
    void on_shapesComboBox_currentIndexChanged(int index);

    /*!
     * \brief on_buttonBox_accepted handles OK button
     */
    void on_buttonBox_accepted();

    /*!
     * \brief on_addPointPushButton_clicked handles Add Point button
     */
    void on_addPointPushButton_clicked();

private:
    typedef Shape::ShapeType sType;

    /*!
     * \brief populateFields populates existing data TODO (probably won't have time to implement)
     * \param shape Shape ptr
     */
    void populateFields(Shape* shape) const;

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

    /*!
     * \brief addShapeToCanvas adds shape to vector
     */
    void addShapeToCanvas();

    /*!
     * \brief addLine creates Line from input data
     */
    void addLine();

    /*!
     * \brief addPolyline creates Polyline from input data
     */
    void addPolyline();

    /*!
     * \brief addPolygon creates Polygon from input data
     */
    void addPolygon();

    /*!
     * \brief addRectangle creates rectangle from input data
     */
    void addRectangle();

    /*!
     * \brief addSquare creates Square from input data
     */
    void addSquare();

    /*!
     * \brief addEllipse creates Ellipse from input data
     */
    void addEllipse();

    /*!
     * \brief addCircle creates Circle from input data
     */
    void addCircle();

    /*!
     * \brief addText creates Text from input data
     */
    void addText();

    /*!
     * \brief getStringColor
     * \return Qt:GlobalColor converted from QString input value
     */
    Qt::GlobalColor getStringColor();

    /*!
     * \brief getStringFlag
     * \return Qt::AlignmentFlag converted from input data
     */
    Qt::AlignmentFlag getStringFlag();

    /*!
     * \brief getTextFontFamily
     * \return QString font family converted from input data
     */
    QString getTextFontFamily();

    /*!
     * \brief getBrushColor
     * \return Qt::GlobalColor converted from input data
     */
    Qt::GlobalColor getBrushColor();

    /*!
     * \brief getColor
     * \return Qt::GlobalColor converted from input data
     */
    Qt::GlobalColor getColor();

    /*!
     * \brief getFontColor
     * \return Qt::GlobalColor converted from input data (text)
     */
    Qt::GlobalColor getFontColor();

    /*!
     * \brief getPenCapStyle
     * \return Qt::PenCapStyle enum value
     */
    Qt::PenCapStyle getPenCapStyle();

    /*!
     * \brief getPenStyle
     * \return Qt::PenStyle enum value
     */
    Qt::PenStyle getPenStyle();

    /*!
     * \brief getPenJointStyle
     * \return Qt::PenJoinStyle enum value
     */
    Qt::PenJoinStyle getPenJointStyle();

    /*!
     * \brief getBrushStyle
     * \return Qt::BrushStyle enum value
     */
    Qt::BrushStyle getBrushStyle();

    /*!
     * \brief getFontStyle
     * \return QFont::Style converted from input data
     */
    QFont::Style getFontStyle();

    /*!
     * \brief getFontWeight
     * \return QFont::Weight converted from input data
     */
    QFont::Weight getFontWeight();

    Shape* modShape;
    int indexModShape;

    Ui::ModifyShapes *ui;

    gp::vector<Shape*> localVec;

    gp::vector<QPoint> pointsVec;
};

#endif // MODIFYSHAPES_H
