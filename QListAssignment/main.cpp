#include <QCoreApplication>
#include <QList>
#include <QDebug>
QList<int> makeList()
{
    QList<int> list;
    for(int i=0; i < 20; ++i)
        list << i*3;

    return list;
}

void find(QList<int> list, int value)
{
    int pos = list.indexOf(value);
    if(pos < 0)
    {
        qInfo() << "Item not found";
        return;
    }
    qInfo() << "At:" << pos << "value" << list.at(pos);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list = makeList();
    qInfo() << list;
    find(list,4);
    return a.exec();
}
