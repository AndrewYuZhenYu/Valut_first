#include "IntSet.h"
#include "RealSet.h"
#include <iostream>

int main() {
    CIntSet integers;
    integers.AddItem(1); integers.AddItem(2); integers.AddItem(3);
    CRealSet reals;
    SetToReal(integers, reals);                             // 友元非成员函数
    std::cout << "int -> real: "; reals.Print();
    reals.Empty();
    reals.AddItem(4.8); reals.AddItem(4.2); reals.AddItem(-3.7);
    SetToInt(reals, integers);                              // 去重后的整数集合
    std::cout << "real -> int: "; integers.Print();
    return 0;
}
