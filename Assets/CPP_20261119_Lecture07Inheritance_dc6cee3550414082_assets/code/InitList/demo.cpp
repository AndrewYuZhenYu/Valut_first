class Pair {
    int a;                                 // 成员 a 先声明
    int b;                                 // 成员 b 后声明
public:
    explicit Pair(int v) : b(v + 1), a(v) {} // 实际先初始化 a，再初始化 b
};
int main(){ Pair p(1); }

