#include "Server.h"
#include <QDataStream>
const int port = 2323;


Server::Server() {
    if (this->listen(QHostAddress::Any, port)) {
        qDebug() << QString("Start server {port: %1}").arg(port);
    } else {
        qDebug() << "Error";
    }
    nextBlockSize = 0;
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "Connect client: " << socketDescriptor;
    SendToClient("==CONNECT==");
}

void Server::slotReadyRead() {
    socket = (QTcpSocket*)sender();  // get client socket
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_6);
    if (in.status() == QDataStream::Ok) {
        qDebug() << "read..";
        /*QString str;
        in >> str;
        //qDebug() << "Client message: " << str;
        SendToClient(str);*/
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
            SendToClient(str);
            break;
        }

    } else {
        qDebug() << "DataStream error";
    }
}

void Server::SendToClient(QString str) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_6);
    out << quint16(0) << str;  // size pac
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof (quint16));
    socket->write(Data);  // from last client
    /*for (int i = 0; i < Sockets.size(); i++) {
        Sockets[i]->write(Data);
    }*/
}
