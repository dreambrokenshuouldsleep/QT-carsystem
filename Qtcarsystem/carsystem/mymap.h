#ifndef MYMAP_H
#define MYMAP_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace Ui {
class mymap;
}

class mymap : public QMainWindow
{
    Q_OBJECT

public:
    explicit mymap(QWidget *parent = nullptr);
    ~mymap();

public  slots:
    void slotReadyRead();
    void show_map();

private slots:
    void on_pushButton_home_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mymap *ui;
    QNetworkReply *reply;
    QNetworkReply *map_reply;
    QNetworkAccessManager *manager;  //坐标HTTP 请求
    QNetworkAccessManager *map;  //地图HTTP 请求
    //地图的经纬度
    QString x;
    QString y;
    QFile *map_png;  //下载的地图文件
    int all_size; //下载的文件大小
    int map_zoom=11;
};

#endif // MYMAP_H
