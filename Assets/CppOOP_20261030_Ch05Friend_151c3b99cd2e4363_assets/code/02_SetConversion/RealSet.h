#ifndef CREALSET_H
#define CREALSET_H
#include "Defines.h"

class CRealSet {
    double mElems[MAXCARD];
    int mCard;
public:
    CRealSet();
    void Empty();
    ErrCode AddItem(double value);
    void Print() const;
    void SetToInt(CIntSet& target) const;
    friend void SetToReal(const CIntSet& source, CRealSet& target);
    friend void SetToInt(const CRealSet& source, CIntSet& target);
};
#endif
