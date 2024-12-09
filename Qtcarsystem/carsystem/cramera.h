#ifndef CRAMERA_H
#define CRAMERA_H

#include <QMainWindow>
#include <QProcess>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QTimer>
namespace Ui {
class cramera;
}

class cramera : public QMainWindow
{
    Q_OBJECT

public:
    explicit cramera(QWidget *parent = nullptr);
    ~cramera();

private slots:

    void on_pushButton_home_clicked();

    void on_pushButton_volume_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_slow_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_fast_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_horizontalSlider_volume_sliderMoved(int position);

    void on_del_clicked();

    void on_horizontalSlider_video_sliderPressed();

    void on_horizontalSlider_video_sliderReleased();

    void send_process();

    void set_time_process();

    void update_process();

private:
    Ui::cramera *ui;
    quint16 volume;
    quint16 state;
    quint16 count;
    QProcess *v;
    QTimer * get_time;
    QTimer * update_time;
    quint16 timetotal;
    quint16 timecurrent;
};

#endif // CRAMERA_H
