#ifndef CSTACK_H
#define CSTACK_H
#include "Node.h"
class CStack {
    CNode* pTop;
public:
    CStack();
    void Push(int data);
    int Pop();
    ~CStack();
    CStack(const CStack&) = delete;                       // 禁止浅拷贝动态节点
    CStack& operator=(const CStack&) = delete;            // 禁止浅赋值
};
#endif
