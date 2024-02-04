#ifndef DOCTOR_H
#define DOCTOR_H

#include "patient.h"
#include <QString>
#include <QVector>

class Doctor
{
public:
    Doctor();  // 构造函数
    Patient* getPatient();  // 获取当前医生正在诊断的病人
    int getTimeLeft();  // 获取当前剩余诊断时间
    void uploadTimeLeft(int t);  // 更新剩余诊断时间
    void uploadPatient(Patient* p);  // 分配病人给当前医生进行诊断
    void uploadPatientBScan(Patient* p);  // 分配病人给B超机器进行诊断

    struct PatientRecord {
        int regID;           // 挂号ID
        QString patientName; // 患者姓名
        bool patientSex;     // 患者性别
        int patientAge;      // 患者年龄
        int diagnosisTime;   // 就诊时间
        int BScanTime;       // B超检查时间

        // 构造函数初始化病人就诊记录
        PatientRecord(int ID, const QString& Name, bool Sex, int Age, int DiagnosisTime, int BScanTime)
            : regID(ID), patientName(Name), patientSex(Sex), patientAge(Age),
            diagnosisTime(DiagnosisTime), BScanTime(BScanTime)
        {}
    };

    void recordPatientVisit(Patient* p);  // 记录病人就诊信息
    QVector<PatientRecord> getPatientRecords() const;  // 记录医生的所有病人的就诊记录

private:
    Patient* patient;  // 当前正在诊断的病人
    int patientNum;    // 医生分配的病人数量
    int timeLeft;      // 剩余诊断时间

    QVector<PatientRecord> patientRecords;  // 存储病人就诊记录

};

#endif // DOCTOR_H
