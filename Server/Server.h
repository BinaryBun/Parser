#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class Server : public QTcpServer  // main server class
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;  // create socket

private:
    QVector <QTcpSocket*> Sockets;  // list of sockets
    QByteArray Data;  // array of sending data
    void SendToClient(QString str);
    quint16 nextBlockSize;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
