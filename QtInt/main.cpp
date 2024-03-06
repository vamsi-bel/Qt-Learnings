#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint8 val8 = 0;
    qint16 val16 = 0;
    qint32 val32 = 0;
    qint64 val64 = 0;
    qintptr valueptr = 0;
    qInfo() << "val8" << sizeof(val8);
    qInfo() << "val16" << sizeof(val16);
    qInfo() << "val32" << sizeof(val32);
    qInfo() << "val64" << sizeof(val64);
    qInfo() << "valueptr" << sizeof(valueptr);
    return a.exec();
}
