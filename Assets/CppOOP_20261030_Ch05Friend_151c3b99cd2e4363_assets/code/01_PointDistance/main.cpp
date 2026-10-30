#include <iostream>
#include "Point.h"

int main() {
    CPoint a(3.5, 5.5), b(6.5, 9.5);                      // 创建两个点
    std::cout << "Distance = " << Distance(a, b) << '\n'; // 输出 5
    return 0;
}
