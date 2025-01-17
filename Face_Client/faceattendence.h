#ifndef FACEATTENDENCE_H
#define FACEATTENDENCE_H

//放置C++标准库
#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>
//其他库，其他模块
#include <opencv4/opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
class FaceAttendence;
}
QT_END_NAMESPACE

class FaceAttendence : public QMainWindow
{
    Q_OBJECT

public:
    FaceAttendence(QWidget *parent = nullptr);
    ~FaceAttendence();

    //定时器时间  QTimeEvent 不同于 QTimer
    void timerEvent(QTimerEvent *e);


private slots:
    void timerConnect();
    void stopConnect();
    void startConnect();
    void recvData();

private:
    Ui::FaceAttendence *ui;

    //haar--一级级联分类器
    cv::CascadeClassifier m_cascade;

    //OpenCV摄像头接口
    cv::VideoCapture m_cap;
    //创建网络套接字
    QTcpSocket m_socket;
    //创建定时器(用于连接服务器的)
    QTimer m_timer;

    //相同人脸标志位
    int m_flag;

};
#endif // FACEATTENDENCE_H
