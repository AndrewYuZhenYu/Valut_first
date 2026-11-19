#include <iostream>                    // 标准输出
class Shape {                          // 抽象图形类
public:
    virtual double Area() const = 0;   // 纯虚面积函数
    virtual ~Shape() = default;        // 虚析构函数
};
class Circle : public Shape {          // 圆
    double radius;                     // 半径
public:
    explicit Circle(double r) : radius(r) {} // 初始化半径
    double Area() const override {     // 计算圆面积
        return 3.141592653589793 * radius * radius;
    }
};
class Rectangle : public Shape {       // 矩形
    double width;                      // 宽
    double height;                     // 高
public:
    Rectangle(double w, double h) : width(w), height(h) {} // 初始化
    double Area() const override {     // 计算矩形面积
        return width * height;
    }
};
int main() {                           // 程序入口
    Circle c(2.0);                     // 半径为 2 的圆
    Rectangle r(3.0, 4.0);             // 宽 3、高 4 的矩形
    const Shape* shapes[] = {&c, &r};  // 指向两种具体类
    for (const Shape* p : shapes) {    // 遍历每种图形
        std::cout << p->Area() << '\n';// 虚函数调用各自实现
    }
    return 0;                          // 正常返回
}
