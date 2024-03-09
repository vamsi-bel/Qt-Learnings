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
 * UTF-8 is used for backward compatibility with ASCII.
 * UTF-16 is used where ASCII is not predominant. It uses 2-bytes per character.
 *
 * Base 64 is used for transmitting special characters
 * every base64 digit represents exactly 6 bits of data.
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
    QByteArray bytes(data.toUtf8());
    QByteArray encoded = bytes.toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << "Encoded: " << encoded;
    qInfo() << "Decoded:" << decoded;
    return a.exec();
}
