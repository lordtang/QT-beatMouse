#include "myscene.h"
#include <stdlib.h>

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    int i = 0;
    for(i = 0;i<16;i++){
        this->item[i] = new myItem;
        this->item[i]->setPos(i/4 * this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }

    this->ptimer = new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));
}
void myScene::showMouse()
{
    //产生一个随机数，0-15
    //先生成1-3个
    int count = rand()%3+1;
    int i = 0;
    for(i = 0;i<16;i++)
    {
        this->item[i]->setPic(":/bg/5.png");
        this->item[i]->setMouse(false);
    }
    for(i = 0;i<count;i++){
        int index = rand()%16;
        this->item[index]->setPic(":/bg/6.png");
        this->item[index]->setMouse(true);

    }
}
void myScene::startGame()
{
    int i = 0;
    for(i = 0;i<16;i++)
    {
        this->item[i]->setStart(true);
    }
    this->ptimer->start(800);
}
void myScene::pauseGame()
{
    this->ptimer->stop();
    int i = 0;
    for(i= 0;i<16;i++){
        this->item[i]->setStart(false);
    }
}

void myScene::stopGame()
{
    this->ptimer->stop();
    int i = 0;
    for(i = 0;i<16;i++)
    {
        this->item[i]->setPic(":/bg/5.png");
        this->item[i]->setMouse(false);
        this->item[i]->setStart(false);

    }
}
