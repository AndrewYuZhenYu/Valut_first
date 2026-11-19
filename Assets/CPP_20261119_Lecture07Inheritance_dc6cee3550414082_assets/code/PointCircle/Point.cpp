#include "Point.h"                         // 引入 CPoint 声明

CPoint::CPoint(int x, int y) : mX(x), mY(y) {  // 初始化坐标
    std::cout << "Point...\n";              // 输出构造提示
}

void CPoint::Show() const {
    std::cout << "X = " << mX << ", Y = " << mY << '\n'; // 输出坐标
}

CPoint::~CPoint() {
    std::cout << "Delete Point!\n";         // 输出析构提示
}
