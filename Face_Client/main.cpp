#include "faceattendence.h"

#include <QApplication>
#include <QScreen>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // 获取主屏幕对象
    QScreen *screen = QApplication::primaryScreen();
    //获取主屏幕的几何形状，它包含了屏幕的位置和大小
    QRect screenGeometry = screen->geometry();
    //从几何形状中提取宽度和高度
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    //输出屏幕的宽度和高度
    qDebug() << "屏幕的高度：" << screenHeight;
    qDebug() << "屏幕的宽度：" << screenWidth;


    FaceAttendence w;
    w.showFullScreen(); //全屏显示
    return a.exec();
}
