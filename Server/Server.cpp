#include "Server.h"
#include <QDataStream>
const int port = 2323;


Server::Server() {
    if (this->listen(QHostAddress::Any, port)) {
        qDebug() << QString("Start server {port: %1}").arg(port);
    } else {
        qDebug() << "Error";
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "Connect client: " << socketDescriptor;
}

void Server::slotReadyRead() {
    socket = (QTcpSocket*)sender();  // get client socket
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_6);
    if (in.status() == QDataStream::Ok) {
        qDebug() << "ready..";
        QString str;
        qDebug() << str;
    } else {
        qDebug() << "DataStream error";
    }
}

void Server::SendToClient(QString str) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_6);
    out << str;
    socket->write(Data);
}
