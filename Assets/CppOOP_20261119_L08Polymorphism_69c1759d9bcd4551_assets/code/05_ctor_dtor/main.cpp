#include <iostream>                    // 标准输出
class Base {                           // 基类
public:
    Base() { F(); }                    // 基类构造阶段虚调用
    virtual void F() { std::cout << "Base\n"; } // 基类版本
    virtual ~Base() { F(); }           // 基类析构阶段虚调用
};
class Derived : public Base {          // 派生类
public:
    Derived() { F(); }                 // 派生构造完成本体时的虚调用
    void F() override { std::cout << "Derived\n"; } // 派生版本
    ~Derived() override { F(); }       // 派生析构阶段的虚调用
};
int main() {                           // 程序入口
    Derived obj;                       // 构造时依次输出 Base、Derived
    Base& ref = obj;                   // 基类引用绑定派生对象
    ref.F();                           // 完整对象阶段输出 Derived
    return 0;                          // 退出时依次输出 Derived、Base
}
