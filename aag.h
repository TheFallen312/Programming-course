#ifndef AAG_H
#define AAG_H

#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QObject>
#include "intercepted.h"

// AAG class description. Git Test.

class AAG : public QGraphicsObject
{
Q_OBJECT
public:
    AAG();
    AAG(qreal x,qreal y,qreal r);
    ~AAG();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool ready;

protected:
    void advance(int phase);
signals:
    void Peleng(qreal R, QPointF pos);
    void Launch(Intercepted *target);
    void Prep();
    void Reload();
public slots:
    void Intercept();
    void Shot(Intercepted* target);
    void SetReady();
private:
    qreal AAG_X;
    qreal AAG_Y;
    qreal range;
    int rocket_amount;
    qreal targeting_time;
    qreal launch_time;
    qreal reload_time;

};

#endif // AAG_H
