#include <iostream>                         // 使用控制台输出
#include <string>                           // 安全存储姓名

class CPerson {
    std::string mName;                     // 使用自动管理内存的字符串
public:
    explicit CPerson(const std::string& name) : mName(name) {
        std::cout << "Person...\n";       // 先构造基类
    }
    ~CPerson() { std::cout << "Delete Person!\n"; } // 最后析构基类
};

class CDate {
    int mYear, mMonth, mDay;               // 保存日期各部分
public:
    CDate(int y, int m, int d) : mYear(y), mMonth(m), mDay(d) {
        std::cout << "Date...\n";         // 先于派生类自身构造函数体
    }
    ~CDate() { std::cout << "Delete Date!\n"; } // 晚于派生类自身析构
};

class CChiefExecutive : public CPerson {  // CPerson 是基类
    CDate mWorkDate;                       // CDate 是成员对象
public:
    CChiefExecutive(const std::string& name, int y, int m, int d)
        : CPerson(name), mWorkDate(y, m, d) { // 初始化基类和成员
        std::cout << "ChiefExecutive...\n"; // 最后执行派生类函数体
    }
    ~CChiefExecutive() {
        std::cout << "Delete ChiefExecutive!\n"; // 最先执行析构函数体
    }
};

int main() {
    CChiefExecutive ce("DJH", 1997, 7, 1); // 创建完整派生类对象
    return 0;                              // 离开作用域后自动销毁
}
