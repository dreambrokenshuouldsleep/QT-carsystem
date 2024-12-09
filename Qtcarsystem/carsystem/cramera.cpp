#include "cramera.h"
#include "ui_cramera.h"

#include <QDebug>
cramera::cramera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cramera)
{
    ui->setupUi(this);
    volume = 0;
    state = 0;
    ui->pushButton_fast->setEnabled(false);
    ui->pushButton_next->setEnabled(false);
    ui->pushButton_pause->setEnabled(false);
    ui->pushButton_prev->setEnabled(false);
    ui->pushButton_slow->setEnabled(false);
    ui->horizontalSlider_video->setEnabled(false);
    ui->horizontalSlider_volume->hide();

    v = new QProcess(this);
    get_time = new QTimer(this);
    update_time = new QTimer(this);
    QObject::connect(get_time , &QTimer::timeout ,this, &cramera::send_process);
    QObject::connect(v ,&QProcess::readyRead, this ,&cramera::set_time_process);
    QObject::connect(update_time , &QTimer::timeout ,this, &cramera::update_process);
}

cramera::~cramera()
{
    delete ui;
}

void cramera::on_pushButton_home_clicked()
{
    v->close();
    get_time->stop();
    update_time->stop();
    this->parentWidget()->show();
    this->hide();
}

void cramera::send_process()
{
    v->write("get_time_pos\n");
}

void cramera::set_time_process()
{
    QString temp = v->readAll();
    QString timelength = temp;
    //qDebug() << temp;
    if(temp.indexOf("ANS_LENGTH=") != -1)
        {
            timelength = timelength.mid(timelength.indexOf("ANS_LENGTH=")+11);
            //qDebug() << timelength;
            timelength = timelength.left(timelength.indexOf('.'));
            //qDebug() << timelength;
            timetotal = timelength.toInt();
            qDebug() << timetotal;
        }
        //当前播放时间ANS_TIME_POSITION get_time_pos
    QString timepos = temp;
    if(temp.indexOf("ANS_TIME_POSITION=") != -1)
    {
        timepos = timepos.mid(timepos.indexOf("ANS_TIME_POSITION=")+18);
        //qDebug() << timepos;
        timepos = timepos.left(timepos.indexOf('.'));
        //qDebug() << timepos;
        timecurrent = timepos.toInt();
        //qDebug() << timecurrent;
    }
}
void cramera::update_process()
{
    QString time_text = QString("%01:%02/%03:%04").
    arg(timecurrent/60).arg(timecurrent%60).arg(timetotal/60).arg(timetotal%60);
    ui->label->setText(time_text);
    ui->horizontalSlider_video->setMaximum(0);
    ui->horizontalSlider_video->setMaximum(timetotal);
    ui->horizontalSlider_video->setValue(timecurrent);
}
void cramera::on_pushButton_volume_clicked()
{
    if(volume == 0)
    {
        ui->horizontalSlider_volume->show();
        volume = 1;
    }
    else {
        ui->horizontalSlider_volume->hide();
        volume = 0;
    }
}

void cramera::on_pushButton_add_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      "选择打开文件路径",
                                                      "/home",
                                                      "Vedio(*.avi *.mp4)");
    ui->listWidget->addItems(files);
    ui->listWidget->setCurrentRow(0);
    count = ui->listWidget->count();
    if(count != 0)
    {
        ui->pushButton_fast->setEnabled(true);
        ui->pushButton_next->setEnabled(true);
        ui->pushButton_pause->setEnabled(true);
        ui->pushButton_prev->setEnabled(true);
        ui->pushButton_slow->setEnabled(true);
    }

}

void cramera::on_pushButton_slow_clicked()
{
    v->write("seek 5\n");
}

void cramera::on_pushButton_prev_clicked()
{
    v->close();
    int row = ui->listWidget->currentRow();
    row--;
    if(row < 0 )
    {
        row = count-1;
    }
    ui->listWidget->setCurrentRow(row);
    v->start(QString("mplayer -quiet -slave  -zoom  -x 600 -y 360  %1").arg(ui->listWidget->currentItem()->text()));
}


void cramera::on_pushButton_pause_clicked()
{
    //state表示播放状态1正在播放,0停止
    if(state == 1)
    {
        state = 0;
        v->write("pause\n");
        ui->pushButton_pause->setStyleSheet("QPushButton{border-image: url(:/music/pause.png);}");
    }
    else {
         state = 1;
         v->write("pause\n");
         ui->pushButton_pause->setStyleSheet("QPushButton{border-image: url(:/music/play.png);}");
    }
}

void cramera::on_pushButton_next_clicked()
{
    v->close();
    int row = ui->listWidget->currentRow();
    row++;
    if(row >= count)
    {
        row = 0;
    }
    ui->listWidget->setCurrentRow(row);
    v->start(QString("mplayer -quiet -slave  -zoom  -x 600 -y 360  %1").arg(ui->listWidget->currentItem()->text()));
}

void cramera::on_pushButton_fast_clicked()
{
    v->write("seek -5\n");
}

void cramera::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(state == 1)
    {
        v->close();
    }
    QString vid = QString("mplayer -quiet -slave  -zoom  -x 600 -y 360  %1")
            .arg(item->text());
     v->start(vid);
     state = 1;
    ui->pushButton_pause->setStyleSheet("QPushButton{border-image: url(:/music/play.png);}");
    ui->horizontalSlider_video->setEnabled(true);
    get_time->start(1000);
    update_time->start(1000);
}

void cramera::on_horizontalSlider_volume_sliderMoved(int position)
{
    QString volume = QString("volume %1 1\n").arg(position);
    v->write(volume.toUtf8());
}

void cramera::on_del_clicked()
{
    int row = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->takeItem(row);
    if(item)
        delete item;
    count--;
    if(ui->listWidget->count() == 0)
    {
        ui->pushButton_fast->setEnabled(false);
        ui->pushButton_next->setEnabled(false);
        ui->pushButton_pause->setEnabled(false);
        ui->pushButton_prev->setEnabled(false);
        ui->pushButton_slow->setEnabled(false);
        ui->horizontalSlider_video->setEnabled(false);
    }
}

void cramera::on_horizontalSlider_video_sliderPressed()
{
    update_time->stop();
}

void cramera::on_horizontalSlider_video_sliderReleased()
{
    QString temp = QString("SEEK %1 2\n").arg(ui->horizontalSlider_video->value());
    v->write(temp.toUtf8());
    update_time->start();

}
