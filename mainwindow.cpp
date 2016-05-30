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


    item2 = new AAG(0,0,10);
    scene->addItem(item2);
    DC=0;
    timer = new QTimer(this);
    tar_timer = new QTimer(this);
    Launch_timer = new QTimer(this);
    Launch_timer->setSingleShot(true);
    Reload_timer = new QTimer(this);
    Reload_timer->setSingleShot(true);
    sim_timer = new QTimer(this);
    sim_timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()),scene,SLOT(advance()));
    connect(item2,SIGNAL(Launch(Intercepted*)),this,SLOT(Intercept(Intercepted*)));
    connect(item2,SIGNAL(Prep()),this,SLOT(Launch_prep()));
    connect(item2,SIGNAL(Reload()),this,SLOT(Reload()));
    connect(Launch_timer,SIGNAL(timeout()),item2,SLOT(SetReady()));
    connect(Reload_timer,SIGNAL(timeout()),item2,SLOT(SetReady()));
    connect(tar_timer,SIGNAL(timeout()),this,SLOT(Launch_target()));
    connect(sim_timer,SIGNAL(timeout()),this,SLOT(StopTimer()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(100);
    tar_timer->start(tar_time);
    sim_timer->start(sim_time);
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}

void MainWindow::StopTimer()
{
    timer->stop();
    tar_timer->stop();
}

void MainWindow::Intercept(Intercepted *target)
{
    Interceptor *item = new Interceptor(0,0,InterceptSpeed,target);
    scene->addItem(item);
    connect(item,SIGNAL(IsCollision()),target,SLOT(Hit()));
    connect(target,SIGNAL(Destroyed()),item,SLOT(Destruction()));

}

void MainWindow::Launch_prep()
{
    Launch_timer->start(item2->getLaunch_time());

}

void MainWindow::Reload()
{
    Launch_timer->start(item2->getReload_time());

}

void MainWindow::Launch_target()
{
    qreal y;
    y = qrand()%tar_y;
    Intercepted *item = new Intercepted(tar_x,-y/100,0,tar_speed);
    scene->addItem(item);
    connect(item2,SIGNAL(Peleng(qreal,QPointF)),item,SLOT(InRange(qreal,QPointF)));
    connect(item,SIGNAL(mirrored(Intercepted*)),item2,SLOT(Shot(Intercepted*)));
    connect(item,SIGNAL(Destroyed()),this,SLOT(Destroyed_Count()));
}



void MainWindow::on_pushButton_3_clicked()
{
    QString LT = ui->lineEdit_3->text();
    item2->setLaunch_time(LT.toDouble());
    QString LR = ui->lineEdit_4->text();
    item2->setReload_time(LR.toDouble());
    QString Range = ui->lineEdit->text();
    item2->setRange(Range.toDouble());
    QString Speed = ui->lineEdit_2->text();
    InterceptSpeed = Speed.toDouble();
    QString TT = ui->lineEdit_7->text();
    tar_time = TT.toDouble();
    QString tx = ui->lineEdit_5->text();
    tar_x = tx.toDouble();
    QString ty = ui->lineEdit_6->text();
    tar_y = ty.toInt();
    QString TS = ui->lineEdit_8->text();
    tar_speed = TS.toDouble();
    QString ST = ui->lineEdit_9->text();
    sim_time = ST.toDouble();


}

void MainWindow::Destroyed_Count()
{

    DC++;
    ui->lineEdit_10->setText(QString::number(DC));

}
