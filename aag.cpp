#include "aag.h"
#include "intercepted.h"
#include <QTimer>

AAG::AAG()
{
    AAG_X = 0;
    AAG_Y = 0;
    range = 200;
    rocket_amount=4;
    ready=true;

}

AAG::AAG(qreal x, qreal y, qreal r)
{
    AAG_X = x;
    AAG_Y = y;
    range = r*100;
    setPos(mapToParent(AAG_X,AAG_Y));
    rocket_amount=4;
    ready=true;
}

AAG::~AAG()
{

}

QRectF AAG::boundingRect() const
{
    return QRect(-10,-10,20,20);
}

void AAG::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::black);
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}


void AAG::advance(int phase)
{
    if(!phase)
        emit Peleng(range, this->pos());
}

void AAG::Intercept()
{

}

void AAG::Shot(Intercepted *target)
{
    if(ready)
    {
       if(rocket_amount>0)
        {
            ready = false;
            rocket_amount--;
            emit Prep();
            emit Launch(target);
        }
       if(rocket_amount<=0)
       {
           ready = false;
           rocket_amount=4;
           emit Reload();
       }
    }

}

void AAG::SetReady()
{
    ready = true;
}

