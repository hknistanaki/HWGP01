#include "deleteshape.h"
#include "ui_deleteshape.h"
#include <QMessageBox>
#include <QDebug>

deleteshape::deleteshape(QWidget *parent, const int &shapeCountFromMain, const gp::vector<Shape*> &shapeVec) :
    QDialog(parent),
    ui(new Ui::deleteshape),
    shapeCount {shapeCountFromMain}
{
    QString temp;
    ui->setupUi(this);
    toDelete = -1;

    // parse shape vector into combo box
    for(gp::vector<Shape*>::const_iterator it = shapeVec.begin(); it != shapeVec.end(); ++it) {
        QString nameTag = (*it)->nameTag(getShapeName((*it)->get_shape()));

        ui->shapeIDcomboBox->addItem(nameTag);
    }

}

deleteshape::~deleteshape()
{
    delete ui;
}

QString deleteshape::getShapeName(Shape::ShapeType shape) const
{
    typedef Shape::ShapeType sType;

    switch(shape) {
    case sType::NoShape:
        return "NoShape";
        break;
    case sType::Line:
        return "Line";
        break;
    case sType::Polyline:
        return "Polyline";
        break;
    case sType::Polygon:
        return "Polygon";
        break;
    case sType::Square:
        return "Square";
        break;
    case sType::Rectangle:
        return "Rectangle";
        break;
    case sType::Circle:
        return "Circle";
        break;
    case sType::Ellipse:
        return "Ellipse";
        break;
    case sType::Text:
        return "Text";
        break;
    default:
        return "NoShape";
    }

}

void deleteshape::on_buttonBox_accepted()
{
    QMessageBox msgBox(this);
    msgBox.setText("The canvas has been modified.");
    msgBox.setInformativeText(("Are you sure you want to delete\n" + ui->shapeIDcomboBox->currentText() + "?"));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
    msgBox.setDefaultButton(QMessageBox::Save);
    int choice = msgBox.exec();

    switch (choice) {
      case QMessageBox::Save:
        // delete shape from vector
        toDelete = ui->shapeIDcomboBox->currentIndex();
        break;
      case QMessageBox::Discard:
        qDebug() << "DBG: Shape has NOT been deleted.";
        break;
      default:
        qDebug() << "ERR: Default case in deleteshape::on_buttonBox_accepted";
        break;
    }

}
