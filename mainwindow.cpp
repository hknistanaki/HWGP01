#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactUs.h"
#include "logindialog.h"
#include "comments.h"

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // initialize pointer members to nullptr
    cWindow = nullptr;
    lDialog = nullptr;
    addShapeDialog = nullptr;
    delShapeDialog = nullptr;
    commentsDialog = nullptr;

    shapeCount = 0; // DEBUG TODO remove

    isAdministrator = true;
    ui->setupUi(this);
}

/*!
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete cWindow;
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
        addShapeDialog = new addShape(this, shapeCount);
        addShapeDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
        addShapeDialog->exec();
        shapeCount = addShapeDialog->getShapeCount();
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
        if(shapeCount == 0) { // TODO change to vector
            QMessageBox::information(this, "Error", "There are no shapes to delete.");
        }else {
            delShapeDialog = new deleteshape(this, shapeCount);
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
    qDebug() << "shapeCount in mainWindow: " << shapeCount;
}

void MainWindow::on_actionComments_triggered()
{
    commentsDialog = new comments;
    commentsDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    commentsDialog->exec();
    delete  commentsDialog;
}
