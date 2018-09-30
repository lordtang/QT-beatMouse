#include "handler.h"

handler::handler(QObject *parent) : QObject(parent)
{

}

handler*handler::hand = new handler;
handler*handler::getInstance()
{

}
void handler::addscore()
{
    emit beatMouse();
}
