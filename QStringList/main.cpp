#include <QCoreApplication>
//List of strings
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data = "Hello World! how are you?";
    QStringList lst = data.split(" ");
    qInfo() << lst;

    foreach(QString str, lst)
        qInfo() << str;

    lst.sort(Qt::CaseInsensitive);
    qInfo() << lst;

    QString myVar = "Hello";

    if(lst.contains(myVar))
    {
        int index = lst.indexOf(myVar);
        qInfo() << lst.value(index);
    }
    return a.exec();
}
