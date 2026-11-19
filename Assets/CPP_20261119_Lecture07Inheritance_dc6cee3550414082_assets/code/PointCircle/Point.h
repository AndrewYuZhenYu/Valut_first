#ifndef CPOINT_H
#define CPOINT_H

#include <iostream>                         // 使用 std::cout

class CPoint {
protected:
    int mX, mY;                             // 派生类可以访问的坐标
public:
    CPoint(int x = 0, int y = 0);           // 声明有默认参数的构造函数
    void Show() const;                      // 不改变对象的成员函数
    ~CPoint();                              // 基类析构函数，课件示例为非虚
};

#endif
