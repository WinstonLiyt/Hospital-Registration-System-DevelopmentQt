#include "doctor.h"

/* 构造函数 */
Doctor::Doctor()
{
    patient = NULL;
    patientNum = 0;
    timeLeft = 0;
}

/* 获取当前医生正在诊断的病人 */
Patient* Doctor::getPatient()
{
    return patient;  // 返回当前正在诊断的病人指针
}

/* 获取当前剩余诊断时间 */
int Doctor::getTimeLeft()
{
    return timeLeft;
}

/* 更新剩余诊断时间 */
void Doctor::uploadTimeLeft(int t)
{
    timeLeft = t;
}

/* 分配病人给当前医生进行诊断 */
void Doctor::uploadPatient(Patient* p)
{
    patient = p;  // 将指定病人分配给当前医生
    if (patient == NULL)  // 若病人为空，剩余诊断时间为0
        timeLeft = 0;
    else  // 否则剩余诊断时间为病人的诊断时间
        timeLeft = patient->getDiagnosisTime();
}

/* 分配病人给当前医B超机器进行诊断 */
void Doctor::uploadPatientBScan(Patient* p)
{
    patient = p;  // 将指定病人分配给当前医生
    if (patient == NULL)  // 若病人为空，剩余诊断时间为0
        timeLeft = 0;
    else  // 否则剩余诊断时间为病人的诊断时间
        timeLeft = patient->getBScanTime();
}

/* 记录病人就诊信息 */
void Doctor::recordPatientVisit(Patient* p)
{
    // 将病人信息存入就诊记录中
    patientRecords.append(PatientRecord(p->getRegID(), p->getPatientName(),
                                        p->getPatientSex(), p->getPatientAge(),
                                        p->getDiagnosisTime(), p->getBScanTime()));
}

/* 记录医生的所有病人的就诊记录 */
QVector<Doctor::PatientRecord> Doctor::getPatientRecords() const
{
    return patientRecords;
}
