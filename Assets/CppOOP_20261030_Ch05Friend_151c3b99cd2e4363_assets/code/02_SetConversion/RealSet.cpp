#include "RealSet.h"
#include "IntSet.h"
#include <iostream>

CRealSet::CRealSet() : mCard(0) {}
void CRealSet::Empty() { mCard = 0; }
ErrCode CRealSet::AddItem(double value) {
    for (int i = 0; i < mCard; ++i)
        if (mElems[i] == value) return NOERR;             // 查重（直接 double 比较适用于本例）
    if (mCard >= MAXCARD) return ZOVERFLOW;
    mElems[mCard++] = value;
    return NOERR;
}
void CRealSet::Print() const {
    std::cout << '{';
    for (int i = 0; i < mCard; ++i) {
        if (i) std::cout << ", ";
        std::cout << mElems[i];
    }
    std::cout << "}\n";
}
void CRealSet::SetToInt(CIntSet& target) const {
    target.Empty();
    for (int i = 0; i < mCard; ++i)
        target.AddItem(static_cast<int>(mElems[i]));     // int 转换可能导致重复
}
