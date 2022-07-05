// ==client ++==
#include "mainwindow.h"
#include "mainwin_1.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    //css
    QApplication a(argc, argv);
    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());

    MainWindow w1;

    w1.show();
    return a.exec();
}

/*
    pkjname:
        cnu: check new user
        tlg: try login

*/
