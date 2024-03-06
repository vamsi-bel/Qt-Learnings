#include <QCoreApplication>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QDebug>
#include "test.h"

void test()
{
    QScopedPointer<Test> sp(new Test());
    sp->setObjectName("My Test");

    qInfo() << "Scoped Pointer " << &sp;
    qInfo() << "Pointer data" << sp.data();
    qInfo() << sp->objectName();
}

QSharedPointer<Test> getObject(QString name)
{
    QSharedPointer<Test> sp(new Test());
    sp->setObjectName(name);

    return sp;
}

void doWork(QSharedPointer<Test> sp)
{
    qInfo() << "Work: " << sp.data();
    qInfo() << "Shared Pointer:" << &sp;
}

void test2()
{
    qInfo() << "Getting the object";
    QSharedPointer<Test> ptr = getObject("My Object");
    qInfo() << "SharedPointer" << &ptr;
    qInfo() << "Object" << ptr.data();

    doWork(ptr);

    qInfo() << "Complete";
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test2();
    qDebug() << "Scope ends";

    return a.exec();
}
