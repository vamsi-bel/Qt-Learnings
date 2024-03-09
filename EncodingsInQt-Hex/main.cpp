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
 *
 *
 */
QString makeData()
{
    QString data;
    for(int i = 0; i < 10; ++i)
    {
        data.append("Hello\r\n");
    }
    return data;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString data = makeData();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded = bytes.toHex();
    QByteArray decoded = QByteArray::fromHex(encoded);

    QString name = "My name is Vamsi\n";
    QByteArray encodedName(name.toLatin1().toBase64());
    QByteArray decodedName = QByteArray::fromBase64(encodedName);
    //qInfo() << "Encoded:" << encoded;
    //qInfo() << "Decoded:" << decoded;

    qInfo() << "Encoded:" << encodedName;
    qInfo() << "Decoded:" << decodedName;


    return a.exec();
}
