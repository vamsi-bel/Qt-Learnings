#include <QCoreApplication>
#include "laptop.h"

void test(laptop& machine){
    machine.test();
}

void makeLaptop()
{
    laptop mine(nullptr, "my laptop");
    laptop yours(nullptr, "your laptop");

    mine.weight = 3;
    yours.weight = 5;

    test(mine);
    test(yours);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    makeLaptop();
    return a.exec();
}
