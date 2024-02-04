#include "digitalclock.h"

/* 构造函数，创建 DigitalClock 对象 */
DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setFrameStyle(QFrame::NoFrame);  // 去除外框样式

    setSegmentStyle(Filled);  // 设置数字填充样式

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);  // 定时器每隔1秒触发一次

    customTime = QTime::currentTime();  // 初始化 customTime 为当前系统时间

    setDigitCount(8);  // 显示格式为 HH:mm:ss

    showTime();
}

/* 设置自定义时间 */
void DigitalClock::setCustomTime(const QTime &time)
{
    customTime = time;
    showTime();
}

/* 获取当前时间的字符串表示 */
void DigitalClock::showTime()
{
    customTime = customTime.addSecs(1);  // 自定义时间增加1秒
    QString text = customTime.toString("hh:mm:ss");  // 格式化为时:分:秒，包括秒数
    // qDebug() << "Current time: " << text;
    display(text);  // 在 LCD 显示器上显示时间文本
}

/* 更新显示的时间 */
QString DigitalClock::getCurrentTime()
{
    return customTime.toString("hh:mm:ss");  // 返回当前时间的字符串表示
}
