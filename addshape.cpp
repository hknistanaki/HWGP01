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

QFont::Style addShape::getFontStyle()
{
    switch(ui->fontStyleComboBox->currentIndex()) {
    case 0:
        return QFont::StyleNormal;
        break;
    case 1:
        return QFont::StyleItalic;
        break;
    case 2:
        return QFont::StyleOblique;
        break;
    default:
        return QFont::StyleNormal;
    }
}

QFont::Weight addShape::getFontWeight()
{
    switch(ui->fontWeightComboBox->currentIndex()) {
    case 0:
        return QFont::Normal;
        break;
    case 1:
        return QFont::Thin;
        break;
    case 2:
        return QFont::Light;
        break;
    case 3:
        return QFont::Bold;
        break;
    }
}

Qt::GlobalColor addShape::getStringColor()
{
    switch(ui->fontColorComboBox->currentIndex()) {
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

Qt::AlignmentFlag addShape::getStringFlag()
{
    // l r t b c
    switch(ui->fontAllignmentComboBox->currentIndex()) {
    case 0:
        return Qt::AlignmentFlag::AlignLeft;
        break;
    case 1:
        return Qt::AlignmentFlag::AlignRight;
        break;
    case 2:
        return Qt::AlignmentFlag::AlignTop;
        break;
    case 3:
        return Qt::AlignmentFlag::AlignBottom;
        break;
    case 4:
        return Qt::AlignmentFlag::AlignCenter;
        break;
    default:
        return Qt::AlignmentFlag::AlignLeft;
    }
}

QString addShape::getTextFontFamily()
{
    switch(ui->fontFamilyComboBox->currentIndex()) {
    case 0:
        return "Comic Sans MS";
        break;
    case 1:
        return "Courier";
        break;
    case 2:
        return "Helvetica";
        break;
    case 3:
        return "Times";
        break;
    }
}
