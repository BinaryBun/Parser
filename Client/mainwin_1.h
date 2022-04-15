#ifndef MAINWIN_1_H
#define MAINWIN_1_H

#include <QMainWindow>

namespace Ui {
class MainWin_1;
}

class MainWin_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin_1(QWidget *parent = nullptr);
    ~MainWin_1();

private:
    Ui::MainWin_1 *ui;
};

#endif // MAINWIN_1_H
