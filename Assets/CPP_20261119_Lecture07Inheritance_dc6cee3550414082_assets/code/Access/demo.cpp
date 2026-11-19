class Base {
private:
    int a = 1;                             // 仅 Base 及其友元可直接访问
protected:
    int b = 2;                             // 派生类可在合法上下文中访问
public:
    int c = 3;                             // 公有接口
};

class Derived : public Base {             // 公有继承 Base
public:
    void Change() {
        b = 20;                            // 合法：访问保护成员
        c = 30;                            // 合法：访问公有成员
        // a = 10;                         // 非法：基类私有成员不可直接访问
    }
};
int main(){Derived x; x.Change();}

