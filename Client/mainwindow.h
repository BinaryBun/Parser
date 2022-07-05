#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCryptographicHash>
#include <QMessageBox>
#include "mainwin_1.h"
#include "singup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    void SendToServer(QString str);
    QString md5(QString str);
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    quint16 nextBlockSize;
    QString token;

    MainWin_1 *form_1 = new MainWin_1();
    Singup *sin_1 = new Singup();


public slots:
    void recieveData(QString login, QString passwd);
    void send_autor(QString id);
    void slotReadyRead();

signals:
    void change_singup(QString ans);
    void set_user_sig(QString user);

};
#endif // MAINWINDOW_H
