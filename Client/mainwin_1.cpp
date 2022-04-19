#include "mainwin_1.h"
#include "ui_mainwin_1.h"

MainWin_1::MainWin_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin_1)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(410, 232));
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_9->setAlignment(Qt::AlignCenter);
    ui->label_10->setAlignment(Qt::AlignCenter);
    ui->label_11->setAlignment(Qt::AlignCenter);
}

MainWin_1::~MainWin_1()
{
    delete ui;
}

void MainWin_1::set_user(QString user)
{
    ui->label_11->setText(user);
}

void MainWin_1::on_pushButton_clicked()
{
    ui->label_5->setText("Error to pars");
    this->setFixedSize(QSize(410, 302));
}


void MainWin_1::on_pushButton_2_clicked()
{
    ui->label_5->setText("Error to load");
    this->setFixedSize(QSize(410, 302));
}

