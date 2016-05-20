#ifndef INTERCEPTED_H
#define INTERCEPTED_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsScene>


class Intercepted : public QGraphicsObject
{
Q_OBJECT
public:
    Intercepted();
    Intercepted(qreal x,qreal y,qreal w,qreal h);
    ~Intercepted();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


protected:
    void advance(int phase);
signals:
    void mirrored(Intercepted *target);
    void IsCollision();
    void Destroyed();
public slots:
    void InRange(qreal range, QPointF pos);
    void Hit();
private:
    qreal angle;
    qreal speed;
    qreal time;
    int battlegroup_amount;


};

#endif // INTERCEPTED_H
