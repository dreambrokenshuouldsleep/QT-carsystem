#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui1 = new weather(this);
    ui2 = new Music(this);
    ui3 = new cramera(this);
    ui4 = new mymap(this);
    ui5 = new opencamera(this);
    time = new QTimer(this);
    date_time = QDateTime::currentDateTime();
    QString date = date_time.toString("yyyy_MM_dd");
    ui->label->setText(date);
    QObject::connect(time , &QTimer::timeout
 , [this](){
        QDateTime rtc_time = QDateTime::currentDateTime();
        QString str = rtc_time.toString("hh:mm:ss");
        ui->label_2->setText(str);
    });
    time->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui1->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui2->show();
    this->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui3->show();
    this->hide();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui4->show();
    this->hide();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui5->show();
    this->hide();
}
