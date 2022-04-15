#include "mainwin_1.h"
#include "ui_mainwin_1.h"

MainWin_1::MainWin_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin_1)
{
    ui->setupUi(this);
}

MainWin_1::~MainWin_1()
{
    delete ui;
}
