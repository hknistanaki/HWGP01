#ifndef ADDSHAPE_H
#define ADDSHAPE_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

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
class addShape;
}

class addShape : public QDialog
{
    Q_OBJECT

public:

    /*!
     * \brief addShape
     * \param parent parent object
     * \param shapeCountFromMain amount of shapes in the vector
     */
    addShape(QWidget *parent, const int &shapeCountFromMain);

    /*!
     * \brief getNewShape
     * \return shape created during execution of addShape obj window
     */
    Shape* getNewShape() const;

    ~addShape();

private slots:

    /*!
     * \brief on_buttonBox_accepted prompts the user to confirm adding a shape to the canvas
     */
    void on_buttonBox_accepted();

private:

    /*!
     * \brief getShapeCount
     * \return shape count after completing the execution of an addShape object
     */
    int getShapeCount() const;

    /*!
     * \brief addShapeToCanvas adds a shape to the internal vector based on parameters from the window
     */
    void addShapeToCanvas();

    /*!
     * \brief addLine creates a Line object based on the window's input data
     */
    void addLine();

    /*!
     * \brief addPolyline creates a Polyline object based on the window's input data
     */
    void addPolyline();

    /*!
     * \brief addPolygon creates a Polygon object based on the window's input data
     */
    void addPolygon();

    /*!
     * \brief addRectangle creates a Rectangle object based on the window's input data
     */
    void addRectangle();

    /*!
     * \brief addSquare creates a Square object based on the window's input data
     */
    void addSquare();

    /*!
     * \brief addEllipse creates an Ellipse object based on the window's input data
     */
    void addEllipse();

    /*!
     * \brief addCircle creates a Circle object based on the window's input data
     */
    void addCircle();

    /*!
     * \brief addText creates a Text object based on the window's input data
     */
    void addText();

    /*!
     * \brief getStringColor
     * \return Qt::GlobalColor value based on a corresponding string from ui->fontColorComboBox
     */
    Qt::GlobalColor getStringColor();

    /*!
     * \brief getStringFlag
     * \return Qt::AlignmentFlag value based on a corresponding string from ui->fontAlignmentComboBox
     */
    Qt::AlignmentFlag getStringFlag();

    /*!
     * \brief getTextFontFamily
     * \return QString that contains a font family name
     */
    QString getTextFontFamily();

    /*!
     * \brief getBrushColor
     * \return Qt::GlobalColor value based on input data (brush)
     */
    Qt::GlobalColor getBrushColor();

    /*!
     * \brief getShapeType
     * \param shape QString value that corresponds to a Shape::ShapeType enum value
     * \return
     */
    Shape::ShapeType getShapeType(QString shape);

    /*!
     * \brief getColor
     * \return Qt::Global color value based on input data
     */
    Qt::GlobalColor getColor();

    /*!
     * \brief getFontColor
     * \return Qt::GlobalColor value based on input data (text)
     */
    Qt::GlobalColor getFontColor();

    /*!
     * \brief getPenCapStyle
     * \return Qt::PenCapStyle enum value
     */
    Qt::PenCapStyle   getPenCapStyle();

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

    /*!
     * \brief getFontStyle
     * \return QFont::Style enum value
     */
    QFont::Style getFontStyle();

    /*!
     * \brief getFontWeight
     * \return QFont::Weight enum value
     */
    QFont::Weight getFontWeight();

    Ui::addShape *ui;

    Shape* newShape;

    int addingShapeID;
};

#endif // ADDSHAPE_H
