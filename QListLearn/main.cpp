#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello world! how are you?";
    QList<QString> list = data.split(" ");

    foreach(QString word, list)
        qInfo() << word;

    QList<int> age{44, 56, 31, 46};
    age.append(99);
    age.remove(1);
    qInfo() << age;

    foreach(int word, age)
        qInfo() << word;



    //Intermediate course

    QList<int> list1;
    list1 << 1 << 2 << 3;
    for(int i=0; i < 6; ++i)
    {
        list1.append(i);
    }
    foreach(const auto& val, list1)
        qInfo() << val;
    qInfo() << list1;

    qInfo() << "length:" << list1.length();
    qInfo() << "size:" << list1.size();
    qInfo() << "count:" << list1.count();
    qInfo() << "count1:" << list1.count(4);

    list1.replace(2,99);    //2 - index (not the value), 99 - value
    qInfo() << list1;
    list1 << 3 << 3 << 3;
    qInfo() << list1;
    list1.remove(3);        //3 - index (not the value)
    qInfo() << list1;
    int s = list1.removeAll(3);     //removeALl returns the no.of elements removed
    qInfo() << list1 << "removed: " << s;
    qInfo() << "length:" << list1.length();
    qInfo() << "size:" << list1.size();
    qInfo() << "count:" << list1.count();

    auto slice = list1.sliced(2,3);
    qInfo() << "list1:" << list1;
    qInfo() << "slice:" << slice;

    qInfo() << "Contains:" << list1.contains(6);
    qInfo() << "indexof:" << list1.indexOf(2);
    return a.exec();
}
