#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QTime>
#include <QTimer>
#include <QLCDNumber>
#include <QTextEdit>
#include <QDebug>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

private:
    QTime customTime;  // 自定义时间对象，用于存储特定时间值

public:
    DigitalClock(QWidget *parent = nullptr);    // 构造函数，创建 DigitalClock 对象
    void setCustomTime(const QTime &time);      // 设置自定义时间
    QString getCurrentTime();                   // 获取当前时间的字符串表示

private slots:
    void showTime();    // 更新显示的时间

};

#endif // DIGITALCLOCK_H
