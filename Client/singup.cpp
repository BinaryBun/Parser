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
        if (is_not_login(ui->lineEdit->text())) {
            db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");
            db.setDatabaseName("parser");
            db.setUserName("root");
            db.setPassword("binarybun");
            // try open
            if (!db.open()) {
                qDebug() << db.lastError().text();
            } else {
                //qDebug() << "Connect";
                QSqlQuery query = QSqlQuery(db);
                query.exec(QString("insert into passwdords values ('%1', '%2')").arg(login, password));
                form_1.show();
                close();
            }
        } else {
            ui->label_6->setText("This user exists");
            ui->label_6->setAlignment(Qt::AlignCenter);
            this->setFixedSize(QSize(321, 442));
        }
    } else {
        ui->label_6->setText("Login incorrect");
        ui->label_6->setAlignment(Qt::AlignCenter);
        this->setFixedSize(QSize(321, 442));
    }
}

bool Singup::is_not_login(QString login)
{
    // connect 2 database
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("parser");
    db.setUserName("root");
    db.setPassword("binarybun");
    // try open
    if (!db.open()) {
        qDebug() << db.lastError().text();
    } else {
        //qDebug() << "Connect";
        QSqlQuery query = QSqlQuery(db);
        if (query.exec(QString("SELECT passw FROM passwdords WHERE login='%1';").arg(login))) {
            while (query.next())
                //qDebug() << query.value("passw").toString();
                return false;
        }
    }
    return true;
}

