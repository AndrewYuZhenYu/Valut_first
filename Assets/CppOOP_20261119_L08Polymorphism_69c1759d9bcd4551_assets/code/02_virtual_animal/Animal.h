#ifndef CPP08_ANIMAL_H
#define CPP08_ANIMAL_H
class CAnimal {                        // 动物抽象接口的具体基类版本
public:
    virtual void Who();                // 在基类声明虚函数
    virtual ~CAnimal() = default;      // 多态基类虚析构
};
#endif
