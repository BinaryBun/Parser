#ifndef SINGUP_H
#define SINGUP_H

#include <QMainWindow>
#include <QCryptographicHash>
#include <QDebug>
#include "mainwin_1.h"

namespace Ui {
class Singup;
}

class Singup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Singup(QWidget *parent = nullptr);
    ~Singup();

private:
    Ui::Singup *ui;
    MainWin_1 form_1;
    void recod_acc();
    bool is_not_login(QString login);
    QString md5(QString str);

signals:
    void send_to_main(QString login, QString password);

private slots:
    void on_pushButton_clicked();

public slots:
    void read_answ(QString answer);
};

#endif // SINGUP_H
