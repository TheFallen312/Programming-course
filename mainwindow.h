#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsEllipseItem>
#include "intercepted.h"
#include "interceptor.h"
#include "aag.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void StopTimer();

    void Intercept(Intercepted *target);

    void Launch_prep();

    void Reload();

    void Launch_target();

    void on_pushButton_3_clicked();

    void Destroyed_Count();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *tar_timer;
    qreal tar_time;
    QTimer *Launch_timer;
    QTimer *Reload_timer;
    AAG *item2;
    qreal InterceptSpeed;
    qreal tar_speed;
    qreal tar_x;
    int tar_y;
    QTimer *sim_timer;
    qreal sim_time;
    int DC;

};

#endif // MAINWINDOW_H
