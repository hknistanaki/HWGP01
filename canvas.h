#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

#include "vector.h"
#include "Shape.h"
#include "shapestorage.h"

class canvas : public QWidget
{
    Q_OBJECT
public:
    canvas(QWidget *parent, shapeStorage* store);

    int getShapeCount()const;

    void setStorage(shapeStorage* store);
protected:
    /**
     * @brief paintEvent
     * @param event
     */
    void paintEvent(QPaintEvent *event) override;

private:
    /*!
     * \brief localStore points to the storage struct in MainWindow
     */
    shapeStorage* localStore;
};

#endif // CANVAS_H
