#include "dog.h"

Dog::Dog(QObject *parent)
    : QObject{parent}
{

}

void Dog::chase()
{
    /*if(!sender())
        return;*/
    qDebug() << "Chasing" << sender();
}
