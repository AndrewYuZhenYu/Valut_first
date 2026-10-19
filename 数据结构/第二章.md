# 数据结构 第2章 线性表（最终定稿版）

> [!abstract] 本章定位
> 线性表是最简单、最常用的线性结构，是后续栈、队列、串、数组等结构的基础。本章围绕**“逻辑结构 → 顺序存储 → 链式存储 → 应用”**主线展开：
> 1. 逻辑结构上定义线性表及其 ADT；
> 2. 顺序存储上实现基本操作，分析时间/空间复杂度；
> 3. 链式存储（单链表、静态链表、循环链表、双向链表）上实现基本操作；
> 4. 以**一元多项式相加**为典型应用，说明存储结构选择对算法设计的影响。
>
> 核心目标：掌握两种存储结构的描述方法与基本操作实现，从**时间、空间复杂度**角度比较二者并选择合理存储结构。

---

## 2.1 线性表的类型定义

### 2.1.1 线性结构的特征

线性表（Linear List）是最简单的**线性结构**。线性结构是 $n$ 个数据元素的**有序（次序）集合**：

> [!important] 线性结构的四个特征
> 1. 集合中必存在唯一的一个“**第一元素**”；
> 2. 集合中必存在唯一的一个“**最后元素**”；
> 3. 除最后元素外，均有**唯一的后继**；
> 4. 除第一元素外，均有**唯一的前驱**。

### 2.1.2 线性表的定义

**线性表**是 $n$ 个数据元素 $a_1, a_2, \dots, a_n$ 的**有限序列**，记为：

$$(a_1, a_2, \dots, a_i, \dots, a_n)$$

其中 $a_i$ 可以是一个数、一个字母、一串字符、一页书，甚至更复杂的信息。

> [!example] 例：线性表的几种形式
> - 英文字母表：$(A, B, C, \dots, Z)$
> - 工资变化情况表：$(800, 1500, 2400, 4100, \dots, 20000)$
> - 学生信息表（数据元素由多个数据项组成）：

| 学号 | 姓名 | 性别 | 年龄 | 班级 |
| --- | --- | --- | --- | --- |
| 1 | 王小林 | 男 | 18 | 计科 0601 |
| 2 | 陈红 | 女 | 20 | 计科 0601 |
| 3 | 刘建平 | 男 | 21 | 计科 0601 |
| 4 | 张立立 | 男 | 17 | 计科 0601 |

> [!important] 要点
> 线性表中的数据元素可以多种多样，但**同一线性表中的元素必定具有相同特性**（属同一数据对象），相邻数据元素之间存在**序偶关系**。

### 2.1.3 基本术语与关系

若线性表记为 $(a_1, \dots, a_{i-1}, a_i, a_{i+1}, \dots, a_n)$：

- $a_{i-1}$ 是 $a_i$ 的**直接前驱**，$a_{i+1}$ 是 $a_i$ 的**直接后继**；
- 第一个元素无前驱，最后一个元素无后继，其它元素仅有一个直接前驱和一个直接后继。

| 术语 | 含义 |
| --- | --- |
| **表长** | 元素个数 $n$（$n \ge 0$） |
| **空表** | $n = 0$ 时的线性表 |
| **位序** | 元素 $a_i$ 的位置 $i$。**位序从 1 开始**（与数组下标从 0 开始不同） |

### 2.1.4 线性表的抽象数据类型

```
ADT List
{
    数据对象:
        D = { aᵢ | aᵢ ∈ ElemSet, i = 1, 2, ..., n, n ≥ 0 }
    数据关系:
        R1 = { <aᵢ₋₁, aᵢ> | aᵢ₋₁, aᵢ ∈ D, i = 2, ..., n }
    基本操作:
        结构初始化操作、结构销毁操作、引用型操作、加工型操作
} ADT List
```

**结构初始化 / 销毁**

```
InitList(&L)
    操作结果: 构造一个空的线性表 L
DestroyList(&L)
    初始条件: 线性表 L 已存在
    操作结果: 销毁线性表 L
```

**引用型操作**

| 操作 | 初始条件 | 操作结果 |
| --- | --- | --- |
| `ListEmpty(L)` | L 已存在 | 空表返回 TRUE，否则 FALSE |
| `ListLength(L)` | L 已存在 | 返回元素个数 |
| `PriorElem(L, cur_e, &pre_e)` | L 已存在 | 若 `cur_e` 是 L 的元素且非首，用 `pre_e` 返回前驱，否则操作失败 |
| `NextElem(L, cur_e, &next_e)` | L 已存在 | 若 `cur_e` 是 L 的元素且非尾，用 `next_e` 返回后继，否则操作失败 |
| `GetElem(L, i, &e)` | $1 \le i \le \text{ListLength}(L)$ | 用 `e` 返回第 $i$ 个元素 |
| `LocateElem(L, e, compare())` | L 已存在，`compare()` 为判定函数 | 返回第 1 个满足关系的元素位序，否则返回 0 |
| `ListTraverse(L, visit())` | L 已存在，`visit()` 为访问函数 | 依次对每个元素调用 `visit()` |

**加工型操作**

| 操作 | 初始条件 | 操作结果 |
| --- | --- | --- |
| `ClearList(&L)` | L 已存在 | 重置为空表 |
| `PutElem(&L, i, e)` | $1 \le i \le \text{ListLength}(L)$ | 将第 $i$ 个元素赋值为 `e` |
| `ListInsert(&L, i, e)` | $1 \le i \le \text{ListLength}(L)+1$ | 在第 $i$ 个元素前插入 `e`，长度增 1 |
| `ListDelete(&L, i, &e)` | L 非空，$1 \le i \le \text{ListLength}(L)$ | 删除第 $i$ 个元素并用 `e` 返回其值，长度减 1 |

> [!note] 抽象操作与具体实现
> 以上只是定义在**逻辑结构**上的抽象运算，只关心“**做什么**”；“**怎样实现**”依赖于所选定的**存储结构**。更复杂的运算（合并、拆分、复制、排序）均可利用上述基本运算实现。

### 2.1.5 线性表 ADT 的应用举例

> [!example] 例 1：求集合的并集 $A = A \cup B$
> 集合 A、B 分别用线性表 LA、LB 表示，求新的 $A = A \cup B$。
>
> **演绎**：扩大 LA，将存在于 LB 中而不存在于 LA 中的元素插入 LA。
>
> **步骤**：① 依次取 LB 的元素 `GetElem(LB, i) → e`；② 在 LA 中查找 `LocateElem(LA, e, equal())`；③ 不存在则 `ListInsert(LA, n+1, e)`。
>
> ```c
> void union(struct SqList &La, struct SqList Lb)
> {
>     int La_len = ListLength(La);
>     int Lb_len = ListLength(Lb);
>     int i, e;
>     for (i = 1; i <= Lb_len; i++)
>     {
>         GetElem(Lb, i, e);              /* 取 Lb 中第 i 个元素赋给 e */
>         if (!LocateElem(La, e, equal())) /* La 中不存在 e，则插入 */
>             ListInsert(La, ++La_len, e);
>     }
> } /* union */
> ```

> [!example] 例 2：构造纯集合（去重）
> 已知非纯集合 B，构造纯集合 A，使 A 包含 B 中所有值各不相同的元素。
>
> **方法一**：扫描 LB，在 LA 中查找，不存在则插入。
> ```c
> void union(struct SqList &La, struct SqList Lb)
> {
>     int La_len, Lb_len, i, e;
>     InitList(La);
>     La_len = ListLength(La);
>     Lb_len = ListLength(Lb);
>     for (i = 1; i <= Lb_len; i++)
>     {
>         GetElem(Lb, i, e);
>         if (!LocateElem(La, e, equal()))
>             ListInsert(La, ++La_len, e);
>     }
> }
> ```
>
> **方法二（改进）**：以**有序表**表示集合。若表中元素可比较且依值**非递减或非递增有序排列**（$a_i \ge a_{i-1}$ 或 $a_i \le a_{i-1}$，$i=2,\dots,n$），称该表为**有序表（Ordered List）**。
>
> 例 $(2, 3, 3, 5, 6, 6, 6, 8, 12)$：值相同的元素必定相邻，A 的元素依值从小到大顺序插入。
> ```c
> void purge(struct SqList &La, struct SqList Lb)
> {
>     int La_len, Lb_len, i, e, en;
>     InitList(La);
>     La_len = ListLength(La);
>     Lb_len = ListLength(Lb);
>     for (i = 1; i <= Lb_len; i++)
>     {
>         GetElem(Lb, i, e);
>         /* en 为 La 当前最后一个元素；依赖 ListEmpty 短路保护 */
>         if (ListEmpty(La) || !equal(en, e))
>         {
>             ListInsert(La, ++La_len, e);
>             en = e;
>         }
>     }
> } /* purge */
> ```
> **改进点**：只需与 LA 最后一个元素比较即可判重，`O(n^2)` 降为 `O(n)`。

> [!example] 例 3：两个有序表归并
> LA、LB 非递减有序，归并为新表 LC，仍非递减有序。
>
> 如 $LA=(3,5,8,11)$，$LB=(2,6,8,9,11,15,20)$，则 $LC=(2,3,5,6,8,8,9,11,11,15,20)$。
>
> 设 $i,j,k$ 分别指向三表：$a \le b$ 取 $a$，否则取 $b$。
>
> ```c
> void MergeList(struct SqList La, struct SqList Lb,
>                struct SqList &Lc)
> {
>     int i = 1, j = 1, k = 0;
>     int ai, bj;
>     int La_len = ListLength(La), Lb_len = ListLength(Lb);
>     InitList(Lc);
>     while (i <= La_len && j <= Lb_len)   /* La 和 Lb 均非空 */
>     {
>         GetElem(La, i, ai);
>         GetElem(Lb, j, bj);
>         if (ai <= bj)
>         {
>             ListInsert(Lc, ++k, ai);
>             ++i;
>         }
>         else
>         {
>             ListInsert(Lc, ++k, bj);
>             ++j;
>         }
>     }
>     while (i <= La_len) { GetElem(La, i++, ai); ListInsert(Lc, ++k, ai); }
>     while (j <= Lb_len) { GetElem(Lb, j++, bj); ListInsert(Lc, ++k, bj); }
> } /* MergeList */
> ```
> 顺序表上每次 `ListInsert` 有移动开销，整体 $O(n^2)$；改用链表并直接改指针可优化到 $O(m+n)$（见 2.3.2）。

---

## 2.2 线性表的顺序表示和实现

### 2.2.1 顺序存储结构——顺序映象

以 $x$、$y$ 的存储位置关系表示逻辑关系 $<x,y>$。最简单的方法是：**令 $y$ 的存储位置与 $x$ 的存储位置相邻**。

**顺序存储结构**：用一组**地址连续的存储单元**依次存放线性表中的数据元素。

```
a₁  a₂  ...  aᵢ₋₁  aᵢ  ...  aₙ
```

线性表的起始地址称作**基地址**。

以“存储位置相邻”表示 $<a_{i-1}, a_i>$。设每个元素占 $L$ 个存储单元：

$$LOC(a_{i+1}) = LOC(a_i) + L$$

$$LOC(a_i) = LOC(a_1) + (i-1) \times L$$

> [!important] 顺序存储结构的特点
> - 相邻元素物理位置也相邻，即以**物理位置相邻**表示**逻辑关系相邻**；
> - 每个元素的存储位置与起始位置相差一个和**序号成正比**的常数；
> - 只要确定起始位置，任一元素都可**随机存取**。**顺序存储结构是随机存取的存储结构**。

### 2.2.2 顺序存储结构的 C 语言描述

```c
#define LIST_INIT_SIZE 80  /* 初始分配量 */
#define LISTINCREMENT 10   /* 分配增量 */

struct SqList {
    int *elem;     /* 存储空间基址 */
    int length;    /* 当前长度 */
    int listsize;  /* 当前分配容量（以 sizeof(int) 为单位） */
}; /* 顺序表 */
```

> [!note] 存储结构示意
> | 存储地址 | 内存状态 | 序号 |
> | --- | --- | --- |
> | $LOC(a_1)$ | $a_1$ | 1 |
> | $LOC(a_1)+L$ | $a_2$ | 2 |
> | $\dots$ | $\dots$ | $\dots$ |
> | $LOC(a_1)+L(i-1)$ | $a_i$ | $i$ |
> | $\dots$ | $\dots$ | $\dots$ |
> | $LOC(a_1)+L(n-1)$ | $a_n$ | $n$ |
> | $\dots$ | 空闲 | — |
> | $LOC(a_1)+(maxlen-1)L$ | 空闲 | — |

### 2.2.3 基本操作在顺序表中的实现

#### 结构初始化

```c
int InitList_Sq(struct SqList &L)
/* 构造一个空的线性表 */
{
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L.elem) exit(OVERFLOW);   /* 存储分配失败 */
    L.length = 0;                  /* 空表长度为零 */
    L.listsize = LIST_INIT_SIZE;   /* 初始存储容量 */
    return OK;
} /* InitList_Sq */
```

#### 扩展容量

```c
int ExtendList_Sq(struct SqList &L)
/* 扩展线性表 L 的容量 */
{
    int *newbase;
    /* 注意：realloc 失败返回 NULL，原指针仍有效，故先用临时变量 */
    newbase = (int *)realloc(L.elem,
                             (L.listsize + LISTINCREMENT) * sizeof(int));
    if (!newbase) exit(OVERFLOW);
    L.elem = newbase;
    L.listsize += LISTINCREMENT;
    return OK;
} /* ExtendList_Sq */
```

- **时间复杂度**：均摊 $O(1)$（`realloc` 可能搬迁数据）。

#### 查找（定位）

将顺序表元素逐个与 `e` 比较。

```c
int LocateElem_Sq(struct SqList L, int e,
                  int (*compare)(int, int))
/* 在顺序表中查询第一个满足判定条件的元素，
   存在则返回位序，否则返回 0 */
{
    int i = 1;           /* i 初值为第 1 元素的位序 */
    int *p = L.elem;     /* p 初值为第 1 元素的存储位置 */
    while (i <= L.length && !(*compare)(*p++, e))
        ++i;
    if (i <= L.length) return i;
    else return 0;
} /* LocateElem_Sq */
```

- **时间复杂度**：$O(\text{ListLength}(L))$；空表时 `L.length=0`，循环条件不成立，安全。

#### 插入操作 `ListInsert(&L, i, e)`

> [!important] 插入时的逻辑结构变化
> $$(a_1, \dots, a_{i-1}, a_i, \dots, a_n) \to (a_1, \dots, a_{i-1}, e, a_i, \dots, a_n)$$
> 有序对 $<a_{i-1}, a_i>$ 变为 $<a_{i-1}, e>$ 与 $<e, a_i>$。
>
> **物理实现**：从表尾开始，将第 $i$ 个位置及之后的元素**依次右移一位**，再在位置 $i$ 处写入 `e`。

```c
/* 指针版本，更接近教材 */
int ListInsert_Sq(struct SqList &L, int i, int e)
/* 1 ≤ i ≤ L.length+1 */
{
    int *q = &(L.elem[i - 1]);   /* q 指示插入位置 */
    int *p;
    for (p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;           /* 右移 */
    *q = e;
    ++L.length;
    return OK;
} /* ListInsert_Sq */
```

```c
/* 下标版本，更直观 */
int ListInsert_Sq(struct SqList &L, int i, int e)
{
    int j;
    if (i < 1 || i > L.length + 1) return ERROR;  /* 位置不合法 */
    for (j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}
```

> [!note] 两版本等价
> 指针版与下标版逻辑等价；指针版强调内存操作，下标版强调逻辑下标。实现时**必须先检查 `i` 是否在 $[1, L.length+1]$ 内**。

> [!important] 插入移动元素平均次数
> 设在第 $i$ 个元素前插入的概率为 $p_i$，则移动次数的期望为：
> $$E_{is} = \sum_{i=1}^{n+1} p_i (n - i + 1)$$
> 若各位置插入等概率（$p_i = \frac{1}{n+1}$），则：
> $$E_{is} = \frac{1}{n+1}\sum_{i=1}^{n+1}(n-i+1) = \frac{n}{2}$$
> 即平均约移动**一半元素**。

#### 删除操作 `ListDelete(&L, i, &e)`

> [!important] 删除时的逻辑结构变化
> $$(a_1, \dots, a_{i-1}, a_i, a_{i+1}, \dots, a_n) \to (a_1, \dots, a_{i-1}, a_{i+1}, \dots, a_n)$$
> 有序对 $<a_{i-1}, a_i>$、$<a_i, a_{i+1}>$ 变为 $<a_{i-1}, a_{i+1}>$。
>
> **物理实现**：将被删元素之后的元素**依次左移一位**，表长减 1。

```c
int ListDelete_Sq(struct SqList &L, int i, int &e)
{
    int *p, *q;
    if ((i < 1) || (i > L.length)) return ERROR;   /* 位置不合法 */
    p = &(L.elem[i - 1]);          /* p 为被删元素位置 */
    e = *p;                        /* 被删值赋给 e */
    q = L.elem + L.length - 1;     /* 表尾元素位置 */
    for (++p; p <= q; ++p)
        *(p - 1) = *p;             /* 左移 */
    --L.length;
    return OK;
} /* ListDelete_Sq */
```

> [!important] 删除移动元素平均次数
> 设删除第 $i$ 个元素的概率为 $q_i$，则：
> $$E_{dl} = \sum_{i=1}^{n} q_i (n - i)$$
> 若各位置删除等概率（$q_i = \frac{1}{n}$），则：
> $$E_{dl} = \frac{1}{n}\sum_{i=1}^{n}(n-i) = \frac{n-1}{2}$$
> 即平均约移动**一半元素**。

> [!note] 插入/删除移动次数小结
> 时间主要耗费在**移动元素**上，移动次数依赖于表长 $n$ 和位置 $i$：
> - $i=1$：全部元素移动，$n$（插）或 $n-1$（删）；
> - $i=L.\text{length}+1$（插）或 $L.\text{length}$（删）：不需移动。
>
> 平均移动一半元素，**时间复杂度 $O(n)$**。

### 2.2.4 顺序存储结构的优缺点

| 优点 | 缺点 |
| --- | --- |
| (1) 无需为表示关系而增加额外空间，**存储密度高**（存储密度 = 1） | (3) **插入和删除**须移动大量元素，效率低 |
| (2) **随机存取**任一元素，存储位置公式简单直观 | (4) 必须**预先分配连续空间**：估小溢出，估大浪费 |

> [!note] 存储密度
> **存储密度 = 结点中数据本身占用的存储量 / 结点结构占用的存储量**。密度越大，空间利用率越高。顺序表 = 1，链式结构 < 1。

---

## 2.3 线性表的链式表示和实现

### 2.3.1 单链表

**链式存储结构的特点**：用一组**任意的存储单元**存储元素（可连续，也可不连续）。

为表示 $a_i$ 与 $a_{i+1}$ 的逻辑关系，一个**结点**包含：

- **数据域 `data`**：存放 $a_i$；
- **指针域 `next`**：指向 $a_{i+1}$ 所在结点。

```
+-------+-------+
| data  | next  |
+-------+-------+
 数据域  指针域
```

**以元素 + 指针 = 结点**。$n$ 个结点通过指针链接成**单链表**。

> [!example] 例：线性表 (ZHAO, QIAN, SUN, LI, ZHOU, WU, ZHENG, WANG) 的链式存储
> | 存储地址 | 数据域 | 指针域 |
> | --- | --- | --- |
> | 1 | LI | 43 |
> | 7 | QIAN | 13 |
> | 13 | SUN | 1 |
> | 19 | WANG | NULL |
> | 25 | WU | 37 |
> | 31 | ZHAO | 7 |
> | 37 | ZHENG | 19 |
> | 43 | ZHOU | 25 |
>
> - **头指针** `H` 指示第一个结点的存储位置；
> - 最后一个结点的指针为**空（NULL）**。
>
> 逻辑状态：
> ```
> H → [ZHAO] → [QIAN] → [SUN] → [LI]
>                                 ↓
>     [WANG] ← [ZHENG] ← [WU] ← [ZHOU]
> ```
> 逻辑相邻元素的物理位置**不要求紧邻**；单链表由**头指针唯一确定**。

#### 头指针与头结点

> [!note] 头结点作用
> - 以第一个数据元素 $a_1$ 的地址作为链表地址，称为**头指针**；
> - 为操作方便，可在第一个结点前**虚加一个“头结点”**，其 `next` 指向第一个数据结点；
> - **好处**：使**在首元素前插入/删除首元素**与普通位置操作统一，**无需特判**空表与首元素；
> - 空表时头结点的 `next` 为空。

#### 结点与单链表的 C 语言描述

```c
struct LNode {
    int data;           /* 数据域 */
    struct LNode *next; /* 指针域 */
};

/* L 为单链表头指针 */
struct LNode *L;
```

> [!note] 单链表是非随机存取结构
> 链表中任何两个元素存储位置无固定联系，每个元素的存储位置包含在其直接前驱的信息中。**取第 $i$ 个元素必须从头指针出发寻找**，所以单链表是**顺序存取**（非随机存取）的存储结构。

### 2.3.2 单链表中基本操作的实现

#### 取第 $i$ 个元素 `GetElem_L(L, i, &e)`

移动指针，比较当前位置 $j$ 与 $i$，令 `p` 始终指向第 $j$ 个数据结点。

```c
int GetElem_L(struct LNode *L, int i, int &e)
/* L 是带头结点的链表头指针，用 e 返回第 i 个元素 */
{
    struct LNode *p = L->next;
    int j = 1;                /* p 指向第一个结点 */
    while (p && j < i)        /* 顺指针向后查找 */
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;   /* 第 i 个元素不存在 */
    e = p->data;
    return OK;
} /* GetElem_L */
```

- **时间复杂度**：$O(n)$。

#### 插入操作 `ListInsert_L(&L, i, e)`

> [!important] 插入时的逻辑结构变化
> 有序对 $<a_{i-1}, a_i>$ 变为 $<a_{i-1}, e>$ 和 $<e, a_i>$。
>
> 链表插入**只需修改指针**；要在第 $i$ 个结点前插入，修改的是**第 $i-1$ 个结点**的指针。基本操作：**找到第 $i-1$ 个结点，修改其后继指针**。

```c
int ListInsert_L(struct LNode *&L, int i, int e)
/* L 为带头结点的单链表头指针，在第 i 个结点前插入 e */
{
    struct LNode *p = L, *s;
    int j = 0;
    while (p && j < i - 1)    /* 寻找第 i-1 个结点 */
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;   /* i 大于表长或小于 1 */

    s = (struct LNode *)malloc(sizeof(struct LNode)); /* 生成新结点 */
    s->data = e;
    s->next = p->next;       /* 顺序不能颠倒！先挂后继 */
    p->next = s;             /* 再改前驱 */
    return OK;
} /* ListInsert_L */
```

- **时间复杂度**：$O(n)$（查找 $i-1$ 结点）；若已持有 $i-1$ 指针则 $O(1)$。

#### 删除操作 `ListDelete_L(&L, i, &e)`

> [!important] 删除时的逻辑结构变化
> 有序对 $<a_{i-1}, a_i>$、$<a_i, a_{i+1}>$ 变为 $<a_{i-1}, a_{i+1}>$。
>
> 基本操作：**找到第 $i-1$ 个结点，修改其后继指针**。

```c
int ListDelete_L(struct LNode *&L, int i, int &e)
/* 删除以 L 为头指针（带头结点）的单链表第 i 个结点 */
{
    struct LNode *p = L, *q;
    int j = 0;
    while (p->next && j < i - 1)   /* 寻找第 i-1 个结点 */
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;  /* 位置不合理 */

    q = p->next;
    p->next = q->next;   /* 删除并释放结点 */
    e = q->data;
    free(q);
    return OK;
} /* ListDelete_L */
```

- **时间复杂度**：$O(n)$。

> [!note] malloc 与 free
> - `p = (struct LNode *)malloc(sizeof(struct LNode));`：由系统生成一个结点，起始位置赋给 `p`；
> - `free(q);`：由系统回收一个结点。
>
> 因此**单链表是动态结构**，可用存储空间被多个链表共享，每个链表按需动态生成。建立链式存储的过程就是**动态生成链表**的过程。

#### 建立单链表

链表是动态结构，不需预先分配空间，生成过程是结点“**逐个插入**”的过程。

> [!example] 例：逆位序输入 $n$ 个数据元素的值，建立带头结点的单链表
> **步骤**：① 建立“空表”；② 输入 $a_n$ 建结点插入；③ 输入 $a_{n-1}$ 建结点插入表头；④ 依次类推直到 $a_1$。
>
> ```c
> void CreateList_L(struct LNode *&L, int n)
> /* 逆序输入 n 个数据元素，建立带头结点的单链表 */
> {
>     struct LNode *p;
>     int i;
>     L = (struct LNode *)malloc(sizeof(struct LNode));
>     L->next = NULL;             /* 先建立带头结点的空表 */
>     for (i = n; i > 0; --i)
>     {
>         p = (struct LNode *)malloc(sizeof(struct LNode));
>         scanf("%d", &p->data);  /* 输入元素值 */
>         p->next = L->next;
>         L->next = p;            /* 插入到表头 */
>     }
> } /* CreateList_L */
> ```
>
> **时间复杂度**：$O(n)$（$n$ 次头插，每次 $O(1)$）。

#### 合并两个有序链表

> [!example] 例：将两个非递减有序的单链表 La、Lb 合并为有序单链表 Lc
> 设 `pa`、`pb` 分别指向 La、Lb 当前结点，`pc` 为结果链表工作指针。
>
> ```c
> void MergeList_L(struct LNode *La, struct LNode *Lb,
>                  struct LNode *&Lc)
> /* 合并 La 和 Lb，结果存入 Lc（指针链接版本） */
> {
>     struct LNode *pa = La->next, *pb = Lb->next, *pc;
>     Lc = (struct LNode *)malloc(sizeof(struct LNode)); /* 头结点 */
>     Lc->next = NULL;
>     pc = Lc;
>     while (pa != NULL && pb != NULL)
>     {
>         if (pa->data <= pb->data)
>         {
>             pc->next = pa;
>             pc = pa;
>             pa = pa->next;
>         }
>         else
>         {
>             pc->next = pb;
>             pc = pb;
>             pb = pb->next;
>         }
>     }
>     /* 串接剩余段 */
>     pc->next = (pa != NULL) ? pa : pb;
> } /* MergeList_L */
> ```
>
> > [!tip] 与 2.1.5 例 3 对比
> > 顺序表上 `ListInsert` 逐个插入，每次 $O(n)$，整体 $O((m+n)^2)$；链表直接改指针连接，整体 $O(m+n)$。**存储结构决定算法效率**。

#### 清空单链表 `ClearList(&L)`

```c
void ClearList(struct LNode *&L)
/* 将单链表重新置为一个空表 */
{
    struct LNode *p;
    while (L->next)
    {
        p = L->next;
        L->next = p->next;
        free(p);
    }
    L->next = NULL;
} /* ClearList */
```

- **时间复杂度**：$O(n)$。

### 2.3.3 其它形式的链表

#### 静态链表

借用**一维数组**描述线性链表，称**静态链表**，便于在不设“指针”类型的高级语言中使用链表。

```c
#define MAXSIZE 1000  /* 链表最大长度 */

struct component {
    int data;
    int cur;  /* 指示结点在数组中的相对位置（游标） */
};
struct component SLinkList[MAXSIZE];
```

数组的一个分量表示一个结点，用**游标（`cur`）**代替指针指示结点在数组中的位置。**数组第 0 个分量可看成头结点**，其 `cur` 指示链表第一个结点。

> [!note] 示例结构（示意）
> 原始状态：`S[0].cur = 1`，`S[1]=(ZHAO,2)`，`S[2]=(QIAN,3)`，…，`S[8]=(WANG,0)`；
> 在 `LI` 后插入 `SHI`、删除 `ZHENG` 后，需：
> - 从**备用链表**取一个空闲分量存放 `SHI`，修改 `LI` 的 `cur` 指向 `SHI`，`SHI.cur` 指向原 `LI` 的后继；
> - 删除 `ZHENG` 时，将其从逻辑链摘下，并把该分量**归还到备用链表**。
>
> 插入删除**不移动元素，仅修改游标**，保持链式结构优点。

> [!important] 静态链表要点
> - 仍需**预先分配较大空间**，但插入删除**不移动元素，仅改指针**，保留链式结构主要优点；
> - 与指针型链表相区别，称**静态链表**；
> - 若第 $i$ 个分量表示链表第 $k$ 个结点，则 `S[i].cur` 指示第 $k+1$ 个结点位置；
> - **指针后移**（类似 `p = p->next`）用 `i = S[i].cur` 实现；
> - **分辨空闲结点**：将所有未用和被删分量用游标链成**备用链表**；插入时从备用链表取第一个结点，删除时归还。

**静态链表定位**：

```c
int LocateElem_SL(struct component S[], int e)
/* 在静态单链线性表 S 中查找第 1 个值为 e 的元素。
   若找到，返回它在数组中的下标；否则返回 0。
   注意：返回的是数组下标（0 号是头结点），不严格等于"位序" */
{
    int i = S[0].cur;             /* i 指示第一个数据结点 */
    while (i && S[i].data != e)
        i = S[i].cur;             /* 顺链查找 */
    return i;
} /* LocateElem_SL */
```

> [!warning] 返回值语义
> 顺序表 / 单链表 `LocateElem` 返回的“位序”从 1 开始；而静态链表这里返回的是**数组下标**（1 才是第一个数据元素）。使用返回值时**不要混淆**。

**静态链表插入删除**：指针修改与单链表基本相同，但 `malloc`/`free` 需**用户自己实现**（从备用链表取结点 / 归还结点到备用链表）。

#### 循环链表

**最后一个结点的指针域又指回头结点**的链表。

```
head → [头结点] → [a₁] → [a₂] → ... → [aₙ]
          ↑                              |
          └──────────────────────────────┘
```

- 和单链表的差别仅在于：**判尾条件不再是“后继为空”，而是“后继为头结点”**；
- **空循环链表（带头结点）**：`L->next == L`；
- **单结点循环链表（带头结点）**：`L->next->next == L`。

#### 双向链表

结点有**两个指针域**：分别指向直接后继和直接前驱。

```
       ┌───────────────────┐
       ↓                   │
... → [a] → ... → [b] → ... → [c] → ...
       ←         ←         ←
```

```c
struct DuLNode {
    int data;                /* 数据域 */
    struct DuLNode *prior;   /* 指向前驱 */
    struct DuLNode *next;    /* 指向后继 */
};
```

**双向链表操作特点**：

- **查询与单链表相同**：`Length`、`Get`、`Locate` 只涉及一个方向指针，算法描述与单链表相同；
- **插入和删除与单链表不同**：需同时修改**两个方向**上的指针。

> [!important] 双向链表插入（在 `p` 所指结点前插入 `s`）
> ```c
> s->prior = p->prior;
> p->prior->next = s;
> s->next = p;
> p->prior = s;
> ```
> 四步操作：**先处理前驱侧两条指针，再处理后继侧两条**。`s->prior = p->prior` 与 `p->prior->next = s` 的顺序不能反，否则会丢失前驱指针。

> [!important] 双向链表删除（删除 `p` 所指结点）
> ```c
> p->prior->next = p->next;
> p->next->prior = p->prior;
> free(p);
> ```
> 两条指针修改顺序可互换，但 **`free(p)` 必须最后执行**。

**带头结点双向循环链表上的插入和删除**：

```c
/* 假设 GetElem_DuL(L, i) 返回第 i 个元素的指针，不存在返回 NULL */
int ListInsert_DuL(struct DuLNode *&L, int i, int e)
/* 在带头结点的双向循环链表 L 中第 i 个结点前插入新元素 e，
   1 ≤ i ≤ 表长 + 1 */
{
    struct DuLNode *p, *s;
    p = GetElem_DuL(L, i);
    if (!p) return ERROR;   /* p = NULL，第 i 个元素不存在 */
    s = (struct DuLNode *)malloc(sizeof(struct DuLNode));
    if (!s) return ERROR;   /* 存储空间分配失败 */
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
} /* ListInsert_DuL */
```

```c
int ListDelete_DuL(struct DuLNode *&L, int i, int &e)
/* 删除带头结点的双向循环链表 L 中第 i 个元素，1 ≤ i ≤ 表长 */
{
    struct DuLNode *p;
    p = GetElem_DuL(L, i);
    if (!p) return ERROR;   /* p = NULL，第 i 个元素不存在 */
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
} /* ListDelete_DuL */
```

- **时间复杂度**：均为 $O(n)$（瓶颈在 `GetElem_DuL` 查找）。

#### 双向循环链表

- **非空表**：头结点的 `prior` 指向尾结点，尾结点的 `next` 指向头结点；
- **空表**：头结点的 `prior` 和 `next` 均指向自己（`L->prior == L && L->next == L`）。

### 2.3.4 改进的线性链表类型

```c
struct LNode {              /* 结点类型 */
    int data;
    struct LNode *next;
};

/* 链表类型 */
struct LinkList {
    struct LNode *head, *tail;  /* 分别指向头结点和尾结点 */
    int len;                    /* 指示链表长度 */
    struct LNode *current;      /* 指向当前被访问结点，初始指向头结点 */
};
```

```
head → [头结点] → [a₁] → ... → [aᵢ] → ... → [aₙ] → NULL
                     ↑ current        ↑ tail
```

**辅助操作**：

| 操作 | 说明 | 时间复杂度 |
| --- | --- | --- |
| `MakeNode(struct LNode *&p, int e)` | 分配由 `p` 指向、值为 `e` 的结点，成功 OK，失败 ERROR | — |
| `FreeNode(struct LNode *&p)` | 释放 `p` 所指结点 | — |

**结构初始化和销毁**：

| 操作 | 说明 | 时间复杂度 |
| --- | --- | --- |
| `InitList(struct LinkList &L)` | 构造空链表，头/尾/当前指针均指向头结点，表长为零 | $O(1)$ |
| `DestroyList(struct LinkList &L)` | 销毁链表 | $O(n)$ |

**引用型操作**：

| 操作 | 说明 | 时间复杂度 |
| --- | --- | --- |
| `ListEmpty(L)` | 判表空 | $O(1)$ |
| `ListLength(L)` | 求表长 | $O(1)$ |
| `Prior(L)` | 当前指针指向前驱 | $O(n)$ |
| `Next(L)` | 当前指针指向后继 | $O(1)$ |
| `GetCurElem(L)` | 返回当前指针所指元素 | $O(1)$ |
| `LocatePos(L, i)` | 当前指针指向第 $i$ 个结点 | $O(n)$ |
| `LocateElem(L, e, compare())` | 移动当前指针到第 1 个满足条件的元素 | $O(n)$ |
| `ListTraverse(L, visit())` | 依次对每个元素调用 `visit()` | $O(n)$ |

**加工型操作**：

| 操作 | 说明 | 时间复杂度 |
| --- | --- | --- |
| `ClearList(&L)` | 重置为空表 | $O(n)$ |
| `SetCurElem(&L, e)` | 更新当前指针所指元素 | $O(1)$ |
| `Append(&L, s)` | 在表尾后链接一串结点 | $O(s)$ |
| `InsAfter(&L, e)` | 将 `e` 插入在当前指针之后 | $O(1)$ |
| `DelAfter(&L, &e)` | 删除当前指针之后的结点 | $O(1)$ |

> [!example] 例：`InsAfter` 和 `DelAfter`
> ```c
> int InsAfter(struct LinkList &L, int e)
> /* 若当前指针在链表中，则将 e 插入在当前指针所指结点之后 */
> {
>     struct LNode *s;
>     if (!L.current) return ERROR;
>     s = (struct LNode *)malloc(sizeof(struct LNode));
>     if (!s) return ERROR;
>     s->data = e;
>     s->next = L.current->next;
>     L.current->next = s;
>     if (L.tail == L.current)   /* 原当前结点是尾结点 */
>         L.tail = s;            /* 新结点成为新尾 */
>     L.current = s;
>     L.len++;
>     return OK;
> } /* InsAfter */
> ```
>
> ```c
> int DelAfter(struct LinkList &L, int &e)
> /* 若当前指针及其后继在链表中，删除当前指针之后的结点 */
> {
>     struct LNode *q;
>     if (!(L.current && L.current->next)) return ERROR;
>     q = L.current->next;
>     L.current->next = q->next;
>     if (L.tail == q)           /* 被删结点恰为尾结点 */
>         L.tail = L.current;
>     e = q->data;
>     free(q);
>     return OK;
> } /* DelAfter */
> ```

> [!note] `current` 与 `tail` 的维护
> - `L.current` 表示“当前被访问结点”，随 `Prior`/`Next`/`Locate*`/`InsAfter` 等操作移动；
> - `L.tail` 在**插入尾结点之后**和**删除尾结点**时必须同步更新，否则后续 `Append` 等操作会出错。

### 2.3.5 有序表类型

```
ADT Ordered_List
{
    数据对象:
        S = { xᵢ | xᵢ ∈ OrderedSet, i = 1, 2, ..., n, n ≥ 0 }
    数据关系:
        R = { <xᵢ₋₁, xᵢ> | xᵢ₋₁, xᵢ ∈ S, xᵢ₋₁ ≤ xᵢ, i = 2, 3, ..., n }
    ...
}
```

**有序表特有的两个操作**（其余与一般线性链表一致）：

```
LocateElem(LinkList L, int e, struct LNode *&q,
           int (*compare)(int, int))
    初始条件: 有序表 L 已存在
    操作结果:
        若 L 中存在元素 e，则 q 指示 L 中第一个值为 e 的结点，返回 TRUE；
        否则 q 指示第一个大于 e 的元素的前驱，返回 FALSE
```

> [!example] 例：在有序表 $(12, 23, 34, 45, 56, 67, 78, 89, 98)$ 中的 `LocateElem`
> - 若 `e = 45`：`q` 指向值为 45 的结点（成功 TRUE）；
> - 若 `e = 88`：`q` 指向 78 所在结点（88 的前驱），表示 88 应插在 `q` 之后（失败 FALSE）。

```
OrderInsert(LinkList L, int e, int (*compare)(int, int))
    初始条件: 有序表 L 已存在
    操作结果: 按 compare() 约定，将值为 e 的结点插入到 L 的适当位置
```

> [!tip] 有序表的优势
> `LocateElem` 返回“插入位置前驱指针”，`OrderInsert` 可直接修改指针完成插入，避免从表头重新查找，时间复杂度 $O(n)$（查找开销）。

### 2.3.6 链式存储结构的优缺点

| 优点 | 缺点 |
| --- | --- |
| (1) **插入删除**无须移动元素，只需修改指针 | (4) **不能随机访问**，访问时间与元素位置有关 |
| (2) 不需要连续存储空间，有可用结点即可 | — |
| (3) 表的规模**易扩充**（动态分配） | — |

### 2.3.7 两种存储结构的综合比较

> [!important] 顺序表 vs 链表
> **① 存储空间**
> - 顺序表**预先分配**：估大浪费，估小溢出；
> - 链表**动态分配**：有内存即可申请，不会溢出；
> - 用**存储密度**衡量：顺序表 = 1，链表 < 1，故顺序表空间利用率通常更高。
>
> **② 运算时间**
> - 顺序表**随机存取** $O(1)$；
> - 链表**顺序存取** $O(n)$；
> - **查找多、插删少 → 顺序表**；
> - **插删频繁 → 链表**。
>
> **③ 程序设计语言**
> 取决于语言**是否提供指针类型**，以及实际需要选用**静态链表**还是**动态链表**。
>
> **结论**：两种实现各有优缺点，**不能笼统判定优劣**，应根据实际问题综合平衡选择。

---

## 2.4 一元多项式的表示及相加

### 2.4.1 多项式的线性表表示

数学上，一元 $n$ 次多项式

$$P_n(x) = P_0 + P_1 x + P_2 x^2 + \dots + P_n x^n$$

由 $n+1$ 个系数唯一确定，可用线性表 $P$ 表示：

$$P = (P_0, P_1, P_2, \dots, P_n)$$

每项指数 $i$ 隐含在其系数 $P_i$ 的**序号**中。

> [!warning] 稀疏多项式的空间浪费
> 如 $S(x) = 1 + 3x^{10000} - 2x^{20000}$，顺序存储需长度 20001 的线性表，但只有**三个非零项**，严重浪费。
>
> **解决**：只存储非零项，但必须**同时存储系数和指数**。

### 2.4.2 稀疏多项式的线性表表示

一般一元稀疏多项式：

$$P(x) = p_1 x^{e_1} + p_2 x^{e_2} + \dots + p_m x^{e_m}$$

其中 $p_i$ 是指数为 $e_i$ 的项的非零系数，且

$$0 \le e_1 < e_2 < \dots < e_m = n$$

用一个长度为 $m$、每个元素含（系数，指数）两个数据项的线性表表示：

$$((p_1, e_1), (p_2, e_2), \dots, (p_m, e_m))$$

> [!example] 例
> $$P_{999}(x) = 7x^3 - 2x^{12} - 8x^{999}$$
> 可表示为 $((7, 3), (-2, 12), (-8, 999))$。
>
> 最坏情况（$n+1$ 个系数都不为零）比只存系数多一倍数据，但对**稀疏多项式**大大节省空间。

### 2.4.3 存储结构的选择

- **只求值**：无须修改系数指数，**顺序存储**为宜；
- **求和/相乘**：需频繁插删合并，**链式存储**为宜。

#### 顺序存储描述

```c
#define MAXLEN 100  /* 线性表最大长度 */

struct elemtp {      /* 元素类型 */
    float coef;      /* 系数域 */
    int exp;         /* 指数域 */
};

struct sequenlist {  /* 线性表类型 */
    struct elemtp vec[MAXLEN];  /* 数组 */
    int len;                    /* 长度 */
};
```

```
┌────┬────┬────┬────┬────┬────┐
│p₁e₁│p₂e₂│ ...│pₘeₘ│    │    │
└────┴────┴────┴────┴────┴────┘
```

#### 链式存储描述

```c
struct polynode {          /* 结点类型 */
    float coef;            /* 系数域 */
    int exp;               /* 指数域 */
    struct polynode *next; /* 指针域 */
};

struct polynode *p, *q;    /* 链表头指针 */
```

### 2.4.4 一元多项式的抽象数据类型

```
ADT Polynomial
{
    数据对象:
        D = { aᵢ | aᵢ ∈ TermSet, i = 1, 2, ..., m, m ≥ 0 }
        TermSet 中每个元素含一个表示系数的实数和表示指数的整数
    数据关系:
        R1 = { <aᵢ₋₁, aᵢ> | aᵢ₋₁, aᵢ ∈ D, i = 2, ..., n,
               且 aᵢ₋₁ 的指数值 < aᵢ 的指数值 }
    基本操作:
        CreatPolyn(&P, m)      输入 m 项的系数和指数，建立多项式 P
        DestroyPolyn(&P)       销毁多项式 P
        PrintPolyn(&P)         打印输出多项式 P
        PolynLength(P)         返回多项式项数
        AddPolyn(&Pa, &Pb)     完成 Pa = Pa + Pb，并销毁 Pb
        SubtractPolyn(&Pa, &Pb) 完成 Pa = Pa - Pb，并销毁 Pb
        MultiplyPolyn(&Pa, &Pb) 完成 Pa = Pa * Pb，并销毁 Pb
} ADT Polynomial
```

### 2.4.5 多项式相加算法

设 $A_n(x)$、$B_m(x)$ 都形如

$$P(x) = p_1 x^{e_1} + p_2 x^{e_2} + \dots + p_m x^{e_m}$$

求 $C_n(x) = A_n(x) + B_m(x)$（$m < n$）。显然**链式存储**最合适，两个链表分别表示两个多项式，每个结点表示一项。

> [!important] 运算规则
> - **指数相同**：系数相加，和不为零则生成和多项式一项；
> - **指数不同**：直接复制到和多项式。

**实现方法**：`p`、`q` 分别指向两多项式的当前结点，比较指数：

| 情况 | 处理 |
| --- | --- |
| ① `p->exp < q->exp` | `*p` 保留，`p` 后移 |
| ② `p->exp == q->exp` | 系数相加：和不为零则修改 `*p` 系数，释放 `q`；和为零则删除 `*p`、`*q` 两结点；`p`、`q` 均后移 |
| ③ `p->exp > q->exp` | `*q` 插到 `*p` 之前，`q` 后移 |

> [!example] 例：两个多项式相加
> **A**：$7x^0 + 3x^1 + 9x^8 + 5x^{17}$
> **B**：$8x^1 + 22x^7 - 9x^8$
>
> 链表：
> ```
> pa → [头] → [7,0] → [3,1] → [9,8] → [5,17] → NULL
>                 ↑ p
> pb → [头] → [8,1] → [22,7] → [-9,8] → NULL
>                 ↑ q
> ```
>
> 过程：
> 1. $0 < 1$：`[7,0]` 保留，`p` 后移；
> 2. $1 = 1$：$3+8=11$，改 `p` 系数为 11，释放 `q` 结点，`p,q` 后移；
> 3. $8 > 7$：将 `[22,7]` 插到 `p` 之前，`q` 后移；
> 4. $8 = 8$：$9+(-9)=0$，删除两结点，`p,q` 后移；
> 5. `p` 指 `[5,17]`，`q` 空：接剩余。
>
> 结果：$7 + 11x + 22x^7 + 5x^{17}$

```c
void polyadd(struct polynode *&pa, struct polynode *&pb)
{
    struct polynode *p, *q, *pre, *r;
    float x;
    p = pa->next;
    q = pb->next;
    pre = pa;                 /* pre 始终指向 p 的前驱 */
    while (p && q)
    {
        if (p->exp < q->exp)          /* 情况 ① */
        {
            pre = p;
            p = p->next;
        }
        else if (p->exp == q->exp)    /* 情况 ② */
        {
            x = p->coef + q->coef;
            if (x != 0)
            {
                p->coef = x;
                pre = p;
                p = p->next;
                r = q;
                q = q->next;
                free(r);
            }
            else
            {
                pre->next = p->next;  /* 删除 p */
                free(p);
                p = pre->next;
                r = q;
                q = q->next;
                free(r);              /* 删除 q */
            }
        }
        else                          /* 情况 ③ */
        {
            r = q->next;
            q->next = p;              /* q 插到 p 之前 */
            pre->next = q;
            pre = q;
            q = r;
        }
    }
    if (q) pre->next = q;             /* q 剩余，接到链尾 */
    free(pb);                         /* 释放 pb 头结点 */
} /* polyadd */
```

> [!warning] 易错点
> - 和为 0 时必须**同时删除 `p` 和 `q` 两个结点**，并更新 `pre->next` 与 `p`；
> - 不能用 `switch` 时忽略 `break`，本实现用 `if-else` 显式消除穿透；
> - 结束后**释放 `pb` 头结点**；
> - **时间复杂度** $O(m+n)$，**空间复杂度** $O(1)$（原地操作）。

---

## 2.5 本章习题精选与解析

> [!question] 习题 2.19
> 线性表元素递增有序，单链表存储。写高效算法删除值在 $(mink, maxk)$ 间的所有元素并释放空间，分析时间复杂度。

```c
void DeleteRange(struct LNode *&L, int mink, int maxk)
/* 删除递增有序单链表 L 中值在 (mink, maxk) 之间的所有结点 */
{
    struct LNode *p = L, *q;
    while (p->next && p->next->data <= mink)  /* 定位到 mink 的前驱 */
        p = p->next;
    while (p->next && p->next->data < maxk)   /* 连续删除 */
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
} /* DeleteRange */
```

> [!tip] 解析
> - **高效性**：利用递增有序性质，**一次定位**到删除区间起点，无需逐个检查；
> - **时间复杂度** $O(n)$；区间为空时几乎 $O(1)$；
> - **空间复杂度** $O(1)$。

---

> [!question] 习题 2.22
> 单链表就地逆置（未特别说明，链表均带头结点）。

```c
void ReverseList(struct LNode *&L)
/* 就地逆置带头结点的单链表 L */
{
    struct LNode *p = L->next, *q;
    L->next = NULL;              /* 摘下头结点 */
    while (p != NULL)
    {
        q = p->next;             /* 暂存后继，防断链 */
        p->next = L->next;
        L->next = p;             /* 头插 */
        p = q;
    }
} /* ReverseList */
```

> [!tip] 解析
> - 时间 $O(n)$，空间 $O(1)$；
> - 关键：**`q = p->next` 必须在修改 `p->next` 之前**，否则断链。

---

> [!question] 习题 2.25
> 有序递增线性表 A、B 表示两集合，另辟空间构造交集 C（仍有序递增），试用顺序表和单链表实现。

**顺序表实现**：

```c
void Intersect_Sq(struct SqList A, struct SqList B, struct SqList &C)
/* 求有序顺序表 A 和 B 的交集，结果存于 C */
{
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        if (A.elem[i] < B.elem[j])      i++;
        else if (A.elem[i] > B.elem[j]) j++;
        else
        {
            C.elem[k++] = A.elem[i];
            i++;
            j++;
        }
    }
    C.length = k;
} /* Intersect_Sq */
```

**单链表实现**：

```c
void Intersect_L(struct LNode *A, struct LNode *B,
                 struct LNode *&C)
/* 求有序单链表 A 和 B 的交集，结果存入新链表 C */
{
    struct LNode *pa = A->next, *pb = B->next, *s, *r;
    C = (struct LNode *)malloc(sizeof(struct LNode));
    C->next = NULL;
    r = C;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)        pa = pa->next;
        else if (pa->data > pb->data)   pb = pb->next;
        else
        {
            s = (struct LNode *)malloc(sizeof(struct LNode));
            s->data = pa->data;
            s->next = NULL;
            r->next = s;
            r = s;
            pa = pa->next;
            pb = pb->next;
        }
    }
} /* Intersect_L */
```

> [!tip] 解析
> - **双指针同步扫描**：较小者前进，相等时输出并两指针同时前进；
> - 时间 $O(m+n)$；空间：顺序表 $O(\min(m,n))$ 结果空间；链表 $O(\min(m,n))$ 新结点。

---

> [!question] 习题 2.37
> 带头结点的双向链表 L，生成另一双向链表，含 L 的奇数项数据，结构和相对次序不变。

```c
void CopyOdd_DuL(struct DuLNode *L, struct DuLNode *&Lc)
/* 复制双向链表 L 的奇数项到新双向链表 Lc */
{
    struct DuLNode *p = L->next, *s, *r;
    int i = 1;
    Lc = (struct DuLNode *)malloc(sizeof(struct DuLNode));
    Lc->next = Lc;
    Lc->prior = Lc;            /* 初始化为空循环链表 */
    r = Lc;
    while (p != L)
    {
        if (i % 2 == 1)
        {
            s = (struct DuLNode *)malloc(sizeof(struct DuLNode));
            s->data = p->data;
            s->prior = r;
            s->next = Lc;      /* 尾插 */
            r->next = s;
            Lc->prior = s;
            r = s;
        }
        p = p->next;
        i++;
    }
} /* CopyOdd_DuL */
```

> [!tip] 解析
> - 遍历原链表，计数器判奇偶，奇数项用**尾插法**加入新链表；
> - 尾插时**同时维护 `prior` 和 `next`**，保持循环特征（`Lc->next`、`Lc->prior` 同步）；
> - 时间 $O(n)$，空间 $O(n/2)$。

---

> [!question] 习题 2.38
> 双向循环链表结点有 `prior`、`data`、`next`、`freq` 四个域，`freq` 初始为 0。每次 `Locate(L, x)` 后，值等于 x 的结点 `freq` 增 1，并按 `freq` **非递增**重排，使频繁访问的结点靠近表头。试写 `Locate` 算法。

```c
int Locate_Freq(struct DuLNode *&L, int x)
/* 在双向循环链表 L 中查找值为 x 的结点，freq 加 1 后按 freq 非递增调整 */
{
    struct DuLNode *p = L->next, *q;
    while (p != L && p->data != x)
        p = p->next;
    if (p == L) return ERROR;    /* 未找到 */
    p->freq++;                   /* 频度增 1 */

    /* 因链表本身按 freq 非递增排列，只需向前找第一个 freq >= p->freq 的结点 */
    q = p->prior;
    while (q != L && q->freq < p->freq)
        q = q->prior;

    if (q != p->prior)           /* 需要移动 */
    {
        /* 从原位置摘下 p */
        p->prior->next = p->next;
        p->next->prior = p->prior;
        /* 将 p 插入到 q 之后 */
        p->next = q->next;
        q->next->prior = p;
        q->next = p;
        p->prior = q;
    }
    return OK;
} /* Locate_Freq */
```

> [!tip] 解析
> - 双向循环链表的优势：**从任一结点双向查找**，无需从头扫描；
> - 因链表本身按 `freq` 非递增，只需从 `p->prior` **向前**找第一个 `freq >= p->freq` 的 `q`，插到 `q` 之后即可；
> - 平均时间 $O(n)$，调整部分 $O(1)$。

---

## 2.6 本章小结

> [!summary] 本章知识速查
>
> **一、逻辑结构**
> - 线性表是 $n$ 个数据元素的**有限序列**；
> - 四特征：唯一首、唯一尾、唯一后继（除尾）、唯一前驱（除首）；
> - **位序从 1 开始**，数组下标从 0 开始；
> - **有序表**：元素依值非递减（或非递增）排列。
>
> **二、两种存储结构对比**
>
> | 对比项 | 顺序表 | 链表 |
> | --- | --- | --- |
> | 存储方式 | 连续存储单元 | 任意存储单元 |
> | 逻辑关系表示 | 物理位置相邻 | 指针 |
> | 存取方式 | **随机存取** $O(1)$ | **顺序存取** $O(n)$ |
> | 插入删除 | 移动元素，$O(n)$ | 改指针，$O(1)$（不含查找） |
> | 存储密度 | 1 | $<1$ |
> | 空间分配 | 预先固定 | 动态 |
> | 适用场景 | 查找多、插删少、长可估 | 插删频繁、长难估 |
>
> **三、链表形式**
>
> | 形式 | 特点 | 关键操作 |
> | --- | --- | --- |
> | 单链表 | `data` + `next`；头指针唯一确定 | `s->next=p->next; p->next=s;` |
> | 静态链表 | 数组 + 游标；需预先分配 | `i = S[i].cur` |
> | 循环链表 | 尾 `next` 指回头结点 | 判尾：`p->next == L`；判空：`L->next == L` |
> | 双向链表 | `prior`、`data`、`next` | 插删需改两个方向指针 |
> | 双向循环链表 | 头 `prior` 指尾，尾 `next` 指头 | 空表：`L->next == L && L->prior == L` |
>
> **四、顺序表复杂度**
>
> | 操作 | 时间 | 说明 |
> | --- | --- | --- |
> | `InitList` | $O(1)$ | 分配空间 |
> | `LocateElem` | $O(n)$ | 逐个比较 |
> | `ListInsert` | $O(n)$ | 平均移动 $n/2$ |
> | `ListDelete` | $O(n)$ | 平均移动 $(n-1)/2$ |
>
> **五、带头结点单链表复杂度**
>
> | 操作 | 时间 | 说明 |
> | --- | --- | --- |
> | `GetElem_L` | $O(n)$ | 从头扫描 |
> | `ListInsert_L` | $O(n)$ | 找 $i-1$；持有指针则 $O(1)$ |
> | `ListDelete_L` | $O(n)$ | 找 $i-1$；持有指针则 $O(1)$ |
> | `CreateList_L` | $O(n)$ | 头插 $n$ 次 |
> | `ClearList` | $O(n)$ | 逐个释放 |
>
> **六、一元多项式**
> - 稀疏多项式存**非零项（系数，指数）**；
> - 求值适合顺序存储，相加相乘适合链式；
> - 相加：双指针扫描，**时间 $O(m+n)$，空间 $O(1)$**。
>
> **七、易错点**
> - 位序从 1 开始，数组下标从 0 开始；
> - 单链表插入 `s->next = p->next; p->next = s;` **顺序不能颠倒**；
> - 删除结点前**先取 `data` 再 `free`**；
> - 双向链表插入四步顺序不能乱，删除时 `free` 最后；
> - 静态链表返回的是**数组下标**，不是位序；
> - 循环链表判空 `L->next == L`，判尾 `p->next == L`；
> - 顺序表插入**从后往前**移动，删除**从前往后**移动；
> - `realloc` 失败时原指针仍有效，应先用临时变量接收。