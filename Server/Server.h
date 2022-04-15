#ifndef SERVER_H
#define SERVER_H
#include <QSqlError>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QCryptographicHash>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDataStream>
#include <QString>


class Server : public QTcpServer  // main server class
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;  // create socket

private:
    QString get_passwd(QString login);
    QVector <QTcpSocket*> Sockets;  // list of sockets
    QByteArray Data;  // array of sending data
    void SendToClient(QString str);
    quint16 nextBlockSize;
    QString get_token();
    QString md5(QString str);
    QMap <qintptr, QString> tokens;
    QSqlDatabase db;



public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
