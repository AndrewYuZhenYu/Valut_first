#include <iostream>                    // 标准输出
class CAnimal {                        // 共同祖先
public:
    void Who() { std::cout << "我不是飞禽就是走兽！\n"; } // 非虚
};
class CBeast : virtual public CAnimal {// 虚继承动物
public:
    void Who() { std::cout << "我是森林之王！\n"; } // 非虚
};
class CBird : virtual public CAnimal { // 虚继承动物
public:
    virtual void Who() { std::cout << "我是一只小小鸟！\n"; } // 虚函数
};
class CBat : public CBeast, public CBird { // 蝙蝠多重继承
public:
    void Who() override { std::cout << "我是蝙蝠大侠！\n"; } // 重写鸟类虚函数
};
int main() {                           // 程序入口
    CBat bat;                          // 创建蝙蝠对象
    CAnimal* pa = &bat;                // 祖先基类指针
    CBeast* pb = &bat;                 // 兽类基类指针
    CBird* pc = &bat;                  // 鸟类基类指针
    pa->Who();                         // 输出动物版本
    pb->Who();                         // 输出兽类版本
    pc->Who();                         // 输出蝙蝠版本
    return 0;                          // 正常返回
}
