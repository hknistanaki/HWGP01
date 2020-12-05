#include "shapelisting.h"
#include "ui_shapelisting.h"

ShapeListing::ShapeListing(QWidget *parent, gp::vector<Shape*> shapeVec) :
    QDialog(parent),
    ui(new Ui::ShapeListing)
{
    ui->setupUi(this);

    // Shapes by ID
    // Sort later
    ui->itemTableWidget->setRowCount(shapeVec.size());
    for(int i = 0; i < shapeVec.size(); ++i) {
        ui->itemTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(shapeVec[i]->get_shapeID())));
        ui->itemTableWidget->setItem(i, 1, new QTableWidgetItem(getShapeName(shapeVec[i]->get_shape())));
    }

}

ShapeListing::~ShapeListing()
{
    delete ui;
}

QString ShapeListing::getShapeName(Shape::ShapeType shape) const
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
