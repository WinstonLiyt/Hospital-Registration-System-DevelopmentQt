#include "welcomewindow.h"
#include "ui_welcomewindow.h"

/* 构造函数 */
WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    /* 设置主窗口图标、名称、固定主窗口大小以及设置主窗口背景颜色 */
    this->setWindowIcon(QIcon(":/new/prefix1/hospital.png"));  // 程序图标
    this->setWindowIconText("Tongji Hospital Calling System");  // 程序名称
    setFixedSize(800, 500);  // 固定窗口大小

    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(199, 228, 215));  // 起始颜色（淡绿色）
    gradient.setColorAt(0.2, QColor(214, 255, 237));  // 起始颜色（淡绿色）
    gradient.setColorAt(0.8, QColor(222, 255, 240));  // 终止颜色（稍深一点的绿色）
    gradient.setColorAt(1, QColor(199, 228, 215));  // 起始颜色（淡绿色）
    QPalette palette;  // 创建 QPalette 对象并设置背景颜色为渐变绿色
    palette.setBrush(QPalette::Window, QBrush(gradient));  // 设置渐变色为背景
    this->setPalette(palette);


    /* 创建logo图标元件 */
    QIcon icon;  // “logo”图标
    QSize item_size(85, 85);
    icon.addFile(":/new/prefix1/logo.png");
    ui->pushButton_logo->setIcon(icon);
    ui->pushButton_logo->setFlat(true);
    ui->pushButton_logo->setIconSize(item_size);

    /* 创建医生图标元件 */
    QIcon icon2;  // “医生”图标
    QSize item_size2(141, 401);
    icon2.addFile(":/new/prefix1/doctor2.png");
    ui->pushButton_doc->setIcon(icon2);
    ui->pushButton_doc->setFlat(true);
    ui->pushButton_doc->setIconSize(item_size2);

    /* 创建医院图标元件 */
    QIcon icon3;  // “医院”图标
    QSize item_size3(500, 253);
    icon3.addFile(":/new/prefix1/hosp2.png");
    ui->pushButton_hos->setIcon(icon3);
    ui->pushButton_hos->setFlat(true);
    ui->pushButton_hos->setIconSize(item_size3);

    /* 设置“开始”按钮风格 */
    ui->pushButton_start_2->setStyleSheet("background-color: #D1F6FF; color: black; "
                                          "border: none; padding: 8px 16px; border-radius: 8px;");
}

/* 析构函数 */
WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

/* 获取输入的小时值 */
int WelcomeWindow::getHour()
{
    return hour;
}

/* 获取输入的分钟值 */
int WelcomeWindow::getMin()
{
    return minute;
}

/* 获取输入的秒钟值 */
int WelcomeWindow::getSec()
{
    return second;
}

/* "开始" 按钮的点击槽函数 */
void WelcomeWindow::on_pushButton_start_2_clicked()
{
    QTime selectedTime = ui->timeEdit->time();

    /* 获取小时、分钟和秒钟 */
    hour = selectedTime.hour();
    minute = selectedTime.minute();
    second = selectedTime.second();
    // qDebug() << hour << " " << minute << " " << second;

    /* 在工作时间范围内，跳转到主窗口 */
    if ((hour >= 9 && hour <= 11) || (hour >= 13 && hour <= 17)) {
        MainWindow *mainWindow = new MainWindow(hour, minute, second); // 传递用户选择的时间
        mainWindow->show(); // 显示主窗口
        this->close(); // 关闭当前欢迎窗口
    }
    /* 不在工作时间范围内，弹出提示框 */
    else {
        QMessageBox::warning(this, "非工作时间", "不在工作时间范围内，暂时无法进行操作。");
    }
}

