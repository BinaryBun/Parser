#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCryptographicHash>
#include <QMessageBox>
#include "form.h"

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

private:
    void SendToServer(QString str);
    QString md5(QString str);
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    quint16 nextBlockSize;
    QString token;

    Form form_1;

public slots:
    void slotReadyRead();
};
#endif // MAINWINDOW_H
