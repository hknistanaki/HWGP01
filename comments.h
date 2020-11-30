#ifndef COMMENTS_H
#define COMMENTS_H

#include <QDialog>
#include <QFile>
#include <QTextBrowser>
#include <QTextStream>
#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <QIODevice>
#include <iostream>
#include <string>
#include <fstream>
#include "logindialog.h"
#include <QDir>
using namespace std;

namespace Ui {
class comments;
}

class comments : public QDialog
{
    Q_OBJECT

public:
    explicit comments(QWidget *parent = nullptr);
    ~comments();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::comments *ui;

    bool isCustomer;
};

#endif // COMMENTS_H
