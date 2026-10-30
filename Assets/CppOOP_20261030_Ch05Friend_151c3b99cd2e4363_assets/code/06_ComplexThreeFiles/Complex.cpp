#include "Complex.h"
CComplex::CComplex(double real, double imag) : mR(real), mI(imag) {}
double CComplex::GetReal() const { return mR; }
double CComplex::GetImag() const { return mI; }
CComplex CComplex::Add(const CComplex& other) const {
    return CComplex(mR + other.mR, mI + other.mI);         // 返回计算所得新对象
}
