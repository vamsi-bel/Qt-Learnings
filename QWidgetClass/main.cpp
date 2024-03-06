#include <QApplication>
#include "rockwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RockWidget r;
    r.show();
    return a.exec();
}
