#include "addshape.h"
#include "ui_addshape.h"

#include "Line.h"

addShape::addShape(QWidget *parent, const int &shapeCountFromMain, shapeStorage* store) :
    QDialog(parent),
    ui(new Ui::addShape),
    localStore{store},
    shapeCount {shapeCountFromMain}
{
    ui->setupUi(this);
    ui->idLineEdit->setText(QString::number(shapeCount+1));
}

/*!
 * \brief addShape::~addShape
 * deletes ui
 */
addShape::~addShape()
{
    delete ui;
}

/*!
 * \brief addShape::initInput
 * Initializes all of the input boxes to be disabled when window is first opened.
 */
void addShape::initInput() {

}

/*!
 * \brief addShape::getShapeCount
 * \return shapeCount number of shapes after adding a shape
 */
int addShape::getShapeCount() const {
    return localStore->shapes.size();
}

/*!
 * \brief addShape::on_buttonBox_accepted
 * adds the described shape
 */
void addShape::on_buttonBox_accepted()
{
    QMessageBox msgBox;
    msgBox.setText("Shape has been created.");
    msgBox.setInformativeText("Are you sure you want to add it to the canvas?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Save:
        addShapeToCanvas(); // extract input data and add it to shape vector
        break;
    case QMessageBox::Discard:
        // Don't add shape
        break;
    default:
        // should never be reached
        break;
    }
}

/*!
 * \brief addShape::addShapeToCanvas
 * adds a shape from input data
 */
void addShape::addShapeToCanvas() {
    switch(ui->shapeTypeComboBox->currentIndex()){
    case 0:
        // adding Line
        addLine();
        break;
    case 1:
        // adding polyLine
        break;
    case 2:
        // adding polygon
        break;
    case 3:
        // adding rectangle
        break;
    case 4:
        // adding ellipse
        break;
    case 5:
        // adding circle
        break;
    case 6:
        // adding text;
        break;
    default:
        // should never be reached
        break;
    }
}

void addShape::addLine()
{
    QPoint tempPoint {ui->posX->value(), ui->posY->value()};
    QPen tempPen;
    QBrush tempBrush;

    tempPen.setWidth(ui->penWidthSpinBox->value());
//    tempPen.setColor();
//    tempPen.setStyle();
//    tempPen.setCapStyle();
//    tempPen.setJoinStyle();

}
