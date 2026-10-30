#include "Stack.h"
#include <stdexcept>
CStack::CStack() : pTop(nullptr) {}                        // 初始空栈

void CStack::Push(int data) {
    CNode* pNode = new CNode(data, pTop);                 // 新结点 pPrev 指向旧栈顶
    pTop = pNode;                                        // 更新栈顶
}
int CStack::Pop() {
    if (pTop == nullptr) throw std::underflow_error("empty stack"); // 空栈不可取值
    CNode* oldTop = pTop;                                // 备份当前栈顶结点地址
    pTop = oldTop->pPrev;                                // 更新栈顶，不能先 delete
    int value = oldTop->mData;                           // 保存待返回的数据
    delete oldTop;                                       // 释放动态结点
    return value;
}
CStack::~CStack() {
    while (pTop != nullptr) {                            // 循环释放所有剩余结点
        CNode* oldTop = pTop;                            // 当前待释放结点
        pTop = oldTop->pPrev;                            // 先找到后继栈节点
        delete oldTop;                                   // 再释放原结点
    }
}
