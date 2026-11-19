#include "Animal.h"                   // 动物基类
#include "Beast.h"                    // 兽类
#include "Bird.h"                     // 鸟类
void Show(CAnimal& animal) {           // 基类引用形参
    animal.Who();                      // 动态虚调用
}
int main() {                           // 程序入口
    CAnimal animal;                    // 基类对象
    CBeast tiger;                      // 兽类对象
    CBird sparrow;                     // 鸟类对象
    Show(animal);                      // 调用基类 Who
    Show(tiger);                       // 调用兽类 Who
    Show(sparrow);                     // 调用鸟类 Who
    return 0;                          // 正常返回
}
