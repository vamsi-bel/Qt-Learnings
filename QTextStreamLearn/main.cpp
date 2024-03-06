#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void write(QFile& file)
{
    if(!file.isWritable())
    {
        qInfo() << "Unable to write to file";
        return;
    }
    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::LastEncoding);

    stream.seek(file.size());
    for(int i = 0; i < 5; i++)
    {
        stream << QString::number(i) << "-Item\r\n";
    }
    stream.flush();
    qInfo() << "File written";
}

void read(QFile& file)
{
    if(!file.isReadable())
    {
        qInfo() << "Unable to read the file";
        return;
    }
    QTextStream stream(&file);
    stream.seek(0);
    while(!stream.atEnd())
    {
        qInfo() << stream.readLine();
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("test.txt");
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream;
        qInfo() << "Encoding:" << stream.encoding();
        write(file);
        read(file);

        file.close();
    }
    else
        qCritical() << file.errorString();
    return a.exec();
}
