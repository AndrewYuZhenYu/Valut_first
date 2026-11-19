#include <iostream>                        // 标准输出
class Circle {
    double radius;                         // 圆半径
public:
    explicit Circle(double r) : radius(r) {} // 初始化圆半径
    double Area() const { return 3.141592653589793 * radius * radius; } // 圆面积
};
class Cylinder : public Circle {          // 圆柱公有继承 Circle
    double height;                         // 圆柱高度
public:
    Cylinder(double r, double h) : Circle(r), height(h) {} // 先构造圆
    double Volume() const { return Area() * height; } // 体积=底面积×高
};
int main() {
    Cylinder c(2.0, 3.0);                  // 半径2，高3
    std::cout << c.Area() << ' ' << c.Volume() << '\n'; // 输出面积和体积
    return 0;
}
