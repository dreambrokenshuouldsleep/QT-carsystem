#ifndef OPENCAMERA_H
#define OPENCAMERA_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QImage>
#include <QPixmap>
namespace Ui {
class opencamera;
}

class opencamera : public QMainWindow
{
    Q_OBJECT

public:
    explicit opencamera(QWidget *parent = nullptr);
    ~opencamera();
    void time_out();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::opencamera *ui;
//    cv::VideoCapture  cap;
//    cv::Mat image; //数据帧
    QTimer * time;
};

#endif // OPENCAMERA_H
