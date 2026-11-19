#include <iostream>                         // 输出演示结果

class CBird {
public:
    void ShowBodyFeature() const { std::cout << "Bird\n"; } // 鸟的特征
};

class CBeast {
public:
    void ShowBodyFeature() const { std::cout << "Beast\n"; } // 兽的特征
};

class CBat : public CBird, public CBeast { // 多重继承
};

int main() {
    CBat bat;                               // 创建多重派生对象
    bat.CBird::ShowBodyFeature();          // 显式选择 CBird 的函数
    bat.CBeast::ShowBodyFeature();         // 显式选择 CBeast 的函数
    return 0;                               // 输出 Bird 与 Beast
}
