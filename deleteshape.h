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
    deleteshape(QWidget *parent, const int &shapeCountFromMain, const gp::vector<Shape*> &shapeVec);
    ~deleteshape();

    /*!
     * \brief getShapeCount
     * \return shapeCount
     */
    int getShapeCount() {return shapeCount;};

    int getToDelete() {return toDelete;}

    QString getShapeName(Shape::ShapeType shape) const;


private slots:
    void on_buttonBox_accepted();

private:
    Ui::deleteshape *ui;

    int toDelete;

    int shapeCount;
};

#endif // DELETESHAPE_H
