#include "intercepted.h"
#include <math.h>
#include <QDebug>

Intercepted::Intercepted()
{
    angle = 0;
    speed = 1500/300;
    setPos(mapToParent(0,0));
    time=0;
    chased = 0;
}

Intercepted::Intercepted(qreal x, qreal y, qreal w,qreal h)
{
    speed = h/300;
    setRotation(w);
    setPos(mapToParent(x/30,y/30));
    time=0;
    chased = 0;
}

Intercepted::~Intercepted()
{

}

QRectF Intercepted::boundingRect() const
{
    return QRect(-10,-10,20,20);
}

void Intercepted::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::black);
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

void Intercepted::advance(int phase)
{
    QPointF location = this->pos();
    if(!phase){
        return;
    }
    angle=57.29*atan(0.5*cos(0.05*location.x()));
    setRotation(angle);
    setPos(mapToParent(speed,0));
}

void Intercepted::InRange(qreal range, QPointF pos)
{
    QPointF target = this->pos();
    qreal r;
    qreal x;
    qreal y;
    x = fabs(target.x()-pos.x());
    y = fabs(target.y()-pos.y());
    r = sqrt(pow(x,2)+pow(y,2));
    if(r<=range)
    {
        emit mirrored(this);
        chased = 1;

    }
}

