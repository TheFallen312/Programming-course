#include "aag.h"
#include "intercepted.h"

AAG::AAG()
{
    AAG_X = 0;
    AAG_Y = 0;
    range = 200;

}

AAG::AAG(qreal x, qreal y, qreal r)
{
    AAG_X = x;
    AAG_Y = y;
    range = r*100;
    setPos(mapToParent(AAG_X,AAG_Y));
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

