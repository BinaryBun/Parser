#include "singup.h"
#include "ui_singup.h"


Singup::Singup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Singup)
{
    this->setFixedSize(QSize(321, 370));
    ui->setupUi(this);
}

QString Singup::md5(QString str)
{
    QByteArray str_arr = str.toUtf8();
    return QString(QCryptographicHash::hash((str_arr),QCryptographicHash::Md5).toHex());
}

Singup::~Singup()
{
    delete ui;
}

void Singup::on_pushButton_clicked()
{
    if (ui->lineEdit_2->text() == ui->lineEdit_3->text()) {

    } else {
        this->setFixedSize(QSize(321, 442));
    }
}

