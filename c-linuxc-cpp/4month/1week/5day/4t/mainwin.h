#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>

namespace Ui {
class mainwin;
}

class mainwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwin(QWidget *parent = 0);
    ~mainwin();

private slots:
    void on_retbt_clicked();
    //自定义一个槽函数，接收登录界面通过信号发送过来的参数
    void fun(QString,QString);
private:
    Ui::mainwin *ui;
};

#endif // MAINWIN_H