#include "One.h"
#include "Two.h"
#include <iostream>
int main() {
    COne first(7, 1);
    CTwo second(3, 8);
    first.SetMemberOfCTwo(second);                       // 只授权这一成员函数
    std::cout << second.GetY1() << ", " << second.GetY2() << '\n'; // 8, 6
    return 0;
}
