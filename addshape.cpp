#include "addshape.h"
#include "ui_addshape.h"

 #include "Line.h"
 //#include "circle.h"
 #include "Polygon.h"
 #include "polyline.h"
 #include "Rectangle.h"
 //#include "square.h"
 #include "Ellipse.h"
 #include "Text.h"

addShape::addShape(QWidget *parent, const int &shapeCountFromMain) :
    QDialog(parent),
    ui(new Ui::addShape),
    newShape {nullptr},
    addingShapeID{shapeCountFromMain+1}
{
    ui->setupUi(this);
    ui->idLineEdit->setText(QString::number(shapeCountFromMain+1));
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
 * create a shape from input data
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
    auto temp = new Line();
    temp->set_shapeID(addingShapeID);

    // Set points, line is 150 px long by default
    temp->set_points(QPoint{ui->posXSpinBox->value(), ui->posYSpinBox->value()}, QPoint{ui->posXSpinBox->value()+150, ui->posYSpinBox->value()});

    // Set pen with values from UI elements
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // Set brush (Not applicable)
    // temp->set_brush(Qt::blue, Qt::BrushStyle::HorPattern);

    newShape = temp;
    temp = nullptr;
}

void addShape::addPolyline()
{
    auto temp = new Polyline();
    temp->set_shapeID(addingShapeID);
    // add two points initially
    temp->set_point(QPoint{ui->posXSpinBox->value(), ui->posYSpinBox->value()});
    temp->set_point(QPoint{ui->posXSpinBox->value()+150, ui->posYSpinBox->value()});

    // Set pen with values from UI elements
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // Set brush (Not applicable)
    // temp->set_brush(Qt::blue, Qt::BrushStyle::HorPattern);

    newShape = temp;
    temp = nullptr;
}

Shape* addShape::getNewShape() const
{
    return newShape;
}

Qt::GlobalColor addShape::getColor()
{
    switch(ui->penColorComboBox->currentIndex()) {
    case 0:
        return Qt::GlobalColor::white;
        break;
    case 1:
        return Qt::GlobalColor::black;
        break;
    case 2:
        return Qt::GlobalColor::red;
        break;
    case 3:
        return Qt::GlobalColor::green;
        break;
    case 4:
        return Qt::GlobalColor::blue;
        break;
    case 5:
        return Qt::GlobalColor::cyan;
        break;
    case 6:
        return Qt::GlobalColor::magenta;
        break;
    case 7:
        return Qt::GlobalColor::yellow;
        break;
    case 8:
        return Qt::GlobalColor::gray;
        break;
    default:
        return Qt::GlobalColor::gray;
    }
}

Qt::PenCapStyle addShape::getPenCapStyle()
{

    switch(ui->capStyleComboBox->currentIndex()) {
    case 0:
        return Qt::PenCapStyle::FlatCap;
        break;
    case 1:
        return Qt::PenCapStyle::SquareCap;
        break;
    case 3:
        return Qt::PenCapStyle::RoundCap;
        break;
    default:
        return Qt::PenCapStyle::FlatCap;

    }
}

Qt::PenStyle addShape::getPenStyle()
{
    switch(ui->penStyleComboBox->currentIndex()) {
    case 0:
        return Qt::NoPen;
        break;
    case 1:
        return Qt::SolidLine;
        break;
    case 2:
        return Qt::DashLine;
        break;
    case 3:
        return Qt::DotLine;
        break;
    case 4:
        return Qt::DashDotLine;
        break;
    case 5:
        return Qt::DashDotDotLine;
        break;
    default:
        return Qt::NoPen;
        break;
    }
}

Qt::PenJoinStyle addShape::getPenJointStyle()
{
    switch(ui->joinStyleComboBox->currentIndex()) {
    case 0:
        return Qt::PenJoinStyle::MiterJoin;
        break;
    case 1:
        return Qt::PenJoinStyle::BevelJoin;
        break;
    case 2:
        return Qt::PenJoinStyle::RoundJoin;
        break;
    default:
        return Qt::PenJoinStyle::MiterJoin;
    }
}

Qt::BrushStyle addShape::getBrushStyle()
{
   switch(ui->brushStyleComboBox->currentIndex()) {
   case 0:
       return Qt::BrushStyle::NoBrush;
       break;
   case 1:
       return Qt::BrushStyle::SolidPattern;
       break;
   case 2:
       return Qt::BrushStyle::HorPattern;
       break;
   case 3:
       return Qt::BrushStyle::VerPattern;
       break;
   default:
       return Qt::BrushStyle::NoBrush;
   }
}

Qt::AlignmentFlag addShape::getFlag(QString flagStr)
{
    if(flagStr == "AlignLeft")
        return Qt::AlignLeft;
    else if(flagStr == "AlignRight")
        return Qt::AlignRight;
    else if(flagStr == "AlignTop")
        return Qt::AlignTop;
    else if(flagStr == "AlignBottom")
        return Qt::AlignBottom;
    else
        return Qt::AlignCenter;
}

QFont::Style addShape::getFontStyle(QString fontStyleStr)
{
    if(fontStyleStr == "StyleNormal")
        return QFont::StyleNormal;
    else if(fontStyleStr == "StyleItalic")
        return QFont::StyleItalic;
    else
        return QFont::StyleOblique;
}

QFont::Weight addShape::getFontWeight(QString fontWeightStr)
{
    if(fontWeightStr == "Thin")
        return QFont::Thin;
    else if(fontWeightStr == "Light")
        return QFont::Light;
    else if(fontWeightStr == "Normal")
        return QFont::Normal;
    else
        return QFont::Bold;
}

QString addShape::getStringColor(QColor color)
{
    if(color == Qt::blue)
        return "blue";
    else if(color == Qt::red)
        return "red";
    else if(color == Qt::green)
        return "green";
    else if(color == Qt::yellow)
        return "yellow";
    else if(color == Qt::black)
        return "black";
    else if(color == Qt::white)
        return "white";
    else if(color == Qt::cyan)
        return "cyan";
    else if(color == Qt::magenta)
        return "magenta";
    else
        return "gray";
}


QString addShape::getStringPenCap(Qt::PenCapStyle penStyle)
{
    if(penStyle == Qt::FlatCap)
        return "FlatCap";
    else if(penStyle == Qt::SquareCap)
        return "SquareCap";
    else
        return "RoundCap";
}

QString   addShape::getStringPenStyle(Qt::PenStyle penStyle)
{
    if(penStyle == Qt::NoPen)
        return "NoPen";
    else if(penStyle == Qt::SolidLine)
        return "SolidLine";
    else if(penStyle == Qt::DashLine)
        return "DashLine";
    else if(penStyle == Qt::DotLine)
        return "DotLine";
    else if(penStyle == Qt::DashDotLine)
        return "DashDotLine";
    else
        return "DashDotDotLine";
}

QString addShape::getStringPenJointStyle(Qt::PenJoinStyle penJointStyle)
{
    if(penJointStyle == Qt::MiterJoin)
        return "MiterJoin";
    else if(penJointStyle == Qt::BevelJoin)
        return "BevelJoin";
    else
        return "RoundJoin";
}

QString addShape::getStringBrush(Qt::BrushStyle brush)
{
    if(brush == Qt::SolidPattern)
        return "SolidPattern";
    else if(brush == Qt::HorPattern)
        return "HorPattern";
    else if(brush == Qt::VerPattern)
        return "VerPattern";
    else
        return "NoBrush";
}

QString addShape::getStringFlag(Qt::AlignmentFlag  flag)
{
    if(flag == Qt::AlignLeft )
        return "AlignLeft";
    else if(flag == Qt::AlignRight)
        return "AlignRight";
    else if(flag == Qt::AlignTop)
        return "AlignTop";
    else if(flag == Qt::AlignBottom)
        return "AlignBottom";
    else
        return "AlignCenter";
}

 QString addShape::getStringFontStyle(QFont::Style fontStyle)
{
    if(fontStyle == QFont::StyleNormal)
        return "StyleNormal";
    else if(fontStyle == QFont::StyleItalic)
        return "StyleItalic";
    else
        return "StyleOblique";
}

QString addShape::getStringFontWeight(int fontWeight)
{
    if(fontWeight == 0)
        return "Thin";
    else if(fontWeight == 25)
        return "Light";
    else if(fontWeight == 50)
        return "Normal";
    else
        return "Bold";
}
