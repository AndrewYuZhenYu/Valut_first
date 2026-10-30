#ifndef CPOINT_H
#define CPOINT_H

class CPoint {
    double mX, mY;
public:
    CPoint(double zX = 0, double zY = 0);
    double GetX() const;
    double GetY() const;
    friend double Distance(const CPoint& a, const CPoint& b);
};
#endif
