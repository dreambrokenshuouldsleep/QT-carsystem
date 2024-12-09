#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "weather.h"
#include "music.h"
#include "cramera.h"
#include "mymap.h"
#include "opencamera.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    weather * ui1;
    Music * ui2;
    cramera * ui3;
    mymap *ui4;
    QDateTime date_time;
    QTimer * time;
    opencamera *ui5;
};
#endif // MAINWINDOW_H
