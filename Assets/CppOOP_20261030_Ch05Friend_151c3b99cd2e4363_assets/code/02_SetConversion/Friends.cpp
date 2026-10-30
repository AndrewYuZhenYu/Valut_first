#include "IntSet.h"
#include "RealSet.h"

void SetToReal(const CIntSet& source, CRealSet& target) {
    target.mCard = source.mCard;                           // 由整数到实数不会合并不同 int 值
    for (int i = 0; i < source.mCard; ++i)
        target.mElems[i] = source.mElems[i];                // 访问两类的私有数组
}
void SetToInt(const CRealSet& source, CIntSet& target) {
    target.mCard = 0;                                     // 不直接复制源基数
    for (int i = 0; i < source.mCard; ++i) {
        int value = static_cast<int>(source.mElems[i]);   // 向零截断（输入在 int 范围内）
        bool found = false;
        for (int j = 0; j < target.mCard; ++j)
            if (target.mElems[j] == value) found = true;   // 去除截断后重复项
        if (!found) target.mElems[target.mCard++] = value;
    }
}
