#ifndef AAG_H
#define AAG_H

#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QObject>

class AAG : public QGraphicsObject
{
Q_OBJECT
public:
    AAG();
    AAG(qreal x,qreal y,qreal r);
    ~AAG();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

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

};

#endif // AAG_H
