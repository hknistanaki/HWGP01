/********************************************************************************
** Form generated from reading UI file 'addshape.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSHAPE_H
#define UI_ADDSHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addShape
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *parameterTabs;
    QWidget *Shape;
    QWidget *formLayoutWidget_2;
    QFormLayout *shapeForm;
    QLineEdit *idLineEdit;
    QLabel *label;
    QLabel *label_2;
    QComboBox *shapeTypeComboBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *dimensionsForm;
    QLabel *label_3;
    QLineEdit *dimensionLineEdit;
    QWidget *Pen;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *penColorComboBox;
    QComboBox *penStyleComboBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *capStyleComboBox;
    QComboBox *joinStyleComboBox;
    QSpacerItem *verticalSpacer;
    QWidget *Brush;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_2;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *brushColorComboBox;
    QComboBox *brushStyleComboBox;
    QWidget *Text;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *textStringLineEdit;
    QComboBox *fontColorComboBox;
    QComboBox *fontAllignmentComboBox;
    QSpinBox *sizeSpinBox;
    QComboBox *fontWeightComboBox;
    QComboBox *fontFamilyComboBox;
    QComboBox *fontStyleComboBox;
    QWidget *Guide;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout;
    QLabel *label_20;
    QLabel *label_19;

    void setupUi(QDialog *addShape)
    {
        if (addShape->objectName().isEmpty())
            addShape->setObjectName(QString::fromUtf8("addShape"));
        addShape->resize(400, 471);
        buttonBox = new QDialogButtonBox(addShape);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 410, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        parameterTabs = new QTabWidget(addShape);
        parameterTabs->setObjectName(QString::fromUtf8("parameterTabs"));
        parameterTabs->setGeometry(QRect(50, 50, 301, 351));
        Shape = new QWidget();
        Shape->setObjectName(QString::fromUtf8("Shape"));
        Shape->setEnabled(true);
        formLayoutWidget_2 = new QWidget(Shape);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(50, 30, 185, 80));
        shapeForm = new QFormLayout(formLayoutWidget_2);
        shapeForm->setObjectName(QString::fromUtf8("shapeForm"));
        shapeForm->setContentsMargins(0, 0, 0, 0);
        idLineEdit = new QLineEdit(formLayoutWidget_2);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(idLineEdit->sizePolicy().hasHeightForWidth());
        idLineEdit->setSizePolicy(sizePolicy);
        idLineEdit->setReadOnly(true);

        shapeForm->setWidget(0, QFormLayout::FieldRole, idLineEdit);

        label = new QLabel(formLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        shapeForm->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        shapeForm->setWidget(0, QFormLayout::LabelRole, label_2);

        shapeTypeComboBox = new QComboBox(formLayoutWidget_2);
        shapeTypeComboBox->addItem(QString());
        shapeTypeComboBox->addItem(QString());
        shapeTypeComboBox->addItem(QString());
        shapeTypeComboBox->addItem(QString());
        shapeTypeComboBox->addItem(QString());
        shapeTypeComboBox->addItem(QString());
        shapeTypeComboBox->addItem(QString());
        shapeTypeComboBox->setObjectName(QString::fromUtf8("shapeTypeComboBox"));

        shapeForm->setWidget(1, QFormLayout::FieldRole, shapeTypeComboBox);

        verticalLayoutWidget = new QWidget(Shape);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 130, 235, 131));
        dimensionsForm = new QVBoxLayout(verticalLayoutWidget);
        dimensionsForm->setObjectName(QString::fromUtf8("dimensionsForm"));
        dimensionsForm->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        dimensionsForm->addWidget(label_3);

        dimensionLineEdit = new QLineEdit(verticalLayoutWidget);
        dimensionLineEdit->setObjectName(QString::fromUtf8("dimensionLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dimensionLineEdit->sizePolicy().hasHeightForWidth());
        dimensionLineEdit->setSizePolicy(sizePolicy1);

        dimensionsForm->addWidget(dimensionLineEdit);

        parameterTabs->addTab(Shape, QString());
        Pen = new QWidget();
        Pen->setObjectName(QString::fromUtf8("Pen"));
        formLayoutWidget = new QWidget(Pen);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 40, 251, 198));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        penColorComboBox = new QComboBox(formLayoutWidget);
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->addItem(QString());
        penColorComboBox->setObjectName(QString::fromUtf8("penColorComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, penColorComboBox);

        penStyleComboBox = new QComboBox(formLayoutWidget);
        penStyleComboBox->addItem(QString());
        penStyleComboBox->addItem(QString());
        penStyleComboBox->addItem(QString());
        penStyleComboBox->addItem(QString());
        penStyleComboBox->addItem(QString());
        penStyleComboBox->addItem(QString());
        penStyleComboBox->setObjectName(QString::fromUtf8("penStyleComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, penStyleComboBox);

        penWidthSpinBox = new QSpinBox(formLayoutWidget);
        penWidthSpinBox->setObjectName(QString::fromUtf8("penWidthSpinBox"));
        penWidthSpinBox->setMaximum(20);

        formLayout->setWidget(2, QFormLayout::FieldRole, penWidthSpinBox);

        capStyleComboBox = new QComboBox(formLayoutWidget);
        capStyleComboBox->addItem(QString());
        capStyleComboBox->addItem(QString());
        capStyleComboBox->addItem(QString());
        capStyleComboBox->setObjectName(QString::fromUtf8("capStyleComboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, capStyleComboBox);

        joinStyleComboBox = new QComboBox(formLayoutWidget);
        joinStyleComboBox->addItem(QString());
        joinStyleComboBox->addItem(QString());
        joinStyleComboBox->addItem(QString());
        joinStyleComboBox->setObjectName(QString::fromUtf8("joinStyleComboBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, joinStyleComboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer);

        parameterTabs->addTab(Pen, QString());
        Brush = new QWidget();
        Brush->setObjectName(QString::fromUtf8("Brush"));
        formLayoutWidget_3 = new QWidget(Brush);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(30, 30, 160, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

        brushColorComboBox = new QComboBox(formLayoutWidget_3);
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->addItem(QString());
        brushColorComboBox->setObjectName(QString::fromUtf8("brushColorComboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, brushColorComboBox);

        brushStyleComboBox = new QComboBox(formLayoutWidget_3);
        brushStyleComboBox->addItem(QString());
        brushStyleComboBox->addItem(QString());
        brushStyleComboBox->addItem(QString());
        brushStyleComboBox->addItem(QString());
        brushStyleComboBox->setObjectName(QString::fromUtf8("brushStyleComboBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, brushStyleComboBox);

        parameterTabs->addTab(Brush, QString());
        Text = new QWidget();
        Text->setObjectName(QString::fromUtf8("Text"));
        formLayoutWidget_4 = new QWidget(Text);
        formLayoutWidget_4->setObjectName(QString::fromUtf8("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(30, 20, 211, 271));
        formLayout_3 = new QFormLayout(formLayoutWidget_4);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(formLayoutWidget_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(1, QFormLayout::LabelRole, verticalSpacer_2);

        label_13 = new QLabel(formLayoutWidget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_13);

        label_14 = new QLabel(formLayoutWidget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(formLayoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(formLayoutWidget_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(formLayoutWidget_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_17);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(5, QFormLayout::LabelRole, verticalSpacer_3);

        textStringLineEdit = new QLineEdit(formLayoutWidget_4);
        textStringLineEdit->setObjectName(QString::fromUtf8("textStringLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, textStringLineEdit);

        fontColorComboBox = new QComboBox(formLayoutWidget_4);
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->addItem(QString());
        fontColorComboBox->setObjectName(QString::fromUtf8("fontColorComboBox"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, fontColorComboBox);

        fontAllignmentComboBox = new QComboBox(formLayoutWidget_4);
        fontAllignmentComboBox->addItem(QString());
        fontAllignmentComboBox->addItem(QString());
        fontAllignmentComboBox->addItem(QString());
        fontAllignmentComboBox->addItem(QString());
        fontAllignmentComboBox->addItem(QString());
        fontAllignmentComboBox->setObjectName(QString::fromUtf8("fontAllignmentComboBox"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, fontAllignmentComboBox);

        sizeSpinBox = new QSpinBox(formLayoutWidget_4);
        sizeSpinBox->setObjectName(QString::fromUtf8("sizeSpinBox"));
        sizeSpinBox->setMinimum(-1);
        sizeSpinBox->setMaximum(50);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, sizeSpinBox);

        fontWeightComboBox = new QComboBox(formLayoutWidget_4);
        fontWeightComboBox->addItem(QString());
        fontWeightComboBox->addItem(QString());
        fontWeightComboBox->addItem(QString());
        fontWeightComboBox->addItem(QString());
        fontWeightComboBox->setObjectName(QString::fromUtf8("fontWeightComboBox"));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, fontWeightComboBox);

        fontFamilyComboBox = new QComboBox(formLayoutWidget_4);
        fontFamilyComboBox->addItem(QString());
        fontFamilyComboBox->addItem(QString());
        fontFamilyComboBox->addItem(QString());
        fontFamilyComboBox->addItem(QString());
        fontFamilyComboBox->setObjectName(QString::fromUtf8("fontFamilyComboBox"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, fontFamilyComboBox);

        fontStyleComboBox = new QComboBox(formLayoutWidget_4);
        fontStyleComboBox->addItem(QString());
        fontStyleComboBox->addItem(QString());
        fontStyleComboBox->addItem(QString());
        fontStyleComboBox->setObjectName(QString::fromUtf8("fontStyleComboBox"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, fontStyleComboBox);

        parameterTabs->addTab(Text, QString());
        Guide = new QWidget();
        Guide->setObjectName(QString::fromUtf8("Guide"));
        verticalLayoutWidget_2 = new QWidget(Guide);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 281, 267));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(verticalLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label_18);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_20 = new QLabel(verticalLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout->addWidget(label_20);

        label_19 = new QLabel(verticalLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout->addWidget(label_19);


        verticalLayout->addLayout(horizontalLayout);

        parameterTabs->addTab(Guide, QString());

        retranslateUi(addShape);
        QObject::connect(buttonBox, SIGNAL(accepted()), addShape, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addShape, SLOT(reject()));

        parameterTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(addShape);
    } // setupUi

    void retranslateUi(QDialog *addShape)
    {
        addShape->setWindowTitle(QCoreApplication::translate("addShape", "Add Shape", nullptr));
        label->setText(QCoreApplication::translate("addShape", "Shape Type", nullptr));
        label_2->setText(QCoreApplication::translate("addShape", "Shape ID", nullptr));
        shapeTypeComboBox->setItemText(0, QCoreApplication::translate("addShape", "Line", nullptr));
        shapeTypeComboBox->setItemText(1, QCoreApplication::translate("addShape", "Polyline", nullptr));
        shapeTypeComboBox->setItemText(2, QCoreApplication::translate("addShape", "Polygon", nullptr));
        shapeTypeComboBox->setItemText(3, QCoreApplication::translate("addShape", "Rectangle", nullptr));
        shapeTypeComboBox->setItemText(4, QCoreApplication::translate("addShape", "Ellipse", nullptr));
        shapeTypeComboBox->setItemText(5, QCoreApplication::translate("addShape", "Circle", nullptr));
        shapeTypeComboBox->setItemText(6, QCoreApplication::translate("addShape", "Text", nullptr));

        label_3->setText(QCoreApplication::translate("addShape", "Enter dimensions separated by commas:", nullptr));
        parameterTabs->setTabText(parameterTabs->indexOf(Shape), QCoreApplication::translate("addShape", "Shape", nullptr));
        label_4->setText(QCoreApplication::translate("addShape", "Pen Color", nullptr));
        label_5->setText(QCoreApplication::translate("addShape", "Pen Style", nullptr));
        label_6->setText(QCoreApplication::translate("addShape", "Pen Width", nullptr));
        label_7->setText(QCoreApplication::translate("addShape", "Cap Style", nullptr));
        label_8->setText(QCoreApplication::translate("addShape", "Join Style", nullptr));
        penColorComboBox->setItemText(0, QCoreApplication::translate("addShape", "White", nullptr));
        penColorComboBox->setItemText(1, QCoreApplication::translate("addShape", "Black", nullptr));
        penColorComboBox->setItemText(2, QCoreApplication::translate("addShape", "Red", nullptr));
        penColorComboBox->setItemText(3, QCoreApplication::translate("addShape", "Green", nullptr));
        penColorComboBox->setItemText(4, QCoreApplication::translate("addShape", "Blue", nullptr));
        penColorComboBox->setItemText(5, QCoreApplication::translate("addShape", "Cyan", nullptr));
        penColorComboBox->setItemText(6, QCoreApplication::translate("addShape", "Magenta", nullptr));
        penColorComboBox->setItemText(7, QCoreApplication::translate("addShape", "Yellow", nullptr));
        penColorComboBox->setItemText(8, QCoreApplication::translate("addShape", "Gray", nullptr));

        penStyleComboBox->setItemText(0, QCoreApplication::translate("addShape", "No Pen", nullptr));
        penStyleComboBox->setItemText(1, QCoreApplication::translate("addShape", "Solid Line", nullptr));
        penStyleComboBox->setItemText(2, QCoreApplication::translate("addShape", "Dashed Line", nullptr));
        penStyleComboBox->setItemText(3, QCoreApplication::translate("addShape", "Dotted Line", nullptr));
        penStyleComboBox->setItemText(4, QCoreApplication::translate("addShape", "Dashed Dotted Line", nullptr));
        penStyleComboBox->setItemText(5, QCoreApplication::translate("addShape", "Dashed Dot Dot Line", nullptr));

        capStyleComboBox->setItemText(0, QCoreApplication::translate("addShape", "Flat", nullptr));
        capStyleComboBox->setItemText(1, QCoreApplication::translate("addShape", "Square", nullptr));
        capStyleComboBox->setItemText(2, QCoreApplication::translate("addShape", "Round", nullptr));

        joinStyleComboBox->setItemText(0, QCoreApplication::translate("addShape", "Miter", nullptr));
        joinStyleComboBox->setItemText(1, QCoreApplication::translate("addShape", "Bevel", nullptr));
        joinStyleComboBox->setItemText(2, QCoreApplication::translate("addShape", "Round", nullptr));

        parameterTabs->setTabText(parameterTabs->indexOf(Pen), QCoreApplication::translate("addShape", "Pen", nullptr));
        label_9->setText(QCoreApplication::translate("addShape", "Brush Color", nullptr));
        label_10->setText(QCoreApplication::translate("addShape", "Brush Style", nullptr));
        brushColorComboBox->setItemText(0, QCoreApplication::translate("addShape", "White", nullptr));
        brushColorComboBox->setItemText(1, QCoreApplication::translate("addShape", "Black", nullptr));
        brushColorComboBox->setItemText(2, QCoreApplication::translate("addShape", "Red", nullptr));
        brushColorComboBox->setItemText(3, QCoreApplication::translate("addShape", "Green", nullptr));
        brushColorComboBox->setItemText(4, QCoreApplication::translate("addShape", "Blue", nullptr));
        brushColorComboBox->setItemText(5, QCoreApplication::translate("addShape", "Cyan", nullptr));
        brushColorComboBox->setItemText(6, QCoreApplication::translate("addShape", "Magenta", nullptr));
        brushColorComboBox->setItemText(7, QCoreApplication::translate("addShape", "Yellow", nullptr));
        brushColorComboBox->setItemText(8, QCoreApplication::translate("addShape", "Gray", nullptr));

        brushStyleComboBox->setItemText(0, QCoreApplication::translate("addShape", "None", nullptr));
        brushStyleComboBox->setItemText(1, QCoreApplication::translate("addShape", "Solid", nullptr));
        brushStyleComboBox->setItemText(2, QCoreApplication::translate("addShape", "Horizontal", nullptr));
        brushStyleComboBox->setItemText(3, QCoreApplication::translate("addShape", "Vertical", nullptr));

        parameterTabs->setTabText(parameterTabs->indexOf(Brush), QCoreApplication::translate("addShape", "Brush", nullptr));
        label_11->setText(QCoreApplication::translate("addShape", "Color", nullptr));
        label_12->setText(QCoreApplication::translate("addShape", "String", nullptr));
        label_13->setText(QCoreApplication::translate("addShape", "Alignment", nullptr));
        label_14->setText(QCoreApplication::translate("addShape", "Size", nullptr));
        label_15->setText(QCoreApplication::translate("addShape", "Font Family", nullptr));
        label_16->setText(QCoreApplication::translate("addShape", "Font Style", nullptr));
        label_17->setText(QCoreApplication::translate("addShape", "Weight", nullptr));
        textStringLineEdit->setText(QCoreApplication::translate("addShape", "Text Object", nullptr));
        fontColorComboBox->setItemText(0, QCoreApplication::translate("addShape", "White", nullptr));
        fontColorComboBox->setItemText(1, QCoreApplication::translate("addShape", "Black", nullptr));
        fontColorComboBox->setItemText(2, QCoreApplication::translate("addShape", "Red", nullptr));
        fontColorComboBox->setItemText(3, QCoreApplication::translate("addShape", "Green", nullptr));
        fontColorComboBox->setItemText(4, QCoreApplication::translate("addShape", "Blue", nullptr));
        fontColorComboBox->setItemText(5, QCoreApplication::translate("addShape", "Cyan", nullptr));
        fontColorComboBox->setItemText(6, QCoreApplication::translate("addShape", "Magenta", nullptr));
        fontColorComboBox->setItemText(7, QCoreApplication::translate("addShape", "Yellow", nullptr));
        fontColorComboBox->setItemText(8, QCoreApplication::translate("addShape", "Gray", nullptr));

        fontAllignmentComboBox->setItemText(0, QCoreApplication::translate("addShape", "Left", nullptr));
        fontAllignmentComboBox->setItemText(1, QCoreApplication::translate("addShape", "Right", nullptr));
        fontAllignmentComboBox->setItemText(2, QCoreApplication::translate("addShape", "Top", nullptr));
        fontAllignmentComboBox->setItemText(3, QCoreApplication::translate("addShape", "Bottom", nullptr));
        fontAllignmentComboBox->setItemText(4, QCoreApplication::translate("addShape", "Center", nullptr));

        fontWeightComboBox->setItemText(0, QCoreApplication::translate("addShape", "Normal", nullptr));
        fontWeightComboBox->setItemText(1, QCoreApplication::translate("addShape", "Thin", nullptr));
        fontWeightComboBox->setItemText(2, QCoreApplication::translate("addShape", "Light", nullptr));
        fontWeightComboBox->setItemText(3, QCoreApplication::translate("addShape", "Bold", nullptr));

        fontFamilyComboBox->setItemText(0, QCoreApplication::translate("addShape", "Comic Sans MS", nullptr));
        fontFamilyComboBox->setItemText(1, QCoreApplication::translate("addShape", "Courier", nullptr));
        fontFamilyComboBox->setItemText(2, QCoreApplication::translate("addShape", "Helvetica", nullptr));
        fontFamilyComboBox->setItemText(3, QCoreApplication::translate("addShape", "Times", nullptr));

        fontStyleComboBox->setItemText(0, QCoreApplication::translate("addShape", "Normal", nullptr));
        fontStyleComboBox->setItemText(1, QCoreApplication::translate("addShape", "Italic", nullptr));
        fontStyleComboBox->setItemText(2, QCoreApplication::translate("addShape", "Oblique", nullptr));

        parameterTabs->setTabText(parameterTabs->indexOf(Text), QCoreApplication::translate("addShape", "Text", nullptr));
        label_18->setText(QCoreApplication::translate("addShape", "<html><head/><body><p><span style=\" font-weight:600;\">Line</span></p><p>x1, y1, x2, y2</p><p><span style=\" font-weight:600;\">Polyline</span></p><p><span style=\" font-family:'monospace';\">x1, y1, x2, y2, x3, y3, ... , xN, yN</span></p><p><span style=\" font-family:'monospace'; font-weight:600;\">Polygon</span></p><p><span style=\" font-family:'monospace';\">x1, y1, x2, y2, x3, y3, ... , xN, yN</span></p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("addShape", "<html><head/><body><p><span style=\" font-family:'monospace'; font-weight:600;\">Circle</span></p><p><span style=\" font-family:'monospace';\">x1, y1, r</span></p><p><span style=\" font-family:'monospace'; font-weight:600;\">Text</span></p><p><span style=\" font-family:'monospace';\">x1, y1, l, w</span></p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("addShape", "<html><head/><body><p><span style=\" font-family:'monospace'; font-weight:600;\">Rectangle</span></p><p><span style=\" font-family:'monospace';\">x1, y1, l, w</span></p><p><span style=\" font-family:'monospace'; font-weight:600;\">Square</span></p><p><span style=\" font-family:'monospace';\">x1, y1, l</span></p></body></html>", nullptr));
        parameterTabs->setTabText(parameterTabs->indexOf(Guide), QCoreApplication::translate("addShape", "Guide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addShape: public Ui_addShape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSHAPE_H
