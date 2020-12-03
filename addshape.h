#ifndef ADDSHAPE_H
#define ADDSHAPE_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

#include "vector.h"
#include <Shape.h>

namespace Ui {
class addShape;
}

class addShape : public QDialog
{
    Q_OBJECT

public:
    addShape(QWidget *parent, const int &shapeCountFromMain);

    int getShapeCount() const;
    void addShapeToCanvas();

    void addLine();
    void addPolyline();

    Shape* getNewShape() const;

    ~addShape();

private slots:

    void on_buttonBox_accepted();

private:

    // These functions NOT the same as in RenderArea

    QString getStringColor(QColor color);
    QString getStringPenCap(Qt::PenCapStyle penCapStyle);
    QString getStringPenStyle(Qt::PenStyle penStyle);
    QString getStringPenJointStyle(Qt::PenJoinStyle penJointStyle);
    QString getStringBrush(Qt::BrushStyle brush);
    QString getStringFlag(Qt::AlignmentFlag  flag);
    QString getStringFontStyle(QFont::Style fontStyle);
    QString getStringFontWeight(int fontWeight);

    Shape::ShapeType  getShapeType(QString shape);
    Qt::GlobalColor   getColor();

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

    Qt::AlignmentFlag getFlag(QString flag);
    QFont::Style      getFontStyle(QString fontStyle);
    QFont::Weight     getFontWeight(QString fontWeight);

    /*!
     * \brief ui
     */
    Ui::addShape *ui;

    /*!
     * \brief newShape ptr to new shape created, nullptr if no shape created.
     */
    Shape* newShape;

    int addingShapeID;
};

#endif // ADDSHAPE_H
