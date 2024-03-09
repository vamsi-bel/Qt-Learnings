#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>
/*
 * It is compatible with ASCII upto first 128.
 * 1-byte to 4-byte character range.
 * It is used to work with non-english languages.
 * QString and QChar are unicode strings.
 */
QString makeData()
{
    QString data;
    data.append("Unicode test\r\n");

    for(int i = 0; i < 10; ++i)
    {
        int number = QRandomGenerator::global()->bounded(0xFFFF);
        data.append(QChar(number));
    }
    return data;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data = makeData();
    qInfo() << data;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf8);
        stream << data;
        stream.flush();
        file.close();
    }
    qInfo() << "Done";
    qInfo() << "UTF-8:" << data;
    qInfo() << "ASCII:" << data.toLatin1();
    return a.exec();
}
