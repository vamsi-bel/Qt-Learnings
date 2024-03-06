#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructed Test" << this;
}

Test::~Test()
{
    qInfo() << "Deconstructed Test" << this;
}
