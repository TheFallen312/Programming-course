#ifndef AAG_H
#define AAG_H

#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QObject>

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
    void shot();


protected:
    void advance(int phase);
signals:
    void Peleng(qreal R, QPointF pos);
public slots:
    void Intercept();
private:
    qreal AAG_X;
    qreal AAG_Y;
    qreal range;
    int rocket_amount;
    qreal prep_time;
    qreal launch_time;
    qreal targeting_time;
    qreal reloading_time;


};

#endif // AAG_H
