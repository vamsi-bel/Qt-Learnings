#include <QCoreApplication>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello world! how are you?";
    QVector<QString> list = data.split(" ");

    foreach(QString word, list)
        qInfo() << word;

    QVector<int> age{44, 56, 31, 46};
    age.append(99);
    age.remove(1);
    qInfo() << age;

    foreach(int word, age)
        qInfo() << word;

    return a.exec();
}
