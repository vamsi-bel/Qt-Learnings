#include "laptop.h"

laptop::laptop(QObject *parent, QString name) : QObject(parent)
{
    this->name = name;
    qInfo() << this << "Constructor" << name;
}

laptop::~laptop()
{
    qInfo() << this << "Destructor" << name;
}

double laptop::asKilo()
{
    return weight * 0.453592;
}

void laptop::test()
{
    qInfo() << this << "Test: " << name << "Kilo: " << asKilo();
}
