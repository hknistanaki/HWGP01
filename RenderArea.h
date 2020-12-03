#ifndef RenderArea_H
#define RenderArea_H

#include <QFile>
#include <QTextStream>
#include "Shape.h"
#include "vector.h"
#include <QPaintEvent>
#include <QWidget>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>

class RenderArea : public QWidget
{
    public:
        RenderArea(QWidget *parent = nullptr);

        void paintEvent(QPaintEvent *event) override; 
        QSize sizeHint() const override;
        QSize minimumSizeHint() const override;

        const gp::vector<Shape*>& getShapes();

        void addShape(Shape* shapeIn);

        int getSize();
        int getnumShapesRA();

        void chopShape(int indexRemove);//Shape remove
        void moveShape(int indexMove, int coordMove, int x, int y);

   private:
        const QImage renderArea;
        gp::vector<Shape*> ShapeMagazine;
        int numShapesRA;

        void readShapeFile();

        QString getStringColor(QColor color);
        QString getStringPenCap(Qt::PenCapStyle penCapStyle);
        QString getStringPenStyle(Qt::PenStyle penStyle);
        QString getStringPenJointStyle(Qt::PenJoinStyle penJointStyle);
        QString getStringBrush(Qt::BrushStyle brush);
        QString getStringFlag(Qt::AlignmentFlag  flag);
        QString getStringFontStyle(QFont::Style fontStyle);
        QString getStringFontWeight(int fontWeight);

        Shape::ShapeType  getShapeType(QString shape);
        Qt::GlobalColor   getColor(QString color);
        Qt::PenCapStyle   getPenCapStyle(QString cap);
        Qt::PenStyle      getPenStyle(QString pen);
        Qt::PenJoinStyle  getPenJointStyle(QString penJoint);
        Qt::BrushStyle    getBrushStyle(QString brushStyle);
        Qt::AlignmentFlag getFlag(QString flag);
        QFont::Style      getFontStyle(QString fontStyle);
        QFont::Weight     getFontWeight(QString fontWeight);
};


#endif
