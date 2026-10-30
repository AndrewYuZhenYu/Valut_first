#ifndef CCOMPLEX_H
#define CCOMPLEX_H
class CComplex {
    double mR, mI;
public:
    CComplex(double real = 0, double imag = 0);
    double GetReal() const;
    double GetImag() const;
    CComplex Add(const CComplex& other) const;
};
#endif
