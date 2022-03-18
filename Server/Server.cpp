#include "Server.h"
#include <QDataStream>
#include <QMap>
static const QMap <QString, QString> logins = {
    {"maxim", "b2a8a7731bb664364d1f43de25f44c4f"}};
const int port = 2323;
QString token = "";


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
    // toket
    token = get_token();
    SendToClient(QString(">> Token: %1").arg(token));

}

QString Server::get_token() {
    const int len = 6;
    static const char alphanum[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    QString tmp_s;
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}

QString Server::md5(QString str)
{
    QByteArray str_arr = str.toUtf8();
    return QString(QCryptographicHash::hash((str_arr),QCryptographicHash::Md5).toHex());
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
            //SendToClient(QString(">> Token: %1\n\tMessage: %2").arg(token, str));
            if (str.count('|') == 1) {
                if (md5(token + logins[str.split('|')[0]]) == str.split('|')[1]) {
                    SendToClient("True");
                } else {
                    SendToClient("False");
                }

            } else {
                SendToClient(QString("Message: %1").arg(str));
            }
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
}
