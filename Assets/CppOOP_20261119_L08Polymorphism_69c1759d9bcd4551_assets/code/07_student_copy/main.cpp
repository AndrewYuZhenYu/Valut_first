#include <cstring>                     // strlen、strcpy
#include <iostream>                    // 标准输出
class CStudent {                       // 学生类
    char* mpName;                      // 动态姓名字符数组
public:
    CStudent() : mpName(nullptr) {}    // 空姓名状态
    explicit CStudent(const char* name) : mpName(nullptr) { // 接受姓名
        SetName(name);                 // 分配并复制姓名
    }
    CStudent(const CStudent& other) : mpName(nullptr) { // 复制构造
        SetName(other.mpName);         // 独立分配新数组
    }
    CStudent& operator=(const CStudent& other) { // 复制赋值
        if (this != &other) {          // 防止自赋值
            SetName(other.mpName);     // 先分配再替换指针
        }
        return *this;                  // 返回当前对象
    }
    ~CStudent() {                      // 对象销毁
        delete[] mpName;               // 释放动态字符数组
    }
    void SetName(const char* name) {   // 修改姓名
        char* next = nullptr;          // 新缓冲区初值为空
        if (name != nullptr) {         // 判断实参是否为空
            next = new char[std::strlen(name) + 1]; // 预留结束符
            std::strcpy(next, name);   // 复制完整姓名
        }
        delete[] mpName;               // 释放旧缓冲区
        mpName = next;                 // 保存新缓冲区
    }
    const char* Name() const {         // 获取姓名
        return mpName != nullptr ? mpName : "(empty)";
    }
};
int main() {                           // 程序入口
    CStudent a("Lily");               // 创建学生 A
    CStudent b = a;                    // 深拷贝学生 B
    a.SetName("Alice");               // 修改 A 不影响 B
    CStudent c;                        // 创建空姓名学生 C
    c = b;                             // 正确处理复制赋值
    std::cout << a.Name() << '\n';    // Alice
    std::cout << b.Name() << '\n';    // Lily
    std::cout << c.Name() << '\n';    // Lily
    return 0;                          // 析构时独立释放内存
}
