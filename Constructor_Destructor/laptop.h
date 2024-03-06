#ifndef LAPTOP_H
#define LAPTOP_H

#include <QObject>
#include <QString>
#include <QDebug>

class laptop : public QObject
{
    Q_OBJECT
public:
    explicit laptop(QObject *parent = nullptr, QString name="");
    ~laptop();

    int weight;
    QString name;
    double asKilo();
    void test();

signals:

};

#endif // LAPTOP_H
