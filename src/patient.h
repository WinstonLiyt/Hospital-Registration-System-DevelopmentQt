#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDebug>
#include <iostream>
#include <cmath>
#include <random>
#include <QRandomGenerator>

class Patient
{
private:
    int regID;              // 病人注册ID
    QString patientName;    // 病人姓名
    bool patientSex;        // 病人性别，T表示男性，F表示女性
    int patientAge;         // 病人年龄
    int dep;                // 病人所在科室
    int doc;                // 病人所选医生
    Patient* next;          // 指向下一个病人的指针
    int visTime;            // 病人到达就诊室的时间
    int diagnosisTime;      // 病人诊断所需时间
    bool needBScan;         // 是否需要进行B超检查
    int BScanTime;          // B超检查所需时间
    int generateRandomNormalInteger(int mean, int stdDev, int minVal, int maxVal);  // 生成正太分布随机整数

    const int mean = 10;    // 诊断时间均值
    const int stdDev = 5;   // 诊断时间标准差
    const int minVal = 5;   // 诊断时间最小值
    const int maxVal = 15;  // 诊断时间最大值

    const int meanB = 23;   // B超均值
    const int stdDevB = 4;  // B超标准差
    const int minValB = 15; // B超最小值
    const int maxValB = 25; // B超最大值

    const double BScanProbability = 0.5;  // 进行B超检查的概率

public:
    Patient() : regID(0), patientName(""), patientSex(true), patientAge(0), dep(0), doc(0), next(nullptr), visTime(0), diagnosisTime(0), needBScan(false), BScanTime(0) {}
    Patient(int ID, QString Name, bool Sex, int Age, int Dep, int Doc, int Time);

    int getRegID();             // 获取病人挂号ID
    QString getPatientName();   // 获取病人姓名
    bool getPatientSex();       // 获取病人性别，T表示男性，F表示女性
    int getPatientAge();        // 获取病人年龄
    int getDep();               // 获取病人所在科室
    int getDoc();               // 获取病人所选医生
    int getVisTime();           // 获取病人到达就诊室的时间
    int getDiagnosisTime();     // 获取病人诊断所需时间
    int getBScanTime();         // 获取B超检查所需时间

    friend class CallingQueue;
};

#endif // PATIENT_H
