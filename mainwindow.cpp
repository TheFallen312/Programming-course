#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "intercepted.h"
#include "interceptor.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush blackbrush(Qt::black);
    QBrush redbrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);

    Intercepted *item1 = new Intercepted(-2,-2,0,1500);
    scene->addItem(item1);
    AAG *item2 = new AAG(0,0,10);
    scene->addItem(item2);

    timer = new QTimer(this);
    Launch_timer = new QTimer(this);
    Launch_timer->setSingleShot(true);
    Reload_timer = new QTimer(this);
    Reload_timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()),scene,SLOT(advance()));
    connect(item2,SIGNAL(Peleng(qreal,QPointF)),item1,SLOT(InRange(qreal,QPointF)));
    connect(item1,SIGNAL(mirrored(Intercepted*)),item2,SLOT(Shot(Intercepted*)));
    connect(item2,SIGNAL(Launch(Intercepted*)),this,SLOT(Intercept(Intercepted*)));
    connect(item1,SIGNAL(Destroyed()),this,SLOT(StopTimer()));
    connect(item2,SIGNAL(Prep()),this,SLOT(Launch_prep()));
    connect(item2,SIGNAL(Reload()),this,SLOT(Reload()));
    connect(Launch_timer,SIGNAL(timeout()),item2,SLOT(SetReady()));
    connect(Reload_timer,SIGNAL(timeout()),item2,SLOT(SetReady()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(100);
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}

void MainWindow::StopTimer()
{
    timer->stop();
}

void MainWindow::Intercept(Intercepted *target)
{
    Interceptor *item = new Interceptor(0,0,2000,target);
    scene->addItem(item);
    connect(item,SIGNAL(IsCollision()),target,SLOT(Hit()));

}

void MainWindow::Launch_prep()
{
    Launch_timer->start(500);

}

void MainWindow::Reload()
{
    Launch_timer->start(2000);

}
