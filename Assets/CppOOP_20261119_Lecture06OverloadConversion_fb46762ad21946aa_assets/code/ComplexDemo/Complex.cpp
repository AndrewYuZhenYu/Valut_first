#include "Complex.h"
#include <cmath>
#include <istream>
#include <ostream>
#include <utility>

CComplex::CComplex(double r, double i, std::string name)
    : real_(r), imag_(i), name_(std::move(name)) {} // 初始化对象

double CComplex::real() const { return real_; }   // 取得实部

double CComplex::imag() const { return imag_; }   // 取得虚部

CComplex CComplex::Add(const CComplex& rhs) const { // 显式成员方法
    return *this + rhs;                              // 复用重载加法
}

CComplex CComplex::operator+(const CComplex& rhs) const {  // 成员二元 +
    return CComplex(real_ + rhs.real_, imag_ + rhs.imag_); // 新复数按值返回
}

CComplex operator-(const CComplex& a, const CComplex& b) { // 友元二元 -
    return CComplex(a.real_ - b.real_, a.imag_ - b.imag_); // 新复数按值返回
}

CComplex& CComplex::operator++() {  // 前置 ++
    ++real_;                         // 实部 +1
    ++imag_;                         // 虚部 +1
    return *this;                    // 返回更新对象自身
}

CComplex CComplex::operator++(int) { // 后置 ++
    CComplex old = *this;            // 保留旧值副本
    ++(*this);                       // 调用前置版本更新自己
    return old;                      // 返回更新前的值
}

CComplex& operator--(CComplex& z) { // 友元前置 --
    --z.real_;                       // 递减实部
    --z.imag_;                       // 递减虚部
    return z;                        // 返回对象引用
}

CComplex operator--(CComplex& z, int) { // 友元后置 --
    CComplex old = z;                   // 保存旧值
    --z;                                // 执行前置 --
    return old;                         // 返回旧值
}

CComplex::operator double() const {     // 类到 double 的转换
    return std::hypot(real_, imag_);     // 课件把转换结果定义为模长
}

std::ostream& operator<<(std::ostream& out, const CComplex& z) { // 输出
    out << z.real_;                     // 输出实部
    if (z.imag_ >= 0) out << "+";       // 正虚部添加 + 号
    out << z.imag_ << "i";              // 输出虚部
    return out;                         // 支持继续 <<
}

std::istream& operator>>(std::istream& in, CComplex& z) { // 输入
    double r = 0, i = 0;                // 用临时数接收
    if (in >> r >> i) z = CComplex(r, i); // 全部成功后再赋值
    return in;                          // 支持继续 >>
}
