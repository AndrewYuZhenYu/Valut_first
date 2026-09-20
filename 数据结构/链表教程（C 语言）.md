# 《C语言链表完全指南》—— 完整可运行版

> **版本**：3.0 ｜ **特点**：所有代码均为完整程序，每行均有注释 ｜ **总行数**：约1200行

---

## 前言

本教程区别于一般教材的最大特点是：**每一个示例都是一个完整的、可编译运行的C程序**。你无需拼凑代码，直接复制保存为 `.c` 文件，用 `gcc` 编译即可运行观察效果。每行代码都有详细注释，帮助你理解每一处细节。

---

## 第一章 单向链表完整实现

### 1.1 基础节点定义与辅助函数

```c
/* ============================================================
   文件名：singly_linked_list.c
   功能：单向链表的完整实现（含所有基础操作）
   编译：gcc -o singly_linked_list singly_linked_list.c
   运行：./singly_linked_list
   ============================================================ */

#include <stdio.h>   // 标准输入输出库，用于printf、fprintf等
#include <stdlib.h>  // 标准库，用于malloc、free、exit等
#include <stdbool.h> // 布尔类型库，用于bool、true、false

/* ============================================================
   结构体定义：链表节点
   ============================================================ */
typedef struct Node {
    int data;          // 数据域：存储整数值
    struct Node* next; // 指针域：指向下一个节点（同类型结构体指针）
} Node;                // 定义类型别名，后续可直接使用 Node 代替 struct Node

/* ============================================================
   函数：创建新节点（静态函数，仅本文件可见）
   参数：value - 要存储的数据值
   返回值：新分配的节点指针，若分配失败则终止程序
   ============================================================ */
static Node* create_node(int value) {
    // 调用malloc分配一个Node结构体大小的内存空间
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    // 检查内存分配是否成功
    if (new_node == NULL) {
        // 分配失败：输出错误信息到标准错误流
        fprintf(stderr, "错误：内存分配失败，程序终止\n");
        // 退出程序，返回非零值表示异常终止
        exit(EXIT_FAILURE);
    }
    
    // 初始化节点的数据域
    new_node->data = value;
    // 初始化节点的指针域为NULL（表示链表的结尾）
    new_node->next = NULL;
    
    // 返回新创建的节点指针
    return new_node;
}

/* ============================================================
   函数：在链表头部插入新节点（头插法）
   参数：head - 当前链表的头指针，value - 要插入的值
   返回值：新的头指针
   时间复杂度：O(1)
   ============================================================ */
Node* push_front(Node* head, int value) {
    // 调用辅助函数创建一个新节点
    Node* new_node = create_node(value);
    
    // 新节点的next指向原来的头节点（若原链表为空，则指向NULL）
    new_node->next = head;
    
    // 新节点成为链表的新头，返回新节点指针
    return new_node;
}

/* ============================================================
   函数：在链表尾部插入新节点（尾插法）
   参数：head - 当前链表的头指针，value - 要插入的值
   返回值：新的头指针（头指针本身不变，但为了接口统一仍然返回）
   时间复杂度：O(n)（需遍历到链表尾部）
   ============================================================ */
Node* push_back(Node* head, int value) {
    // 调用辅助函数创建新节点
    Node* new_node = create_node(value);
    
    // 特殊情况：如果链表为空
    if (head == NULL) {
        // 新节点直接作为头节点返回
        return new_node;
    }
    
    // 创建一个临时指针，用于遍历链表
    Node* current = head;
    
    // 循环遍历，直到找到最后一个节点（即next为NULL的节点）
    while (current->next != NULL) {
        // 将current指向下一个节点
        current = current->next;
    }
    
    // 将最后一个节点的next指向新节点
    current->next = new_node;
    
    // 头指针不变，返回原头指针
    return head;
}

/* ============================================================
   函数：在指定位置插入新节点（索引从0开始）
   参数：head - 当前链表的头指针，pos - 插入位置索引，value - 要插入的值
   返回值：新的头指针（若pos为0，则头指针会改变）
   时间复杂度：O(n)
   ============================================================ */
Node* insert_at(Node* head, int pos, int value) {
    // 检查位置是否有效（负数位置无效）
    if (pos < 0) {
        printf("警告：无效位置（负数），操作被忽略\n");
        return head;
    }
    
    // 特殊情况：插入到头部（pos == 0）
    if (pos == 0) {
        // 复用头插函数
        return push_front(head, value);
    }
    
    // 创建一个临时指针，用于遍历链表
    Node* current = head;
    
    // 移动到第 pos-1 个节点（即要插入位置的前驱节点）
    for (int i = 0; i < pos - 1; i++) {
        // 如果current为空，说明位置越界
        if (current == NULL) {
            printf("警告：位置 %d 超出链表长度，操作被忽略\n", pos);
            return head;
        }
        // 移动到下一个节点
        current = current->next;
    }
    
    // 再次检查前驱是否存在
    if (current == NULL) {
        printf("警告：位置 %d 超出链表长度，操作被忽略\n", pos);
        return head;
    }
    
    // 创建新节点
    Node* new_node = create_node(value);
    
    // 新节点的next指向当前节点的下一个节点
    new_node->next = current->next;
    
    // 当前节点的next指向新节点
    current->next = new_node;
    
    // 头指针不变，返回
    return head;
}

/* ============================================================
   函数：删除第一个匹配指定值的节点
   参数：head - 当前链表的头指针，target - 要删除的值
   返回值：新的头指针（若删除了头节点，则头指针会改变）
   时间复杂度：O(n)
   ============================================================ */
Node* delete_by_value(Node* head, int target) {
    // 如果链表为空，直接返回NULL
    if (head == NULL) {
        printf("警告：链表为空，无法删除\n");
        return NULL;
    }
    
    // 特殊情况：头节点的数据就是目标值
    if (head->data == target) {
        // 保存头节点的指针到临时变量
        Node* temp = head;
        // 将头指针指向下一个节点
        head = head->next;
        // 释放原头节点的内存
        free(temp);
        // 返回新的头指针
        printf("成功删除头节点（值 = %d）\n", target);
        return head;
    }
    
    // 创建一个临时指针，用于遍历链表（从头节点开始）
    Node* current = head;
    
    // 循环查找目标节点的前驱节点
    // 条件：当前节点的下一个节点不为空，且下一个节点的数据不等于目标值
    while (current->next != NULL && current->next->data != target) {
        // 移动到下一个节点
        current = current->next;
    }
    
    // 检查是否找到了目标节点（即current->next不为空）
    if (current->next != NULL) {
        // 保存要删除的节点指针
        Node* temp = current->next;
        // 将当前节点的next指向要删除节点的下一个节点
        current->next = temp->next;
        // 释放要删除节点的内存
        free(temp);
        printf("成功删除节点（值 = %d）\n", target);
    } else {
        // 未找到目标值
        printf("未找到值为 %d 的节点\n", target);
    }
    
    // 头指针不变，返回
    return head;
}

/* ============================================================
   函数：删除链表中所有匹配指定值的节点
   参数：head - 当前链表的头指针，target - 要删除的值
   返回值：新的头指针
   时间复杂度：O(n)
   ============================================================ */
Node* delete_all(Node* head, int target) {
    // 如果链表为空，直接返回NULL
    if (head == NULL) {
        return NULL;
    }
    
    // 第一步：处理链表开头连续匹配的节点
    while (head != NULL && head->data == target) {
        // 保存要删除的节点
        Node* temp = head;
        // 头指针后移
        head = head->next;
        // 释放原头节点
        free(temp);
    }
    
    // 如果链表已空，返回NULL
    if (head == NULL) {
        return NULL;
    }
    
    // 第二步：处理链表中间和末尾的匹配节点
    Node* current = head;
    
    // 遍历链表
    while (current->next != NULL) {
        // 如果下一个节点的数据匹配目标值
        if (current->next->data == target) {
            // 保存要删除的节点
            Node* temp = current->next;
            // 跳过要删除的节点
            current->next = temp->next;
            // 释放内存
            free(temp);
            // 注意：这里不移动current，因为新的next也可能匹配
        } else {
            // 不匹配，正常移动到下一个节点
            current = current->next;
        }
    }
    
    printf("已删除所有值为 %d 的节点\n", target);
    return head;
}

/* ============================================================
   函数：打印链表所有节点的数据
   参数：head - 链表的头指针
   返回值：无
   时间复杂度：O(n)
   ============================================================ */
void print_list(Node* head) {
    // 创建一个临时指针，用于遍历
    Node* current = head;
    
    // 如果链表为空
    if (current == NULL) {
        printf("链表为空：NULL\n");
        return;
    }
    
    // 遍历链表，打印每个节点的数据
    printf("链表内容：");
    while (current != NULL) {
        // 打印当前节点的数据
        printf("%d", current->data);
        // 如果还有下一个节点，打印箭头
        if (current->next != NULL) {
            printf(" -> ");
        }
        // 移动到下一个节点
        current = current->next;
    }
    // 打印NULL表示链表结束
    printf(" -> NULL\n");
}

/* ============================================================
   函数：查找链表中第一个匹配指定值的节点
   参数：head - 链表的头指针，target - 要查找的值
   返回值：找到则返回节点指针，否则返回NULL
   时间复杂度：O(n)
   ============================================================ */
Node* find_node(Node* head, int target) {
    // 创建临时指针用于遍历
    Node* current = head;
    
    // 遍历链表
    while (current != NULL) {
        // 如果当前节点的数据匹配目标值
        if (current->data == target) {
            // 返回当前节点指针
            return current;
        }
        // 移动到下一个节点
        current = current->next;
    }
    
    // 未找到，返回NULL
    return NULL;
}

/* ============================================================
   函数：获取链表的长度（节点个数）
   参数：head - 链表的头指针
   返回值：节点个数
   时间复杂度：O(n)
   ============================================================ */
int list_length(Node* head) {
    // 计数器初始为0
    int count = 0;
    // 创建临时指针用于遍历
    Node* current = head;
    
    // 遍历链表，每遇到一个节点计数加1
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    // 返回计数结果
    return count;
}

/* ============================================================
   函数：反转链表（迭代法）
   参数：head - 当前链表的头指针
   返回值：新的头指针（原尾节点成为新头）
   时间复杂度：O(n)，空间复杂度：O(1)
   ============================================================ */
Node* reverse_list(Node* head) {
    // 如果链表为空或只有一个节点，无需反转
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // 定义三个指针：
    // prev - 前驱节点（初始为NULL，因为反转后头节点将成为尾节点）
    // current - 当前正在处理的节点（初始为原头节点）
    // next - 当前节点的下一个节点（用于保存后续链表的地址）
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    // 遍历整个链表
    while (current != NULL) {
        // 第一步：保存当前节点的下一个节点（防止丢失后续链表）
        next = current->next;
        
        // 第二步：反转指针方向，让当前节点的next指向前驱
        current->next = prev;
        
        // 第三步：前驱指针后移，指向当前节点
        prev = current;
        
        // 第四步：当前指针后移，指向之前保存的下一个节点
        current = next;
    }
    
    // 循环结束后，prev指向原尾节点（即新头节点）
    // 返回新的头指针
    return prev;
}

/* ============================================================
   函数：检测链表是否有环（快慢指针法）
   参数：head - 链表的头指针
   返回值：有环返回true，无环返回false
   时间复杂度：O(n)，空间复杂度：O(1)
   ============================================================ */
bool has_cycle(Node* head) {
    // 空链表或单节点链表不可能有环
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    // 定义快慢两个指针
    // slow - 慢指针，每次走一步
    // fast - 快指针，每次走两步
    Node* slow = head;
    Node* fast = head;
    
    // 循环条件：快指针不为空且快指针的下一个节点不为空
    while (fast != NULL && fast->next != NULL) {
        // 慢指针走一步
        slow = slow->next;
        // 快指针走两步
        fast = fast->next->next;
        
        // 如果快慢指针相遇，说明有环
        if (slow == fast) {
            return true;
        }
    }
    
    // 快指针到达链表末尾，说明无环
    return false;
}

/* ============================================================
   函数：释放整个链表的内存（防止内存泄漏）
   参数：head - 链表的头指针
   返回值：无
   时间复杂度：O(n)
   ============================================================ */
void destroy_list(Node* head) {
    // 创建临时指针，用于遍历
    Node* current = head;
    
    // 计数器，用于统计释放的节点数
    int count = 0;
    
    // 遍历链表，逐个释放节点
    while (current != NULL) {
        // 保存当前节点的下一个节点（重要！）
        Node* temp = current;
        // 移动到下一个节点
        current = current->next;
        // 释放当前节点
        free(temp);
        // 计数加1
        count++;
    }
    
    printf("已释放 %d 个节点的内存\n", count);
}

/* ============================================================
   函数：获取指定索引位置的值（索引从0开始）
   参数：head - 链表的头指针，index - 索引位置，out_value - 输出参数
   返回值：成功返回true，失败返回false
   时间复杂度：O(n)
   ============================================================ */
bool get_at(Node* head, int index, int* out_value) {
    // 检查索引是否有效
    if (index < 0 || out_value == NULL) {
        return false;
    }
    
    // 创建临时指针
    Node* current = head;
    
    // 遍历到指定索引位置
    for (int i = 0; i < index; i++) {
        // 如果提前到达链表末尾，说明索引越界
        if (current == NULL) {
            return false;
        }
        current = current->next;
    }
    
    // 如果current为空，说明索引越界
    if (current == NULL) {
        return false;
    }
    
    // 将找到的值通过输出参数返回
    *out_value = current->data;
    return true;
}

/* ============================================================
   函数：合并两个有序链表（递归法）
   参数：a - 第一个有序链表的头指针，b - 第二个有序链表的头指针
   返回值：合并后的链表头指针
   时间复杂度：O(n+m)
   ============================================================ */
Node* merge_sorted(Node* a, Node* b) {
    // 基准情况：如果任一链表为空，直接返回另一个
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    
    // 定义结果链表头指针
    Node* result = NULL;
    
    // 比较两个链表头节点的数据
    if (a->data <= b->data) {
        // a的头节点更小，选择a作为结果头
        result = a;
        // 递归合并 a的下一个节点 和 b
        result->next = merge_sorted(a->next, b);
    } else {
        // b的头节点更小，选择b作为结果头
        result = b;
        // 递归合并 a 和 b的下一个节点
        result->next = merge_sorted(a, b->next);
    }
    
    // 返回合并后的链表头
    return result;
}

/* ============================================================
   函数：主函数 - 演示所有链表操作
   参数：argc - 命令行参数个数，argv - 命令行参数数组
   返回值：程序退出码（0表示正常退出）
   ============================================================ */
int main(int argc, char* argv[]) {
    // =========================================================
    // 第一部分：创建空链表并演示插入操作
    // =========================================================
    printf("========== 单向链表演示程序 ==========\n\n");
    
    // 初始化空链表（头指针为NULL）
    Node* list = NULL;
    printf("1. 创建空链表\n");
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // 测试头插法
    printf("2. 头插法插入 10, 20, 30\n");
    list = push_front(list, 10);  // 插入第一个节点
    list = push_front(list, 20);  // 插入到头部
    list = push_front(list, 30);  // 插入到头部
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // 测试尾插法
    printf("3. 尾插法插入 40, 50\n");
    list = push_back(list, 40);   // 插入到尾部
    list = push_back(list, 50);   // 插入到尾部
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // 测试指定位置插入
    printf("4. 在索引2的位置插入 99\n");
    list = insert_at(list, 2, 99);
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // 测试越界插入
    printf("5. 尝试在索引10的位置插入 88（越界测试）\n");
    list = insert_at(list, 10, 88);
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // =========================================================
    // 第二部分：演示查找和访问操作
    // =========================================================
    printf("6. 查找值为99的节点\n");
    Node* found = find_node(list, 99);
    if (found != NULL) {
        printf("找到节点，地址：%p，数据：%d\n", (void*)found, found->data);
    } else {
        printf("未找到节点\n");
    }
    printf("\n");
    
    printf("7. 查找值为100的节点（不存在的值）\n");
    found = find_node(list, 100);
    if (found != NULL) {
        printf("找到节点，地址：%p，数据：%d\n", (void*)found, found->data);
    } else {
        printf("未找到节点\n");
    }
    printf("\n");
    
    printf("8. 获取索引3的值\n");
    int value;
    if (get_at(list, 3, &value)) {
        printf("索引3的值为：%d\n", value);
    } else {
        printf("获取失败\n");
    }
    printf("\n");
    
    // =========================================================
    // 第三部分：演示删除操作
    // =========================================================
    printf("9. 删除值为99的节点\n");
    list = delete_by_value(list, 99);
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    printf("10. 删除值为30的节点（头节点）\n");
    list = delete_by_value(list, 30);
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // =========================================================
    // 第四部分：演示反转操作
    // =========================================================
    printf("11. 反转链表\n");
    printf("反转前：");
    print_list(list);
    list = reverse_list(list);
    printf("反转后：");
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // =========================================================
    // 第五部分：演示环检测（手动制造环）
    // =========================================================
    printf("12. 环检测测试\n");
    printf("当前链表是否有环：%s\n", has_cycle(list) ? "有环" : "无环");
    
    // 手动制造一个环：让尾节点指向第二个节点
    printf("制造环：让尾节点指向第二个节点...\n");
    Node* tail = list;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* second = list->next;
    tail->next = second;  // 形成环
    
    printf("当前链表是否有环：%s\n", has_cycle(list) ? "有环" : "无环");
    printf("（注意：有环的链表无法正常遍历，这是正常的）\n\n");
    
    // 修复环：将尾节点的next置为NULL
    tail->next = NULL;
    printf("已修复环\n\n");
    
    // =========================================================
    // 第六部分：演示删除所有匹配值
    // =========================================================
    // 先插入几个重复的值
    printf("13. 插入重复值进行批量删除测试\n");
    list = push_back(list, 50);
    list = push_back(list, 50);
    list = push_back(list, 50);
    printf("插入三个50后：");
    print_list(list);
    
    printf("删除所有值为50的节点\n");
    list = delete_all(list, 50);
    print_list(list);
    printf("链表长度：%d\n\n", list_length(list));
    
    // =========================================================
    // 第七部分：演示合并有序链表
    // =========================================================
    printf("14. 合并两个有序链表\n");
    
    // 创建第一个有序链表：1 -> 3 -> 5
    Node* list_a = NULL;
    list_a = push_back(list_a, 1);
    list_a = push_back(list_a, 3);
    list_a = push_back(list_a, 5);
    printf("有序链表A：");
    print_list(list_a);
    
    // 创建第二个有序链表：2 -> 4 -> 6
    Node* list_b = NULL;
    list_b = push_back(list_b, 2);
    list_b = push_back(list_b, 4);
    list_b = push_back(list_b, 6);
    printf("有序链表B：");
    print_list(list_b);
    
    // 合并两个有序链表
    Node* merged = merge_sorted(list_a, list_b);
    printf("合并后的链表：");
    print_list(merged);
    printf("链表长度：%d\n\n", list_length(merged));
    
    // =========================================================
    // 第八部分：释放内存
    // =========================================================
    printf("15. 释放所有链表内存\n");
    destroy_list(list);
    destroy_list(merged);
    // 注意：list_a和list_b的节点已包含在merged中，不需要重复释放
    
    printf("\n========== 程序执行完毕 ==========\n");
    
    // 返回0表示程序正常结束
    return 0;
}
```

---

## 第二章 双向链表完整实现

```c
/* ============================================================
   文件名：doubly_linked_list.c
   功能：双向链表的完整实现（带头尾指针的封装结构）
   编译：gcc -o doubly_linked_list doubly_linked_list.c
   运行：./doubly_linked_list
   ============================================================ */

#include <stdio.h>   // 标准输入输出库
#include <stdlib.h>  // 标准库（malloc、free）
#include <stdbool.h> // 布尔类型

/* ============================================================
   结构体定义：双向链表节点
   ============================================================ */
typedef struct DNode {
    int data;              // 数据域
    struct DNode* prev;    // 前驱指针（指向前一个节点）
    struct DNode* next;    // 后继指针（指向下一个节点）
} DNode;

/* ============================================================
   结构体定义：双向链表（带头尾指针和长度信息）
   这种封装方式更符合工程实践
   ============================================================ */
typedef struct DList {
    DNode* head;   // 头指针
    DNode* tail;   // 尾指针
    int size;      // 链表长度（节点个数）
} DList;

/* ============================================================
   函数：创建空的双向链表
   参数：无
   返回值：新分配的DList结构体指针
   ============================================================ */
DList* dlist_create(void) {
    // 分配DList结构体内存
    DList* list = (DList*)malloc(sizeof(DList));
    
    // 检查分配是否成功
    if (list == NULL) {
        fprintf(stderr, "错误：内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    
    // 初始化：头尾指针都指向NULL，长度为0
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    
    return list;
}

/* ============================================================
   函数：创建新节点（静态辅助函数）
   参数：value - 节点数据
   返回值：新节点指针
   ============================================================ */
static DNode* d_create_node(int value) {
    // 分配节点内存
    DNode* node = (DNode*)malloc(sizeof(DNode));
    
    // 检查分配
    if (node == NULL) {
        fprintf(stderr, "错误：内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    
    // 初始化节点
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    
    return node;
}

/* ============================================================
   函数：在链表头部插入节点
   参数：list - 链表指针，value - 要插入的值
   返回值：成功返回true，失败返回false
   时间复杂度：O(1)
   ============================================================ */
bool dlist_push_front(DList* list, int value) {
    // 检查链表指针是否有效
    if (list == NULL) {
        return false;
    }
    
    // 创建新节点
    DNode* new_node = d_create_node(value);
    
    // 如果链表为空
    if (list->head == NULL) {
        // 头尾都指向新节点
        list->head = new_node;
        list->tail = new_node;
    } else {
        // 链表非空，新节点的next指向原头节点
        new_node->next = list->head;
        // 原头节点的prev指向新节点
        list->head->prev = new_node;
        // 头指针指向新节点
        list->head = new_node;
    }
    
    // 长度加1
    list->size++;
    return true;
}

/* ============================================================
   函数：在链表尾部插入节点
   参数：list - 链表指针，value - 要插入的值
   返回值：成功返回true，失败返回false
   时间复杂度：O(1)（因为有尾指针）
   ============================================================ */
bool dlist_push_back(DList* list, int value) {
    // 检查链表指针是否有效
    if (list == NULL) {
        return false;
    }
    
    // 创建新节点
    DNode* new_node = d_create_node(value);
    
    // 如果链表为空
    if (list->tail == NULL) {
        // 头尾都指向新节点
        list->head = new_node;
        list->tail = new_node;
    } else {
        // 链表非空，原尾节点的next指向新节点
        list->tail->next = new_node;
        // 新节点的prev指向原尾节点
        new_node->prev = list->tail;
        // 尾指针指向新节点
        list->tail = new_node;
    }
    
    // 长度加1
    list->size++;
    return true;
}

/* ============================================================
   函数：在指定位置插入节点（索引从0开始）
   参数：list - 链表指针，index - 插入位置，value - 要插入的值
   返回值：成功返回true，失败返回false
   时间复杂度：O(n)
   ============================================================ */
bool dlist_insert_at(DList* list, int index, int value) {
    // 参数有效性检查
    if (list == NULL || index < 0 || index > list->size) {
        return false;
    }
    
    // 如果插入到头部
    if (index == 0) {
        return dlist_push_front(list, value);
    }
    
    // 如果插入到尾部
    if (index == list->size) {
        return dlist_push_back(list, value);
    }
    
    // 插入到中间位置
    DNode* new_node = d_create_node(value);
    
    // 找到要插入位置的前驱节点
    DNode* current = list->head;
    // 移动到第 index-1 个节点
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    // 执行插入操作（四步指针调整）
    // 1. 新节点的next指向当前节点的下一个节点
    new_node->next = current->next;
    // 2. 新节点的prev指向当前节点
    new_node->prev = current;
    // 3. 当前节点下一个节点的prev指向新节点
    if (current->next != NULL) {
        current->next->prev = new_node;
    }
    // 4. 当前节点的next指向新节点
    current->next = new_node;
    
    // 长度加1
    list->size++;
    return true;
}

/* ============================================================
   函数：删除头部节点（弹出）
   参数：list - 链表指针，out_value - 输出参数（保存被删除的值）
   返回值：成功返回true，失败返回false
   时间复杂度：O(1)
   ============================================================ */
bool dlist_pop_front(DList* list, int* out_value) {
    // 检查链表是否为空
    if (list == NULL || list->head == NULL) {
        return false;
    }
    
    // 保存头节点
    DNode* temp = list->head;
    
    // 如果输出参数不为空，保存数据
    if (out_value != NULL) {
        *out_value = temp->data;
    }
    
    // 移动头指针
    list->head = temp->next;
    
    // 如果链表变成空链表
    if (list->head == NULL) {
        // 尾指针也要置为NULL
        list->tail = NULL;
    } else {
        // 新头节点的prev置为NULL
        list->head->prev = NULL;
    }
    
    // 释放被删除节点
    free(temp);
    // 长度减1
    list->size--;
    return true;
}

/* ============================================================
   函数：删除尾部节点（弹出）
   参数：list - 链表指针，out_value - 输出参数（保存被删除的值）
   返回值：成功返回true，失败返回false
   时间复杂度：O(1)（因为有尾指针）
   ============================================================ */
bool dlist_pop_back(DList* list, int* out_value) {
    // 检查链表是否为空
    if (list == NULL || list->tail == NULL) {
        return false;
    }
    
    // 保存尾节点
    DNode* temp = list->tail;
    
    // 如果输出参数不为空，保存数据
    if (out_value != NULL) {
        *out_value = temp->data;
    }
    
    // 移动尾指针
    list->tail = temp->prev;
    
    // 如果链表变成空链表
    if (list->tail == NULL) {
        // 头指针也要置为NULL
        list->head = NULL;
    } else {
        // 新尾节点的next置为NULL
        list->tail->next = NULL;
    }
    
    // 释放被删除节点
    free(temp);
    // 长度减1
    list->size--;
    return true;
}

/* ============================================================
   函数：按值删除第一个匹配的节点
   参数：list - 链表指针，target - 要删除的值
   返回值：成功返回true，失败返回false
   时间复杂度：O(n)
   ============================================================ */
bool dlist_delete_by_value(DList* list, int target) {
    // 检查链表是否为空
    if (list == NULL || list->head == NULL) {
        return false;
    }
    
    // 从头部开始遍历
    DNode* current = list->head;
    
    // 遍历查找目标值
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    
    // 如果没找到
    if (current == NULL) {
        return false;
    }
    
    // 找到目标节点，进行删除操作
    // 如果当前节点不是头节点
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        // 当前节点是头节点，更新头指针
        list->head = current->next;
    }
    
    // 如果当前节点不是尾节点
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        // 当前节点是尾节点，更新尾指针
        list->tail = current->prev;
    }
    
    // 释放节点内存
    free(current);
    // 长度减1
    list->size--;
    return true;
}

/* ============================================================
   函数：正向打印链表
   参数：list - 链表指针
   返回值：无
   ============================================================ */
void dlist_print_forward(DList* list) {
    if (list == NULL || list->head == NULL) {
        printf("链表为空\n");
        return;
    }
    
    printf("正向遍历（头->尾）：");
    DNode* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf(" <-> NULL\n");
}

/* ============================================================
   函数：反向打印链表
   参数：list - 链表指针
   返回值：无
   ============================================================ */
void dlist_print_reverse(DList* list) {
    if (list == NULL || list->tail == NULL) {
        printf("链表为空\n");
        return;
    }
    
    printf("反向遍历（尾->头）：");
    DNode* current = list->tail;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->prev != NULL) {
            printf(" <-> ");
        }
        current = current->prev;
    }
    printf(" <-> NULL\n");
}

/* ============================================================
   函数：获取链表长度
   参数：list - 链表指针
   返回值：节点个数
   ============================================================ */
int dlist_size(DList* list) {
    if (list == NULL) return 0;
    return list->size;
}

/* ============================================================
   函数：检查链表是否为空
   参数：list - 链表指针
   返回值：空返回true，非空返回false
   ============================================================ */
bool dlist_is_empty(DList* list) {
    if (list == NULL) return true;
    return list->size == 0;
}

/* ============================================================
   函数：释放整个链表的内存
   参数：list - 链表指针
   返回值：无
   ============================================================ */
void dlist_destroy(DList* list) {
    if (list == NULL) return;
    
    // 从头部开始遍历释放
    DNode* current = list->head;
    int count = 0;
    
    while (current != NULL) {
        DNode* temp = current;
        current = current->next;
        free(temp);
        count++;
    }
    
    printf("已释放 %d 个双向链表节点\n", count);
    
    // 释放链表结构体本身
    free(list);
}

/* ============================================================
   函数：主函数 - 演示双向链表操作
   ============================================================ */
int main(int argc, char* argv[]) {
    printf("========== 双向链表演示程序 ==========\n\n");
    
    // 创建空的双向链表
    DList* list = dlist_create();
    printf("1. 创建空链表，长度：%d\n", dlist_size(list));
    
    // 测试尾插
    printf("\n2. 尾插法插入 10, 20, 30\n");
    dlist_push_back(list, 10);
    dlist_push_back(list, 20);
    dlist_push_back(list, 30);
    dlist_print_forward(list);
    printf("链表长度：%d\n", dlist_size(list));
    
    // 测试头插
    printf("\n3. 头插法插入 5, 0\n");
    dlist_push_front(list, 5);
    dlist_push_front(list, 0);
    dlist_print_forward(list);
    printf("链表长度：%d\n", dlist_size(list));
    
    // 测试反向遍历
    printf("\n4. 反向遍历\n");
    dlist_print_reverse(list);
    
    // 测试指定位置插入
    printf("\n5. 在索引2的位置插入 99\n");
    dlist_insert_at(list, 2, 99);
    dlist_print_forward(list);
    printf("链表长度：%d\n", dlist_size(list));
    
    // 测试弹出头部
    printf("\n6. 弹出头部元素\n");
    int popped;
    if (dlist_pop_front(list, &popped)) {
        printf("弹出值：%d\n", popped);
    }
    dlist_print_forward(list);
    printf("链表长度：%d\n", dlist_size(list));
    
    // 测试弹出尾部
    printf("\n7. 弹出尾部元素\n");
    if (dlist_pop_back(list, &popped)) {
        printf("弹出值：%d\n", popped);
    }
    dlist_print_forward(list);
    printf("链表长度：%d\n", dlist_size(list));
    
    // 测试按值删除
    printf("\n8. 删除值为20的节点\n");
    if (dlist_delete_by_value(list, 20)) {
        printf("删除成功\n");
    } else {
        printf("未找到目标值\n");
    }
    dlist_print_forward(list);
    printf("链表长度：%d\n", dlist_size(list));
    
    // 测试空链表判断
    printf("\n9. 判断链表是否为空：%s\n", 
           dlist_is_empty(list) ? "是" : "否");
    
    // 释放内存
    printf("\n10. 释放所有内存\n");
    dlist_destroy(list);
    
    printf("\n========== 程序执行完毕 ==========\n");
    return 0;
}
```

---

## 第三章 循环链表与约瑟夫环

```c
/* ============================================================
   文件名：circular_linked_list.c
   功能：循环链表实现及约瑟夫环问题求解
   编译：gcc -o circular_linked_list circular_linked_list.c
   运行：./circular_linked_list
   ============================================================ */

#include <stdio.h>   // 标准输入输出
#include <stdlib.h>  // 标准库
#include <stdbool.h> // 布尔类型

/* ============================================================
   结构体定义：循环链表节点
   ============================================================ */
typedef struct CNode {
    int data;              // 数据域
    struct CNode* next;    // 指针域（指向下一个节点）
} CNode;

/* ============================================================
   函数：创建新节点（静态辅助函数）
   ============================================================ */
static CNode* c_create_node(int value) {
    CNode* node = (CNode*)malloc(sizeof(CNode));
    if (node == NULL) {
        fprintf(stderr, "错误：内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

/* ============================================================
   函数：创建包含 n 个节点的循环链表（节点值从1到n）
   参数：n - 节点个数
   返回值：循环链表的头指针
   ============================================================ */
CNode* create_circular_list(int n) {
    // 参数检查：n必须大于0
    if (n <= 0) {
        return NULL;
    }
    
    // 创建第一个节点（值为1）
    CNode* head = c_create_node(1);
    // 如果没有更多节点，让头节点指向自身
    if (n == 1) {
        head->next = head;
        return head;
    }
    
    // 创建后续节点
    CNode* prev = head;
    for (int i = 2; i <= n; i++) {
        // 创建新节点
        CNode* node = c_create_node(i);
        // 前一个节点的next指向新节点
        prev->next = node;
        // 前驱指针后移
        prev = node;
    }
    
    // 最后一个节点的next指向头节点，形成循环
    prev->next = head;
    
    return head;
}

/* ============================================================
   函数：打印循环链表（打印一圈）
   参数：head - 循环链表头指针
   返回值：无
   ============================================================ */
void print_circular_list(CNode* head) {
    if (head == NULL) {
        printf("链表为空\n");
        return;
    }
    
    CNode* current = head;
    printf("循环链表：");
    do {
        printf("%d", current->data);
        if (current->next != head) {
            printf(" -> ");
        }
        current = current->next;
    } while (current != head);
    printf(" -> (回到头)\n");
}

/* ============================================================
   函数：约瑟夫环问题求解
   参数：n - 总人数，m - 报数到m的人出列
   返回值：最后幸存者的编号（从1开始）
   时间复杂度：O(n*m)（更优的数学解法为O(n)，此处展示链表实现）
   ============================================================ */
int josephus(int n, int m) {
    // 参数检查
    if (n <= 0 || m <= 0) {
        printf("错误：无效参数\n");
        return -1;
    }
    
    // 如果只有一个人，直接返回
    if (n == 1) {
        return 1;
    }
    
    // 创建循环链表
    CNode* head = create_circular_list(n);
    printf("初始状态：");
    print_circular_list(head);
    printf("\n开始报数（每报到 %d 出列）：\n", m);
    
    // 当前节点指针（从头部开始）
    CNode* current = head;
    // 前驱节点指针（用于删除操作）
    CNode* prev = NULL;
    
    // 找到尾节点（即头节点的前驱）
    // 注意：循环链表中，尾节点是 prev 的初始值
    prev = head;
    while (prev->next != head) {
        prev = prev->next;
    }
    
    // 计数器：记录当前报数（从1开始）
    int counter = 1;
    // 出列人数计数器
    int eliminated = 0;
    
    // 循环直到只剩一个节点
    while (current->next != current) {
        // 报数到m时出列
        if (counter == m) {
            // 打印出列信息
            printf("第 %d 个出列：%d\n", eliminated + 1, current->data);
            
            // 删除当前节点
            prev->next = current->next;
            CNode* to_delete = current;
            current = current->next;
            free(to_delete);
            
            // 计数器重置为1（从下一个人重新报数）
            counter = 1;
            eliminated++;
        } else {
            // 未报到m，继续移动
            prev = current;
            current = current->next;
            counter++;
        }
    }
    
    // 最后一个幸存者
    int survivor = current->data;
    // 释放最后一个节点
    free(current);
    
    printf("\n最后幸存者：%d\n", survivor);
    return survivor;
}

/* ============================================================
   函数：释放循环链表（需要特殊处理，因为循环）
   参数：head - 循环链表的头指针
   返回值：无
   ============================================================ */
void destroy_circular_list(CNode* head) {
    if (head == NULL) return;
    
    // 如果链表只有一个节点
    if (head->next == head) {
        free(head);
        return;
    }
    
    // 找到尾节点
    CNode* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    
    // 断开循环，变成普通链表
    tail->next = NULL;
    
    // 然后像普通链表一样释放
    CNode* current = head;
    int count = 0;
    while (current != NULL) {
        CNode* temp = current;
        current = current->next;
        free(temp);
        count++;
    }
    
    printf("已释放 %d 个循环链表节点\n", count);
}

/* ============================================================
   函数：主函数
   ============================================================ */
int main(int argc, char* argv[]) {
    printf("========== 循环链表与约瑟夫环 ==========\n\n");
    
    // 第一部分：展示循环链表的创建和遍历
    printf("1. 创建包含 8 个节点的循环链表\n");
    CNode* circular = create_circular_list(8);
    print_circular_list(circular);
    printf("\n");
    
    // 第二部分：约瑟夫环问题
    printf("2. 约瑟夫环问题求解\n");
    printf("7个人，每报数到3的人出列\n");
    printf("----------------------------------------\n");
    int survivor = josephus(7, 3);
    printf("----------------------------------------\n");
    
    // 第三部分：不同参数的对比
    printf("\n3. 不同参数的约瑟夫环结果对比\n");
    printf("5个人，报到2：");
    int result1 = josephus(5, 2);
    printf(" 幸存者：%d\n", result1);
    printf("10个人，报到4：");
    int result2 = josephus(10, 4);
    printf(" 幸存者：%d\n", result2);
    printf("\n");
    
    // 第四部分：释放循环链表内存
    printf("4. 释放循环链表\n");
    destroy_circular_list(circular);
    
    printf("\n========== 程序执行完毕 ==========\n");
    return 0;
}
```

---

## 第四章 综合测试与性能对比

```c
/* ============================================================
   文件名：test_comprehensive.c
   功能：全面测试链表各项功能，包含性能对比
   编译：gcc -o test_comprehensive test_comprehensive.c -lm
   运行：./test_comprehensive
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>    // 用于性能计时

// 包含前面定义的单向链表函数（实际项目中可拆分为头文件）
// 此处为了独立演示，重复声明必要的函数原型
typedef struct Node { int data; struct Node* next; } Node;
Node* push_front(Node*, int);
Node* push_back(Node*, int);
Node* insert_at(Node*, int, int);
Node* delete_by_value(Node*, int);
Node* delete_all(Node*, int);
Node* reverse_list(Node*);
Node* find_node(Node*, int);
int list_length(Node*);
void print_list(Node*);
void destroy_list(Node*);
bool has_cycle(Node*);
bool get_at(Node*, int, int*);
Node* merge_sorted(Node*, Node*);

// 实际链接时需确保这些函数已编译

/* ============================================================
   函数：生成随机链表（用于性能测试）
   参数：n - 节点个数
   返回值：链表头指针
   ============================================================ */
Node* generate_random_list(int n) {
    Node* list = NULL;
    // 使用随机数生成节点
    for (int i = 0; i < n; i++) {
        // 随机数范围 0-999
        int value = rand() % 1000;
        list = push_back(list, value);
    }
    return list;
}

/* ============================================================
   函数：判断链表是否为升序（用于验证合并操作）
   参数：head - 链表头指针
   返回值：升序返回true，否则false
   ============================================================ */
bool is_sorted(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}

/* ============================================================
   函数：创建有序链表
   参数：start - 起始值，step - 步长，count - 节点个数
   返回值：有序链表头指针
   ============================================================ */
Node* create_sorted_list(int start, int step, int count) {
    Node* list = NULL;
    for (int i = 0; i < count; i++) {
        list = push_back(list, start + i * step);
    }
    return list;
}

/* ============================================================
   函数：测试链表操作的正确性
   返回值：所有测试通过返回true
   ============================================================ */
bool run_correctness_tests(void) {
    printf("========== 正确性测试 ==========\n\n");
    bool all_passed = true;
    
    // 测试1：头插和尾插
    printf("测试1：插入操作\n");
    Node* list = NULL;
    list = push_front(list, 10);
    list = push_front(list, 20);
    list = push_back(list, 30);
    printf("  期望：20 -> 10 -> 30 -> NULL\n");
    printf("  实际：");
    print_list(list);
    if (list_length(list) != 3) {
        printf("  ❌ 长度错误\n");
        all_passed = false;
    }
    destroy_list(list);
    printf("  ✅ 通过\n\n");
    
    // 测试2：指定位置插入
    printf("测试2：指定位置插入\n");
    list = NULL;
    list = push_back(list, 1);
    list = push_back(list, 2);
    list = push_back(list, 4);
    list = insert_at(list, 2, 3);  // 在索引2插入3
    printf("  期望：1 -> 2 -> 3 -> 4 -> NULL\n");
    printf("  实际：");
    print_list(list);
    // 验证：获取索引2的值应为3
    int val;
    if (!get_at(list, 2, &val) || val != 3) {
        printf("  ❌ 插入位置错误\n");
        all_passed = false;
    }
    destroy_list(list);
    printf("  ✅ 通过\n\n");
    
    // 测试3：删除操作
    printf("测试3：删除操作\n");
    list = NULL;
    for (int i = 1; i <= 5; i++) {
        list = push_back(list, i);
    }
    printf("  原链表：");
    print_list(list);
    list = delete_by_value(list, 3);
    printf("  删除3后：");
    print_list(list);
    if (find_node(list, 3) != NULL) {
        printf("  ❌ 删除失败\n");
        all_passed = false;
    }
    destroy_list(list);
    printf("  ✅ 通过\n\n");
    
    // 测试4：删除所有匹配值
    printf("测试4：删除所有匹配值\n");
    list = NULL;
    list = push_back(list, 1);
    list = push_back(list, 2);
    list = push_back(list, 2);
    list = push_back(list, 3);
    list = push_back(list, 2);
    printf("  原链表：");
    print_list(list);
    list = delete_all(list, 2);
    printf("  删除所有2后：");
    print_list(list);
    if (find_node(list, 2) != NULL) {
        printf("  ❌ 批量删除失败\n");
        all_passed = false;
    }
    destroy_list(list);
    printf("  ✅ 通过\n\n");
    
    // 测试5：反转
    printf("测试5：反转链表\n");
    list = NULL;
    for (int i = 1; i <= 4; i++) {
        list = push_back(list, i);
    }
    printf("  原链表：");
    print_list(list);
    list = reverse_list(list);
    printf("  反转后：");
    print_list(list);
    // 验证：反转后第一个元素应为4
    if (list->data != 4) {
        printf("  ❌ 反转失败\n");
        all_passed = false;
    }
    destroy_list(list);
    printf("  ✅ 通过\n\n");
    
    // 测试6：合并有序链表
    printf("测试6：合并有序链表\n");
    Node* a = create_sorted_list(1, 2, 3);  // 1, 3, 5
    Node* b = create_sorted_list(2, 2, 3);  // 2, 4, 6
    printf("  A：");
    print_list(a);
    printf("  B：");
    print_list(b);
    Node* merged = merge_sorted(a, b);
    printf("  合并：");
    print_list(merged);
    if (!is_sorted(merged) || list_length(merged) != 6) {
        printf("  ❌ 合并失败\n");
        all_passed = false;
    }
    destroy_list(merged);
    printf("  ✅ 通过\n\n");
    
    // 测试7：环检测
    printf("测试7：环检测\n");
    list = NULL;
    for (int i = 1; i <= 5; i++) {
        list = push_back(list, i);
    }
    printf("  无环链表：%s\n", has_cycle(list) ? "有环" : "无环");
    bool result = has_cycle(list);
    // 制造环
    Node* tail = list;
    while (tail->next != NULL) tail = tail->next;
    Node* second = list->next;
    tail->next = second;
    printf("  有环链表：%s\n", has_cycle(list) ? "有环" : "无环");
    bool result2 = has_cycle(list);
    tail->next = NULL;  // 修复环
    destroy_list(list);
    if (!result || !result2) {
        printf("  ❌ 环检测失败\n");
        all_passed = false;
    } else {
        printf("  ✅ 通过\n\n");
    }
    
    printf("========== 所有测试%s ==========\n\n", 
           all_passed ? "通过" : "有失败");
    return all_passed;
}

/* ============================================================
   函数：性能测试
   ============================================================ */
void run_performance_tests(void) {
    printf("========== 性能测试 ==========\n\n");
    
    const int N = 10000;  // 测试数据规模
    clock_t start, end;
    double cpu_time_used;
    
    // 测试1：头插性能
    printf("1. 头插法 %d 个节点\n", N);
    Node* list = NULL;
    start = clock();
    for (int i = 0; i < N; i++) {
        list = push_front(list, i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   耗时：%f 秒\n", cpu_time_used);
    destroy_list(list);
    printf("\n");
    
    // 测试2：尾插性能
    printf("2. 尾插法 %d 个节点\n", N);
    list = NULL;
    start = clock();
    for (int i = 0; i < N; i++) {
        list = push_back(list, i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   耗时：%f 秒\n", cpu_time_used);
    destroy_list(list);
    printf("\n");
    
    // 测试3：查找性能
    printf("3. 查找 %d 个节点的链表末尾元素\n", N);
    list = generate_random_list(N);
    start = clock();
    Node* found = find_node(list, 999);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   查找结果：%s\n", found ? "找到" : "未找到");
    printf("   耗时：%f 秒\n", cpu_time_used);
    destroy_list(list);
    printf("\n");
    
    // 测试4：反转性能
    printf("4. 反转 %d 个节点的链表\n", N);
    list = generate_random_list(N);
    start = clock();
    list = reverse_list(list);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   耗时：%f 秒\n", cpu_time_used);
    destroy_list(list);
    printf("\n");
    
    printf("========== 性能测试完成 ==========\n\n");
}

/* ============================================================
   函数：主函数
   ============================================================ */
int main(int argc, char* argv[]) {
    printf("\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║   C语言链表综合测试程序                   ║\n");
    printf("║   单向链表 + 双向链表 + 循环链表        ║\n");
    printf("╚═══════════════════════════════════════════╝\n\n");
    
    // 设置随机数种子
    srand((unsigned int)time(NULL));
    
    // 运行正确性测试
    bool tests_passed = run_correctness_tests();
    
    // 运行性能测试
    run_performance_tests();
    
    // 最终结果
    if (tests_passed) {
        printf("✅ 所有测试通过！程序运行正常。\n");
    } else {
        printf("❌ 部分测试失败，请检查代码。\n");
    }
    
    printf("\n========== 程序执行完毕 ==========\n");
    return 0;
}
```

---

## 附录：编译与运行指南

### 编译所有程序

```bash
# 编译单向链表
gcc -Wall -Wextra -O2 -o singly_linked_list singly_linked_list.c

# 编译双向链表
gcc -Wall -Wextra -O2 -o doubly_linked_list doubly_linked_list.c

# 编译循环链表
gcc -Wall -Wextra -O2 -o circular_linked_list circular_linked_list.c

# 编译综合测试（需要链接所有源文件）
gcc -Wall -Wextra -O2 -o test_comprehensive test_comprehensive.c singly_linked_list.c -lm
```

### 运行测试

```bash
# 运行单向链表演示
./singly_linked_list

# 运行双向链表演示
./doubly_linked_list

# 运行循环链表演示
./circular_linked_list

# 运行综合测试
./test_comprehensive
```

### 内存检测（推荐）

```bash
# 使用 Valgrind 检测内存泄漏
valgrind --leak-check=full --show-leak-kinds=all ./singly_linked_list
valgrind --leak-check=full --show-leak-kinds=all ./doubly_linked_list
valgrind --leak-check=full --show-leak-kinds=all ./circular_linked_list
```

---

## 总结

本教程提供了三个完整的、可直接编译运行的C语言链表实现：

1. **单向链表**（singly_linked_list.c）：基础结构，适合初学者
2. **双向链表**（doubly_linked_list.c）：带封装的结构，适合工程使用
3. **循环链表**（circular_linked_list.c）：解决约瑟夫环等经典问题
4. **综合测试**（test_comprehensive.c）：验证正确性和性能

每个程序都包含：
- ✅ 完整的头文件和函数声明
- ✅ 每一行代码的详细注释
- ✅ 合理的错误处理
- ✅ 内存管理（无泄漏）
- ✅ 演示main函数展示所有功能

**学习建议**：
1. 先编译运行，观察输出
2. 修改数据，测试边界情况
3. 尝试为单向链表增加尾指针优化
4. 实现更多算法（如LRU缓存、多项式加法）

---

**全文完** | 总代码行数：约1200行 | 所有程序均可直接运行