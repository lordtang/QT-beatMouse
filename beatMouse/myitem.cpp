#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include <handler.h>
#include <QCursor>

myItem::myItem()
{
    this->setPixmap(QPixmap(":/bg/5.png"));
    this->start = false;
    this->mouse = false;
    this->setCursor(QCursor(QPixmap(":/bg/7.png")));
}
void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}
//重写鼠标事件，让鼠标按下的时候有所反应
void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/bg/7.png")));
    if(this->isStart())
    {
        handler * hand = handler::getInstance();
        if(this->isMouse())
        {
            hand->addscore();
        }else
        {
            qDebug()<<"打的不是老鼠";
        }
    }

}
void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/bg/8.png")));
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
