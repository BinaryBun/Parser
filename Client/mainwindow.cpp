#include "mainwindow.h"
#include "ui_mainwindow.h"
const QString serv_addr = "127.0.0.1";
const int serv_port = 2323;
QString token;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;

    socket->connectToHost(serv_addr, serv_port);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // login
    QString login = ui->lineEdit_2->text();
    QString password = md5(ui->lineEdit_3->text());
    password = md5(token + password);
    ui->textBrowser->append(QString("You: \tLogin: %1").arg(login));
    ui->textBrowser->append(QString("You: \tPasswd: %1").arg(password));
    ui->textBrowser->append(QString("You: \tToken: %1").arg(token));
    //clear lineEdit
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    SendToServer(QString("%1|%2").arg(login, password));
}

void MainWindow::SendToServer(QString str)
{
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
            ui->textBrowser->append(QString("Server: %1").arg(str));
            if (str.count(">> Token: ") == 1) {
                token = str.replace(0, 10, "");
            }
            break;
        }

    } else {
        ui->textBrowser->append("==DataStream error==");
    }
}
