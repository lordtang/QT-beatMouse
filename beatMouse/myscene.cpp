#include "myscene.h"

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    this->item = new myItem;
    this->addItem(this->item);

}
