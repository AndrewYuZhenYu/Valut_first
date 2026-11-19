#include <iostream>                         // 观察构造先后

class CAnimal {
    int mTag;                               // 虚基类保存共同数据
public:
    explicit CAnimal(int tag) : mTag(tag) {
        std::cout << "Animal(" << mTag << ")\n"; // 输出被选中的实参
    }
    int GetTag() const { return mTag; }     // 提供读取接口
};

class CBird : virtual public CAnimal {     // 声明共享虚基类
public:
    CBird() : CAnimal(1) { std::cout << "Bird\n"; } // 单独构造 Bird 时用 1
};

class CBeast : virtual public CAnimal {    // 同样共享虚基类
public:
    CBeast() : CAnimal(2) { std::cout << "Beast\n"; } // 单独构造 Beast 时用 2
};

class CBat : public CBird, public CBeast { // Bird 在继承列表中排在 Beast 前
public:
    CBat() : CAnimal(99), CBeast(), CBird() { // 实际顺序不由这里排列决定
        std::cout << "Bat\n";              // 在全部基类初始化后执行
    }
};

int main() {
    CBat bat;                               // 创建最派生对象
    std::cout << bat.GetTag() << '\n';      // 从共享的 Animal 读取标签 99
    return 0;                               // 对象自动销毁
}
