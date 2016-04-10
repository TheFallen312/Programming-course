#include "intercepted.h"
#include <math.h>
#include <QDebug>

Intercepted::Intercepted()
{
    angle = 0;
    speed = 5;
    setPos(mapToParent(0,0));
    time=0;
    chased = 0;
}

Intercepted::Intercepted(qreal x, qreal y, qreal w,qreal h)
{
    speed = h;
    setRotation(w);
    setPos(mapToParent(x,y));
    time=0;
    chased = 0;
}

Intercepted::~Intercepted()
{

}

QRectF Intercepted::boundingRect() const
{
    return QRect(0,0,20,20);
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

