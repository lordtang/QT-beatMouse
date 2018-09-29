#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <myitem.h>

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);

signals:

public slots:

private:
    myItem *item;
};

#endif // MYSCENE_H
