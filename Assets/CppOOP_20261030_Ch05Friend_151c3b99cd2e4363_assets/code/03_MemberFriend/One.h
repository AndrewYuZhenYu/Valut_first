#ifndef CONE_H
#define CONE_H
class CTwo;
class COne {
    int mX1, mX2;
public:
    COne(int x1, int x2);
    int GetX1() const;
    int GetX2() const;
    void SetMemberOfCTwo(CTwo& target) const;
};
#endif
