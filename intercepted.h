#ifndef INTERCEPTED_H
#define INTERCEPTED_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsScene>
#include "aag.h"

class Intercepted : public QGraphicsObject
{
Q_OBJECT
public:
    Intercepted();
    Intercepted(qreal x,qreal y,qreal w,qreal h);
    ~Intercepted();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool chased;

protected:
    void advance(int phase);
signals:
    void mirrored(Intercepted *target);
    void IsCollision();
public slots:
    void InRange(qreal range, QPointF pos);
private:
    qreal angle;
    qreal speed;
    qreal time;


};

#endif // INTERCEPTED_H
