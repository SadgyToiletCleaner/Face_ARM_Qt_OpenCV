/********************************************************************************
** Form generated from reading UI file 'faceattendence.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEATTENDENCE_H
#define UI_FACEATTENDENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceAttendence
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FaceAttendence)
    {
        if (FaceAttendence->objectName().isEmpty())
            FaceAttendence->setObjectName(QString::fromUtf8("FaceAttendence"));
        FaceAttendence->resize(800, 600);
        centralwidget = new QWidget(FaceAttendence);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FaceAttendence->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FaceAttendence);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        FaceAttendence->setMenuBar(menubar);
        statusbar = new QStatusBar(FaceAttendence);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FaceAttendence->setStatusBar(statusbar);

        retranslateUi(FaceAttendence);

        QMetaObject::connectSlotsByName(FaceAttendence);
    } // setupUi

    void retranslateUi(QMainWindow *FaceAttendence)
    {
        FaceAttendence->setWindowTitle(QCoreApplication::translate("FaceAttendence", "FaceAttendence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceAttendence: public Ui_FaceAttendence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEATTENDENCE_H
