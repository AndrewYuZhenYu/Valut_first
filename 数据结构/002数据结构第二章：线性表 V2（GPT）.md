# 数据结构第二章：线性表

> [!abstract] 学习路线与代码约定
> 本章围绕“逻辑结构 → 抽象数据类型 → 顺序表 → 链表 → 有序表 → 一元多项式”展开，重点理解数据关系如何映射到内存，以及不同存储结构如何实现同一组基本操作。
>
> **代码统一使用标准 C++17**，不使用 `typedef` 或类型别名，普通数据类型默认使用 `int`。动态结点使用 `new` / `delete`，动态数组使用 `new[]` / `delete[]`。线性表的逻辑位序从 **1** 开始，C++ 数组下标从 **0** 开始。

> [!tip] 阅读算法的顺序
> 先看参数与返回值，再看边界检查，最后跟踪数组下标或指针的变化。重点留意 `i` 与 `i - 1` 的对应关系、修改 `next` 的先后顺序，以及释放内存前是否还需要访问结点。

## 目录

- 1. 线性表的逻辑结构
- 2. 抽象数据类型 List
- 3. 顺序表：顺序存储结构
- 4. 单链表：链式存储结构
- 5. 其他链表形式
- 6. 改进的线性链表与有序表
- 7. 一元多项式的表示及相加
- 8. 顺序表与链表的综合比较
- 9. 综合算法与典型练习
- 10. 易错点与考前速查

---

# 1. 线性表的逻辑结构

## 1.1 定义

**线性表（Linear List）** 是由 $n$ 个数据元素组成的有限序列，通常记为：

$$
L=(a_1,a_2,\ldots,a_i,\ldots,a_n),\qquad n\geq 0
$$

- **数据元素**：线性表中的基本单位，可以是整数、字符、字符串，也可以是由多个数据项构成的复杂记录。
- **数据对象**：同一个线性表中的元素必须属于同一数据对象，具有相同的数据特性。
- **长度**：线性表中数据元素的个数，记为 $n$。
- **空表**：当 $n=0$ 时，线性表为空表。
- **位序**：非空线性表中，元素 $a_i$ 的位序为 $i$，位序从 **1** 开始。

例如：

- 字母表：$(A,B,C,\ldots,Z)$
- 工资记录：$(800,1500,2400,4100,\ldots)$
- 学生表：每个元素可由学号、姓名、年龄、班级等多个数据项组成。

## 1.2 线性结构的基本特征

对于非空线性表 $L=(a_1,\ldots,a_n)$：

1. 存在唯一的第一个元素 $a_1$。
2. 存在唯一的最后一个元素 $a_n$。
3. 除最后一个元素外，每个元素都有且仅有一个直接后继。
4. 除第一个元素外，每个元素都有且仅有一个直接前驱。

因此：

- $a_1$ 没有直接前驱；
- $a_n$ 没有直接后继；
- 中间元素恰好有一个直接前驱和一个直接后继。

> [!important] 核心理解
> **线性表强调的是元素之间的逻辑次序，不限定元素在计算机内存中的物理存放方式。** 顺序表和链表的逻辑结构相同，区别在于它们如何存储和实现操作。

## 1.3 逻辑结构与存储结构

| 概念 | 关注的问题 | 线性表中的体现 |
|---|---|---|
| 逻辑结构 | 元素之间是什么关系 | 有先后次序，相邻元素互为直接前驱和直接后继 |
| 存储结构 | 逻辑关系如何在内存中表示 | 顺序存储、链式存储等 |
| 基本操作 | 对线性表可以做什么 | 查找、插入、删除、遍历等 |
| 算法实现 | 具体如何完成操作 | 移动数组元素或修改结点指针 |

---

# 2. 抽象数据类型 List

抽象数据类型（ADT）只描述数据对象、数据关系和操作的功能，不要求某一种具体实现。相同的 List 操作既可以由顺序表实现，也可以由链表实现。

## 2.1 基本操作及含义

| 操作 | 含义 | 关键条件或结果 |
|---|---|---|
| `InitList(L)` | 初始化 | 构造空表 |
| `DestroyList(L)` | 销毁 | 释放表所占资源，表不再存在 |
| `ListEmpty(L)` | 判空 | 空表返回真，否则返回假 |
| `ListLength(L)` | 求长度 | 返回元素个数 |
| `PriorElem(L, x)` | 求前驱 | 若 `x` 存在且不是首元素，返回其前驱 |
| `NextElem(L, x)` | 求后继 | 若 `x` 存在且不是末元素，返回其后继 |
| `GetElem(L, i)` | 按位序取元素 | 要求 $1\leq i\leq n$ |
| `LocateElem(L, e)` | 按值查找 | 返回第一个满足判定条件的元素位序；不存在返回 0 |
| `ListTraverse(L)` | 遍历 | 按逻辑顺序依次访问每个元素 |
| `ClearList(L)` | 置空 | 保留表结构，但删除全部数据元素 |
| `PutElem(L, i, e)` | 修改元素 | 将第 $i$ 个元素改为 $e$ |
| `ListInsert(L, i, e)` | 插入元素 | 在第 $i$ 个元素之前插入；允许 $i=n+1$ |
| `ListDelete(L, i)` | 删除元素 | 删除第 $i$ 个元素，并返回被删值 |

### 位序边界必须记牢

> [!important] 高频边界规则
> **取值、修改、删除：** $1\leq i\leq n$；**插入：** $1\leq i\leq n+1$。空表的唯一合法插入位置是 1。

设表长为 $n$：

- 取元素：$1\leq i\leq n$
- 修改元素：$1\leq i\leq n$
- 删除元素：$1\leq i\leq n$
- 插入元素：$1\leq i\leq n+1$

插入位置 $i=n+1$ 表示在表尾插入；空表也可以在位置 1 插入第一个元素。

## 2.2 引用型操作与加工型操作

- **引用型操作**：读取、判断或访问已有数据，一般不改变表的内容，如判空、求长度、取元素、查找、遍历。
- **加工型操作**：会改变表的状态，如置空、修改、插入、删除。
- **结构初始化与销毁**：负责建立或释放整个数据结构。

> [!warning] `ClearList` 与 `DestroyList` 不同
> `ClearList` 是“清空元素但保留表”，清空后仍然可以继续插入；`DestroyList` 是“销毁表”，动态分配的存储空间也必须释放。

## 2.3 用基本操作构造复杂操作

复杂操作可以由基本操作组合得到，体现了抽象数据类型的可复用性。

### 例 1：集合并集 $A\cup B$

用线性表 `LA`、`LB` 分别表示集合 A、B。将 `LB` 中每个元素逐个取出，在 `LA` 中查找；如果不存在，就追加到 `LA` 的表尾。

步骤：

1. 读取 `LB` 的一个元素 `e`。
2. 在 `LA` 中查找 `e`。
3. 如果不存在，将 `e` 插入 `LA` 的末尾。
4. 重复直到处理完 `LB`。

若每次查找均使用线性扫描，`LA` 初始长度为 $m$，`LB` 长度为 $n$，最坏时间复杂度通常为 $O(mn+n^2)$；若通过其他结构加速查重，可进一步优化。

> [!warning] 线性表不自动等于集合
> 线性表允许重复元素。若用线性表表示集合，必须在插入时额外保证元素不重复；有序也不意味着唯一。

### 例 2：删除重复元素，得到纯集合

若输入表无序，逐个检查新表中是否已经存在当前元素，不存在才插入，最坏时间复杂度为 $O(n^2)$。

若输入表已经按值非递减排列，相同元素必定相邻，只需保留每组相同值中的一个，能够在 $O(n)$ 时间完成。

### 例 3：两个有序表归并

假设：

- $LA=(3,5,8,11)$
- $LB=(2,6,8,9,11,15,20)$

每次比较两个表当前尚未处理的元素，将较小者放入结果表；相等时先取任意一方即可，另一方后续仍会被保留。某个表处理完后，将另一个表的剩余元素全部追加。

结果：

$$
LC=(2,3,5,6,8,8,9,11,11,15,20)
$$

若每次追加均为 $O(1)$，整体时间复杂度为 $O(m+n)$。

## 2.4 有序表

如果任意相邻元素满足：

$$
a_{i-1}\leq a_i\quad (i=2,3,\ldots,n)
$$

则称其为**非递减有序表**。若满足 $a_{i-1}\geq a_i$，则为非递增有序表。

- 非递减允许相等，例如 $(2,3,3,5,6,6,8)$。
- 有序表不一定是集合，因为它可以含重复值。
- 如果把线性表用于表示集合，通常还需要保证没有重复元素。

---

# 3. 顺序表：顺序存储结构

## 3.1 定义与存储特点

**顺序存储结构**：用一组地址连续的存储单元，依次存放线性表中的数据元素。采用顺序存储结构的线性表简称**顺序表**。

若每个元素占用 $L$ 个存储单元，首元素地址为 `LOC(a1)`，则：

$$
LOC(a_{i+1})=LOC(a_i)+L
$$

$$
LOC(a_i)=LOC(a_1)+(i-1)L
$$

因此，只要知道首元素地址和位序，就能直接计算元素的存储地址。顺序表是一种**随机存取**结构。

在 C++ 数组中，下标从 0 开始，因此逻辑位序为 $i$ 的元素对应数组下标 `i - 1`。

## 3.2 顺序表的基本描述

> [!important] 先分清三个字段
> - `data` 指向数组空间；
> - `length` 是当前有效元素数；
> - `capacity` 是已经申请的容量。
>
> **始终满足 `0 <= length <= capacity`。** 访问元素时只能访问下标 `0` 到 `length - 1`，不能把容量误当成当前长度。

顺序表需要记录：

- 存储空间的基址；
- 当前长度 `length`；
- 当前容量 `capacity`。

下面用标准 C++ 实现一个以 `int` 为元素类型的顺序表。容量不足时申请更大的数组，复制旧元素，再释放旧数组。

> [!important] 阅读顺序表代码时重点观察
> 1. `length` 与 `capacity` 分别记录有效长度和已分配容量；
> 2. 插入前先检查位置，再判断是否需要扩容；
> 3. 插入从后向前移动，删除从前向后移动；
> 4. 数组申请与释放必须使用匹配的 `new[]` 和 `delete[]`。

```cpp
#include <iostream>  // 提供 cout、输出换行等输入输出功能
#include <new>       // 提供 std::nothrow，让申请内存失败时返回空指针

// 顺序表：用连续数组保存元素，并记录当前长度和总容量。
struct SqList {
    int* data;       // 动态数组的首地址
    int length;      // 当前实际元素个数，不是数组容量
    int capacity;    // 数组最多可以容纳的元素个数
};

// 初始化顺序表；成功返回 true，申请失败或容量不合法时返回 false。
bool InitList(SqList& L, int initialCapacity = 80) {
    L.data = nullptr;  // 先设置成安全的空状态，避免失败后留下野指针
    L.length = 0;      // 新表中没有任何数据元素
    L.capacity = 0;    // 尚未成功申请存储空间

    if (initialCapacity <= 0) {  // 容量必须是正数
        return false;
    }

    L.data = new (std::nothrow) int[initialCapacity];  // 申请连续的 int 数组
    if (L.data == nullptr) {                           // 检查内存申请是否成功
        return false;
    }

    L.capacity = initialCapacity;  // 记录实际分配的容量
    return true;
}

// 销毁顺序表，释放数组并重置字段，防止后续误用旧地址。
void DestroyList(SqList& L) {
    delete[] L.data;        // 数组用 new[] 申请，必须用 delete[] 释放
    L.data = nullptr;       // 释放后清空指针
    L.length = 0;            // 表中不再有元素
    L.capacity = 0;          // 不再拥有数组容量
}

// 扩大容量；原有元素按顺序复制到新数组中。
bool ExpandList(SqList& L, int increment = 10) {
    if (L.data == nullptr || L.capacity <= 0 || increment <= 0) {
        return false;  // 表未正确初始化或扩容量不合法
    }

    int newCapacity = L.capacity + increment;  // 计算扩容后的容量
    int* newData = new (std::nothrow) int[newCapacity];  // 申请更大的连续空间
    if (newData == nullptr) {
        return false;  // 申请失败时保留旧数组，原表仍然有效
    }

    for (int i = 0; i < L.length; ++i) {
        newData[i] = L.data[i];  // 复制所有有效元素，而不是复制整个旧容量
    }

    delete[] L.data;       // 确认复制完成后，才释放旧数组
    L.data = newData;      // 让顺序表指向新数组
    L.capacity = newCapacity;  // 更新容量记录
    return true;
}

// 读取第 i 个元素；线性表位序从 1 开始，数组下标从 0 开始。
bool GetElem(const SqList& L, int i, int& e) {
    if (i < 1 || i > L.length) {
        return false;  // 第 i 个元素不存在
    }

    e = L.data[i - 1];  // 位序 i 对应数组下标 i - 1
    return true;
}

// 返回第一个等于 e 的元素位序；不存在时返回 0。
int LocateElem(const SqList& L, int e) {
    for (int i = 0; i < L.length; ++i) {  // 逐个检查有效元素
        if (L.data[i] == e) {
            return i + 1;  // 返回位序，因此要把下标加 1
        }
    }
    return 0;  // 0 表示没有找到
}

// 在第 i 个元素之前插入 e；合法范围是 1 到 length + 1。
bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false;  // length + 1 表示允许在表尾插入
    }

    if (L.length == L.capacity) {  // 没有空位时先扩容
        if (!ExpandList(L)) {
            return false;  // 扩容失败，不能继续写入
        }
    }

    // 从后向前移动，避免覆盖尚未移动的原元素。
    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];  // 将位序 j 的元素右移到下标 j
    }

    L.data[i - 1] = e;  // 把新元素放到目标位序对应的下标
    ++L.length;         // 成功插入后表长增加 1
    return true;
}

// 删除第 i 个元素，并用 e 返回被删除的值。
bool ListDelete(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length) {
        return false;  // 删除位置必须对应已有元素
    }

    e = L.data[i - 1];  // 先保存被删值，避免后续左移覆盖它

    // 从前向后移动，把被删元素后面的元素依次左移一格。
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }

    --L.length;  // 有效元素个数减少 1，末尾旧值不再属于表
    return true;
}

// 按逻辑顺序输出全部有效元素。
void PrintList(const SqList& L) {
    for (int i = 0; i < L.length; ++i) {
        if (i > 0) {
            std::cout << ' ';  // 只在元素之间输出空格，不在开头输出
        }
        std::cout << L.data[i];  // 只输出 [0, length) 范围内的元素
    }
    std::cout << '\n';  // 输出换行，便于下一次输出从新行开始
}
```

> [!note] 关于动态扩容
> 该实现采用“容量不足时增加固定容量”的策略，采用固定增量扩容策略。每次扩容需要复制现有元素，因此单次扩容是 $O(n)$；若采用倍增扩容策略，连续尾插的均摊成本通常更低。本章重点是顺序表基本操作的实现原理。

## 3.3 顺序表插入

在第 $i$ 个元素之前插入新元素 $e$：

$$
(a_1,\ldots,a_{i-1},a_i,\ldots,a_n)
\rightarrow
(a_1,\ldots,a_{i-1},e,a_i,\ldots,a_n)
$$

操作步骤：

1. 检查插入位置是否合法：$1\leq i\leq n+1$。
2. 若容量不足，先扩容。
3. 从表尾向后，依次将第 $n,n-1,\ldots,i$ 个元素右移一位。
4. 将 $e$ 写入数组下标 `i - 1`。
5. 表长加 1。

若数组原来为：

`[10, 20, 30, 40]`

在位序 3 插入 99 后：

`[10, 20, 99, 30, 40]`

> [!danger] 插入时的移动方向
> 如果从前往后移动，前面的元素可能覆盖后面尚未移动的元素。**插入时从后向前移动，删除时从前向后移动。**

## 3.4 顺序表删除

删除第 $i$ 个元素：

$$
(a_1,\ldots,a_{i-1},a_i,a_{i+1},\ldots,a_n)
\rightarrow
(a_1,\ldots,a_{i-1},a_{i+1},\ldots,a_n)
$$

操作步骤：

1. 检查 $1\leq i\leq n$。
2. 保存被删元素 `data[i - 1]`。
3. 将原来第 $i+1,\ldots,n$ 个元素依次左移一位。
4. 表长减 1。

删除位序 2 的元素后，原位序 3 的元素移动到位序 2。

## 3.5 顺序表插入、删除的移动次数

设当前表长为 $n$。

- 在位序 $i$ 插入，需要移动 $n-i+1$ 个元素。
- 删除位序 $i$ 的元素，需要移动 $n-i$ 个元素。
- 表头插入移动元素最多；表尾插入不需要移动已有元素。
- 删除表头元素移动元素最多；删除表尾元素不需要移动元素。

若插入位置在 $1,\ldots,n+1$ 中等概率出现，则平均移动次数为：

$$
E_{\text{insert}}=\frac{0+1+\cdots+n}{n+1}=\frac{n}{2}
$$

若删除位置在 $1,\ldots,n$ 中等概率出现，则平均移动次数为：

$$
E_{\text{delete}}=\frac{0+1+\cdots+(n-1)}{n}=\frac{n-1}{2}
$$

因此，顺序表插入和删除的平均时间复杂度均为 $O(n)$。

## 3.6 顺序表优缺点

**优点**

1. 存储密度高，不需要额外的指针域来表示元素之间的关系。
2. 支持随机存取，按位序访问元素为 $O(1)$。
3. 元素连续存放，遍历和按下标访问直观。

**缺点**

1. 插入、删除通常需要移动大量元素。
2. 需要一块连续的存储空间。
3. 固定容量的实现需要提前估计最大长度；估计过小可能容量不足，估计过大可能浪费空间。
4. 动态扩容时需要分配新空间并复制元素。

## 3.7 顺序表复杂度速查

| 操作 | 时间复杂度 | 说明 |
|---|---:|---|
| 按位序取元素 | $O(1)$ | 直接计算数组下标 |
| 按值查找 | $O(n)$ | 最坏情况下逐个比较 |
| 插入 | $O(n)$ | 主要耗费在右移元素 |
| 删除 | $O(n)$ | 主要耗费在左移元素 |
| 遍历 | $O(n)$ | 每个元素访问一次 |
| 表尾追加（有空余容量） | $O(1)$ | 不需要移动已有元素 |
| 扩容 | $O(n)$ | 复制现有元素 |

---

# 4. 单链表：链式存储结构

## 4.1 结点与单链表

**链式存储结构**使用一组任意的存储单元存放数据元素。存储单元不要求连续。

单链表的每个结点包含：

- **数据域 `data`**：保存元素值；
- **指针域 `next`**：保存直接后继结点的地址。

例如：

`头结点 → [10] → [20] → [30] → 空指针`

逻辑上相邻的元素在物理内存中不一定相邻。只要知道头指针，就可以沿着 `next` 找到链表中的结点。

## 4.2 头指针与头结点

> [!note] 三个容易混淆的概念
> - **头指针**是一个指针变量，保存链表起始位置的地址；
> - **头结点**是额外设置的第一个结点，通常不保存有效数据；
> - **首元结点**才是第一个真正保存线性表元素的结点。

- **头指针**：指向链表起始位置的指针。
- **头结点**：为了统一操作，在第一个数据结点之前额外设置的结点；它通常不保存有效数据，`next` 指向第一个数据结点。
- **首元结点**：链表中的第一个数据结点。

本笔记中的单链表算法默认采用**带头结点**的形式：

- 空表：`head != nullptr` 且 `head->next == nullptr`。
- 非空表：`head->next` 指向第一个数据结点。
- 表长只计算数据结点，不计算头结点。

> [!important] 头结点的价值
> 插入第一个数据元素、删除第一个数据元素时，不必单独修改头指针；只需像处理其他结点一样修改头结点的 `next`。头结点不是线性表中的有效数据元素。

## 4.3 单链表结点定义

> [!note] 单链表结点结构
> ```cpp
> // 单链表结点：保存一个整数和指向后继结点的指针。
> struct Node {
>     int data;       // 数据域：保存元素值
>     Node* next;     // 指针域：保存下一个结点的地址
> };
> ```

不需要使用类型别名；定义结构体后直接使用 `Node*` 表示结点指针。

## 4.4 单链表基本操作的完整实现

> [!important] 这份实现的统一约定
> `head` 指向头结点；`head->next` 指向第一个数据结点；数据位序从 1 开始。插入和删除先定位前驱，再修改链接。`ClearList` 保留头结点，`DestroyList` 连头结点一起释放。

以下代码以带头结点的单链表为基础，覆盖初始化、取元素、查找、插入、删除、清空、销毁、尾插建表和就地逆置。

> [!important] 指针操作的三个检查点
> - 修改 `next` 前，确认需要保留的后继地址已经保存；
> - `delete` 之前，确认结点已从链表链接中摘除；
> - `ClearList` 与 `DestroyList` 的释放范围不同，不能混为一谈。

```cpp
#include <iostream>  // 提供 cout 和换行输出
#include <new>       // 提供 std::nothrow

// 单链表结点；本实现采用带头结点的形式。
struct Node {
    int data;       // 数据域；头结点的 data 不代表有效表元素
    Node* next;     // 指向下一个结点，最后一个数据结点指向 nullptr
};

// 创建头结点，建立一个空链表。
bool InitList(Node*& head) {
    head = new (std::nothrow) Node{0, nullptr};  // 头结点不保存有效元素
    return head != nullptr;                     // 用返回值告知申请是否成功
}

// 读取第 i 个数据结点的值；位序从 1 开始。
bool GetElem(const Node* head, int i, int& e) {
    if (head == nullptr || i < 1) {
        return false;  // 空指针或非法位序都不能读取
    }

    const Node* p = head->next;  // 从第一个数据结点开始，不把头结点计入位序
    int j = 1;                   // p 当前对应的逻辑位序

    while (p != nullptr && j < i) {
        p = p->next;  // 沿 next 向后走一个结点
        ++j;          // 位序同步加 1
    }

    if (p == nullptr) {
        return false;  // 遍历到链尾仍未到达位序 i
    }

    e = p->data;  // 取出目标结点的数据
    return true;
}

// 返回第一个等于 e 的元素位序；不存在时返回 0。
int LocateElem(const Node* head, int e) {
    if (head == nullptr) {
        return 0;  // 未初始化的链表无法查找
    }

    const Node* p = head->next;  // 从首元结点开始查找
    int i = 1;                   // 记录当前结点的位序

    while (p != nullptr) {
        if (p->data == e) {
            return i;  // 返回第一个匹配元素的位置
        }
        p = p->next;  // 当前值不匹配，检查后继
        ++i;          // 后继的位序加 1
    }

    return 0;  // 扫描完整条链表仍未找到
}

// 在第 i 个数据结点之前插入 e；i = 表长 + 1 表示尾插。
bool ListInsert(Node* head, int i, int e) {
    if (head == nullptr || i < 1) {
        return false;  // 头结点不存在或位序不合法
    }

    Node* p = head;  // 从头结点开始找第 i - 1 个结点
    int j = 0;       // 头结点之前的逻辑计数为 0

    while (p != nullptr && j < i - 1) {
        p = p->next;  // 每走一步，前驱候选向后移动
        ++j;
    }

    if (p == nullptr) {
        return false;  // 没有找到第 i - 1 个结点，插入位置越界
    }

    Node* s = new (std::nothrow) Node{e, p->next};  // 新结点先接上原后继
    if (s == nullptr) {
        return false;  // 内存申请失败，原链表不变
    }

    p->next = s;  // 再让前驱指向新结点，完成插入
    return true;
}

// 删除第 i 个数据结点，并用 e 返回被删除的值。
bool ListDelete(Node* head, int i, int& e) {
    if (head == nullptr || i < 1) {
        return false;  // 链表不存在或位序不合法
    }

    Node* p = head;  // p 最终停在待删除结点的前驱
    int j = 0;       // 头结点对应计数 0

    while (p->next != nullptr && j < i - 1) {
        p = p->next;  // 向目标结点前方移动
        ++j;
    }

    if (p->next == nullptr) {
        return false;  // 没有第 i 个数据结点
    }

    Node* q = p->next;  // 保存待删除结点，后面需要读取并释放它
    e = q->data;        // 在释放前保存数据
    p->next = q->next;  // 前驱越过 q，直接连接 q 的后继
    delete q;            // 释放已经从链表中摘下的结点
    return true;
}

// 清空数据结点，但保留头结点，因而链表仍然可继续使用。
void ClearList(Node* head) {
    if (head == nullptr) {
        return;  // 没有头结点，无需处理
    }

    Node* p = head->next;  // 第一个需要释放的数据结点
    while (p != nullptr) {
        Node* next = p->next;  // 释放 p 前先保存后继地址
        delete p;              // 释放当前数据结点
        p = next;              // 继续处理原来的后继
    }

    head->next = nullptr;  // 头结点重新指向空，形成空表
}

// 销毁整个链表，包括头结点，并把调用者的指针置空。
void DestroyList(Node*& head) {
    if (head == nullptr) {
        return;  // 已经为空，不需要重复释放
    }

    ClearList(head);  // 先释放所有数据结点
    delete head;      // 再释放头结点本身
    head = nullptr;   // 防止调用者继续使用已释放地址
}

// 把数组中的 n 个值按原顺序追加到已有的空链表中。
bool CreateListTail(Node* head, const int values[], int n) {
    if (head == nullptr || n < 0) {
        return false;  // 检查链表和元素数量是否合法
    }

    Node* tail = head;  // 尾指针先指向头结点
    while (tail->next != nullptr) {
        tail = tail->next;  // 如果表非空，先找到当前尾结点
    }

    for (int i = 0; i < n; ++i) {
        Node* s = new (std::nothrow) Node{values[i], nullptr};  // 新结点暂时作为链尾
        if (s == nullptr) {
            return false;  // 分配失败；此前已插入的结点会保留在链表中
        }

        tail->next = s;  // 原尾结点接上新结点
        tail = s;        // 更新尾指针，便于下一次尾插
    }

    return true;
}

// 就地逆置：只修改 next 指针，不新建数据结点。
void ReverseList(Node* head) {
    if (head == nullptr) {
        return;  // 链表未初始化
    }

    Node* previous = nullptr;  // 已反转部分的前一个结点，最初为空
    Node* current = head->next;  // 从首元结点开始反转

    while (current != nullptr) {
        Node* next = current->next;  // 先保存未处理部分的入口
        current->next = previous;    // 将当前结点的指针反向
        previous = current;          // previous 前进到当前结点
        current = next;              // current 前进到原来的后继
    }

    head->next = previous;  // 反转结束后，previous 是新的首元结点
}

// 按链表中的逻辑顺序输出所有数据结点。
void PrintList(const Node* head) {
    if (head == nullptr) {
        return;  // 未初始化的链表不输出
    }

    const Node* p = head->next;  // 跳过头结点
    while (p != nullptr) {
        std::cout << p->data;  // 输出当前结点的值
        if (p->next != nullptr) {
            std::cout << ' ';  // 仅在两个元素之间输出空格
        }
        p = p->next;  // 移动到下一个结点
    }
    std::cout << '\n';  // 输出换行
}
```

> [!warning] 关于建表时的内存分配失败
> `CreateListTail` 在分配中途失败时会返回 `false`，此前已经插入的结点仍留在表中，调用方应决定是保留已有结点还是调用 `ClearList` 回滚。正式工程代码还应根据需要完善异常安全处理。

## 4.5 取第 $i$ 个元素

顺序表能直接通过下标访问，而单链表不能直接计算第 $i$ 个结点的地址。因此必须从第一个数据结点开始，沿 `next` 逐个后移，直到计数器达到 $i$。

- 时间复杂度：$O(n)$。
- 这称为**顺序存取**，不是随机存取。

## 4.6 单链表插入

在第 $i$ 个结点之前插入新结点，核心是先找到第 $i-1$ 个结点，再修改指针。

原结构：

`前驱 p → 后继`

新结构：

`前驱 p → 新结点 s → 原后继`

下面用一段最小代码观察指针更新顺序：

> [!example] 插入结点：先接后继，再接前驱
> ```cpp
> // 先让新结点 s 指向原后继，避免丢失后续链段。
> s->next = p->next;
> // 再把前驱 p 的后继改成 s，插入才真正完成。
> p->next = s;
> ```

必须先让新结点指向原后继，再让前驱指向新结点。若先执行 `p->next = s`，原后继地址可能丢失。

- 找到前驱：最坏 $O(n)$。
- 已知前驱后完成插入：$O(1)$。
- 按位序插入的总体复杂度：$O(n)$。

## 4.7 单链表删除

删除第 $i$ 个结点时，先找到其前驱 `p`，令 `q = p->next`，再绕过 `q`：

> [!warning] 删除结点：先摘链，再释放
> ```cpp
> Node* q = p->next;      // 保存待删除结点，后续要读取并释放它
> p->next = q->next;       // 前驱越过 q，直接指向 q 的后继
> e = q->data;             // 在释放前保存被删除元素的值
> delete q;                // 结点已脱离链表，现在可以释放内存
> ```

- 先保存被删结点指针；
- 先修改链，再释放结点；
- 返回被删值；
- 不要在 `delete q` 后继续访问 `q->data` 或 `q->next`。

按位序删除的总体复杂度为 $O(n)$，其中定位前驱需要线性扫描，真正修改指针和释放结点只需 $O(1)$。

## 4.8 清空与销毁

- `ClearList`：逐个删除数据结点，头结点保留，最终 `head->next = nullptr`。
- `DestroyList`：先清空，再删除头结点，并把外部头指针设为 `nullptr`。

链表是动态结构，结点由程序在需要时申请。C++ 中本笔记使用 `new` 申请结点，使用 `delete` 释放单个结点；数组形式的动态空间则使用 `new[]` 与 `delete[]` 配对。

## 4.9 头插法与尾插法建表

### 头插法

每次把新结点插到头结点之后。若输入次序是 $a_n,a_{n-1},\ldots,a_1$，最终链表为 $a_1,a_2,\ldots,a_n$。

- 每次插入 $O(1)$；
- 建表总时间 $O(n)$；
- 若输入按 $a_1,a_2,\ldots,a_n$ 的顺序进行，头插法会使最终次序反转。

### 尾插法

维护尾指针，每次把新结点接到表尾。输入次序与链表次序一致。

- 若每次都从头扫描寻找尾结点，建表可能达到 $O(n^2)$；
- 若维护尾指针，建表总时间为 $O(n)$。

## 4.10 合并两个非递减有序单链表

设 `La`、`Lb` 都带头结点，数据结点按非递减顺序排列。两个指针分别扫描两条链，每次选择较小的元素追加到结果链表；一个链表到达末尾后，将另一个链表的剩余部分接入。

下面采用**复制结点**的方式生成新表，保留原表不变：

> [!example] 双指针归并有序链表
> ```cpp
> // 把两个非递减链表复制合并成新链表；原链表保持不变。
> Node* MergeSortedCopy(const Node* La, const Node* Lb) {
>     if (La == nullptr || Lb == nullptr) {
>         return nullptr;  // 任一输入缺少头结点，无法按约定处理
>     }
>
>     Node* result = new Node{0, nullptr};  // 新建结果头结点
>     Node* tail = result;                 // tail 始终指向结果链表的最后一个结点
>     const Node* pa = La->next;           // 指向 A 的第一个数据结点
>     const Node* pb = Lb->next;           // 指向 B 的第一个数据结点
>
>     while (pa != nullptr && pb != nullptr) {  // 两条链都还有未处理元素
>         int value;  // 暂存本轮选中的较小值
>
>         if (pa->data <= pb->data) {
>             value = pa->data;  // A 当前值较小或相等，先复制 A 的值
>             pa = pa->next;     // A 的当前结点已处理，向后移动
>         } else {
>             value = pb->data;  // B 当前值较小，先复制 B 的值
>             pb = pb->next;     // B 的当前结点已处理，向后移动
>         }
>
>         tail->next = new Node{value, nullptr};  // 把新结点接到结果表尾
>         tail = tail->next;                      // 更新结果尾指针
>     }
>
>     while (pa != nullptr) {  // B 已处理完，复制 A 的剩余结点
>         tail->next = new Node{pa->data, nullptr};
>         tail = tail->next;
>         pa = pa->next;
>     }
>
>     while (pb != nullptr) {  // A 已处理完，复制 B 的剩余结点
>         tail->next = new Node{pb->data, nullptr};
>         tail = tail->next;
>         pb = pb->next;
>     }
>
>     return result;  // 返回带头结点的新链表，调用者负责最终销毁它
> }
> ```

- 时间复杂度：$O(m+n)$。
- 复制结果表需要 $O(m+n)$ 额外空间。
- 若改为直接重连原结点，可减少额外空间，但会改变输入链表结构，必须明确结点所有权，不能同时让多个表不加区分地管理同一批结点。

---

# 5. 其他链表形式

## 5.1 静态链表

**静态链表**：借助数组描述链表，用整数游标 `cur` 代替指针，表示后继结点在数组中的下标。

> [!note] 静态链表的结点与数组
> ```cpp
> // 静态链表用整数游标 cur 表示后继结点在数组中的下标。
> struct StaticNode {
>     int data;  // 当前分量保存的数据
>     int cur;   // 后继分量的数组下标；0 表示没有后继
> };
>
> const int MAXSIZE = 1000;  // 静态链表可使用的数组容量
> StaticNode S[MAXSIZE];     // 结点全部存放在这个固定数组中
> ```

约定：

- `S[0]` 作为头结点；
- `S[0].cur` 指向第一个数据结点的数组下标；
- `S[i].cur` 指向后继结点的数组下标；
- `cur == 0` 表示到达链尾；
- 数组下标为 1 到 `MAXSIZE - 1` 的分量可用作数据结点。

遍历示例：

> [!example] 静态链表遍历
> ```cpp
> #include <iostream>  // 提供 cout
>
> int i = S[0].cur;  // 从头结点记录的第一个数据结点下标开始
> while (i != 0) {   // 游标为 0 表示已经到达链尾
>     std::cout << S[i].data << ' ';  // 访问当前数组分量的数据域
>     i = S[i].cur;                   // 沿游标移动到后继分量
> }
> ```

### 静态链表的定位、分配与释放

以下代码约定 `S[0]` 是表头，`freeHead` 指向备用结点链表的首下标。初始化时，所有数据分量先连接成备用链表。

> [!note] 静态链表的两条游标链
> `S[0].cur` 管理正在使用的主链表；`freeHead` 管理尚未使用的备用结点。插入时从备用链表取结点，删除时把结点放回备用链表。

```cpp
const int MAXSIZE = 1000;  // 数组容量，0 号分量留作链表头结点

struct StaticNode {
    int data;  // 数据域
    int cur;   // 后继分量的数组下标，0 表示空链接
};

// 初始化主链表为空，并把其余分量串成备用结点链表。
void InitStaticList(StaticNode S[], int& freeHead) {
    S[0].data = 0;  // 头结点不存放有效数据
    S[0].cur = 0;   // 主链表初始为空

    for (int i = 1; i < MAXSIZE - 1; ++i) {
        S[i].data = 0;       // 初始化数据域
        S[i].cur = i + 1;    // 当前空闲分量指向下一个空闲分量
    }

    S[MAXSIZE - 1].data = 0;       // 初始化最后一个分量
    S[MAXSIZE - 1].cur = 0;        // 备用链表在此结束
    freeHead = 1;                  // 备用链表首下标设为 1
}

// 查找第一个值为 e 的结点，返回数组下标；未找到返回 0。
int LocateStaticList(const StaticNode S[], int e) {
    int i = S[0].cur;  // 主链表的第一个数据结点

    while (i != 0 && S[i].data != e) {
        i = S[i].cur;  // 沿主链表逐个查找
    }

    return i;  // 0 既表示链尾，也表示没有找到目标值
}

// 从备用链表取出一个空闲分量，并返回它的下标。
int AllocateStaticNode(StaticNode S[], int& freeHead) {
    if (freeHead == 0) {
        return 0;  // 备用链表为空，没有可用分量
    }

    int k = freeHead;       // 记录即将分配的分量下标
    freeHead = S[k].cur;    // 备用链表头移到下一个空闲分量
    return k;
}

// 把删除的分量重新接回备用链表。
void ReleaseStaticNode(StaticNode S[], int k, int& freeHead) {
    S[k].cur = freeHead;  // 被释放分量指向原备用链表头
    freeHead = k;         // 让该分量成为新的备用链表头
}

// 在位序 position 之前插入 e，位序从 1 开始。
bool StaticInsert(StaticNode S[], int& freeHead, int position, int e) {
    if (position < 1) {
        return false;  // 位序不能小于 1
    }

    int previous = 0;  // 从头结点开始找插入位置的前驱
    int j = 0;         // 头结点对应计数 0

    while (j < position - 1 && S[previous].cur != 0) {
        previous = S[previous].cur;  // 沿主链表向后移动
        ++j;                         // 同步更新已走过的结点数
    }

    if (j != position - 1) {
        return false;  // 前驱不存在，插入位置超出表尾后一位
    }

    int k = AllocateStaticNode(S, freeHead);  // 申请一个空闲分量
    if (k == 0) {
        return false;  // 静态数组已没有可用分量
    }

    S[k].data = e;                  // 写入新元素
    S[k].cur = S[previous].cur;     // 新结点先接上原后继
    S[previous].cur = k;            // 再让前驱指向新结点
    return true;
}

// 删除位序 position 的元素，并用 e 返回其值。
bool StaticDelete(StaticNode S[], int& freeHead, int position, int& e) {
    if (position < 1) {
        return false;  // 位序必须从 1 开始
    }

    int previous = 0;  // 从头结点寻找目标结点的前驱
    int j = 0;         // 记录已走过的数据结点数

    while (j < position - 1 && S[previous].cur != 0) {
        previous = S[previous].cur;  // 向后移动前驱
        ++j;
    }

    if (j != position - 1 || S[previous].cur == 0) {
        return false;  // 前驱或待删除结点不存在
    }

    int k = S[previous].cur;    // k 是待删除分量的下标
    e = S[k].data;              // 先保存被删除值
    S[previous].cur = S[k].cur; // 主链表跳过 k，接上它的后继
    ReleaseStaticNode(S, k, freeHead);  // 将 k 回收到备用链表
    return true;
}
```

静态链表插入、删除的逻辑与单链表相似，主要区别是需要用游标修改数组分量，并自行维护空闲分量链表：

- 分配结点：从备用链表取出一个空闲下标；
- 释放结点：把删除的下标重新接回备用链表。

**优点**：不依赖动态指针，也不需要在插入、删除时移动数据元素。
**缺点**：仍需预先分配数组空间，最大容量受数组大小限制。

## 5.2 循环链表

循环链表的最后一个结点不指向空指针，而是指回头结点。

若采用带头结点的单向循环链表：

- 空表时 `head->next == head`；
- 非空表时最后一个数据结点的 `next == head`；
- 判断链尾的条件是“后继是否为头结点”，而不是“后继是否为空”。

遍历：

> [!example] 循环链表遍历
> ```cpp
> Node* p = head->next;  // 从第一个数据结点开始；head 是头结点
> while (p != head) {    // 循环链表以“回到头结点”作为结束条件
>     std::cout << p->data << ' ';  // 访问当前数据结点
>     p = p->next;                  // 移动到后继结点
> }
> ```

循环链表适合需要反复从表尾回到表头、循环访问数据的场景。

> [!warning] 循环链表的终止条件
> 带头结点的循环链表遍历应判断 `p != head`，不能判断 `p != nullptr`。因为最后一个结点会再次指向头结点，错误的终止条件可能造成无限循环。

## 5.3 双向链表

双向链表每个数据结点有两个指针域：

- `prior`：指向直接前驱；
- `next`：指向直接后继。

> [!note] 双向链表结点结构
> ```cpp
> // 双向链表结点：除了数据域，还保存前驱和后继两个方向。
> struct DNode {
>     int data;       // 保存元素值
>     DNode* prior;   // 指向直接前驱
>     DNode* next;    // 指向直接后继
> };
> ```

双向链表可以向前、向后遍历。查找和按位序访问仍需定位，因此通常仍为 $O(n)$；但在**已经知道目标结点地址**的前提下，插入或删除只需修改固定数量的指针，为 $O(1)$。

### 双向循环链表的初始化

用头结点构成循环结构，空表时头结点的两个方向都指向自身：

> [!example] 双向循环链表初始化
> ```cpp
> // 建立带头结点的双向循环链表；空表时两个链接都指向头结点自身。
> DNode* InitDoublyCircularList() {
>     DNode* head = new DNode{0, nullptr, nullptr};  // 创建不存有效数据的头结点
>     head->prior = head;  // 空表中头结点的前驱指向自己
>     head->next = head;   // 空表中头结点的后继也指向自己
>     return head;         // 把头结点地址交给调用者
> }
> ```

### 在结点 `p` 之前插入新结点

> [!example] 在已知结点之前插入
> ```cpp
> #include <new>  // 提供 std::nothrow
>
> // 把值为 e 的新结点插入到已知结点 p 的前面。
> bool InsertBefore(DNode* p, int e) {
>     if (p == nullptr) {
>         return false;  // 没有目标结点，无法插入
>     }
>
>     // 新结点先记录 p 的原前驱和 p 本身，先把自身两端关系设好。
>     DNode* s = new (std::nothrow) DNode{e, p->prior, p};
>     if (s == nullptr) {
>         return false;  // 申请失败，原链表保持不变
>     }
>
>     p->prior->next = s;  // 原前驱的后继改为新结点
>     p->prior = s;        // p 的前驱改为新结点，完成四条链接更新
>     return true;
> }
> ```

> [!important] 双向链表插入：四条链接都要更新
> 1. 新结点的前驱指向 `p` 的原前驱；
> 2. 原前驱的后继指向新结点；
> 3. 新结点的后继指向 `p`；
> 4. `p` 的前驱改为新结点。

### 删除已知结点 `p`

> [!warning] 删除双向链表结点
> ```cpp
> // 删除双向循环链表中的已知数据结点 p，并返回其数据。
> bool DeleteDNode(DNode* head, DNode* p, int& e) {
>     if (head == nullptr || p == nullptr || p == head) {
>         return false;  // 不能删除空指针，也不删除头结点
>     }
>
>     e = p->data;                // 先保存要返回的元素值
>     p->prior->next = p->next;   // 前驱越过 p，连接到 p 的后继
>     p->next->prior = p->prior;  // 后继越过 p，连接到 p 的前驱
>     delete p;                   // 两个方向修复后再释放 p
>     return true;
> }
> ```

删除时同时修复前驱的 `next` 和后继的 `prior`。若只修改其中一个方向，链表就会出现不一致。

## 5.4 链表形式对比

| 形式 | 结点链接方式 | 主要特点 | 需要特别注意 |
|---|---|---|---|
| 单链表 | 只有 `next` | 结构简单，空间开销较小 | 不能直接向前访问 |
| 静态链表 | 数组下标 `cur` | 不依赖指针类型 | 需维护空闲分量 |
| 循环链表 | 尾结点指回头结点 | 可循环访问 | 终止条件不能写成空指针 |
| 双向链表 | `prior` 与 `next` | 可双向遍历 | 插入、删除需同时修改两个方向 |
| 双向循环链表 | 双向链接且首尾相连 | 两端操作统一 | 空表初始化及头结点边界必须正确 |

---

# 6. 改进的线性链表与有序表

## 6.1 改进的线性链表

改进的线性链表在常规结点和头指针之外，额外保存：

- `head`：头结点指针；
- `tail`：尾结点指针；
- `len`：数据结点个数；
- `current`：当前访问结点指针。

示意结构：

> [!note] 改进链表的附加字段
> ```cpp
> // 常规单链表结点定义。
> struct LinkNode {
>     int data;            // 数据域
>     LinkNode* next;      // 后继指针
> };
>
> // 改进链表：额外保存尾指针、当前指针和表长。
> struct LinkList {
>     LinkNode* head;      // 头结点指针，便于统一首结点操作
>     LinkNode* tail;      // 尾结点指针，使尾插无需重新遍历整条链
>     LinkNode* current;   // 当前操作结点，便于实现当前结点相关操作
>     int len;             // 数据结点个数，不包括头结点
> };
> ```

这不是类型别名，而是两个直接定义的结构体。

### 各字段的作用

- `head` 使空表、首结点操作更容易统一。
- `tail` 让表尾追加不必每次从头遍历。
- `len` 让求表长可在 $O(1)$ 时间完成。
- `current` 让“对当前结点进行操作”更方便。

若约定初始化时 `head`、`tail`、`current` 都指向头结点，`len = 0`，则空表的状态容易判断。

这类结构通常可以支持以下操作：

| 操作 | 含义 | 典型复杂度 |
|---|---|---:|
| `InitList` | 建立空链表 | $O(1)$ |
| `DestroyList` | 销毁链表 | $O(n)$ |
| `ListEmpty` | 判空 | $O(1)$ |
| `ListLength` | 求表长 | $O(1)$ |
| `Prior` / `Next` | 移动当前指针 | 取决于结点结构与实现 |
| `GetCurElem` | 读取当前结点值 | $O(1)$ |
| `LocatePos` | 移动到第 $i$ 个结点 | $O(n)$ |
| `LocateElem` | 按值定位 | $O(n)$ |
| `ListTraverse` | 遍历 | $O(n)$ |
| `ClearList` | 清空数据结点 | $O(n)$ |
| `SetCurElem` | 修改当前值 | $O(1)$ |
| `Append` | 追加一串结点 | 与追加结点数有关 |
| `InsAfter` | 在当前结点后插入 | $O(1)$ |
| `DelAfter` | 删除当前结点的后继 | $O(1)$ |

> [!warning] 复杂度的前提
> “插入、删除为 $O(1)$”只在已经拿到需要修改的结点或其前驱时成立。若还要先按位序查找，整体时间通常仍是 $O(n)$。

## 6.2 有序链表的查找与插入

有序链表的元素按某个比较规则排列。以非递减整数链表为例：

`12 → 23 → 34 → 45 → 56 → 67 → 78 → 89 → 98`

查找值 `45`，返回该元素所在结点；查找值 `88`，则定位到第一个大于 `88` 的结点之前，也就是 `78` 所在结点之后，插入 `88` 即可保持有序。

### 按非递减次序插入

下面的算法把新元素插到所有小于或等于它的元素之后，因此相同值可以保留，链表仍为非递减：

> [!example] 向有序链表插入元素
> ```cpp
> #include <new>  // 提供 std::nothrow
>
> // 将整数 e 插入到非递减有序单链表中，允许保留重复值。
> bool OrderedInsert(Node* head, int e) {
>     if (head == nullptr) {
>         return false;  // 必须先有头结点
>     }
>
>     Node* p = head;  // p 最终停在新结点应插入位置的前驱
>     while (p->next != nullptr && p->next->data <= e) {
>         p = p->next;  // 跳过所有小于或等于 e 的元素，保证顺序不变
>     }
>
>     Node* s = new (std::nothrow) Node{e, p->next};  // 新结点接上原后继
>     if (s == nullptr) {
>         return false;  // 申请失败时不修改原链表
>     }
>
>     p->next = s;  // 前驱连接新结点，完成有序插入
>     return true;
> }
> ```

- 定位插入点：最坏 $O(n)$。
- 修改链接：$O(1)$。
- 总体复杂度：$O(n)$。

若业务要求集合元素不重复，插入前还需要检查是否已存在相同值。

---

# 7. 一元多项式的表示及相加

## 7.1 多项式与线性表

一般的一元 $n$ 次多项式可写为：

$$
P_n(x)=p_0+p_1x+p_2x^2+\cdots+p_nx^n
$$

如果用数组保存系数，指数 $i$ 可以由系数在数组中的位置隐含表示：

$$
P=(p_0,p_1,\ldots,p_n)
$$

这种方式适合指数范围不大、系数较密集的多项式。

## 7.2 稀疏多项式

> [!important] 稀疏存储的核心
> **只保存非零项，并同时记录系数和指数。** 指数不再依赖数组下标隐含表示，因此即使指数很大，只要非零项少，仍然可以节省空间。

当最高指数很大，但非零项很少时，直接按最高指数建立数组会浪费空间。

例如：

$$
S(x)=1+3x^{10000}-2x^{20000}
$$

若按指数下标存储，需要长度约为 20001 的数组，但只有 3 个非零系数。

解决方法是**只存储非零项**，每一项保存：

- 系数 `coef`；
- 指数 `exp`。

例如：

$$
P(x)=7x^3-2x^{12}-8x^{999}
$$

可以表示为：

$$
((7,3),(-2,12),(-8,999))
$$

一般的稀疏多项式表示为：

$$
P(x)=\sum_{i=1}^{m}p_i x^{e_i},
\qquad 0\leq e_1<e_2<\cdots<e_m
$$

每个结点表示一项，结点按指数递增链接。

> [!note] 关于本节示例中的系数类型
> 数学定义中的系数可以是实数；为遵守本次整理提出的“数据类型默认使用 `int`”要求，以下示例代码使用整数系数。若实际任务允许小数系数，应将系数域改成 `double`，指数仍可用 `int`。

## 7.3 选择顺序存储还是链式存储

| 运算需求 | 较合适的存储方式 | 原因 |
|---|---|---|
| 指数范围较小、项较密集 | 顺序存储 | 按指数访问直接，结构简单 |
| 指数范围很大、非零项稀疏 | 稀疏项顺序表或链表 | 不需要为零系数保留大量空间 |
| 两个多项式相加，需处理不同指数项 | 按指数排序的链表很合适 | 可用双指针线性归并 |

## 7.4 多项式抽象数据类型

多项式结构可以定义以下基本操作：

- `CreatePolyn(P, m)`：输入 $m$ 项的系数和指数，建立多项式；
- `DestroyPolyn(P)`：销毁多项式；
- `PrintPolyn(P)`：打印多项式；
- `PolynLength(P)`：返回多项式的项数；
- `AddPolyn(Pa, Pb)`：完成 $Pa=Pa+Pb$，并销毁 `Pb`；
- `SubtractPolyn(Pa, Pb)`：完成 $Pa=Pa-Pb$，并销毁 `Pb`；
- `MultiplyPolyn(Pa, Pb)`：完成 $Pa=Pa\times Pb$，并销毁 `Pb`。

这些操作中的“销毁另一个多项式”是一种接口约定。实际编程时应明确函数是否接管输入对象的所有权，避免重复释放或访问已释放的结点。

## 7.5 多项式相加的规则

> [!important] 双指针归并的三种情况
> - 指数较小的一项直接进入结果，移动对应指针；
> - 指数相同则合并系数，并同时移动两个指针；
> - 系数和为 0 时不保留该项。
>
> 因为每轮至少移动一个指针，所以每一项只需处理常数次，整体可做到线性时间。

设两个多项式的非零项都按指数递增排列。用指针 `p`、`q` 分别扫描两条链表：

1. 若 `p->exp < q->exp`，`p` 指向的项指数较小，应将该项放入结果，`p` 后移。
2. 若 `p->exp > q->exp`，`q` 指向的项指数较小，应将该项放入结果，`q` 后移。
3. 若指数相等，将系数相加：
   - 和不为 0：结果中保留该指数项；
   - 和为 0：该项抵消，不放入结果。
   - 两个指针都后移。
4. 任意一个链表到达末尾后，另一个链表剩余的项直接复制到结果。

### 标准 C++ 实现

以下函数把输入多项式视为**带头结点**的链表，按指数递增排列。结果是一个新链表，不修改输入链表；系数和指数均使用 `int`。

> [!important] 多项式相加的代码约定
> - 输入结点按指数递增排列；
> - 输入链表由调用者持有，函数只读取它们；
> - 函数创建独立的结果链表，调用者必须在使用完后调用 `DestroyPolynomial`；
> - 系数和为 0 的项不进入结果。

```cpp
#include <iostream>  // 提供多项式输出功能
#include <new>       // 提供 std::nothrow

// 多项式的一项：系数 coef、指数 exp，以及指向下一项的指针。
struct TermNode {
    int coef;       // 系数；本示例按要求使用 int
    int exp;        // 指数，非负整数
    TermNode* next; // 指向下一项；各项按指数递增排列
};

// 在结果多项式末尾追加一项；零系数项不存入链表。
bool AppendTerm(TermNode*& tail, int coef, int exp) {
    if (coef == 0) {
        return true;  // 零系数项没有必要存储，视为成功处理
    }

    TermNode* node = new (std::nothrow) TermNode{coef, exp, nullptr};  // 新项暂作链尾
    if (node == nullptr) {
        return false;  // 内存不足，通知调用者处理失败
    }

    tail->next = node;  // 原尾结点接上新项
    tail = node;        // 更新尾指针，下一项可继续尾插
    return true;
}

// 提前声明销毁函数，便于相加过程中出错时释放已生成的结果。
void DestroyPolynomial(TermNode*& head);

// a、b 都是带头结点且按指数递增排列的多项式；函数生成独立的新结果。
TermNode* AddPolynomials(const TermNode* a, const TermNode* b) {
    if (a == nullptr || b == nullptr) {
        return nullptr;  // 输入缺少头结点，无法按约定读取
    }

    TermNode* result = new (std::nothrow) TermNode{0, 0, nullptr};  // 创建结果头结点
    if (result == nullptr) {
        return nullptr;  // 头结点申请失败
    }

    TermNode* tail = result;           // tail 始终指向结果表的最后一项
    const TermNode* p = a->next;       // 跳过 a 的头结点，指向第一项
    const TermNode* q = b->next;       // 跳过 b 的头结点，指向第一项

    while (p != nullptr && q != nullptr) {  // 两个多项式都还有未处理项
        if (p->exp < q->exp) {  // p 的指数更小，该项不可能与 q 合并
            if (!AppendTerm(tail, p->coef, p->exp)) {
                DestroyPolynomial(result);  // 失败时释放已生成的结果，避免泄漏
                return nullptr;
            }
            p = p->next;  // p 这一项已处理，移动 p
        } else if (p->exp > q->exp) {  // q 的指数更小，先处理 q
            if (!AppendTerm(tail, q->coef, q->exp)) {
                DestroyPolynomial(result);
                return nullptr;
            }
            q = q->next;  // q 这一项已处理，移动 q
        } else {  // 指数相同，两个系数必须相加
            int sum = p->coef + q->coef;  // 合并同类项
            if (!AppendTerm(tail, sum, p->exp)) {
                DestroyPolynomial(result);
                return nullptr;
            }
            p = p->next;  // 同指数的两项都已处理
            q = q->next;
        }
    }

    while (p != nullptr) {  // q 已到链尾，复制 a 剩余的项
        if (!AppendTerm(tail, p->coef, p->exp)) {
            DestroyPolynomial(result);
            return nullptr;
        }
        p = p->next;
    }

    while (q != nullptr) {  // p 已到链尾，复制 b 剩余的项
        if (!AppendTerm(tail, q->coef, q->exp)) {
            DestroyPolynomial(result);
            return nullptr;
        }
        q = q->next;
    }

    return result;  // 返回新多项式，调用者负责最终销毁它
}

// 输出多项式；假定各项按指数递增排列且不包含零系数项。
void PrintPolynomial(const TermNode* head) {
    if (head == nullptr) {
        return;  // 空指针不是有效多项式
    }

    const TermNode* p = head->next;  // 跳过头结点，读取第一项
    if (p == nullptr) {
        std::cout << 0 << '\n';  // 没有非零项时，多项式为 0
        return;
    }

    bool first = true;  // 用于判断当前是否为输出的第一项

    while (p != nullptr) {
        if (!first && p->coef > 0) {
            std::cout << '+';  // 非第一项的正系数前补加号
        }

        if (p->exp == 0) {
            std::cout << p->coef;  // 常数项不需要输出 x
        } else {
            std::cout << p->coef << "*x";  // 输出系数和变量
            if (p->exp != 1) {
                std::cout << '^' << p->exp;  // 指数为 1 时省略 ^1
            }
        }

        first = false;  // 后续项都不再是第一项
        p = p->next;    // 继续输出下一项
    }

    std::cout << '\n';  // 输出结束后换行
}

// 释放多项式的全部结点，包括头结点，并将 head 置空。
void DestroyPolynomial(TermNode*& head) {
    if (head == nullptr) {
        return;  // 已经销毁或从未初始化
    }

    TermNode* p = head;  // 从头结点开始逐个释放
    while (p != nullptr) {
        TermNode* next = p->next;  // 先保存后继，防止释放后无法继续遍历
        delete p;                  // 释放当前结点
        p = next;                  // 继续处理原来的后继
    }

    head = nullptr;  // 清空调用者持有的指针
}
```

> [!warning] 内存分配失败
> 若结果结点分配失败，函数会释放已经生成的结果链表并返回 `nullptr`，避免把不完整的多项式误当作正确结果。调用方应检查返回值是否为空。

## 7.6 多项式相加的复杂度

设两个多项式分别有 $m$、$n$ 个非零项：

- 每个结点最多被扫描一次；
- 每次循环至少让一个指针后移；
- 结果中的项数最多为 $m+n$。

因此：

- 时间复杂度：$O(m+n)$；
- 若生成新结果链表，额外空间复杂度：$O(m+n)$。

若直接复用和重连原链表结点，可以降低额外空间，但需要处理好原链表所有权及被抵消项的释放。

---

# 8. 顺序表与链表的综合比较

## 8.1 复杂度对照

> [!abstract] 选型先看最常做的操作
> 需要大量按位序读取时，顺序表通常更合适；需要频繁在已知位置附近插入、删除时，链表更有优势。**定位成本必须计入总复杂度**，不能只计算最后修改指针的那一步。

| 操作 | 顺序表 | 单链表（带头结点） |
|---|---:|---:|
| 按位序访问 | $O(1)$ | $O(n)$ |
| 按值查找 | $O(n)$ | $O(n)$ |
| 已知下标 / 结点位置后插入 | 顺序表仍需移动，通常 $O(n)$ | 已知前驱时 $O(1)$ |
| 按位序插入 | $O(n)$ | $O(n)$，定位前驱耗时 |
| 已知待删结点及必要链接后删除 | 通常仍需移动，$O(n)$ | 可为 $O(1)$，但单链表通常需要前驱 |
| 按位序删除 | $O(n)$ | $O(n)$ |
| 遍历 | $O(n)$ | $O(n)$ |
| 表尾追加 | 有空余容量时 $O(1)$ | 有尾指针时 $O(1)$，否则 $O(n)$ |
| 存储空间 | 元素连续，额外链接空间少 | 每个结点需要指针域，存储密度较低 |

## 8.2 存储密度

存储密度可理解为：

$$
\text{存储密度}=
\frac{\text{数据元素本身所占存储量}}
{\text{结点整体所占存储量}}
$$

顺序表不需要为每个元素额外保存后继指针，因此存储密度通常较高；链表需要保存一个或多个指针域，存储密度较低。

## 8.3 如何选择

优先考虑**顺序表**的情况：

- 经常按位序读取；
- 数据规模较稳定；
- 插入、删除不频繁；
- 希望结构简单、存储密度高。

优先考虑**链表**的情况：

- 插入、删除较频繁；
- 数据规模变化较大；
- 不要求随机访问；
- 已经能方便地取得插入或删除位置附近的结点。

> [!important] 不存在绝对更优的存储结构
> 选择时要综合考虑访问模式、插入删除频率、空间开销、最大规模、是否需要连续存储，以及所用语言的能力。不能只根据“链表插入快”就断定链表总是更好：如果每次插入前都需要从头查找位置，总体仍可能是 $O(n)$。

---

# 9. 综合算法与典型练习

本节通过典型算法练习线性表的实际操作，包括有序链表区间删除、就地逆置、有序表交集、双向链表复制和按访问频度调整结点。代码统一使用标准 C++，数据默认使用 `int`；链表题目会在题意中明确头结点和循环结构等约定。

## 9.1 删除有序单链表中指定区间的结点

> [!example] 解题锚点
> 先找到最后一个满足 `data <= mink` 的结点作为前驱，然后反复删除它的后继，直到后继不存在或其值达到 `maxk`。因为表有序，所以无需扫描区间之外的剩余结点。

**题意**：已知单链表元素按递增顺序排列，删除所有满足

$$
mink < x < maxk
$$

的结点，并释放结点空间。`mink`、`maxk` 可以与表中元素相同。

**思路**：

1. 若 `mink >= maxk`，不存在满足条件的值，直接返回。
2. 从头开始跳过所有小于或等于 `mink` 的结点。
3. 从第一个大于 `mink` 的结点开始，删除所有小于 `maxk` 的结点。
4. 遇到第一个大于或等于 `maxk` 的结点后即可结束。

> [!example] 删除开区间内的元素
> ```cpp
> // 删除有序单链表中所有满足 mink < data < maxk 的结点。
> void DeleteBetween(Node* head, int mink, int maxk) {
>     if (head == nullptr || mink >= maxk) {
>         return;  // 链表无效或区间为空，不需要删除
>     }
>
>     Node* p = head;  // p 用来寻找待删除区间的前驱
>
>     while (p->next != nullptr && p->next->data <= mink) {
>         p = p->next;  // 保留所有小于或等于 mink 的结点
>     }
>
>     // 此时 p->next 是第一个大于 mink 的候选结点。
>     while (p->next != nullptr && p->next->data < maxk) {
>         Node* q = p->next;  // 保存当前要删除的结点
>         p->next = q->next;  // 绕过 q；p 不前进，以便继续检查新的后继
>         delete q;            // 释放被摘下的结点
>     }
> }
> ```

**复杂度**：时间 $O(n)$，额外空间 $O(1)$。由于链表有序，删除区间结束后可以提前停止。

**易错点**：条件必须是严格不等式。值等于 `mink` 或 `maxk` 的结点不能删除。

## 9.2 单链表就地逆置

> [!tip] 三指针记忆法
> `previous` 指向已反转部分，`current` 指向当前结点，`next` 暂存未反转部分的入口。每轮先保存 `next`，再反转链接，最后整体向前推进。

**题意**：不另建一条存放数据的新链表，只修改原链表指针，使顺序反转。

例如：

`1 → 2 → 3 → 4`

变为：

`4 → 3 → 2 → 1`

**思路**：维护 `previous`、`current`、`next` 三个指针。每次先保存后继，再把当前结点的 `next` 指向前一个结点，最后三个指针依次前进。

> [!example] 单链表就地逆置
> ```cpp
> // 就地逆置带头结点的单链表，不额外申请数据结点。
> void ReverseList(Node* head) {
>     if (head == nullptr) {
>         return;  // 没有头结点，无法操作
>     }
>
>     Node* previous = nullptr;  // 已反转部分的尾端；初始没有结点
>     Node* current = head->next;  // 当前准备反转的结点，跳过头结点
>
>     while (current != nullptr) {
>         Node* next = current->next;  // 必须先保存原后继，否则剩余链会丢失
>         current->next = previous;    // 把当前结点的 next 反向指向前驱
>         previous = current;          // 已处理部分向前扩展一结点
>         current = next;              // 转向尚未处理的下一个结点
>     }
>
>     head->next = previous;  // previous 最终是原链表的最后一个数据结点
> }
> ```

**复杂度**：时间 $O(n)$，额外空间 $O(1)$。

**易错点**：改变 `current->next` 之前，必须先保存原来的后继，否则剩余链表会丢失。

## 9.3 两个递增有序表的交集

> [!important] 有序性带来的优势
> 每次只比较两个当前元素：较小的一方不可能与对方当前及后续更大的元素匹配，因此可以安全地前移。两个指针都只向前走，避免了双重循环。

**题意**：有两个递增有序表 A、B，另建表 C，使 C 保存 A 与 B 的交集，且 C 仍按递增次序排列。分别考虑顺序表和单链表。

### 方法一：顺序表

双指针从两个表头开始：

- 若 `A[i] < B[j]`，则 A 当前元素不可能出现在 B 的当前及后续位置，`i++`。
- 若 `A[i] > B[j]`，则 `j++`。
- 若相等，将该值放入 C，然后两个指针都后移。

> [!example] 求两个有序序列的交集
> ```cpp
> #include <vector>  // 使用标准动态数组表示顺序表
>
> // 求两个递增有序序列的交集；结果不重复，且仍按递增顺序排列。
> std::vector<int> IntersectSequential(
>     const std::vector<int>& A,  // 输入 A：只读引用，避免复制整个序列
>     const std::vector<int>& B   // 输入 B：只读引用，避免复制整个序列
> ) {
>     std::vector<int> C;  // 用于保存交集结果
>     int i = 0;           // A 当前检查的数组下标
>     int j = 0;           // B 当前检查的数组下标
>
>     while (i < static_cast<int>(A.size()) &&
>            j < static_cast<int>(B.size())) {  // 两个序列都还有元素时继续
>         if (A[i] < B[j]) {
>             ++i;  // A[i] 太小，不可能匹配 B 当前及后续元素
>         } else if (A[i] > B[j]) {
>             ++j;  // B[j] 太小，不可能匹配 A 当前及后续元素
>         } else {
>             // 两边当前值相同，属于交集；检查结果尾部避免重复加入。
>             if (C.empty() || C.back() != A[i]) {
>                 C.push_back(A[i]);  // 将共同元素追加到结果尾部
>             }
>             ++i;  // 相等时两边都消费当前元素
>             ++j;
>         }
>     }
>
>     return C;  // 返回新结果，原始 A、B 不会被修改
> }
> ```

这里使用标准库 `std::vector<int>` 表示顺序表结果。若输入表本身就是无重复的有序集合，去重判断可以省略。

### 方法二：单链表

同样使用两个指针扫描两个有序链表：

- 小者所在链表的指针前移；
- 相等时把该值追加到结果链表，两个指针都前移；
- 任一链表到达末尾时结束。

时间复杂度为 $O(m+n)$。若新建结果结点，额外空间为 $O(k)$，其中 $k$ 是交集元素个数。

## 9.4 复制双向链表的奇数位序结点

> [!warning] “奇数项”不等于“奇数值”
> 本题选择位序为 1、3、5……的结点。即使某个偶数位结点保存的值是奇数，也不能复制它。

**题意**：给定带头结点的双向链表 L，另建一个双向链表，只包含 L 中第 1、3、5、……个数据结点，保持相对次序不变。

这里的“奇数项”指**位序为奇数的结点**，不是数据值为奇数。

> [!example] 复制奇数位序结点
> ```cpp
> // 双向循环链表结点，带头结点；复制原表位序为 1、3、5……的数据。
> struct DNode {
>     int data;       // 保存数据值
>     DNode* prior;   // 指向前驱
>     DNode* next;    // 指向后继
> };
>
> DNode* CopyOddPositions(const DNode* head) {
>     if (head == nullptr) {
>         return nullptr;  // 原表没有头结点，无法复制
>     }
>
>     // 建立新表的头结点，并让空表的前后指针都回指自己。
>     DNode* result = new DNode{0, nullptr, nullptr};
>     result->next = result;
>     result->prior = result;
>
>     int position = 1;  // 第一个数据结点的位序为 1
>
>     for (const DNode* p = head->next; p != head; p = p->next) {
>         if (position % 2 == 1) {  // 只复制奇数位序，不判断数据值的奇偶
>             // 新结点放到结果表尾，先填写前驱和后继。
>             DNode* s = new DNode{p->data, result->prior, result};
>             result->prior->next = s;  // 原尾结点的后继改为新结点
>             result->prior = s;        // 头结点的 prior 更新为新尾结点
>         }
>         ++position;  // 每访问一个原数据结点，位序加 1
>     }
>
>     return result;  // 返回新链表，调用者负责释放它
> }
> ```

**复杂度**：遍历原链表一次，时间 $O(n)$；新表最多保存约一半的结点，额外空间 $O(n)$。

**前提**：原链表采用双向循环结构，头结点的 `next`、`prior` 均正确连接；新表也采用双向循环结构。

## 9.5 按访问频度调整双向循环链表

> [!important] 调整顺序
> 先确认找到目标结点，再增加频度；随后把结点从原位置摘下，按新频度找到插入位置，最后修复双向链接。查找失败时不得修改链表。

**题意**：每个结点增加 `freq`，初始为 0。每次执行 `Locate(L, x)` 找到值为 `x` 的结点后，将其 `freq` 加 1，并调整结点次序，使链表按 `freq` 非递增排列，频度高的结点靠近表头。

> [!example] 按访问频度重新定位结点
> ```cpp
> // 双向循环链表结点增加访问频度 freq，初始时应将 freq 设为 0。
> struct FreqNode {
>     int data;          // 数据值
>     int freq;          // 访问频度
>     FreqNode* prior;   // 前驱结点
>     FreqNode* next;    // 后继结点
> };
>
> // 找到值为 x 的结点后将其频度加 1，并按频度非递增顺序重新插入。
> FreqNode* LocateAndReorder(FreqNode* head, int x) {
>     if (head == nullptr) {
>         return nullptr;  // 无头结点，查找失败
>     }
>
>     FreqNode* p = head->next;  // 从第一个数据结点开始查找
>     while (p != head && p->data != x) {
>         p = p->next;  // 尚未回到头结点且值不匹配时继续向后找
>     }
>
>     if (p == head) {
>         return nullptr;  // 遍历一圈仍未找到 x
>     }
>
>     ++p->freq;  // 只有成功找到目标结点后才增加频度
>
>     // 先把 p 从原位置摘下，同时修复它前后两个结点的链接。
>     p->prior->next = p->next;
>     p->next->prior = p->prior;
>
>     // 找到第一个频度严格小于 p->freq 的结点，在它前面插入。
>     FreqNode* q = head->next;
>     while (q != head && q->freq >= p->freq) {
>         q = q->next;  // 跳过频度更高或相同的结点，保持同频结点相对次序
>     }
>
>     // 将 p 插到 q 前面，必须更新前后两端的链接。
>     p->prior = q->prior;  // p 的前驱设为 q 的原前驱
>     p->next = q;          // p 的后继设为 q
>     q->prior->next = p;   // 原前驱的后继改为 p
>     q->prior = p;         // q 的前驱改为 p
>
>     return p;  // 返回被访问并重新定位的结点
> }
> ```

**复杂度**：查找和重新定位都可能遍历整张表，时间复杂度 $O(n)$，额外空间 $O(1)$。

**易错点**：

- 必须先判断是否找到元素；找不到时不能修改频度。
- 结点摘下后，才能在新的链表顺序中寻找插入位置。
- `while (q != head && q->freq >= p->freq)` 会把结点放到所有同频结点之后；这样可以保持同频结点的相对次序。
- 链表的 `next` 与 `prior` 必须同时维护。

---

# 10. 易错点与考前速查

> [!abstract] 本章核心主线
> - **逻辑结构**回答“元素之间是什么关系”；
> - **存储结构**回答“这些关系如何在内存中表示”；
> - **顺序表**以连续存储换取随机访问；
> - **链表**以链接关系换取灵活插入、删除；
> - **算法复杂度**必须同时考虑定位、移动、链接和内存管理。

## 10.1 位序、下标和长度

| 概念 | 起点 | 示例 |
|---|---:|---|
| 线性表位序 | 1 | 第 1 个元素位序为 1 |
| C++ 数组下标 | 0 | 第 1 个元素下标为 0 |
| 顺序表插入合法范围 | 1 到 $n+1$ | $n+1$ 表示表尾插入 |
| 取值 / 修改 / 删除合法范围 | 1 到 $n$ | 不能操作不存在的第 $n+1$ 个元素 |

## 10.2 高频指针操作

| 场景 | 关键操作 | 需要注意 |
|---|---|---|
| 单链表插入 | `s->next = p->next; p->next = s;` | 先连接新结点后继 |
| 单链表删除 | `q = p->next; p->next = q->next; delete q;` | 先保存被删结点，再绕过并释放 |
| 单链表逆置 | 保存后继，再反转当前 `next` | 不可丢失未处理链段 |
| 双向链表插入 | 同时改四条链接关系 | `prior`、`next` 都要更新 |
| 双向链表删除 | 前驱越过目标，后继越过目标 | 两个方向都必须一致 |
| 循环链表遍历 | `p != head` | 不能等待 `nullptr` |
| 静态链表遍历 | `i = S[i].cur` | `cur` 是数组下标，不是地址 |

## 10.3 复杂度速记

- 顺序表按位序访问：$O(1)$。
- 顺序表按值查找：$O(n)$。
- 顺序表插入、删除：通常 $O(n)$，因为需要移动元素。
- 单链表按位序访问、查找：$O(n)$。
- 单链表已知前驱后的插入、删除：$O(1)$。
- 单链表按位序插入、删除：通常 $O(n)$，因为需要先定位。
- 有序表归并、求交集：双指针均摊扫描，$O(m+n)$。
- 单链表就地逆置：$O(n)$ 时间、$O(1)$ 额外空间。
- 两个按指数排序的稀疏多项式相加：$O(m+n)$。

## 10.4 最后检查清单

> [!tip] 自测建议
> 不要只背复杂度结论。建议遮住代码，自己写出顺序表插入、单链表删除、就地逆置和有序表交集，再用空表、首元素、尾元素和越界位置检查边界。

- [ ] 能区分逻辑结构、存储结构和抽象数据类型。
- [ ] 能说清线性表、长度、空表、位序、前驱、后继的定义。
- [ ] 熟悉 List 的初始化、销毁、查找、取值、插入、删除和遍历操作。
- [ ] 能写出顺序表插入、删除，并解释移动方向和复杂度。
- [ ] 能写出带头结点单链表的取值、插入、删除、清空和逆置。
- [ ] 能解释头指针、头结点、首元结点的区别。
- [ ] 能区分静态链表、循环链表、双向链表和双向循环链表。
- [ ] 能比较顺序表与链表的空间和时间特性。
- [ ] 能用双指针归并有序表、求有序表交集。
- [ ] 能解释稀疏多项式为什么需要同时保存系数和指数。
- [ ] 能根据指数比较完成多项式相加，并处理系数和为 0 的项。
- [ ] 能识别代码中的边界检查、指针更新顺序和内存释放位置。
- [ ] 所有代码使用标准 C++，不使用类型别名，普通数据类型默认使用 `int`。
