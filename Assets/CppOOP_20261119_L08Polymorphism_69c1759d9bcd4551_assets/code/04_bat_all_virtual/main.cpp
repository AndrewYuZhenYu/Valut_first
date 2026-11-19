#include <iostream>                    // 标准输出
class CAnimal {                        // 共同祖先
public:
    virtual void Who() { std::cout << "动物\n"; } // 祖先虚函数
    virtual ~CAnimal() = default;      // 虚析构
};
class CBeast : virtual public CAnimal {// 虚继承动物
public:
    void Who() override { std::cout << "兽\n"; } // 覆盖祖先虚函数
};
class CBird : virtual public CAnimal { // 虚继承动物
public:
    void Who() override { std::cout << "鸟\n"; } // 覆盖祖先虚函数
};
class CBat : public CBeast, public CBird { // 最派生类
public:
    void Who() override { std::cout << "蝙蝠\n"; } // 唯一最终覆盖者
};
int main() {                           // 程序入口
    CBat bat;                          // 创建蝙蝠对象
    CAnimal* pa = &bat;                // 祖先基类指针
    CBeast* pb = &bat;                 // 兽类基类指针
    CBird* pc = &bat;                  // 鸟类基类指针
    pa->Who();                         // 输出蝙蝠
    pb->Who();                         // 输出蝙蝠
    pc->Who();                         // 输出蝙蝠
    return 0;                          // 正常返回
}
