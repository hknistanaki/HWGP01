#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include "contactUs.h"
#include "logindialog.h"
#include "addshape.h"
#include "deleteshape.h"
#include "comments.h"
#include "canvas.h"

#include "shapestorage.h"
#include "vector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionContact_Us_triggered();

    void on_actionLogin_triggered();

    void on_actionLog_Out_triggered();

    void on_actionAdd_Shape_triggered();

    void on_actionRemove_Shape_triggered();

    void on_actiondebug_shapeCount_triggered();
    
    void on_actionComments_triggered();

private:
    Ui::MainWindow *ui;
    ContactUs *cWindow;
    logindialog *lDialog;
    addShape *addShapeDialog;
    deleteshape *delShapeDialog;
    comments *commentsDialog;

    canvas *canvasWidget;

    shapeStorage store;

    int shapeCount;

    bool isAdministrator;
};
#endif // MAINWINDOW_H
