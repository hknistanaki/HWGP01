#ifndef DELETESHAPE_H
#define DELETESHAPE_H

#include <QDialog>
#include "vector.h"
#include "Shape.h"

namespace Ui {
class deleteshape;
}

class deleteshape : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief deleteshape ctor
     * \param parent QWidget parent ptr
     * \param shapeCountFromMain shape count number from renderarea
     * \param shapeVec const reference to vector of shapes from renderarea
     */
    deleteshape(QWidget *parent, const int &shapeCountFromMain, const gp::vector<Shape*> &shapeVec);

    ~deleteshape();

    /*!
     * \brief getShapeCount
     * \return shapeCount
     */
    int getShapeCount() {return shapeCount;};

    /*!
     * \brief getToDelete
     * \return int index of shape to delete
     */
    int getToDelete() {return toDelete;}

    /*!
     * \brief getShapeName
     * \param shape Shape::ShapeType enum value
     * \return QString corresponding to ShapeType enum value
     */
    QString getShapeName(Shape::ShapeType shape) const;


private slots:
    /*!
     * \brief on_buttonBox_accepted handles OK button
     */
    void on_buttonBox_accepted();

private:
    Ui::deleteshape *ui;

    int toDelete;

    int shapeCount;
};

#endif // DELETESHAPE_H
