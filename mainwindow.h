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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;

};

#endif // MAINWINDOW_H
