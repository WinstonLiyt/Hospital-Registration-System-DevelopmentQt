#include "mainwindow.h"
#include "ui_mainwindow.h"

/* 构造函数 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

}

/* 构造函数 */
MainWindow::MainWindow(int selectedHour, int selectedMinute, int selectedSecond, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 设置主窗口图标、名称、固定主窗口大小以及设置主窗口背景颜色 */
    this->setWindowIcon(QIcon(":/new/prefix1/hospital.png"));  // 程序图标
    this->setWindowIconText("Tongji Hospital Calling System");  // 程序名称
    this->setWindowTitle("Tongji Hospital Calling System");

    setFixedSize(800, 700);  // 固定窗口大小
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(199, 228, 215));  // 起始颜色（淡绿色）
    gradient.setColorAt(0.2, QColor(214, 255, 237));  // 起始颜色（淡绿色）
    gradient.setColorAt(0.8, QColor(222, 255, 240));  // 终止颜色（稍深一点的绿色）
    gradient.setColorAt(1, QColor(199, 228, 215));  // 起始颜色（淡绿色）
    QPalette palette;  // 创建 QPalette 对象并设置背景颜色为渐变绿色
    palette.setBrush(QPalette::Window, QBrush(gradient));  // 设置渐变色为背景
    this->setPalette(palette);

    /* 创建渐变绿色的直线 */
    QLinearGradient lineGradient(20, 80, 780, 80);
    lineGradient.setColorAt(1, QColor(0, 255, 0, 200));  // 起始颜色（绿色，稍带透明度）
    lineGradient.setColorAt(0.5, QColor(0, 200, 0, 200));  // 中间颜色（绿色，稍带透明度）
    lineGradient.setColorAt(0, QColor(0, 128, 0, 0));  // 终止颜色（透明绿色）

    /* 在窗口上添加一个 QLabel 作为渐变绿色直线表示分隔栏 */
    QLabel *lineLabel = new QLabel(this);
    QPixmap pixmap(760, 1);  // 创建渐变线的图像
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(lineGradient, 20);  // 设置渐变的线条颜色和宽度
    painter.setPen(pen);
    painter.drawLine(0, 0, 760, 0);  // 在图像上绘制渐变线
    lineLabel->setPixmap(pixmap);
    lineLabel->setGeometry(30, 80, 770, 20);  // 设置渐变线的位置和大小

    id = 0;  // 挂号ID

    /* 将 DigitalClock 添加到主窗口的布局中 */
    DigitalClock *clock = new DigitalClock(this);  // 创建 DigitalClock 对象
    QTime customTime(selectedHour, selectedMinute, selectedSecond);  // 读取用户在欢迎界面选择的时刻
    clock->setCustomTime(customTime);
    ui->verticalLayout->addWidget(clock);

    /* 添加界面2表格风格表 */
    ui->tabWidget->setStyleSheet("QTabWidget::pane { border: none; }"
                             "QTabWidget::tab-bar { alignment: center; }"
                             "QTabBar::tab { background-color: #E9FFF1; padding: 8px 16px; border: 1px solid gray; border-radius: 8px; margin: 2px; }"
                             "QTabBar::tab:selected { background-color: #D3FBFF; border: 1px solid black; }");

    ui->tabWidget->tabBar()->setStyleSheet("QTabBar::tab { color: black; font-weight: bold; font-size: 14px; }"
                                           "QTabBar::tab:selected { color: #7799EC; }");

    ui->label_welcome->setStyleSheet("color: #5F88EB;");
    ui->label_welcome_2->setStyleSheet("color: #5F88EB;");

    /* 添加性别选项到下拉列表 */
    ui->comboBox_sex->addItem("Male");
    ui->comboBox_sex->addItem("Female");
    ui->comboBox_sex->setStyleSheet("background-color: " + myBlue2.name() + "; "
                                    "border: 1px solid transparent; padding: 4px; border-radius: 4px;");

    /* 添加科室选项到下拉列表 */
    ui->comboBox_dep->addItem("Room 1");
    ui->comboBox_dep->addItem("Room 2");
    ui->comboBox_dep->addItem("Room 3");
    ui->comboBox_dep->addItem("Room 4");
    ui->comboBox_dep->addItem("Room 5");
    ui->comboBox_dep->addItem("Room 6");
    ui->comboBox_dep->addItem("Room 7");
    ui->comboBox_dep->addItem("Room 8");
    ui->comboBox_dep->addItem("Room 9");
    ui->comboBox_dep->addItem("Room 10");
    ui->comboBox_dep->addItem("Room 11");
    ui->comboBox_dep->addItem("Room 12");
    ui->comboBox_dep->addItem("Room 13");
    ui->comboBox_dep->addItem("Room 14");
    ui->comboBox_dep->addItem("Room 15");
    ui->comboBox_dep->setStyleSheet("background-color: " + myBlue2.name() + "; "
                                    "border: 1px solid transparent; padding: 4px; border-radius: 4px;");

    /* 添加医生选项到下拉列表 */
    ui->comboBox_doc->addItem("Doctor A");
    ui->comboBox_doc->addItem("Doctor B");
    ui->comboBox_doc->addItem("Doctor C");
    ui->comboBox_doc->addItem("Any");
    ui->comboBox_doc->setStyleSheet("background-color: " + myBlue2.name() + "; "
                                    "border: 1px solid transparent; border-radius: 4px;");

    /* 修改年龄、名字输入表类型 */
    ui->lineEdit_age->setStyleSheet("background-color: " + myBlue2.name() + "; "
                                    "border: 1px solid transparent;");
    ui->lineEdit_name->setStyleSheet("background-color: " + myBlue2.name() + "; "
                                    "border: 1px solid transparent;");

    /* 添加科室选项到下拉列表（界面3） */
    ui->comboBox_dep_2->addItem("Room 1");
    ui->comboBox_dep_2->addItem("Room 2");
    ui->comboBox_dep_2->addItem("Room 3");
    ui->comboBox_dep_2->addItem("Room 4");
    ui->comboBox_dep_2->addItem("Room 5");
    ui->comboBox_dep_2->addItem("Room 6");
    ui->comboBox_dep_2->addItem("Room 7");
    ui->comboBox_dep_2->addItem("Room 8");
    ui->comboBox_dep_2->addItem("Room 9");
    ui->comboBox_dep_2->addItem("Room 10");
    ui->comboBox_dep_2->addItem("Room 11");
    ui->comboBox_dep_2->addItem("Room 12");
    ui->comboBox_dep_2->addItem("Room 13");
    ui->comboBox_dep_2->addItem("Room 14");
    ui->comboBox_dep_2->addItem("Room 15");
    ui->comboBox_dep_2->setStyleSheet("background-color: " + myBlue2.name() + "; "
                                      "border: 1px solid transparent; padding: 4px; border-radius: 4px;");

    /* 添加医生选项到下拉列表（界面3） */
    ui->comboBox_doc_2->addItem("Doctor A");
    ui->comboBox_doc_2->addItem("Doctor B");
    ui->comboBox_doc_2->addItem("Doctor C");
    ui->comboBox_doc_2->setStyleSheet("background-color: " + myBlue2.name() + "; "
                                      "border: 1px solid transparent; padding: 4px; border-radius: 4px;");

    /* 添加挂号框架风格表 */
    ui->frame->setStyleSheet("border: 1px solid black; background-color: #B8F6CF; "
                             "border-radius: 8px; box-shadow: 5px 5px 10px rgba(0, 0, 0, 0.5);");

    ui->pushButton_submit->setStyleSheet("color: black; "
                                         "background-color: " + myBlue2.name() + "; "
                                         "border: 1px solid transparent; padding: 8px 16px; border-radius: 8px;");

    ui->pushButton_search->setStyleSheet("color: black; "
                                         "background-color: " + myBlue2.name() + "; "
                                         "border: 1px solid transparent; padding: 8px 16px; border-radius: 8px;"
                                         "font-family: 'Sitka Text'; font-size: 14px; font-weight: bold;");

    /* 创建窗口图标 */
    QIcon icon;  // “logo”图标
    QSize item_size(200, 390);
    icon.addFile(":/new/prefix1/nurse.png");
    ui->pushButton_nurse->setIcon(icon);
    ui->pushButton_nurse->setFlat(true);
    ui->pushButton_nurse->setIconSize(item_size);

    /* 设置tableWidget样式 */
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    // 表格内容不可编辑
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);      // 设置不可选
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // 设置滚动隐藏
    QString tableStyle = "QTableWidget { border: 1px solid gray; border-radius: 5px; }"
                         "QTableWidget::item { padding: 5px; }"
                         "QTableWidget::item:selected { background-color: lightgray; }";
    ui->tableWidget->setStyleSheet(tableStyle);
    QString headerStyle = "QHeaderView::section { background-color: lightblue; }";
    ui->tableWidget->horizontalHeader()->setStyleSheet(headerStyle);

    QTableWidgetItem *itemB = new QTableWidgetItem("B-Scan");
    itemB->setTextAlignment(Qt::AlignCenter);
    QFont fontB = itemB->font();
    fontB.setBold(true);
    itemB->setFont(fontB);
    itemB->setBackground(QBrush(myBlue));
    ui->tableWidget->setItem(0, 0, itemB);

    /* 搜索表格风格表（界面3） */
    ui->tableWidget_2->setStyleSheet("QTableWidget QHeaderView::section { background-color: " + myBlue2.name() + ";"
                                                                          " color: black; }");

    /* 设计表格（界面2） */
    for (int row = 1; row <= numRows; ++row) {
        QTableWidgetItem *item = new QTableWidgetItem("Room " + QString::number(row));
        item->setTextAlignment(Qt::AlignCenter);
        QFont font = item->font();
        font.setBold(true); // Make the text bold
        item->setFont(font);

        item->setBackground(QBrush(myBlue)); // Set background color for the first row
        item->setForeground(QBrush(Qt::black)); // Set text color for the first row

        ui->tableWidget->setItem(row, 0, item);
    }
    QPalette paletteText;
    paletteText.setColor(QPalette::Base, myPink);
    ui->textBrowser->setPalette(paletteText);

    /* 更新计时器，连接到槽函数 */
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateQueueStatus);
    updateTimer->start(1000); // 每1s当1min来更新

    connect(ui->pushButton_submit, &QPushButton::clicked, [=](){
        // qDebug() << "Ok";
        if (getPatientName().size() && getPatientAge() != -1) {
            QString currentTimeStr = clock->getCurrentTime();
            int presetHour = selectedHour;
            int presetMinute = selectedMinute;

            int minuteDifference = calculateMinuteDifference(currentTimeStr, presetHour, presetMinute);
            // qDebug() << "minuteDifference:" << minuteDifference;
            Patient *newPatient = new Patient(++ id, getPatientName(), getPatientSex(), getPatientAge(),
                                              getPatientDep(), getPatientDoc(), minuteDifference);
            // qDebug() << "Ok";
            queue[newPatient->getDep() - 1].enqueue(newPatient);
            qDebug() << "Ok";
        }
        /* 消息提示框 */
        static QMessageBox box;
        QIcon iconbox(":/new/prefix1/hospital.png");  // “logo”图标
        box.setWindowTitle("Registration Form");
        box.setWindowIcon(iconbox);
        QString styleSheet = "QLabel{"
                              "min-width: 320px;"
                              "min-height: 180px;"
                              "font-size: 16px;"
                              "text-align: center;" // Center align the text
                              "word-wrap: break-word;" // Enable word wrapping
                             "}";
        box.setStyleSheet(styleSheet);
        if (getPatientName().size()  && getPatientAge() != -1) {
            box.setText("Registration successful! \nYour name is " + getPatientName() + "."
                        + "\nYour ID is " + QString::number(id) + ".");
        }
        else if (!getPatientName().size())
            box.setText("Please enter your name.");
        else
            box.setText("Please enter a valid positive integer age.");
        box.exec();
        /* 重置输入框 */
        ui->lineEdit_name->clear();
        ui->lineEdit_age->clear();
        ui->comboBox_sex->setCurrentIndex(0);
        ui->comboBox_doc->setCurrentIndex(0);
        ui->comboBox_dep->setCurrentIndex(0);
    });

    /* 查询医生看病患者信息槽函数 */
    connect(ui->pushButton_search, &QPushButton::clicked, [=](){
        int dep = getPatientDep_2();
        int doc = getPatientDoc_2();
        // qDebug() << dep << " " << doc;

        ui->tableWidget_2->clearContents();  // 清空表格内容
        QVector<Doctor::PatientRecord> patientRecords = doctor[dep - 1][doc - 1].getPatientRecords();  // 获取指定科室和医生的病人记录

        /* 清空表格之前的内容 */
        ui->tableWidget_2->clearContents();
        ui->tableWidget_2->setRowCount(0);

        /* 为每个病人记录添加新行 */
        for (const Doctor::PatientRecord& record : patientRecords) {
            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);

            /* 创建各个单元格的表格项 */
            QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(record.regID));
            QTableWidgetItem* nameItem = new QTableWidgetItem(record.patientName);
            QTableWidgetItem* sexItem = new QTableWidgetItem(record.patientSex ? "Male" : "Female");
            QTableWidgetItem* ageItem = new QTableWidgetItem(QString::number(record.patientAge));
            QTableWidgetItem* diagTimeItem = new QTableWidgetItem(QString::number(record.diagnosisTime));
            QTableWidgetItem* dbScanTimeItem = new QTableWidgetItem(QString::number(record.BScanTime));

            /* 设置单元格文本居中对齐 */
            idItem->setTextAlignment(Qt::AlignCenter);
            nameItem->setTextAlignment(Qt::AlignCenter);
            sexItem->setTextAlignment(Qt::AlignCenter);
            ageItem->setTextAlignment(Qt::AlignCenter);
            diagTimeItem->setTextAlignment(Qt::AlignCenter);
            dbScanTimeItem->setTextAlignment(Qt::AlignCenter);

            /* 将表格项添加到表格的指定行和列 */
            ui->tableWidget_2->setItem(row, 0, idItem);
            ui->tableWidget_2->setItem(row, 1, nameItem);
            ui->tableWidget_2->setItem(row, 2, sexItem);
            ui->tableWidget_2->setItem(row, 3, ageItem);
            ui->tableWidget_2->setItem(row, 4, diagTimeItem);
            ui->tableWidget_2->setItem(row, 5, dbScanTimeItem);
        }
    });
}

/* 析构函数 */
MainWindow::~MainWindow()
{
    delete ui;
}

/* 获取患者姓名 */
QString MainWindow::getPatientName()
{
    return ui->lineEdit_name->text();
}

/* 获取患者性别 */
bool MainWindow::getPatientSex()
{
    QString str = ui->comboBox_sex->currentText();
    bool isMale = (str == "Male");
    return isMale;
}

/* 获取患者年龄 */
int MainWindow::getPatientAge()
{
    QString str = ui->lineEdit_age->text();
    bool conversionOk;
    int age = str.toInt(&conversionOk);

    if (conversionOk && age > 0) {
        return age;
    }
    return -1;
}

/* 获取患者所选科室 */
int MainWindow::getPatientDep()
{
    // 获取下拉框中选择的科室字符串
    QString str = ui->comboBox_dep->currentText();

    // 使用空格作为分隔符，将字符串拆分为多个部分
    QStringList parts = str.split(" ");

    // 获取拆分后字符串的最后一部分
    QString roomNumberStr = parts.last();

    // 将科室号字符串转换为整数
    int roomNumber = roomNumberStr.toInt();
    return roomNumber;
}


/* 获取患者所选医生 */
int MainWindow::getPatientDoc()
{
    QString str = ui->comboBox_doc->currentText();
    int doctorId = 0;

    if (str == "Doctor A")
        doctorId = 1;
    else if (str == "Doctor B")
        doctorId = 2;
    else if (str == "Doctor C")
        doctorId = 3;
    else if (str == "Any")
        doctorId = 4;

    return doctorId;
}

/* 获取患者所选科室（搜索功能） */
int MainWindow::getPatientDep_2()
{
    // 获取下拉框中选择的科室字符串
    QString str = ui->comboBox_dep_2->currentText();

    // 使用空格作为分隔符，将字符串拆分为多个部分
    QStringList parts = str.split(" ");

    // 获取拆分后字符串的最后一部分
    QString roomNumberStr = parts.last();

    // 将科室号字符串转换为整数
    int roomNumber = roomNumberStr.toInt();
    return roomNumber;
}

/* 获取患者所选医生（搜索功能） */
int MainWindow::getPatientDoc_2()
{
    QString str = ui->comboBox_doc_2->currentText();
    int doctorId = 0;

    if (str == "Doctor A")
        doctorId = 1;
    else if (str == "Doctor B")
        doctorId = 2;
    else if (str == "Doctor C")
        doctorId = 3;

    return doctorId;
}

/* 计算当前时间与预设时间的分钟差 */
int MainWindow::calculateMinuteDifference(const QString &currentTimeStr, int presetHour, int presetMinute)
{
    QStringList timeParts = currentTimeStr.split(":");
    int currentHour = timeParts[0].toInt();
    int currentMinute = timeParts[1].toInt();
    int currentSecond = timeParts[2].toInt();

    if (currentSecond != 0)
        currentMinute++;

    int currentTotalMinutes = currentHour * 60 + currentMinute;
    int presetTotalMinutes = presetHour * 60 + presetMinute;

    return currentTotalMinutes - presetTotalMinutes;
}

/* 更新队列状态 */
void MainWindow::updateQueueStatus() {
    for (int i = 0; i < numRows; ++ i) {
        for (int j = 0; j < numRooms; ++ j) {
            if (doctor[i][j].getTimeLeft() > 0) {
//                if (doctorExecutionCounters[i][j] >= 60) {
//                    // 每60s执行一次，【如果要把诊断/B超时间改为分钟一定要修改！当下是秒！】
//                    doctor[i][j].uploadTimeLeft(doctor[i][j].getTimeLeft() - 1);
//                    doctorExecutionCounters[i][j] = 0;
//                }
//                doctorExecutionCounters[i][j]++;

                doctor[i][j].uploadTimeLeft(doctor[i][j].getTimeLeft() - 1);
            }
            /* 看完病了 */
            else {
                Patient* patient_diagnosed = doctor[i][j].getPatient();
                if (patient_diagnosed != NULL) {
                    /* 有B超检查，转到B超队列 */
                    if (patient_diagnosed->getBScanTime() != 0) {
                        doctor[i][j].recordPatientVisit(patient_diagnosed);
                        queue[15].enqueue(patient_diagnosed);
                    }
                    /* 没有B超检查，从队列中移除 */
                    else {
                        doctor[i][j].recordPatientVisit(patient_diagnosed);
                        delete patient_diagnosed;
                    }
                }
                /* 为医生安排新的病人 */
                Patient* temp = queue[i].dequeueDoctor(j + 1);  // 第i个诊室，第 j+1 个医生
                doctor[i][j].uploadPatient(temp);

                if (temp != NULL) {
                    QString text = "请" + QString::number(temp->getRegID()) +
                                   "号患者 " + temp->getPatientName() +
                                   " 前往 " + QString::number(i + 1) +
                                   " 号科室 Doctor" + numToLetter(j + 1) +
                                   " 处就诊！";
                    ui->textBrowser->append(text);

                    QTextBrowser *textBrowser = new QTextBrowser;
                    textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                    textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                    textBrowser->setFrameShape(QFrame::NoFrame);
                    textBrowser->setWordWrapMode(QTextOption::NoWrap);
                    QString text2 = QString("<center>ID: %1</center><center>Name: %2</center>")
                                       .arg(doctor[i][j].getPatient()->getRegID())
                                       .arg(doctor[i][j].getPatient()->getPatientName());
                    textBrowser->setHtml(text2);
                    textBrowser->setMaximumHeight(maximumHeight);
                    textBrowser->setMaximumWidth(maximumWidth);
                    textBrowser->setAlignment(Qt::AlignCenter);

                    QPalette palette;
                    palette.setColor(QPalette::Base, myPink);
                    textBrowser->setPalette(palette);

                    // 设置QTableWidgetItem
                    QTableWidgetItem *item = new QTableWidgetItem();
                    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                    ui->tableWidget->setItem(i + 1, j + 1, item);

                    // 将QTextBrowser嵌入QTableWidgetItem中
                    ui->tableWidget->setCellWidget(i + 1, j + 1, textBrowser);

                    // 调整单元格大小以适应内容
                    ui->tableWidget->resizeRowToContents(i + 1);
                    ui->tableWidget->resizeColumnToContents(j + 1);
                    ui->tableWidget->item(i + 1, j + 1)->setBackground(QColor(myPink));
                    ui->tableWidget->item(i + 1, j + 1)->setTextAlignment(Qt::AlignCenter);
                }
                /* “Free”状态 */
                else {
                    QTextBrowser *textBrowser = new QTextBrowser;
                    textBrowser->setFrameShape(QFrame::NoFrame);
                    textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                    textBrowser->setWordWrapMode(QTextOption::NoWrap);
                    textBrowser->setPlainText("Free");
                    textBrowser->setAlignment(Qt::AlignCenter);

                    textBrowser->setMaximumHeight(maximumHeight);
                    textBrowser->setMaximumWidth(maximumWidth);

                    QPalette palette;
                    palette.setColor(QPalette::Base, myGreen);
                    textBrowser->setPalette(palette);

                    QTableWidgetItem *item = new QTableWidgetItem();
                    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                    ui->tableWidget->setItem(i + 1, j + 1, item);

                    ui->tableWidget->setCellWidget(i + 1, j + 1, textBrowser);

                    ui->tableWidget->resizeRowToContents(i + 1);
                    ui->tableWidget->resizeColumnToContents(j + 1);
                    ui->tableWidget->item(i + 1, j + 1)->setBackground(QColor(myGreen));
                    ui->tableWidget->item(i + 1, j + 1)->setTextAlignment(Qt::AlignCenter);
                }
            }
        }
        ui->tableWidget->setItem(i + 1, 4, new QTableWidgetItem(QString::number(queue[i].getLen())));
        ui->tableWidget->item(i + 1, 4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(i + 1, 4)->setBackground(QColor(myYellow));
    }
    for (int i = 0; i < numRooms; ++ i) {
        if (BScan[i].getTimeLeft() > 0) {
//             if (doctorExecutionCounters[15][i] >= 60) {
//                // 每60s执行一次，【如果要把诊断/B超时间改为分钟一定要修改！当下是秒！】
//                qDebug() << BScan[i].getTimeLeft();
//                BScan[i].uploadTimeLeft(BScan[i].getTimeLeft() - 1);
//                doctorExecutionCounters[15][i] = 0;
//            }
//            doctorExecutionCounters[15][i]++;

            BScan[i].uploadTimeLeft(BScan[i].getTimeLeft() - 1);
        }
        /* B超结束 */
        else {
            Patient* patient_Bscaned = BScan[i].getPatient();
            if (patient_Bscaned != NULL)
                delete patient_Bscaned;
            /* 为B超机安排新的病人 */
            Patient* temp = queue[15].dequeueBScan();
            BScan[i].uploadPatientBScan(temp);
            if (temp != NULL) {
                QString text = "请" + QString::number(temp->getRegID()) +
                               "号患者 " + temp->getPatientName() +
                                 " 前往 Doctor" + numToLetter(i + 1) +
                                                 " 的B超室进行B超！";
                ui->textBrowser->append(text);
                QTextBrowser *textBrowser = new QTextBrowser;
                textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                textBrowser->setFrameShape(QFrame::NoFrame);
                textBrowser->setWordWrapMode(QTextOption::NoWrap);
                QString text3 = QString("<center>ID: %1</center><center>Name: %2</center>")
                                    .arg(temp->getRegID())
                                    .arg(temp->getPatientName());
                textBrowser->setHtml(text3);
                textBrowser->setAlignment(Qt::AlignCenter);

                textBrowser->setMaximumHeight(maximumHeight);
                textBrowser->setMaximumWidth(maximumWidth);
                textBrowser->setAlignment(Qt::AlignCenter);

                QPalette palette;
                palette.setColor(QPalette::Base, myPink);
                textBrowser->setPalette(palette);

                QTableWidgetItem *item = new QTableWidgetItem();
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                ui->tableWidget->setItem(0, i + 1, item);

                ui->tableWidget->setCellWidget(0, i + 1, textBrowser);

                ui->tableWidget->resizeRowToContents(0);
                ui->tableWidget->resizeColumnToContents(i + 1);
                ui->tableWidget->item(0, i + 1)->setBackground(QColor(myPink));
                ui->tableWidget->item(0, i + 1)->setTextAlignment(Qt::AlignCenter);
            }
            /* "Free"状态 */
            else {
                QTextBrowser *textBrowser = new QTextBrowser;
                textBrowser->setFrameShape(QFrame::NoFrame);
                textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                textBrowser->setWordWrapMode(QTextOption::NoWrap);
                textBrowser->setPlainText("Free");
                textBrowser->setAlignment(Qt::AlignCenter);

                textBrowser->setMaximumHeight(maximumHeight);
                textBrowser->setMaximumWidth(maximumWidth);

                QPalette palette;
                palette.setColor(QPalette::Base, myGreen);
                textBrowser->setPalette(palette);

                QTableWidgetItem *item = new QTableWidgetItem();
                item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                ui->tableWidget->setItem(0, i + 1, item);

                ui->tableWidget->setCellWidget(0, i + 1, textBrowser);

                ui->tableWidget->resizeRowToContents(0);
                ui->tableWidget->resizeColumnToContents(i + 1);
                ui->tableWidget->item(0, i + 1)->setBackground(QColor(myGreen));
                ui->tableWidget->item(0, i + 1)->setTextAlignment(Qt::AlignCenter);
            }
        }
        ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(queue[15].getLen())));
        ui->tableWidget->item(0, 4)->setTextAlignment(Qt::AlignCenter);  // 文字居中
        ui->tableWidget->item(0, 4)->setBackground(QColor(myYellow));
    }
}

/* 数字转换为字母表示 */
QString MainWindow::numToLetter(int num) {
    return QString(QChar('A' + num - 1));
}
