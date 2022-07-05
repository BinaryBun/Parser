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
#include <QProcess>
#include <QDir>


class Server : public QTcpServer  // main server class
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;  // create socket

private:
    QProcess *console_run;
    QVector <QTcpSocket*> Sockets;  // list of sockets
    QByteArray Data;  // array of sending data
    quint16 nextBlockSize;
    QMap <qintptr, QString> tokens;
    QSqlDatabase db;

    QString get_passwd(QString login);
    void SendToClient(QString str);
    QString get_token();
    QString md5(QString str);
    bool is_not_login(QString login);



public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
