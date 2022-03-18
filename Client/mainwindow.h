#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCryptographicHash>

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
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str);
    quint16 nextBlockSize;
    QString md5(QString str);

public slots:
    void slotReadyRead();
};
#endif // MAINWINDOW_H
