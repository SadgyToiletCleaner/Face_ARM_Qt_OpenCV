//同名头文件
#include "faceattendence.h"
//放置C++标准库
#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>
//其他库，其他模块
#include <opencv4/opencv2/opencv.hpp>
//当前项目的其他头文件
#include "ui_faceattendence.h"

FaceAttendence::FaceAttendence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceAttendence)
{
    ui->setupUi(this);

    //打开摄像头
    if(!m_cap.open(0)){
        qDebug() << "摄像头打开失败";
    }

    //导入级联分类器
    m_cascade.load("/userdata/Qt/Qt_ARM_OpenCV/haarcascade_frontalface_alt2.xml");

    //定时器连接服务器
    connect(&m_timer, &QTimer::timeout, this, &FaceAttendence::timerConnect);
    //QTcpSocket当断开连接的时候disconnected信号
    connect(&m_socket, &QTcpSocket::disconnected, this, &FaceAttendence::startConnect);
    //QTcpSocket连接的时候会发送connected信号
    connect(&m_socket, &QTcpSocket::connected, this, &FaceAttendence::stopConnect);
    //关联接收数据的槽函数
    connect(&m_socket, &QTcpSocket::readyRead,this, &FaceAttendence::recvData);
    //启动定时器
    m_timer.start(5000);//每5s钟连接一次，直到连接成功就不在连接

    //启动采集摄像头的定时器时间（QTimeEvent）
    startTimer(100); //100 ms

}

FaceAttendence::~FaceAttendence()
{
    delete ui;
}


void FaceAttendence::timerEvent(QTimerEvent *e)
{
    //采集数据
    cv::Mat srcImage;
    //尝试从视频源捕获下一帧的图像
    if(m_cap.grab()){
        m_cap.read(srcImage); //读取一帧数据
    }

    //把图片大小设置与窗口一样大
    //        输入图像   输出图像     目标大小
    cv::resize(srcImage, srcImage, cv::Size(480, 480));

    cv::Mat grayImage;
    //转灰度图
    cvtColor(srcImage, grayImage, cv::COLOR_BGR2GRAY);
    //检测人脸数据
    std::vector<cv::Rect> faceRects;
    //检测人脸
    m_cascade.detectMultiScale(grayImage,faceRects);

    if(faceRects.size() > 0 && m_flag >= 0){
        //返回第一个检测到的人脸的边界框
        cv::Rect rect = faceRects.at(0);

        //移动人脸框

    }



}


void FaceAttendence::timerConnect()
{
    //连接服务器
    m_socket.connectToHost("192.168.2.148",9999);
    qDebug()<<"正在连接服务器";
}

void FaceAttendence::stopConnect()
{
    m_timer.stop();
    qDebug()<<"成功连接服务器";
}

void FaceAttendence::startConnect()
{
    m_timer.start(5000);//启动定时器
    qDebug()<<"断开连接";
}


void FaceAttendence::recvData()
{

}
