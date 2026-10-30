#include "CObject.h"
int main() {
    CObject a(1), b(2), c(3);
    a.SetPtrObject(&b);                                    // b 为局部对象，a 不拥有 b
    a.SetStaticPtrObject(&c);                              // 所有对象共享静态指针
    return 0;
}
