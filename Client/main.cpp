// ==client ++==
#include "mainwindow.h"
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
    //MainWindow w2;
    w1.show();
    //w2.show();
    return a.exec();
}
