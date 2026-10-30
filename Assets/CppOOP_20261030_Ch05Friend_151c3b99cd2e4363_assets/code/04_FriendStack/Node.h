#ifndef CNODE_H
#define CNODE_H
class CStack;
class CNode {
    int mData;
    CNode* pPrev;
public:
    CNode(int data, CNode* prev);
    friend class CStack;                                 // 整个栈类获得节点访问权限
};
#endif
