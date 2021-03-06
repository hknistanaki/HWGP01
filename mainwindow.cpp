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

    isAdministrator = false;
    //shapeCount = 0;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete cWindow;
    //delete canvas;
}

void MainWindow::on_actionContact_Us_triggered()
{
    // Only create one contact us window per program execution
    if(cWindow == nullptr) {
        cWindow = new ContactUs(this);
    }

    cWindow->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    cWindow->show();

}

void MainWindow::on_actionLogin_triggered()
{
    lDialog = new logindialog;
    lDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    lDialog->exec();
    isAdministrator = lDialog->getIsLoggedIn();
    delete lDialog;
}

void MainWindow::on_actionLog_Out_triggered()
{
    if(!isAdministrator) {
        QMessageBox::information(this, "Error", "User is not logged in.");
    }else{
        QMessageBox::information(this, "Success", "User is now logged out.");
        isAdministrator = false;
    }
}

void MainWindow::on_actionAdd_Shape_triggered()
{
    if(!isAdministrator) {
        QMessageBox::information(this, "Error", "You must be logged in to add shapes.");
    }else {
        addShapeDialog = new addShape(this, ui->renderWidget->getnumShapesRA());
        addShapeDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
        addShapeDialog->exec();
        //shapeCount = ui->renderWidget->getnumShapesRA();

        // add the shape created previously to vector
        // if no shape created, pass
        if (addShapeDialog->getNewShape() != nullptr) {
            ui->renderWidget->addShape(addShapeDialog->getNewShape());
        }

        delete addShapeDialog;
    }
}

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

            // delete the shape from the render area
            // delete by shape id and not index in vector
            if(delShapeDialog->getToDelete() > -1) {
                ui->renderWidget->chopShape(delShapeDialog->getToDelete()+1);
                //shapeCount = ui->renderWidget->getnumShapesRA();
            }
            delete delShapeDialog;
        }
    }
}

void MainWindow::on_actionComments_triggered()
{
    commentsDialog = new comments;
    commentsDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    commentsDialog->exec();
    delete  commentsDialog;
}

void MainWindow::on_actionShape_Report_triggered()
{
    sDialog = new ShapeListing(this, ui->renderWidget->getShapes());
    sDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    sDialog->exec();

    delete sDialog;
}

void MainWindow::on_actionModify_Shape_triggered()
{

    if(!isAdministrator) {
        QMessageBox::information(this, "Error", "You must be logged in to modify shapes.");
    }else {
        if(ui->renderWidget->getnumShapesRA() == 0) {
            QMessageBox::information(this, "Error", "There are no shapes to modify.");
        }else {
            modDialog = new ModifyShapes(this, ui->renderWidget->getShapes());
            modDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
            modDialog->exec();

            // if a shape was modified, replace it in the RenderArea vector
            if(modDialog->getModShape() != nullptr) {

                ui->renderWidget->replaceShape(modDialog->getModIndex(), modDialog->getModShape());
            }

            delete modDialog;
        }
    }
}
