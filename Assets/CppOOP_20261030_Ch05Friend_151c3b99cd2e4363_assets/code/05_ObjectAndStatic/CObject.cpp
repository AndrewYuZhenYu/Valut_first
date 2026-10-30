#include "CObject.h"
#include <iostream>
CObject CObject::zStaticObject(0);                         // 定义唯一的静态对象
CObject* CObject::pStaticObject = nullptr;                // 定义共享的静态指针
CObject::CObject(int id) : mID(id), pObject(nullptr) {
    std::cout << "Construct " << mID << '\n';
}
void CObject::SetPtrObject(CObject* object) { pObject = object; }    // 只记录地址
void CObject::SetStaticPtrObject(CObject* object) { pStaticObject = object; }
CObject::~CObject() { std::cout << "Destroy " << mID << '\n'; }    // 不 delete 非拥有指针
