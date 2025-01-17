#ifndef FACEATTENDENCE_H
#define FACEATTENDENCE_H

#include <QMainWindow>
#include <QTcpSocket>

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

private:
    Ui::FaceAttendence *ui;


    //创建网络套接字
    QTcpSocket msocket;
};
#endif // FACEATTENDENCE_H
