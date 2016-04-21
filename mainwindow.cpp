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

    Intercepted *item1 = new Intercepted(-2000,-3000,0,2000);
    scene->addItem(item1);
    AAG *item2 = new AAG();
    scene->addItem(item2);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),scene,SLOT(advance()));
    connect(item2,SIGNAL(Peleng(qreal,QPointF)),item1,SLOT(InRange(qreal,QPointF)));
    connect(item1,SIGNAL(mirrored(Intercepted*)),this,SLOT(Intercept(Intercepted*)));


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
    if(!target->chased)
    {
        Interceptor *item = new Interceptor(0,0,2000,target);
        scene->addItem(item);
        connect(item,SIGNAL(IsCollision()),this,SLOT(StopTimer()));
    }

}
