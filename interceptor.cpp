#include "interceptor.h"
#include <math.h>

Interceptor::Interceptor()
{
    angle = 0;
    speed = 5;
    setPos(mapToParent(0,0));
}


Interceptor::Interceptor(qreal x, qreal y, qreal h, Intercepted *item)
{
    speed = (h*0.28)/100;
    setPos(mapToParent(x*100,y*100));
    target = item;
}



Interceptor::~Interceptor()
{

}

QRectF Interceptor::boundingRect() const
{
    return QRect(-10,-10,20,20);
}

void Interceptor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::red);
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
    if(this->collidesWithItem(target))
        emit IsCollision();
}

void Interceptor::advance(int phase)
{
    QPointF location = this->pos();
    QPointF tlocation = target->pos();
    if(!phase)
    {
        angle = 57.29*atan((tlocation.y()-location.y())/(tlocation.x()-location.x()));
        if(tlocation.x()-location.x()>=0)
            setRotation(angle);
        if(tlocation.x()-location.x()<0)
            setRotation(angle+180);


        return;
    }

    setPos(mapToParent(speed,0));

}






