#include "Circle.h"                        // 获得派生类声明

CCircle::CCircle(int x, int y, int r)
    : CPoint(x, y), mR(r) {                 // 先初始化基类，再初始化半径
    std::cout << "Circle...\n";            // 输出构造提示
}

void CCircle::Show() const {
    std::cout << "圆心为点(" << mX << ", " << mY << ")\n"; // 访问保护坐标
    std::cout << "半径为 " << mR << '\n';   // 输出新增数据
}

CCircle::~CCircle() {
    std::cout << "Delete Circle!\n";       // 先输出本类析构提示
}
