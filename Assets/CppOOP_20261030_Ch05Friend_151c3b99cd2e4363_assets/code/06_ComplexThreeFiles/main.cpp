#include "Complex.h"
#include <iostream>
int main() {
    CComplex a(2, 3), b(4, -1);
    CComplex c = a.Add(b);                                // 6 + 2i
    std::cout << c.GetReal() << ", " << c.GetImag() << '\n';
    return 0;
}
