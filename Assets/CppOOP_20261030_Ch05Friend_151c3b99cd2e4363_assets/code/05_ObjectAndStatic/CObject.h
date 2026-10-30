#ifndef COBJECT_H
#define COBJECT_H
class CObject {
    int mID;
    CObject* pObject;                                     // 可定义指向同类的指针
    static CObject zStaticObject;                         // 可声明同类静态成员对象
    static CObject* pStaticObject;
public:
    explicit CObject(int id);
    void SetPtrObject(CObject* object);
    static void SetStaticPtrObject(CObject* object);
    ~CObject();
};
#endif
