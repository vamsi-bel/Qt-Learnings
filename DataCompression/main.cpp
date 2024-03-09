#include <QCoreApplication>
#include <QDebug>

void print(const QByteArray& data)
{
    qInfo() << "Size:" << data.size();
    qInfo() << "Data:" << data;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data("This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying"
                    "This a very long line and it is so annoying");

    QByteArray compressed = qCompress(data,9);
    QByteArray decompressed = qUncompress(compressed);

    print(compressed);
    qInfo() << "\n-------------------------------------\n";
    print(decompressed);

    return a.exec();
}
