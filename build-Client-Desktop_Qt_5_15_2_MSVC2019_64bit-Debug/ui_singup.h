/********************************************************************************
** Form generated from reading UI file 'singup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGUP_H
#define UI_SINGUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Singup
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QLabel *label_6;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Singup)
    {
        if (Singup->objectName().isEmpty())
            Singup->setObjectName(QString::fromUtf8("Singup"));
        Singup->resize(321, 471);
        centralwidget = new QWidget(Singup);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(50, 200, 221, 24));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 240, 221, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 90, 101, 16));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 70, 281, 281));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 221, 24));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 220, 221, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 10, 161, 51));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        label_3->setFont(font);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 370, 281, 51));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 281, 51));
        QFont font1;
        font1.setPointSize(12);
        label_6->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 170, 91, 16));
        Singup->setCentralWidget(centralwidget);
        groupBox->raise();
        lineEdit_3->raise();
        lineEdit_2->raise();
        label->raise();
        label_3->raise();
        groupBox_3->raise();
        label_2->raise();
        menubar = new QMenuBar(Singup);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 321, 21));
        Singup->setMenuBar(menubar);
        statusbar = new QStatusBar(Singup);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Singup->setStatusBar(statusbar);

        retranslateUi(Singup);

        QMetaObject::connectSlotsByName(Singup);
    } // setupUi

    void retranslateUi(QMainWindow *Singup)
    {
        Singup->setWindowTitle(QCoreApplication::translate("Singup", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Singup", "Username", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("Singup", "Sing up", nullptr));
        label_3->setText(QCoreApplication::translate("Singup", "Sign up to Parser", nullptr));
        groupBox_3->setTitle(QString());
        label_6->setText(QCoreApplication::translate("Singup", "Incorrect password", nullptr));
        label_2->setText(QCoreApplication::translate("Singup", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Singup: public Ui_Singup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGUP_H
