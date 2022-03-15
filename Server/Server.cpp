#include "Server.h"
#include <QDataStream>


Server::Server() {
    if (this->listen(QHostAddress::Any, 2323)) {
        qDebug() << "Start";
    } else {
        qDebug() << "Error";
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpServer::deleteLater);

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
