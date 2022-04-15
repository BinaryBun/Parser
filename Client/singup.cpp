#include "singup.h"
#include "ui_singup.h"


Singup::Singup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Singup)
{
    this->setFixedSize(QSize(321, 370));
    //this->setFixedSize(QSize(321, 442));
    ui->setupUi(this);
}

Singup::~Singup()
{
    delete ui;
}
