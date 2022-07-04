#include "mainwin_1.h"
#include "ui_mainwin_1.h"
#include <QDebug>
QString name = "";

MainWin_1::MainWin_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin_1)
{
    ui->setupUi(this);
    ui->label_11->setText(name);
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
    name = user;
    ui->label_11->setText(user);
    qDebug() << "user set!!! " << user;
}

void MainWin_1::on_pushButton_clicked()
{
    //qDebug() << ui->lineEdit_2->text();
    emit send_from_user(ui->lineEdit_2->text());
    ui->lineEdit_2->clear();
    //ui->label_5->setText("Error to pars");
    //this->setFixedSize(QSize(410, 302));
}


void MainWin_1::on_pushButton_2_clicked()
{
    ui->label_5->setText("Load from ssh!!!");
    this->setFixedSize(QSize(410, 302));
}

