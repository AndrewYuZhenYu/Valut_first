#ifndef CPP06_COMPLEX_H
#define CPP06_COMPLEX_H

#include <iosfwd>
#include <string>

class CComplex {
    double real_;                                     // 实部
    double imag_;                                     // 虚部
    std::string name_;                                // 名称自动管理资源
public:
    CComplex(double r = 0, double i = 0, std::string name = ""); // 构造函数
    double real() const;                              // 读取实部
    double imag() const;                              // 读取虚部
    CComplex Add(const CComplex& rhs) const;           // 课件中的 Add 方法
    CComplex operator+(const CComplex& rhs) const;     // 成员加法
    friend CComplex operator-(const CComplex& a, const CComplex& b); // 非成员减法
    CComplex& operator++();                            // 前置 ++
    CComplex operator++(int);                          // 后置 ++
    friend CComplex& operator--(CComplex& z);          // 前置 --
    friend CComplex operator--(CComplex& z, int);      // 后置 --
    operator double() const;                           // 转为模长
    friend std::ostream& operator<<(std::ostream& out, const CComplex& z); // 输出
    friend std::istream& operator>>(std::istream& in, CComplex& z);       // 输入
};

#endif
