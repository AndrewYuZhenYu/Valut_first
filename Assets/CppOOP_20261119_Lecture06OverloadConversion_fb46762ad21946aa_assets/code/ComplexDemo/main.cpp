#include "Complex.h"
#include <cmath>
#include <iostream>
#include <sstream>

int main() {
    std::istringstream input("3 4 1 2");     // 构造可重复的输入流
    CComplex a, b;                           // 创建两个复数
    input >> a >> b;                         // 验证连续输入
    std::cout << "a=" << a << " b=" << b << '\n'; // 连续输出
    std::cout << "sum=" << (a + b) << '\n'; // 计算加法
    std::cout << "diff=" << (a - b) << '\n'; // 计算减法
    CComplex old = a++;                      // 保存更新前的值
    std::cout << "old=" << old << " new=" << a << '\n'; // 后置差异
    ++a;                                     // 再执行前置递增
    std::cout << "prefix=" << a << '\n';    // 打印更新值
    --a;                                     // 友元前置递减
    std::cout << "after --=" << a << '\n'; // 恢复状态
    std::cout << "|a|=" << static_cast<double>(a) << '\n'; // 转成模长
    std::cout << "sqrt(|a|)=" << std::sqrt(a) << '\n';  // 依赖隐式转换
    std::cout << "Add(5)=" << a.Add(5) << '\n'; // 转换构造函数
    return 0;                                // 标准入口返回值
}
