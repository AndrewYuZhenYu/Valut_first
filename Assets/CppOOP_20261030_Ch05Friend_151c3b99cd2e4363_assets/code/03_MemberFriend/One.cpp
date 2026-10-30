#include "One.h"
#include "Two.h"

COne::COne(int x1, int x2) : mX1(x1), mX2(x2) {}
int COne::GetX1() const { return mX1; }
int COne::GetX2() const { return mX2; }
void COne::SetMemberOfCTwo(CTwo& target) const {
    target.mY1 = mX1 + mX2;                    // 7 + 1 = 8，直接写入私有字段
    target.mY2 = mX1 - mX2;                    // 7 - 1 = 6
}
