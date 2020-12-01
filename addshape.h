#ifndef ADDSHAPE_H
#define ADDSHAPE_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

#include "shapestorage.h"

namespace Ui {
class addShape;
}

class addShape : public QDialog
{
    Q_OBJECT

public:
    explicit addShape(QWidget *parent, const int &shapeCountFromMain, shapeStorage* store);

    void initInput();
    int getShapeCount() const;
    void addShapeToCanvas();

    void addLine();

    ~addShape();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::addShape *ui;

    // points to shape storage in MainWindow
    shapeStorage* localStore;

    int shapeCount; // TEMP, TODO replace with vector later
};

#endif // ADDSHAPE_H
