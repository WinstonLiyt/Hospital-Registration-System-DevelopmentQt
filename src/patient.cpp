#include "patient.h"

/* 构造函数 */
Patient::Patient(int ID, QString Name, bool Sex, int Age, int Dep, int Doc, int Time)
{
    regID = ID;
    patientName = Name;
    patientSex = Sex;
    patientAge = Age;
    dep = Dep;
    doc = Doc;
    visTime = Time;

    /* 生成服从正态分布的诊断时间 */
    diagnosisTime = generateRandomNormalInteger(mean, stdDev, minVal, maxVal);

    double P_Bscan = rand() % 100 / (double)101;  // 生成0到1之间的随机概率值
    if (P_Bscan < BScanProbability)
        BScanTime = 0;
    else
        BScanTime = generateRandomNormalInteger(meanB, stdDevB, minValB, maxValB);

    next = NULL;  // 初始化指向下一个病人的指针

    qDebug() << Name << ": " << diagnosisTime;
}

/* 获取病人挂号ID */
int Patient::getRegID()
{
    return regID;
}

/* 获取病人姓名 */
QString Patient::getPatientName()
{
    return patientName;
}

/* 获取病人性别，T表示男性，F表示女性 */
bool Patient::getPatientSex()
{
    return patientSex;
}

/* 获取病人年龄 */
int Patient::getPatientAge()
{
    return patientAge;
}

/* 获取病人所在科室 */
int Patient::getDep()
{
    return dep;
}

/* 获取病人所选医生 */
int Patient::getDoc()
{
    return doc;
}

/* 获取病人到达就诊室的时间 */
int Patient::getVisTime()
{
    return visTime;
}

/* 获取病人诊断所需时间 */
int Patient::getDiagnosisTime()
{
    return diagnosisTime;
}

/* 获取B超检查所需时间 */
int Patient::getBScanTime()
{
    return BScanTime;
}

/* 生成正太分布随机整数 */
int Patient::generateRandomNormalInteger(int mean, int stdDev, int minVal, int maxVal) {
    std::random_device rd;  // 创建一个随机设备以获得随机种子
    std::mt19937 gen(rd());  // 创建一个 Mersenne Twister 伪随机数生成器并用随机设备的种子初始化
    std::normal_distribution<> distribution(mean, stdDev);  // 创建一个服从正态分布的随机数分布，指定均值和标准差

    int randomValue;
    do {
        randomValue = static_cast<int>(round(distribution(gen)));  // 生成服从正态分布的随机浮点数，并进行四舍五入转换为整数
    } while (randomValue < minVal || randomValue > maxVal);  // 循环直到生成在范围内的随机数

    return randomValue;
}
