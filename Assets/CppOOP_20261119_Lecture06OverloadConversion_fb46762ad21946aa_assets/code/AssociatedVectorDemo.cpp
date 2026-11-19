#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class CAssociateVector {
    struct Node {                                // 每个结点是一对键和值
        std::string key;                        // 字符串索引
        int value;                              // 整数数据
    };
    std::vector<Node> elems_;                   // 自动管理内存
    std::size_t capacity_;                      // 最大结点数
public:
    explicit CAssociateVector(std::size_t capacity)
        : capacity_(capacity) {}                // 设置容量上限

    int& operator[](const std::string& key) {   // 下标返回内部数值引用
        for (Node& e : elems_) {               // 线性扫描现有元素
            if (e.key == key) return e.value;  // 存在则返回原有值
        }
        if (elems_.size() >= capacity_) {      // 无法容纳新结点
            throw std::out_of_range("capacity reached"); // 明确报告失败
        }
        int initial = static_cast<int>(elems_.size()) + 1; // 复现课件初值规则
        elems_.push_back(Node{key, initial});   // 保存新键值
        return elems_.back().value;             // 返回新单元引用
    }

    void Print() const {                        // 输出所有已存结点
        for (const Node& e : elems_) {         // 按插入顺序打印
            std::cout << e.key << " = " << e.value << '\n'; // 输出键值
        }
    }
};

int main() {
    CAssociateVector fruit(8);                  // 容量为 8
    fruit["Apple"] = 8;                         // 新建键并设为 8
    fruit["Orange"];                           // 新建第 2 个键，默认值为 2
    fruit["Banana"] = 10;                       // 新建第 3 个键并设为 10
    fruit.Print();                              // 第一次输出
    fruit["Fruit"] = (fruit["Apple"] + fruit["Orange"] + fruit["Banana"]) / 3; // 计算整数平均数
    std::cout << "---\n";                      // 输出分隔符
    fruit.Print();                              // 第二次输出
    return 0;                                   // 正常退出
}
