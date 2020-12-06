#include "shapelisting.h"
#include "ui_shapelisting.h"

ShapeListing::ShapeListing(QWidget *parent, gp::vector<Shape*> shapeVec) :
    QDialog(parent),
    ui(new Ui::ShapeListing)
{
    ui->setupUi(this);

    // Shapes by ID
    // Sort later
    ui->shapeIDTable->setRowCount(shapeVec.size());
    for(int i = 0; i < shapeVec.size(); ++i) {
        ui->shapeIDTable->setItem(i, 0, new QTableWidgetItem(QString::number(shapeVec[i]->get_shapeID())));
        ui->shapeIDTable->setItem(i, 1, new QTableWidgetItem(getShapeName(shapeVec[i]->get_shape())));
    }

    // copy vector into vectors to sort
    areaVec = shapeVec;
    periVec = shapeVec;

    // sort the vectors
    std::sort(areaVec.begin(), areaVec.end(), compArea);
    std::sort(periVec.begin(), periVec.end(), compPerimeter);

    // populate the area tab
    ui->areaTable->setRowCount(shapeVec.size());
    for(int i = 0; i < shapeVec.size(); ++i) {
        ui->areaTable->setItem(i, 0, new QTableWidgetItem(QString::number(areaVec[i]->area())));
        ui->areaTable->setItem(i, 1, new QTableWidgetItem(getShapeName(areaVec[i]->get_shape())));
    }

    // populate the perimeter tab
    ui->perimeterTable->setRowCount(periVec.size());
    for(int i = 0; i < periVec.size(); ++i) {
        ui->perimeterTable->setItem(i, 0, new QTableWidgetItem(QString::number(periVec[i]->perimeter())));
        ui->perimeterTable->setItem(i, 1, new QTableWidgetItem(getShapeName(periVec[i]->get_shape())));
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

bool compPerimeter(Shape *i, Shape *j) {
    return i->perimeter() < j->perimeter();
}

bool compArea(Shape *i, Shape *j) {
    return i->area() < j->area();
}
