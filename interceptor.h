#ifndef INTERCEPTOR_H
#define INTERCEPTOR_H

#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsScene>
#include "intercepted.h"
#include <QObject>

class Interceptor : public QGraphicsObject
{
Q_OBJECT
public:
    Interceptor();
    Interceptor(qreal x,qreal y,qreal h,Intercepted *item);
    ~Interceptor();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


protected:
    void advance(int phase);
signals:
    void IsCollision();
private:
    qreal angle;
    qreal speed;
    Intercepted *target;

};


#endif // INTERCEPTOR_H
