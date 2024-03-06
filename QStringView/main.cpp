#include <QCoreApplication>
#include <QStringView>
#include <QString>
#include <QDebug>

QStringView genView()
{
    QString v = "Hello World!";
    return v;
}
void display(QStringView view)
{
    qInfo() << view.toString();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "Hello world! How are you?";
    display(genView());
    return a.exec();
}
