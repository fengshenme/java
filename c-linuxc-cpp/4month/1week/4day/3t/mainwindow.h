#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void mysignal();

//槽函数的声明;
private slots:
    void asfunc(QString, int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H