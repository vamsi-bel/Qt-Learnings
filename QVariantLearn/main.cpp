#include <QCoreApplication>
#include <QDebug>
#include <QVariant>

void test(QVariant value)  //COPY
{
    qInfo() << value;

    //Limitation - programmer has to figure out the data type.
    int i = 0;
    bool ok = false;

    i = value.toInt(&ok);
    if(ok)
    {
        qInfo() << "Int " << i;
    }
    else
    {
        qInfo() << "Not an Int";
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVariant value = 1;
    QVariant value2 = "Hello World!";
    test(value);
    test(value2);
    return a.exec();
}
