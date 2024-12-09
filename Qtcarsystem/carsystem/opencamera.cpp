#include "opencamera.h"
#include "ui_opencamera.h"

opencamera::opencamera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::opencamera)
{
    ui->setupUi(this);
    time = new QTimer(this);
    //cap.open(0);

}

opencamera::~opencamera()
{
    //cap.release();
    delete ui;
}

void opencamera::on_pushButton_clicked()
{
    connect(time , &QTimer::timeout , this , &opencamera::time_out);
    time->start(100);
}

void opencamera::time_out()
{
        /*cap>>image;

       // 2. 原始数据  --->  灰度图
//       cv::Mat OutImage;                                       // Mat 矩阵输出对象
//       cv::cvtColor( image , OutImage ,cv::COLOR_BGR2GRAY );   // 转换颜色空间 （ BGR888 ---> 灰度图 ）

//       // 3. 级联分类器检测目标（ 获得人脸矩形位置 ）
//       std::vector<cv::Rect> objects;                          // 容器对象（ 保存矩形信息 ）
//       casc.detectMultiScale(OutImage,objects,1.1,3,0);

//       //  4. 根据矩形位置绘制矩形( 标记人脸 )
//       //  容器元素引用
//       //  objects.at(0);  使用at方法引用第0成员
//       //  objects[0]      使用数组下标引用法
//       cv::rectangle(image,objects[0],cv::Scalar(0,0,255,0));

//       // 5. 将摄像头数据（ 框选过的 ）放到标签中
//       // 需要进行转换（ image ---》 opencv 中类型 ---> QT中类型 ）
       QImage img(image.data,image.cols,image.rows,QImage::Format_RGB888);
       QPixmap mmp = QPixmap::fromImage(img);

       // 6. 根据标签的大小进行缩放
       mmp = mmp.scaled(ui->label->size());

       // 7. 将缩放后数据写入到标签
       ui->label->setPixmap(mmp);*/
}

void opencamera::on_pushButton_2_clicked()
{
     //cap.release();
     time->stop();
}
