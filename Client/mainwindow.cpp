#include "mainwindow.h"
#include "ui_mainwindow.h"

static QString serv_addr = "127.0.0.1";
const int serv_port = 2323;
QString user_name;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(QSize(321, 394));
    //setWindowFlags(Qt::Dialog);
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    connect(sin_1, SIGNAL(send_to_main(QString, QString)), this, SLOT(recieveData(QString, QString)));
    connect(this, SIGNAL(change_singup(QString)), sin_1, SLOT(read_answ(QString)));
    connect(this, SIGNAL(set_user_sig(QString)), form_1, SLOT(set_user(QString)));
    connect(form_1, SIGNAL(send_from_user(QString)), this, SLOT(send_autor(QString)));
    nextBlockSize = 0;

    socket->connectToHost(serv_addr, serv_port);
}

MainWindow::~MainWindow()
{
    qDebug() << "END MAIN";
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // login
    QString login = ui->lineEdit_2->text();
    user_name = login;
    QString password = md5(ui->lineEdit_3->text());
    qDebug() << (QString("You: \tPasswd: %1").arg(password));
    password = md5(this->token + password);
    qDebug() << (QString("You: \tLogin: %1").arg(login));
    qDebug() << (QString("You: \tPasswd(md5): %1").arg(password));
    qDebug() << (QString("You: \tToken: %1").arg(this->token));
    // change form

    //clear lineEdit
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    SendToServer(QString("tlg%1|%2").arg(login, password));
}

void MainWindow::SendToServer(QString str)
{
    qDebug() << user_name;
    emit set_user_sig(user_name);  // эмитируем сигнал
    qDebug() << "send";
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_6);
    out << quint16(0) << str;  // size pac
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof (quint16));
    socket->write(Data);
}

QString MainWindow::md5(QString str)
{
    QByteArray str_arr = str.toUtf8();
    return QString(QCryptographicHash::hash((str_arr),QCryptographicHash::Md5).toHex());
}

void MainWindow::recieveData(QString login, QString passwd)
{
    // принимает данные с сигнала
    qDebug() << QString("Login: %1 -- Password: %2").arg(login, passwd);
    user_name = login;
    qDebug() << user_name;
    // const_key + const_hash + login
    SendToServer("cnu"+passwd+login);

}

void MainWindow::send_autor(QString id)
{
    qDebug() << "aut" + id;
    SendToServer("aut" + id);
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_6);
    if (in.status() == QDataStream::Ok) {
        while (true) {
            if (nextBlockSize == 0) {
                if (socket->bytesAvailable() < 2) {
                    break;
                }
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize) {
                 break;
            }

            QString str;
            in >> str;
            nextBlockSize = 0;
            qDebug() << (QString("Server: %1").arg(str));
            if (str.count(">> Token: ") == 1) {
                token = str.replace(0, 10, "");
                qDebug() << QString("Token: %1").arg(token);
            } else if (str == "tlgTrue") {
                form_1->show();
                close();
            } else if (str == "tlgFalse") {
                // error
                this->setFixedSize(QSize(321, 452));
            } else if (str == "cnuFalse") {
                emit change_singup(str);
            } else if (str == "cnuTrue") {
                emit change_singup(str);
                form_1->show();
            }
            break;
        }

    } else {
        qDebug() << ("==DataStream error==");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    sin_1->show();
    close();
}

