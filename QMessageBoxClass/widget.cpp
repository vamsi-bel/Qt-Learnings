#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //setMinimumSize(300,100);
    QPushButton *button = new QPushButton(this);
    button->setText("Click Me");
    button->move(200,200);
    connect(button,&QPushButton::clicked,[=]()
            {
                /*
                QMessageBox msg;
                msg.setMinimumSize(300,200);
                msg.setWindowTitle("Message Title");
                msg.setText("Something happened");
                msg.setInformativeText("Do you want to do something about it?");
                msg.setIcon(QMessageBox::Critical);
                msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                msg.setDefaultButton(QMessageBox::Cancel);
                auto ret = msg.exec();
                */
                //auto ret = QMessageBox::critical(this,"Message Title", "Something happened. Do you want to do something about it?", QMessageBox::Cancel | QMessageBox::Ok);
                //auto ret = QMessageBox::information(this,"Message Title", "Something happened. Do you want to do something about it?", QMessageBox::Cancel | QMessageBox::Ok | QMessageBox::Ignore);
                //auto ret = QMessageBox::warning(this,"Message Title", "Something happened. Do you want to do something about it?", QMessageBox::Cancel | QMessageBox::Ok | QMessageBox::Ignore);
                auto ret = QMessageBox::question(this,"Message Title", "Something happened. Do you want to do something about it?", QMessageBox::Cancel | QMessageBox::Ok | QMessageBox::Ignore);
                if(ret == QMessageBox::Ok)
                    qDebug() << "User clicked Ok";
                else
                    qDebug() << "User clicked Cancel";
            });
}

Widget::~Widget()
{
}

