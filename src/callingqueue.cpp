#include "callingqueue.h"

/* 构造函数 */
CallingQueue::CallingQueue()
{
    h = new Patient;
    h->next = NULL;
    len = 0;
}

/* 析构函数 */
CallingQueue::~CallingQueue()
{
    Patient* t = h;
    while (t != nullptr) {  // 清空队列
        Patient* nxt = t->next;
        delete t;
        t = nxt;
    }
}

/* 获取队列长度 */
int CallingQueue::getLen()
{
    return len;
}

/* 入队操作 */
void CallingQueue::enqueue(Patient* p)
{
    Patient* t = h;
    while (t->next != NULL)  // 移动到队列末尾
        t = t->next;
    t->next = p;  // 将新患者节点连接到队尾
    len ++;  // 队列长度增加
}

/* 将患者从B超队列中出队 */
Patient* CallingQueue::dequeueBScan()
{
    if (len == 0)
        return NULL;

    Patient* q = h->next;
    if (q != NULL) {  // 将头节点连接到下一个节点，跳过队头节点
        h->next = q->next;
        len--;
        q->next = NULL;
    }
    return q;
}

/* 将患者从诊室队列中出队 */
Patient* CallingQueue::dequeueDoctor(int doc)
{
    if (len == 0)
        return NULL;

    Patient* p = h;
    while (p->next != NULL) {
        int potentialDoc = p->next->getDoc();
        if (potentialDoc == 4 || potentialDoc == doc) {
            Patient* q = p->next;  // 取出匹配的患者节点
            p->next = q->next;  // 将上一个节点连接到下一个节点，跳过匹配节点
            len --;
            q->next = NULL;
            return q;  // 返回出队的患者节点
        }
        p = p->next;  // 移动到下一个节点
    }
    return NULL;  // 没有匹配的患者节点，返回空指针
}

/* 查看队列头部的患者，不出队 */
Patient* CallingQueue::peek()
{
    if (len == 0)
        return NULL;

    return h->next;
}
