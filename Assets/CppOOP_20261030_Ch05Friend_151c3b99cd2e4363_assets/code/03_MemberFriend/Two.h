#ifndef CTWO_H
#define CTWO_H
#include "One.h"
class CTwo {
    int mY1, mY2;
public:
    CTwo(int y1, int y2);
    int GetY1() const;
    int GetY2() const;
    friend void COne::SetMemberOfCTwo(CTwo&) const;
};
#endif
