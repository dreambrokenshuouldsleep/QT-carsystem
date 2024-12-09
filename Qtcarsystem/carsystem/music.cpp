#include "music.h"
#include "ui_music.h"
#include <unistd.h>
Music::Music(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Music)
{
    ui->setupUi(this);
    p = new QProcess(this);
    get_time = new QTimer(this);
    update_time = new QTimer(this);
    state = 0;
    volum_state = 0;
    play = 0;
    flag = 0;
    ui->verticalSlider->hide();
    ui->verticalSlider->setValue(100);
    ui->horizontalSlider->setRange(0,100);
    QObject::connect(p ,&QProcess::readyRead, this ,&Music::set_time_process);
    QObject::connect(get_time , &QTimer::timeout ,this, &Music::send_process);
    QObject::connect(update_time , &QTimer::timeout ,this, &Music::update_process);
    //擦除listWidget边框
    ui->listWidget->setFrameShape(QListWidget::NoFrame);
    ui->pushButton_next->setEnabled(false);
    ui->pushButton_play->setEnabled(false);
    ui->pushButton_prev->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);
}

Music::~Music()
{
    delete ui;
}

void Music::send_process()
{
    p->write("get_time_pos\n");
    p->write("get_percent_pos\n");
}
void Music::set_time_process()
{
        QString temp = p->readAll();
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

void Music::update_process()
{
    QString time_text = QString("%01:%02/%03:%04").
    arg(timecurrent/60).arg(timecurrent%60).arg(timetotal/60).arg(timetotal%60);
    ui->label->setText(time_text);
    ui->horizontalSlider->setMaximum(0);
    ui->horizontalSlider->setMaximum(timetotal);
    ui->horizontalSlider->setValue(timecurrent);
    set_music_text(timecurrent);
}
//添加歌曲
void Music::on_pushButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      "选择打开文件路径",
                                                      "/home",
                                                      "Images(*.mp3)");
    ui->listWidget->addItems(files);
    count = ui->listWidget->count();
    ui->listWidget->setCurrentRow(0);
    if(count != 0)
    {
        ui->pushButton_next->setEnabled(true);
        ui->pushButton_play->setEnabled(true);
        ui->pushButton_prev->setEnabled(true);
    }
}

//退出音乐播放界面
void Music::on_pushButton_2_clicked()
{
    p->close();
    get_time->stop();
    update_time->stop();
    this->parentWidget()->show();
    this->hide();
}

//双击播放音乐
void Music::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(state == 1)
    {
        p->close();
    }
    QString mis = QString("mplayer -quiet -slave  -zoom  -x 800 -y 380  %1")
            .arg(item->text());
    p->start(mis);
    p->write("get_time_length\n");
    ui->pushButton_play->setStyleSheet("QPushButton{border-image: url(:/music/play.png);}");
    ui->horizontalSlider->setEnabled(true);
    get_music_text();
    get_time->start(1000);
    update_time->start(1000);
    state = 1;
    play = 1;
}


//播放按钮
void Music::on_pushButton_play_clicked()
{
    if(state == 1)
    {
            p->write("pause\n");
            ui->pushButton_play->setStyleSheet("QPushButton{border-image: url(:/music/pause.png);}");
            get_time->stop();
            update_time->stop();
            state = 0;
    }
    else if(state == 0)
    {
        if(play == 1)
        {
            p->write("pause\n");
            ui->pushButton_play->setStyleSheet("QPushButton{border-image: url(:/music/play.png);}");
            get_time->start(1000);
            update_time->start(1000);
            state = 1;
        }
        else
        {
            QString mis = QString("mplayer -quiet -slave  -zoom  -x 800 -y 380  %1")
                    .arg(ui->listWidget->currentItem()->text());
            p->start(mis);
            p->write("get_time_length\n");
            get_music_text();
            ui->pushButton_play->setStyleSheet("QPushButton{border-image: url(:/music/play.png);}");
            get_time->start(1000);
            update_time->start(1000);
            state = 1;
        }
    }
}

//开关调节音量
void Music::on_pushButton_3_clicked()
{
    if(volum_state == 0)
    {
        ui->verticalSlider->show();
        volum_state = 1;
    }
    else if(volum_state == 1)
    {
        ui->verticalSlider->hide();
        volum_state = 0;
    }
}

//调节音量
void Music::on_verticalSlider_sliderMoved(int position)
{
    if(state == 0)
    {
        state = 1;
        ui->pushButton_play->setStyleSheet("QPushButton{border-image: url(:/music/play.png);}");
    }
    QString volume = QString("volume %1 1\n").arg(position);
    p->write(volume.toUtf8());
}

//删除歌曲
void Music::on_del_clicked()
{
    int row = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->takeItem(row);
    if(item)
        delete item;
    count--;
    if(ui->listWidget->count() == 0)
    {
        ui->pushButton_next->setEnabled(false);
        ui->pushButton_play->setEnabled(false);
        ui->pushButton_prev->setEnabled(false);
        ui->horizontalSlider->setEnabled(false);
    }
}

//下一首
void Music::on_pushButton_next_clicked()
{
    int row = ui->listWidget->currentRow();
    row++;
    if(row >= count)
    {
        row = 0;
    }
    p->close();
    ui->listWidget->setCurrentRow(row);
    p->start(QString("mplayer -quiet -slave  -zoom  -x 800 -y 380  %1").arg(ui->listWidget->currentItem()->text()));
    get_music_text();
}
//D:\GZ2112\02文件IO\04项目一\mp3
//上一首
void Music::on_pushButton_prev_clicked()
{
    int row = ui->listWidget->currentRow();
    row--;
    if(row < 0 )
    {
        row = count-1;
    }
    p->close();
    ui->listWidget->setCurrentRow(row);
    p->start(QString("mplayer -quiet -slave  -zoom  -x 800 -y 380  %1").arg(ui->listWidget->currentItem()->text()));
    get_music_text();
}
//获取歌词文本并处理
void Music::get_music_text()
{
    QString load = ui->listWidget->currentItem()->text();
    load = load.left(load.indexOf("."));
    load = load + ".txt";
    QFile file(load);
   if(!file.open(QFile::ReadOnly))
   {
       qDebug() << "open error!";
   }
   QString str = file.readAll();
   str.remove("\n");
   QStringList list = str.split("[");
   QStringList total_list;
   for(int i = 0 ; i <list.count(); i++)
   {
        total_list += list.at(i).split("]");
   }
   total_list.pop_front();
   for(int i = 0 ; i <(total_list.count())/2; i++)
   {
       time += total_list.at(2*i);
       Text += total_list.at(2*i+1);
   }
}
//设置歌词
void Music::set_music_text(int get_time_value)
{
   int i = 0;
   for(; i <time.count(); i++)
   {
      int min = time.at(i).left(time.at(i).indexOf(":")).toInt();
      int msec = time.at(i).mid(6,2).toInt();
      int sec = time.at(i).mid(3,2).toInt();
      int total = min*60*100+sec*100+msec;
      if(get_time_value*100 < total)
      {  
          break;
      }
   }
   if(i>1)
   {
     ui->label_word_2->setText(Text.at(i-1));
   }
   if(i>2)
   {
     ui->label_word->setText(Text.at(i-2));
   }
   ui->label_word_3->setText(Text.at(i));
   if(i < time.count()-1)
   {
       ui->label_word_4->setText(Text.at(i+1));
   }
   if(i < time.count()-2)
   {
       ui->label_word_5->setText(Text.at(i+2));
   }
   if(i < time.count()-3)
   {
       ui->label_word_6->setText(Text.at(i+3));
   }
   //total_list.pop_back();
}


void Music::on_horizontalSlider_sliderPressed()
{
    update_time->stop();
    //p->write("pause\n");
}

void Music::on_horizontalSlider_sliderReleased()
{
    if(state == 0)
    {
        state = 1;
        ui->pushButton_play->setStyleSheet("QPushButton{border-image: url(:/music/play.png);}");
    }
    QString temp = QString("SEEK %1 2\n").arg(ui->horizontalSlider->value());
    p->write(temp.toUtf8());
    //p->write("pause\n");
    update_time->start(1000);
}
