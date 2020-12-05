#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactUs.h"
#include "logindialog.h"
#include "comments.h"
#include "parser.h"
#include "vector.h"

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialize pointer members to nullptr
    cWindow = nullptr;
    lDialog = nullptr;
    addShapeDialog = nullptr;
    delShapeDialog = nullptr;
    commentsDialog = nullptr;

    // parse shapes
    gp::vector<Shape*> temp = ParseFile();

    //qDebug() << "reached MainWindow";

    // add to renderWidget's vector
    //qDebug() << "adding " << temp.size() << "shapes";
    for(int i = 0; i < temp.size(); ++i) {
        //qDebug() << "added " << i+1;
        ui->renderWidget->addShape(temp[i]);
    }

    //qDebug() << "Finished copy";

    // delete all shapes in temp
    // this should be an iterator but i couldn't
    // make it work for some reason
//    for(int i = 0; i < temp.size(); ++i) {
//        delete temp[i];
//    }

    isAdministrator = true;
    shapeCount = 0;
}

/*!
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete cWindow;
    //delete canvas;
}

/*!
 * \brief MainWindow::on_actionContact_Us_triggered
 */
void MainWindow::on_actionContact_Us_triggered()
{
    // Only create one contact us window per program execution
    if(cWindow == nullptr) {
        cWindow = new ContactUs(this);
    }

    cWindow->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    cWindow->show();

}

/*!
 * \brief MainWindow::on_actionLogin_triggered
 */
void MainWindow::on_actionLogin_triggered()
{
    lDialog = new logindialog;
    lDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    lDialog->exec();
    isAdministrator = lDialog->getIsLoggedIn();
    delete lDialog;
}

/*!
 * \brief MainWindow::on_actionLog_Out_triggered
 */
void MainWindow::on_actionLog_Out_triggered()
{
    if(!isAdministrator) {
        QMessageBox::information(this, "Error", "User is not logged in.");
    }else{
        QMessageBox::information(this, "Success", "User is now logged out.");
        isAdministrator = false;
    }
}

/*!
 * \brief MainWindow::on_actionAdd_Shape_triggered
 */
void MainWindow::on_actionAdd_Shape_triggered()
{
    if(!isAdministrator) {
        QMessageBox::information(this, "Error", "You must be logged in to add shapes.");
    }else {
        addShapeDialog = new addShape(this, ui->renderWidget->getnumShapesRA());
        addShapeDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
        addShapeDialog->exec();
        shapeCount = ui->renderWidget->getnumShapesRA();

        // add the shape created previously to vector
        // if no shape created, pass
        if (addShapeDialog->getNewShape() != nullptr) {
            ui->renderWidget->addShape(addShapeDialog->getNewShape());
        }

        delete addShapeDialog;
    }
}

/*!
 * \brief MainWindow::on_actionRemove_Shape_triggered
 */
void MainWindow::on_actionRemove_Shape_triggered()
{
    if(!isAdministrator) {
        QMessageBox::information(this, "Error", "You must be logged in to delete shapes.");
    }else {
        if(ui->renderWidget->getnumShapesRA() == 0) { // TODO change to vector
            QMessageBox::information(this, "Error", "There are no shapes to delete.");
        }else {
            delShapeDialog = new deleteshape(this, ui->renderWidget->getnumShapesRA(), ui->renderWidget->getShapes());
            delShapeDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
            delShapeDialog->exec();
            shapeCount = delShapeDialog->getShapeCount();
            delete delShapeDialog;
        }
    }
}

// !!! TEMPORARY !!!
void MainWindow::on_actiondebug_shapeCount_triggered()
{
    qDebug() << "shapeCount in mainWindow: " << ui->renderWidget->getnumShapesRA();

}

void MainWindow::on_actionComments_triggered()
{
    commentsDialog = new comments;
    commentsDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    commentsDialog->exec();
    delete  commentsDialog;
}
