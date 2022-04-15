/********************************************************************************
** Form generated from reading UI file 'mainwin_1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_1_H
#define UI_MAINWIN_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin_1
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWin_1)
    {
        if (MainWin_1->objectName().isEmpty())
            MainWin_1->setObjectName(QString::fromUtf8("MainWin_1"));
        MainWin_1->resize(800, 600);
        menubar = new QMenuBar(MainWin_1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWin_1->setMenuBar(menubar);
        centralwidget = new QWidget(MainWin_1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWin_1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWin_1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWin_1->setStatusBar(statusbar);

        retranslateUi(MainWin_1);

        QMetaObject::connectSlotsByName(MainWin_1);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin_1)
    {
        MainWin_1->setWindowTitle(QCoreApplication::translate("MainWin_1", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWin_1: public Ui_MainWin_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_1_H
