#include <iostream>                    // 标准输出
class CAnimal {                        // 动物基类
public:
    void Who() { std::cout << "动物版本\n"; } // 非虚函数
};
class CBeast : public CAnimal {        // 兽类派生类
public:
    void Who() { std::cout << "兽类版本\n"; } // 同名但不是虚重写
};
int main() {                           // 程序入口
    CBeast tiger;                      // 实际创建兽类对象
    CAnimal* p = &tiger;               // 基类指针绑定派生对象
    p->Who();                          // 调用动物版本
    tiger.Who();                       // 调用兽类版本
    return 0;                          // 正常返回
}
