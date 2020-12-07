#include "modifyshapes.h"
#include "ui_modifyshapes.h"

ModifyShapes::ModifyShapes(QWidget *parent, gp::vector<Shape*> shapeVec) :
    QDialog(parent),
    modShape{nullptr},
    indexModShape{-1},
    ui(new Ui::ModifyShapes)
{
    ui->setupUi(this);

    // copy vector from RenderArea into local
    localVec = shapeVec;

    // parse shapes from vector into combo box
    for(gp::vector<Shape*>::const_iterator it = localVec.begin(); it != localVec.end(); ++it) {
        QString nameTag = (*it)->nameTag(getShapeName((*it)->get_shape()));
        ui->shapesComboBox->addItem(nameTag);
    }

    // Disable fields that are always read-only
    ui->idLineEdit->setReadOnly(true);
    ui->shapeTypeLineEdit->setReadOnly(true);

    // disable all fields on init
    disableAll();

}

ModifyShapes::~ModifyShapes()
{
    delete ui;
}



QString ModifyShapes::getShapeName(Shape::ShapeType shape) const
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

void ModifyShapes::disableAll() const
{
    // Dimensions tab
    ui->x1LineEdit->setEnabled(false);
    ui->y1LineEdit->setEnabled(false);
    ui->x2LineEdit->setEnabled(false);
    ui->y2LineEdit->setEnabled(false);

    ui->lLineEdit->setEnabled(false);
    ui->wLineEdit->setEnabled(false);

    ui->aLineEdit->setEnabled(false);
    ui->bLineEdit->setEnabled(false);

    ui->rLineEdit->setEnabled(false);

    ui->addXLineEdit->setEnabled(false);
    ui->addYLineEdit->setEnabled(false);
    ui->addPointPushButton->setEnabled(false);

    // Pen tab
    ui->penColorComboBox->setEnabled(false);
    ui->penStyleComboBox->setEnabled(false);
    ui->penWidthSpinBox->setEnabled(false);

    ui->capStyleComboBox->setEnabled(false);
    ui->joinStyleComboBox->setEnabled(false);

    // Brush tab
    ui->brushColorComboBox->setEnabled(false);
    ui->brushStyleComboBox->setEnabled(false);

    // Text tab
    ui->textStringLineEdit->setEnabled(false);

    ui->fontColorComboBox->setEnabled(false);
    ui->fontAllignmentComboBox->setEnabled(false);
    ui->sizeSpinBox->setEnabled(false);

    ui->fontFamilyComboBox->setEnabled(false);
    ui->fontStyleComboBox->setEnabled(false);
    ui->fontWeightComboBox->setEnabled(false);

}

void ModifyShapes::enableAll(Shape::ShapeType shape) const
{
    switch(shape) {
    case sType::NoShape:
        break;
    case sType::Circle:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);

        ui->rLineEdit->setEnabled(true);

        // Pen tab
        ui->penColorComboBox->setEnabled(true);
        ui->penStyleComboBox->setEnabled(true);
        ui->penWidthSpinBox->setEnabled(true);

        ui->capStyleComboBox->setEnabled(true);
        ui->joinStyleComboBox->setEnabled(true);

        // Brush tab
        ui->brushColorComboBox->setEnabled(true);
        ui->brushStyleComboBox->setEnabled(true);
        break;
    case sType::Ellipse:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);

        ui->aLineEdit->setEnabled(true);
        ui->bLineEdit->setEnabled(true);

        // Pen tab
        ui->penColorComboBox->setEnabled(true);
        ui->penStyleComboBox->setEnabled(true);
        ui->penWidthSpinBox->setEnabled(true);

        ui->capStyleComboBox->setEnabled(true);
        ui->joinStyleComboBox->setEnabled(true);

        // Brush tab
        ui->brushColorComboBox->setEnabled(true);
        ui->brushStyleComboBox->setEnabled(true);
        break;
    case sType::Line:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);
        ui->x2LineEdit->setEnabled(true);
        ui->y2LineEdit->setEnabled(true);

        // Pen tab
        ui->penColorComboBox->setEnabled(true);
        ui->penStyleComboBox->setEnabled(true);
        ui->penWidthSpinBox->setEnabled(true);

        ui->capStyleComboBox->setEnabled(true);
        ui->joinStyleComboBox->setEnabled(true);
        break;
    case sType::Polyline:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);
        ui->x2LineEdit->setEnabled(true);
        ui->y2LineEdit->setEnabled(true);

        ui->addXLineEdit->setEnabled(true);
        ui->addYLineEdit->setEnabled(true);
        ui->addPointPushButton->setEnabled(true);

        // Pen tab
        ui->penColorComboBox->setEnabled(true);
        ui->penStyleComboBox->setEnabled(true);
        ui->penWidthSpinBox->setEnabled(true);

        ui->capStyleComboBox->setEnabled(true);
        ui->joinStyleComboBox->setEnabled(true);
        break;
    case sType::Square:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);

        ui->lLineEdit->setEnabled(true);

        // Pen tab
        ui->penColorComboBox->setEnabled(true);
        ui->penStyleComboBox->setEnabled(true);
        ui->penWidthSpinBox->setEnabled(true);

        ui->capStyleComboBox->setEnabled(true);
        ui->joinStyleComboBox->setEnabled(true);

        // Brush tab
        ui->brushColorComboBox->setEnabled(true);
        ui->brushStyleComboBox->setEnabled(true);
        break;
    case sType::Rectangle:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);

        ui->lLineEdit->setEnabled(true);
        ui->wLineEdit->setEnabled(true);

        // Pen tab
        ui->penColorComboBox->setEnabled(true);
        ui->penStyleComboBox->setEnabled(true);
        ui->penWidthSpinBox->setEnabled(true);

        ui->capStyleComboBox->setEnabled(true);
        ui->joinStyleComboBox->setEnabled(true);

        // Brush tab
        ui->brushColorComboBox->setEnabled(true);
        ui->brushStyleComboBox->setEnabled(true);
        break;
    case sType::Polygon:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);
        ui->x2LineEdit->setEnabled(true);
        ui->y2LineEdit->setEnabled(true);

        ui->addXLineEdit->setEnabled(true);
        ui->addYLineEdit->setEnabled(true);
        ui->addPointPushButton->setEnabled(true);

        // Pen tab
        ui->penColorComboBox->setEnabled(true);
        ui->penStyleComboBox->setEnabled(true);
        ui->penWidthSpinBox->setEnabled(true);

        ui->capStyleComboBox->setEnabled(true);
        ui->joinStyleComboBox->setEnabled(true);

        // Brush tab
        ui->brushColorComboBox->setEnabled(true);
        ui->brushStyleComboBox->setEnabled(true);
        break;
    case sType::Text:
        // Dimensions tab
        ui->x1LineEdit->setEnabled(true);
        ui->y1LineEdit->setEnabled(true);

        ui->lLineEdit->setEnabled(true);
        ui->wLineEdit->setEnabled(true);

        // Text tab
        ui->textStringLineEdit->setEnabled(true);

        ui->fontColorComboBox->setEnabled(true);
        ui->fontAllignmentComboBox->setEnabled(true);
        ui->sizeSpinBox->setEnabled(true);

        ui->fontFamilyComboBox->setEnabled(true);
        ui->fontStyleComboBox->setEnabled(true);
        ui->fontWeightComboBox->setEnabled(true);
        break;
    }
}

void ModifyShapes::on_shapesComboBox_currentIndexChanged(int index)
{   
   qDebug() << "index: " << index;
   disableAll();
   if(index != 0) {
       enableAll(localVec[index-1]->get_shape()); // index-1 since combo box has a default value at index 0
       ui->idLineEdit->setText(QString::number(localVec[index-1]->get_shapeID()));
       ui->shapeTypeLineEdit->setText(getShapeName(localVec[index-1]->get_shape()));
   }else {
       ui->idLineEdit->setText("");
       ui->shapeTypeLineEdit->setText("");
   }
}

void ModifyShapes::on_buttonBox_accepted()
{
    //qDebug() << ui->shapesComboBox->currentIndex();

    if(ui->shapesComboBox->currentIndex() < 1) {
        QMessageBox noShapeSelected;
        noShapeSelected.setText("ERR: Please select a shape to modify.");
        noShapeSelected.exec();
    }else{
       addShapeToCanvas();
    }

}

// adapted from addShape

void ModifyShapes::addShapeToCanvas() {
    switch(localVec[ui->shapesComboBox->currentIndex()-1]->get_shape()){
    case sType::Line:
        // adding Line
        addLine();
        break;
    case sType::Polyline:
        // adding polyLine
        addPolyline();
        break;
    case sType::Polygon:
        // adding polygon
        addPolygon();
        break;
    case sType::Rectangle:
        // adding rectangle
        addRectangle();
        break;
    case sType::Square:
        // adding square
        addSquare();
        break;
    case sType::Ellipse:
        // adding ellipse
        addEllipse();
        break;
    case sType::Circle:
        // adding circle
        addCircle();
        break;
    case sType::Text:
        // adding text
        addText();
        break;
    default:
        // should never be reached
        qDebug() << "Error addShapeToCanvas() in modifyShape";
        break;
    }
}

void ModifyShapes::addLine()
{
    auto temp = new Line();
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    // Set points using x1 y1 x2 y2
    temp->set_points(QPoint{ui->x1LineEdit->text().toInt(), ui->y1LineEdit->text().toInt()}, QPoint{ui->x2LineEdit->text().toInt(), ui->y2LineEdit->text().toInt()});

    // Set pen with values from UI elements
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // Set brush (Not applicable)
    // temp->set_brush(Qt::blue, Qt::BrushStyle::HorPattern);

    modShape = temp;
    temp = nullptr;
}

void ModifyShapes::addPolyline()
{
    auto temp = new Polyline();
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    // TODO add points

    // Set pen with values from UI elements
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // Set brush (Not applicable)
    // temp->set_brush(Qt::blue, Qt::BrushStyle::HorPattern);

    modShape = temp;
    temp = nullptr;
}

void ModifyShapes::addPolygon()
{
    auto temp = new Polygon(nullptr);
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    // TODO add points

    // set pen
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // set brush
    temp->set_brush(getBrushColor(), getBrushStyle());
    modShape = temp;
    temp = nullptr;
}

void ModifyShapes::addRectangle()
{
    auto temp = new Rectangle(nullptr);
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    temp->set_point(QPoint{ui->posXSpinBox->value(), ui->posYSpinBox->value()});

    // default dimensions on shape creation
    temp->set_dimensions(50, 50);
    // set pen
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // set brush
    temp->set_brush(getBrushColor(), getBrushStyle());
    modShape = temp;
    temp = nullptr;
}

void ModifyShapes::addSquare()
{
    auto temp = new Square(nullptr);
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    temp->set_point(QPoint{ui->posXSpinBox->value(), ui->posYSpinBox->value()});

    // default dimensions on shape creation
    temp->set_dimension(50);
    // set pen
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // set brush
    temp->set_brush(getBrushColor(), getBrushStyle());
    modShape = temp;
    temp = nullptr;
}

void ModifyShapes::addEllipse()
{
    auto temp = new Ellipse(nullptr);
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    temp->set_point(QPoint{ui->posXSpinBox->value(), ui->posYSpinBox->value()});

    // default dimensions on shape creation
    temp->set_dimensions(50, 100);
    // set pen
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // set brush
    temp->set_brush(getBrushColor(), getBrushStyle());
    modShape = temp;
    temp = nullptr;
}

void ModifyShapes::addCircle()
{
    auto temp = new Circle(nullptr);
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    temp->set_point(QPoint{ui->posXSpinBox->value(), ui->posYSpinBox->value()});

    // default dimensions on shape creation
    temp->set_radius(50);
    // set pen
    temp->set_pen(getColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    // set brush
    temp->set_brush(getBrushColor(), getBrushStyle());
    modShape = temp;
    temp = nullptr;
}

void ModifyShapes::addText()
{
    auto temp = new Text(nullptr);
    temp->set_shapeID(localVec[ui->shapesComboBox->currentIndex()-1]->get_shapeID());

    temp->set_point(QPoint{ui->posXSpinBox->value(), ui->posYSpinBox->value()});

    temp->set_pen(getStringColor(), ui->penWidthSpinBox->value(), getPenStyle(), getPenCapStyle(), getPenJointStyle());

    temp->set_all_text(ui->textStringLineEdit->text(), getStringColor(), getStringFlag(), ui->sizeSpinBox->value(), getTextFontFamily(), QFont::Style::StyleNormal, getFontWeight());

    // default dimensions on shape creation
    temp->set_dimensions(50, 300);

    modShape = temp;
    temp = nullptr;
}

Qt::GlobalColor ModifyShapes::getColor()
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

Qt::GlobalColor ModifyShapes::getBrushColor()
{
    switch(ui->brushColorComboBox->currentIndex()) {
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

Qt::PenCapStyle ModifyShapes::getPenCapStyle()
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

Qt::PenStyle ModifyShapes::getPenStyle()
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

Qt::PenJoinStyle ModifyShapes::getPenJointStyle()
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

Qt::BrushStyle ModifyShapes::getBrushStyle()
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

QFont::Style ModifyShapes::getFontStyle()
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

QFont::Weight ModifyShapes::getFontWeight()
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
    default:
        return QFont::Normal;
    }
}

Qt::GlobalColor ModifyShapes::getStringColor()
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

Qt::AlignmentFlag ModifyShapes::getStringFlag()
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

QString ModifyShapes::getTextFontFamily()
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
    default:
        return "Comic Sans MS";
    }
}
