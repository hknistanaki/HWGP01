/********************************************************************************
** Form generated from reading UI file 'deleteshape.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETESHAPE_H
#define UI_DELETESHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteshape
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *shapeIDLineEdit;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *deleteshape)
    {
        if (deleteshape->objectName().isEmpty())
            deleteshape->setObjectName(QString::fromUtf8("deleteshape"));
        deleteshape->resize(400, 126);
        buttonBox = new QDialogButtonBox(deleteshape);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(deleteshape);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 241, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        shapeIDLineEdit = new QLineEdit(verticalLayoutWidget);
        shapeIDLineEdit->setObjectName(QString::fromUtf8("shapeIDLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, shapeIDLineEdit);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);


        verticalLayout->addLayout(formLayout);


        retranslateUi(deleteshape);
        QObject::connect(buttonBox, SIGNAL(accepted()), deleteshape, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deleteshape, SLOT(reject()));

        QMetaObject::connectSlotsByName(deleteshape);
    } // setupUi

    void retranslateUi(QDialog *deleteshape)
    {
        deleteshape->setWindowTitle(QCoreApplication::translate("deleteshape", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("deleteshape", "Shape ID:", nullptr));
        label->setText(QCoreApplication::translate("deleteshape", "<html><head/><body><p align=\"center\">Enter Shape ID to delete:</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteshape: public Ui_deleteshape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETESHAPE_H
