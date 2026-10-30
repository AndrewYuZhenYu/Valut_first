#include "IntSet.h"
#include "RealSet.h"
#include <iostream>

CIntSet::CIntSet() : mCard(0) {}                          // 初始化为空集合
void CIntSet::Empty() { mCard = 0; }                     // 逻辑清空
ErrCode CIntSet::AddItem(int value) {
    for (int i = 0; i < mCard; ++i)                      // 查重
        if (mElems[i] == value) return NOERR;             // 已有该元素
    if (mCard >= MAXCARD) return ZOVERFLOW;               // 避免数组越界
    mElems[mCard++] = value;                              // 写入新元素
    return NOERR;
}
void CIntSet::Print() const {
    std::cout << '{';
    for (int i = 0; i < mCard; ++i) {
        if (i) std::cout << ", ";
        std::cout << mElems[i];
    }
    std::cout << "}\n";
}
void CIntSet::SetToReal(CRealSet& target) const {
    target.Empty();                                      // 从空集合开始
    for (int i = 0; i < mCard; ++i)
        target.AddItem(mElems[i]);                        // 经公开接口插入
}
