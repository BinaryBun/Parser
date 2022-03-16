#include "mainwindow.h"
#include "ui_mainwindow.h"
const QString serv_addr = "127.0.0.1";
const int serv_port = 2323;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost(serv_addr, serv_port);
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

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_6);
    if (in.status() == QDataStream::Ok) {
        /*QString str;
        in >> str;
        //qDebug() << str;
        ui->textBrowser->append(QString("Server: %1").arg(str)); */
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
            break;
        }

    } else {
        ui->textBrowser->append("==DataStream error==");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    //qDebug() << ui->lineEdit->text();
    SendToServer(ui->lineEdit->text());
    ui->textBrowser->append(QString("You: %1").arg(ui->lineEdit->text()));
    ui->lineEdit->clear();
}


void MainWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
    ui->textBrowser->append(QString("You: %1").arg(ui->lineEdit->text()));
    ui->lineEdit->clear();
}

