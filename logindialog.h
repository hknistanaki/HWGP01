#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class logindialog;
}

class logindialog : public QDialog
{
    Q_OBJECT

public:

    explicit logindialog(QWidget *parent = nullptr);

    ~logindialog();

    /*!
     * \brief getIsLoggedIn
     * \return true if user has logged in successfully as Admin
     */
    bool getIsLoggedIn() {return isLoggedIn;};

private slots:
    /*!
     * \brief on_pushButton_clicked handles login button clicked event
     */
    void on_pushButton_clicked();

private:
    Ui::logindialog *ui;
    bool isLoggedIn;
};

#endif // LOGINDIALOG_H
