#include <string>                          // 使用标准字符串

class CComplex {
protected:
    double mR, mI;                         // 复数实部、虚部
public:
    CComplex(double r, double i) : mR(r), mI(i) {} // 初始化复数值
    void SetValues(double r, double i) { mR = r; mI = i; } // 修改复数值
};

class CNamedComplex : public CComplex {   // 通过继承复用实部、虚部
    std::string mName;                    // 自动管理字符内存
public:
    CNamedComplex(const std::string& name, double r, double i)
        : CComplex(r, i), mName(name) {}  // 基类先于成员初始化
    void SetValues(const std::string& name, double r, double i) {
        mName = name;                      // 安全更新字符串
        CComplex::SetValues(r, i);        // 明确调用基类版本
    }
};
int main(){ CNamedComplex c("name",1,2); c.SetValues("new",3,4); }

