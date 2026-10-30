#include "Stack.h"
#include <iostream>
int main() {
    CStack stack;
    stack.Push(10); stack.Push(23); stack.Push(50);       // 栈顶为 50
    std::cout << stack.Pop() << ' ';                      // 50
    std::cout << stack.Pop() << '\n';                     // 23
    return 0;                                            // 析构清理剩余 10
}
