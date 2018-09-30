#include "myitem.h"
#include <QPixmap>
#include <QDebug>

myItem::myItem()
{
    this->setPixmap(QPixmap(":/bg/5.png"));
    this->start = false;
    this->mouse = false;
}
void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}
//重写鼠标事件，让鼠标按下的时候有所反应
void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->isStart())
    {
        if(this->isMouse())
        {
            qDebug()<<"打的是老鼠";
        }else
        {
            qDebug()<<"打的不是老鼠";
        }
    }

}
void myItem::setMouse(bool mouse)
{
    this->mouse = mouse;
}

bool myItem::isMouse()
{
    return this->mouse;
}
void myItem::setStart(bool start)
{
    this->start = start;
}

bool myItem::isStart()
{
    return this->start;
}
