#include "Circle.h"                       // 包含完整的派生类声明

int main() {
    CPoint point(7, 1);                    // 创建基类对象
    CCircle circle(9, 9, 9);               // 创建派生类对象，先构造基类
    point.Show();                          // 调用基类 Show
    circle.Show();                         // 调用派生类 Show
    circle.CPoint::Show();                 // 显式调用基类 Show
    return 0;                              // 标准 main 函数返回值
}
