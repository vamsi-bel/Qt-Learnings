#include "rockwidget.h"

RockWidget::RockWidget(QWidget *parent)
    : QWidget{parent}
{
    //setBaseSize(500,500);
    setMinimumSize(sizeHint());
    QLabel *label = new QLabel("This is my label",this);
    QLabel *label1 = new QLabel(this);
    label1->setText("My colored label");
    label1->move(50,50);
    label1->setAutoFillBackground(true);
    QFont label1Font("Times",20,QFont::Bold);
    label1->setFont(label1Font);

    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window,Qt::yellow);
    label1Palette.setColor(QPalette::WindowText,Qt::blue);
    label1->setPalette(label1Palette);


    QFont buttonFont("Times New Roman", 20, QFont::Bold);
    QPushButton *button1 = new QPushButton(this);
    button1->setFont(buttonFont);
    button1->setText("Click Me");
    button1->move(70,170);

    connect(button1,SIGNAL(clicked()),this,SLOT(buttonClicked()));
}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this, "Message", "You clicked on button");
}

QSize RockWidget::sizeHint() const
{
    return QSize(400,300);
}
