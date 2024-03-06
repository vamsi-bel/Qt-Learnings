#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug() << "Submitting data..";
    qDebug() << "First Name is: " << ui->fName_lineEdit->text();
    qDebug() << "Last Name is: " << ui->lName_lineEdit_2->text();
    qDebug() << "Message: " << ui->msg_textEdit->toPlainText();

}

