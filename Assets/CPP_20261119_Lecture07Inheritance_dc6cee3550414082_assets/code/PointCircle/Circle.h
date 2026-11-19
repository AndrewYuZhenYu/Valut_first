#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "Point.h"                         // 定义基类时必须可见完整类型

class CCircle : public CPoint {             // CCircle 公有继承 CPoint
    int mR;                                 // 新增半径
public:
    CCircle(int x, int y, int r);           // 声明派生类构造函数
    void Show() const;                      // 隐藏基类同名 Show
    ~CCircle();                             // 声明析构函数
};

#endif
