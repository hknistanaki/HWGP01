#include "comments.h"
#include "ui_comments.h"
#include "logindialog.h"

comments::comments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comments)
{
    ui->setupUi(this);
    isCustomer = false;
}

comments::~comments()
{
    delete ui;
}

void comments::on_pushButton_clicked()
{
    QString line = "";
    QString customerType ="";

    if(isCustomer == true)
    {
        customerType = " (Customer)";
    }
    else
    {
        customerType = " (Guest)";
    }

    // TXT file address for saving the history of customer comments.
    QFile inputFile("D://CHEN//Downloads//HWGP01-master//HWGP01-master//CommentsFile//customerComments");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    line = in.readAll();
    ui->textBrowser->setText(line);
    inputFile.close();

    ui->textBrowser->setText(line);
    QString textString = ui->textEdit->toHtml();
    QString textPlain = ui->textEdit->toPlainText();

    ui->textBrowser->setText(line + textPlain + customerType);
    QString copyComments = ui->textBrowser->toHtml();
    ui->textBrowser->setText(copyComments);
    ui->textEdit->clear();

    QFile outputFile("D://CHEN//Downloads//HWGP01-master//HWGP01-master//CommentsFile//customerComments");
    if (outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
    QTextStream out(&outputFile);
    QString text = copyComments;
    out <<  text << "\n";
    }
    outputFile.close();
}

void comments::on_pushButton_2_clicked()
{
    this->isCustomer = true;
}
