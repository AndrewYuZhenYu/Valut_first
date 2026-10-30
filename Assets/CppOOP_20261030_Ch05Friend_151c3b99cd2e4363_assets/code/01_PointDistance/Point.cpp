#include "Point.h"
#include <cmath>

CPoint::CPoint(double zX, double zY) : mX(zX), mY(zY) {}  // 初始化坐标
double CPoint::GetX() const { return mX; }                 // 返回 x 坐标
double CPoint::GetY() const { return mY; }                 // 返回 y 坐标

double Distance(const CPoint& a, const CPoint& b) {
    double dx = b.mX - a.mX;                              // 友元读取私有 x 坐标
    double dy = b.mY - a.mY;                              // 友元读取私有 y 坐标
    return std::sqrt(dx * dx + dy * dy);                   // 勾股定理
}
