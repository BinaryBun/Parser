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
        QString login = ui->lineEdit->text();
        QString password = md5(ui->lineEdit_2->text());
        emit send_to_main(login, password);
    } else {
        ui->label_6->setText("Password incorrect");
        ui->label_6->setAlignment(Qt::AlignCenter);
        this->setFixedSize(QSize(321, 442));
    }
}

void Singup::read_answ(QString answer)
{
    if (answer != "cnuTrue") {
        ui->label_6->setText("This user exists");
        ui->label_6->setAlignment(Qt::AlignCenter);
        this->setFixedSize(QSize(321, 442));
    } else if (answer == "cnuTrue") {
        close();
    }
}
