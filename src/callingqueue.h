#ifndef CALLINGQUEUE_H
#define CALLINGQUEUE_H

#include "patient.h"

class CallingQueue
{
private:
    Patient* h;     // 队列头指针
    int len;        // 队列长度

public:
    CallingQueue();     // 构造函数，初始化队列
    ~CallingQueue();    // 析构函数，释放队列内存

    void enqueue(Patient* p);           // 将患者加入队列
    Patient* dequeueBScan();            // 将患者从B超队列中出队
    Patient* dequeueDoctor(int doc);    // 将患者从诊室队列中出队
    int getLen();                       // 获取队列长度
    Patient* peek();                    // 查看队列头部的患者，不出队
};

#endif // CALLINGQUEUE_H
