/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionLog_Out;
    QAction *actionContact_Us;
    QAction *actionQuit;
    QAction *actionAdd_Shape;
    QAction *actionRemove_Shape;
    QAction *actionList_Shapes;
    QAction *actionMove_Shape;
    QAction *actiondebug_shapeCount;
    QAction *actionComments;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLog_Out = new QAction(MainWindow);
        actionLog_Out->setObjectName(QString::fromUtf8("actionLog_Out"));
        actionContact_Us = new QAction(MainWindow);
        actionContact_Us->setObjectName(QString::fromUtf8("actionContact_Us"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAdd_Shape = new QAction(MainWindow);
        actionAdd_Shape->setObjectName(QString::fromUtf8("actionAdd_Shape"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/img/001-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("img/001-add.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAdd_Shape->setIcon(icon);
        actionRemove_Shape = new QAction(MainWindow);
        actionRemove_Shape->setObjectName(QString::fromUtf8("actionRemove_Shape"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/img/002-cancel.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRemove_Shape->setIcon(icon1);
        actionList_Shapes = new QAction(MainWindow);
        actionList_Shapes->setObjectName(QString::fromUtf8("actionList_Shapes"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("img/003-list.png"), QSize(), QIcon::Normal, QIcon::On);
        actionList_Shapes->setIcon(icon2);
        actionMove_Shape = new QAction(MainWindow);
        actionMove_Shape->setObjectName(QString::fromUtf8("actionMove_Shape"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("img/004-edit.png"), QSize(), QIcon::Normal, QIcon::On);
        actionMove_Shape->setIcon(icon3);
        actiondebug_shapeCount = new QAction(MainWindow);
        actiondebug_shapeCount->setObjectName(QString::fromUtf8("actiondebug_shapeCount"));
        actionComments = new QAction(MainWindow);
        actionComments->setObjectName(QString::fromUtf8("actionComments"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLogin);
        menuFile->addAction(actionLog_Out);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionContact_Us);
        menuHelp->addAction(actiondebug_shapeCount);
        menuHelp->addAction(actionComments);
        toolBar->addAction(actionAdd_Shape);
        toolBar->addAction(actionRemove_Shape);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "2D Graphics Modeler [Super Scrum]", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        actionLog_Out->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        actionContact_Us->setText(QCoreApplication::translate("MainWindow", "Contact Us", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionAdd_Shape->setText(QCoreApplication::translate("MainWindow", "Add Shape", nullptr));
#if QT_CONFIG(tooltip)
        actionAdd_Shape->setToolTip(QCoreApplication::translate("MainWindow", "Add Shape", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRemove_Shape->setText(QCoreApplication::translate("MainWindow", "Remove Shape", nullptr));
#if QT_CONFIG(tooltip)
        actionRemove_Shape->setToolTip(QCoreApplication::translate("MainWindow", "Remove Shape", nullptr));
#endif // QT_CONFIG(tooltip)
        actionList_Shapes->setText(QCoreApplication::translate("MainWindow", "List Shapes", nullptr));
#if QT_CONFIG(tooltip)
        actionList_Shapes->setToolTip(QCoreApplication::translate("MainWindow", "List Shapes", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMove_Shape->setText(QCoreApplication::translate("MainWindow", "Move Shape", nullptr));
#if QT_CONFIG(tooltip)
        actionMove_Shape->setToolTip(QCoreApplication::translate("MainWindow", "Move Shape", nullptr));
#endif // QT_CONFIG(tooltip)
        actiondebug_shapeCount->setText(QCoreApplication::translate("MainWindow", "debug shapeCount", nullptr));
        actionComments->setText(QCoreApplication::translate("MainWindow", "Comments", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
