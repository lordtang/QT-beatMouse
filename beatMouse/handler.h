#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

class handler : public QObject
{
    Q_OBJECT



private:
    static handler *hand;
    explicit handler(QObject *parent = nullptr);
public:
    void addscore();   //被调用时向外发射beatMouse()信号
    static handler * getInstance();


signals:
    void beatMouse();

public slots:
};

#endif // HANDLER_H
