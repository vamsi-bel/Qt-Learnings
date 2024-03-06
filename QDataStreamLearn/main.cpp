#include <QCoreApplication>
#include <QFile>
#include <QDataStream>

bool write(QString& filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << file.errorString();
        return false;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_3);

    int age = 30;
    QString name = "Vamsi";
    double weight = 185.06;

    qInfo() << "Writing file";
    stream << age << name << weight;
    if(!file.flush())
    {
        qInfo() << file.errorString();
        file.close();
        return false;
    }
    qInfo() << "File Written";
    file.close();
    return true;
}

bool read(QString& filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo() << file.errorString();
        return false;
    }
    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_3)
    {
        qInfo() << "Wrong file version";
        file.close();
        return false;
    }
    int age;
    QString name;
    double weight;
    stream >> age >> name >> weight;
    file.close();

    qInfo() << "Name:" << name;
    qInfo() << "Age:" << age;
    qInfo() << "Weight:" << weight;
    /*
     * Order is very much important here
     * if we do stream >> age >> weight >> name;
     * it won't work.
     */
    qInfo() << "Closing file";
    file.close();
    return true;

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString filename = "test.txt";

    /*
     * Here version is important.
     * if we try to open test.txt, it shows some
     * encoded hex data. It is encoded data not
     * encrypted data.
     */
    if(write(filename)) read(filename);
    return a.exec();
}
