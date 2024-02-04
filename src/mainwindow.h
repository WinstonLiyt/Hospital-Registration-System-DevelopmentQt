#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "digitalclock.h"
#include "patient.h"
#include "bscan.h"
#include "callingqueue.h"
#include "doctor.h"
#include <QTime>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QLinearGradient>
#include <QColor>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  // 构造函数
    explicit MainWindow(int selectedHour, int selectedMinute, int selectedSecond, QWidget *parent = nullptr);  // 构造函数重载
    ~MainWindow();  // 析构函数

    QString getPatientName();   // 获取病人姓名
    bool getPatientSex();       // 获取病人性别
    int getPatientAge();        // 获取病人年龄
    int getPatientDep();        // 获取病人所在科室
    int getPatientDoc();        // 获取病人所需医生
    int calculateMinuteDifference(const QString &currentTimeStr, int presetHour, int presetMinute);  // 计算时间差（分钟）
    void updateQueueStatus();   // 更新队列状态
    int getPatientDep_2();      // 获取病人所在科室（三界面）
    int getPatientDoc_2();      // 获取病人所需医生（三界面）

private:
    Ui::MainWindow *ui;

    int id;  // 病人ID
    int selectedHour;       // 选定的小时值
    int selectedMinute;     // 选定的分钟值
    int selectedSecond;     // 选定的秒钟值

    const int maximumHeight = 50;  // 表格最大高度
    const int maximumWidth = 105;  // 表格最大宽度

    const int numRows = 15;  // 科室数
    const int numCols = 5;   // 表格列数
    const int numRooms = 3;  // 医生数

    /* 自定义颜色 */
    QColor myBlue = QColor(200, 220, 255);
    QColor myGreen = QColor(230, 255, 226);
    QColor myPink = QColor(245, 219, 234);
    QColor myYellow = QColor(242, 245, 219);
    QColor myBlue2 = QColor(209, 246, 255);

    CallingQueue queue[16];  // 系统队列（15条科室队列，1条B超队列）
    Doctor doctor[15][3];    // 医生数组，15个科室，每个科室三个医生
    BScan BScan[3];          // B超机数组，1个B超室，3个B超机

    QTimer *updateTimer;  // 定时器
    int doctorExecutionCounters[16][3] = {{0}};  // 医生执行计数器数组
    QString numToLetter(int num);  // 数字转换为字母表示

};
#endif // MAINWINDOW_H
