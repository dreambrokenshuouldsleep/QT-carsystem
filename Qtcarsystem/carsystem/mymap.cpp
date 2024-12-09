#include "mymap.h"
#include "ui_mymap.h"

mymap::mymap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mymap)
{
    ui->setupUi(this);

    manager = new  QNetworkAccessManager(this);
    map     = new  QNetworkAccessManager(this);

    map_png =  new  QFile(this);
    map_png->setFileName("map.png");
    QNetworkRequest request;   //自己申请的API
   // http://api.map.baidu.com/location/ip?ak=自己申请的密钥&ip=当前公网地址&coor=
    request.setUrl(QUrl("http://api.map.baidu.com/location/ip?ak=自己申请的密钥&ip=当前公网地址&coor="));
    reply = manager->get(request);
    connect(reply, &QIODevice::readyRead, this, &mymap::slotReadyRead);
    ui->label->lower();
}

mymap::~mymap()
{
    delete ui;
}

void mymap::slotReadyRead()
{
    QString  msg = reply ->readAll();
    //获取头数据类型
    QString  head  = reply->rawHeader("Content-Type");
    qDebug() << head;
    //追加数据
    //  ui->textBrowser->append(msg);
    if(head == "application/json;charset=utf-8")   //返回JSON
    {
    //解析JSON
        QJsonDocument  doc = QJsonDocument::fromJson(msg.toUtf8(),NULL);
        QJsonObject    obj_x = doc.object();
        QJsonObject    obj_y = doc.object();
        x = obj_x.take("content").toObject().take("point").toObject().take("x").toString();
        y = obj_y.take("content").toObject().take("point").toObject().take("y").toString();
        ui->lineEdit_x->setText(x);
        ui->lineEdit_y->setText(y);
        QNetworkRequest request;   //自己申请的API
        int  zoom = map_zoom; //地图放大倍数
        //设置地址
        QString  URL = QString("http://api.map.baidu.com/staticimage/v2?ak=密钥&mcode=666666&center=%1,%2&width=800&height=400&zoom=%3;").arg(x).arg(y).arg(zoom);
        qDebug() << URL;
        request.setUrl(QUrl(URL));
        //发送请求
        map_reply = map->get(request);
        all_size=0;
        connect(map_reply,SIGNAL(readyRead()),this,SLOT(show_map()));
        if(map_png->open(QIODevice::ReadWrite|QIODevice::Truncate))
        {
            qDebug() << "open file map.png"  << endl;
        }
        else
        {
            qDebug() << "open file fail"  << endl;
        }

    }
}

void mymap::show_map()
{
    //读取所有数据
         QByteArray msg = map_reply ->readAll();


        //获取头数据类型
        QString  head  = map_reply->rawHeader("Content-Type");
              qDebug() << head;

         QString  file_size  = map_reply->rawHeader("Content-Length");
              qDebug() << file_size;

        //写入本地
          map_png->write(msg);
          all_size += msg.length();
          qDebug() << all_size;

          if(all_size == file_size.toInt() )
          {
              map_png->close();


              QPixmap pic=map_png->fileName();
              if(pic.load(map_png->fileName()))
              {
                  //显示图片
                  pic=pic.scaled(ui->label->width(),ui->label->height());
                  ui->label->setPixmap(pic);
              }
              else
              {
                  ui->label->setText("因为文件已经损坏、损毁或过大");
              }

          }
}

void mymap::on_pushButton_home_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

void mymap::on_pushButton_3_clicked()
{
    QNetworkRequest request;   //自己申请的API


        int  zoom = map_zoom; //地图放大倍数


       x  =  ui->lineEdit_x->text();
       y  =  ui->lineEdit_y->text();



      //设置地址
      QString  URL = QString("http://api.map.baidu.com/staticimage/v2?ak=密钥&mcode=666666&center=%1,%2&width=800&height=400&zoom=%3;").arg(x).arg(y).arg(zoom);

         qDebug() << URL;

      request.setUrl(QUrl(URL));


      //发送请求
      //发送请求
      map_reply = map->get(request);

      connect(map_reply,SIGNAL(readyRead()),this,SLOT(show_map()));

      if(map_png->open(QIODevice::ReadWrite|QIODevice::Truncate))
      {
          qDebug() << "open file map.png"  << endl;
      }
      else
      {
            qDebug() << "open file fail"  << endl;
      }

      all_size=0;
}

void mymap::on_pushButton_clicked()
{
    QNetworkRequest request;   //自己申请的API


       if(map_zoom <= 17)
       {
           map_zoom++;
       }
       else
       {
              qDebug() << "地图已经最大";
       }

      int  zoom = map_zoom; //地图放大倍数



       //设置地址
       QString  URL = QString("http://api.map.baidu.com/staticimage/v2?ak=密钥&mcode=666666&center=%1,%2&width=800&height=400&zoom=%3;").arg(x).arg(y).arg(zoom);

          qDebug() << URL;

       request.setUrl(QUrl(URL));


       //发送请求
       //发送请求
       map_reply = map->get(request);

       connect(map_reply,SIGNAL(readyRead()),this,SLOT(show_map()));

       if(map_png->open(QIODevice::ReadWrite|QIODevice::Truncate))
       {
           qDebug() << "open file map.png"  << endl;
       }
       else
       {
             qDebug() << "open file fail"  << endl;
       }

       all_size=0;
}

void mymap::on_pushButton_2_clicked()
{
    QNetworkRequest request;   //自己申请的API


        if(map_zoom >= 4)
        {
            map_zoom--;
        }
        else
        {
               qDebug() << "地图已经最小";
        }

       int  zoom = map_zoom; //地图放大倍数



        //设置地址
        QString  URL = QString("http://api.map.baidu.com/staticimage/v2?ak=密钥&mcode=666666&center=%1,%2&width=800&height=400&zoom=%3;").arg(x).arg(y).arg(zoom);

           qDebug() << URL;

        request.setUrl(QUrl(URL));


        //发送请求
        //发送请求
        map_reply = map->get(request);

        connect(map_reply,SIGNAL(readyRead()),this,SLOT(show_map()));

        if(map_png->open(QIODevice::ReadWrite|QIODevice::Truncate))
        {
            qDebug() << "open file map.png"  << endl;
        }
        else
        {
              qDebug() << "open file fail"  << endl;
        }

        all_size=0;
}
