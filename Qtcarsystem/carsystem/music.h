#ifndef MUSIC_H
#define MUSIC_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QListWidgetItem>
#include <QProcess>
#include <QPixmap>
#include <QPushButton>
#include <QSlider>
#include <QStringList>
#include <QTimer>
#include <QMutex>
namespace Ui {
class Music;
}

class Music : public QMainWindow
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    ~Music();
    void set_music_text(int time);

    void get_music_text();

    void update_process();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_play_clicked();

    void on_pushButton_3_clicked();

    //void on_horizontalSlider_sliderMoved(int position);

    void on_verticalSlider_sliderMoved(int position);

    void on_del_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

    void set_time_process();

    void send_process();

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

private:
    Ui::Music *ui;
    QProcess *p;
    qint16 state;
    qint16 volum_state;
    qint16 count;
    qint16 play;//是否播放过
    QTimer * get_time;//获取时间定时器
    quint16   timetotal;//总时间长度
    quint16  timecurrent;//当前时间进度
    QString timepos;
    QString timelength;
    QStringList time;//歌词时间信息
    QStringList Text;//歌词文本信息
    QMutex mutex;
    quint16 flag;
    quint16 percentcurrent;
    QTimer * update_time;
};

#endif // MUSIC_H
