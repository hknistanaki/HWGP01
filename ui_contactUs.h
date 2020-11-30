/********************************************************************************
** Form generated from reading UI file 'contactus.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTUS_H
#define UI_CONTACTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactUs
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_0;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_1;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_8;

    void setupUi(QDialog *ContactUs)
    {
        if (ContactUs->objectName().isEmpty())
            ContactUs->setObjectName(QString::fromUtf8("ContactUs"));
        ContactUs->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ContactUs->sizePolicy().hasHeightForWidth());
        ContactUs->setSizePolicy(sizePolicy);
        ContactUs->setMinimumSize(QSize(400, 300));
        ContactUs->setMaximumSize(QSize(400, 300));
        ContactUs->setSizeGripEnabled(false);
        verticalLayoutWidget = new QWidget(ContactUs);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 371, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_0 = new QLabel(verticalLayoutWidget);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setWordWrap(true);

        gridLayout->addWidget(label_0, 0, 0, 1, 1, Qt::AlignHCenter);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1, Qt::AlignHCenter);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 1, 1, 1);

        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        gridLayout->addWidget(label_1, 0, 1, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1, Qt::AlignHCenter);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ContactUs);

        QMetaObject::connectSlotsByName(ContactUs);
    } // setupUi

    void retranslateUi(QDialog *ContactUs)
    {
        ContactUs->setWindowTitle(QCoreApplication::translate("ContactUs", "About Us", nullptr));
        label->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\"><img src=\":/new/logo/img/team-logo.png\"/></p></body></html>", nullptr));
        label_0->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Chen Zhihuang<br/>****@ivc.edu</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Paul Jo<br/>****@ivc.edu</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Ethan Lew<br/>elew1<br/>@saddleback.edu</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Quan Nguyen<br/>****@ivc.edu</p></body></html>", nullptr));
        label_1->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Justin Chiu<br/>****@ivc.edu</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Eric Nakayama<br/>****@ivc.edu</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Adrian Hernandez<br/>****@ivc.edu</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Ahmed Mohammed<br/>****@ivc.edu</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("ContactUs", "<html><head/><body><p align=\"center\">Henry Nistanaki<br/>****@ivc.edu</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactUs: public Ui_ContactUs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTUS_H
