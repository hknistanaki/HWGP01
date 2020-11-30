/********************************************************************************
** Form generated from reading UI file 'comments.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTS_H
#define UI_COMMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_comments
{
public:
    QPushButton *pushButton;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QDialog *comments)
    {
        if (comments->objectName().isEmpty())
            comments->setObjectName(QString::fromUtf8("comments"));
        comments->resize(734, 514);
        pushButton = new QPushButton(comments);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 470, 191, 41));
        label_2 = new QLabel(comments);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 161, 21));
        verticalLayoutWidget = new QWidget(comments);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 40, 711, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        pushButton_2 = new QPushButton(comments);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 470, 71, 41));
        textEdit = new QTextEdit(comments);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 330, 711, 131));
        label = new QLabel(comments);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 470, 171, 41));
        label_3 = new QLabel(comments);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 310, 131, 16));

        retranslateUi(comments);

        QMetaObject::connectSlotsByName(comments);
    } // setupUi

    void retranslateUi(QDialog *comments)
    {
        comments->setWindowTitle(QCoreApplication::translate("comments", "Customer Testimonials", nullptr));
        pushButton->setText(QCoreApplication::translate("comments", "POST", nullptr));
        label_2->setText(QCoreApplication::translate("comments", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Customer testimonials:</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("comments", "Click Me", nullptr));
        label->setText(QCoreApplication::translate("comments", "<html><head/><body><p><span style=\" font-size:12pt;\">If you have an account,</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("comments", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Enter your view:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class comments: public Ui_comments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTS_H
