#ifndef CPP08_BIRD_H
#define CPP08_BIRD_H
#include "Animal.h"                   // 基类声明
class CBird : public CAnimal {         // 鸟类公有继承动物
public:
    void Who() override;               // 重写动物自我介绍
};
#endif
