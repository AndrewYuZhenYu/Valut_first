#ifndef CPP08_BEAST_H
#define CPP08_BEAST_H
#include "Animal.h"                   // 基类声明
class CBeast : public CAnimal {        // 兽类公有继承动物
public:
    void Who() override;               // 重写动物自我介绍
};
#endif
