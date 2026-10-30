#ifndef CINTSET_H
#define CINTSET_H
#include "Defines.h"

class CIntSet {
    int mElems[MAXCARD];
    int mCard;
public:
    CIntSet();
    void Empty();
    ErrCode AddItem(int value);
    void Print() const;
    void SetToReal(CRealSet& target) const;
    friend void SetToReal(const CIntSet& source, CRealSet& target);
    friend void SetToInt(const CRealSet& source, CIntSet& target);
};
#endif
