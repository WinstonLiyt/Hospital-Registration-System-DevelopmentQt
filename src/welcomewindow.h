#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>
#include <QDebug>
#include "mainwindow.h"
#include <QMessageBox>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

    int getHour();  // 获取输入的小时值
    int getMin();   // 获取输入的分钟值
    int getSec();   // 获取输入的秒钟值

private slots:
    void on_pushButton_start_2_clicked();  // "开始" 按钮的点击槽函数

private:
    Ui::WelcomeWindow *ui;
    int hour;               // 存储输入的小时值
    int minute;             // 存储输入的分钟值
    int second;             // 存储输入的秒钟值
};

#endif // WELCOMEWINDOW_H
