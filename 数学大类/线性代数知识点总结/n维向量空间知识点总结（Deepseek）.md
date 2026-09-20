# 线性代数：n维向量空间

## 目录
1. [向量的基本概念](##1.向量的基本概念)
2. [向量空间的定义与性质](#2.向量空间的定义与性质)
3. [子空间](#3.子空间)
4. [向量的线性关系](#4.向量的线性关系)
5. [向量组的秩](#5.向量组的秩)
6. [基与维数](#6.基与维数)
7. [坐标](#7.坐标)
8. [向量的内积与正交性](#8.向量的内积与正交性)
9. [正交基与正交化](#9.正交基与正交化)

---

## 1. 向量的基本概念

### 1.1 向量的定义
**n维向量**是由n个有序实数（或复数）组成的数组：
- **行向量**：$\boldsymbol{\alpha} = (a_1, a_2, \dots, a_n)$
- **列向量**：$\boldsymbol{\alpha} = \begin{pmatrix} a_1 \\ a_2 \\ \vdots \\ a_n \end{pmatrix}$ 或 $\boldsymbol{\alpha} = (a_1, a_2, \dots, a_n)^T$

### 1.2 向量的运算
设 $\boldsymbol{\alpha} = (a_1, \dots, a_n)^T$, $\boldsymbol{\beta} = (b_1, \dots, b_n)^T$, $k \in \mathbb{R}$（或 $\mathbb{C}$）

1. **加法**：$\boldsymbol{\alpha} + \boldsymbol{\beta} = (a_1 + b_1, \dots, a_n + b_n)^T$
2. **数乘**：$k\boldsymbol{\alpha} = (ka_1, \dots, ka_n)^T$
3. **零向量**：$\boldsymbol{0} = (0, 0, \dots, 0)^T$
4. **负向量**：$-\boldsymbol{\alpha} = (-a_1, \dots, -a_n)^T$

### 1.3 运算性质
- 交换律：$\boldsymbol{\alpha} + \boldsymbol{\beta} = \boldsymbol{\beta} + \boldsymbol{\alpha}$
- 结合律：$(\boldsymbol{\alpha} + \boldsymbol{\beta}) + \boldsymbol{\gamma} = \boldsymbol{\alpha} + (\boldsymbol{\beta} + \boldsymbol{\gamma})$
- 分配律：$k(\boldsymbol{\alpha} + \boldsymbol{\beta}) = k\boldsymbol{\alpha} + k\boldsymbol{\beta}$
- $(k+l)\boldsymbol{\alpha} = k\boldsymbol{\alpha} + l\boldsymbol{\alpha}$

---

## 2. 向量空间的定义与性质

### 2.1 向量空间定义
设 $V$ 是非空集合，$\mathbb{F}$ 是数域（$\mathbb{R}$ 或 $\mathbb{C}$），若在 $V$ 上定义了加法和数乘运算，且满足以下8条公理，则称 $V$ 为 $\mathbb{F}$ 上的**向量空间**：

1. $\boldsymbol{\alpha} + \boldsymbol{\beta} = \boldsymbol{\beta} + \boldsymbol{\alpha}$
2. $(\boldsymbol{\alpha} + \boldsymbol{\beta}) + \boldsymbol{\gamma} = \boldsymbol{\alpha} + (\boldsymbol{\beta} + \boldsymbol{\gamma})$
3. $\exists \boldsymbol{0} \in V, \forall \boldsymbol{\alpha} \in V, \boldsymbol{\alpha} + \boldsymbol{0} = \boldsymbol{\alpha}$
4. $\forall \boldsymbol{\alpha} \in V, \exists -\boldsymbol{\alpha} \in V, \boldsymbol{\alpha} + (-\boldsymbol{\alpha}) = \boldsymbol{0}$
5. $1 \cdot \boldsymbol{\alpha} = \boldsymbol{\alpha}$
6. $k(l\boldsymbol{\alpha}) = (kl)\boldsymbol{\alpha}$
7. $(k+l)\boldsymbol{\alpha} = k\boldsymbol{\alpha} + l\boldsymbol{\alpha}$
8. $k(\boldsymbol{\alpha} + \boldsymbol{\beta}) = k\boldsymbol{\alpha} + k\boldsymbol{\beta}$

### 2.2 常见向量空间
1. **$\mathbb{R}^n$**：所有n维实向量构成的向量空间
2. **$\mathbb{C}^n$**：所有n维复向量构成的向量空间
3. **多项式空间**：$P_n[x] = \{ a_0 + a_1x + \dots + a_{n-1}x^{n-1} \mid a_i \in \mathbb{R} \}$
4. **矩阵空间**：$M_{m \times n}(\mathbb{R})$

---

## 3. 子空间

### 3.1 定义
设 $V$ 是向量空间，$W \subseteq V$，若 $W$ 对 $V$ 的加法和数乘运算封闭，则 $W$ 是 $V$ 的**子空间**。

**封闭性条件**：
1. $\forall \boldsymbol{\alpha}, \boldsymbol{\beta} \in W, \boldsymbol{\alpha} + \boldsymbol{\beta} \in W$
2. $\forall \boldsymbol{\alpha} \in W, k \in \mathbb{F}, k\boldsymbol{\alpha} \in W$

### 3.2 常见子空间
1. **零子空间**：$\{ \boldsymbol{0} \}$
2. **生成子空间**：$L(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_s) = \{ k_1\boldsymbol{\alpha}_1 + \dots + k_s\boldsymbol{\alpha}_s \mid k_i \in \mathbb{F} \}$
3. **齐次线性方程组的解空间**：$W = \{ \boldsymbol{x} \mid A\boldsymbol{x} = \boldsymbol{0} \}$

### 3.3 子空间的运算
1. **交空间**：$W_1 \cap W_2 = \{ \boldsymbol{\alpha} \mid \boldsymbol{\alpha} \in W_1 \text{且} \boldsymbol{\alpha} \in W_2 \}$
2. **和空间**：$W_1 + W_2 = \{ \boldsymbol{\alpha}_1 + \boldsymbol{\alpha}_2 \mid \boldsymbol{\alpha}_1 \in W_1, \boldsymbol{\alpha}_2 \in W_2 \}$

**维数公式**：
$$
\dim(W_1) + \dim(W_2) = \dim(W_1 + W_2) + \dim(W_1 \cap W_2)
$$

---

## 线性相关与线性无关的深入展开

### 1. 严格定义与等价表述

#### 1.1 形式化定义
设 $\boldsymbol{\alpha}_1, \boldsymbol{\alpha}_2, \dots, \boldsymbol{\alpha}_m$ 是数域 $\mathbb{F}$ 上向量空间 $V$ 中的向量组。

##### 线性相关 (Linearly Dependent)
存在**不全为零**的标量 $k_1, k_2, \dots, k_m \in \mathbb{F}$，使得：
$$
k_1\boldsymbol{\alpha}_1 + k_2\boldsymbol{\alpha}_2 + \cdots + k_m\boldsymbol{\alpha}_m = \boldsymbol{0}
$$

##### 线性无关 (Linearly Independent)
只有当所有标量 $k_1 = k_2 = \cdots = k_m = 0$ 时，才有：
$$
k_1\boldsymbol{\alpha}_1 + k_2\boldsymbol{\alpha}_2 + \cdots + k_m\boldsymbol{\alpha}_m = \boldsymbol{0}
$$
即，零向量的表示方式**唯一**。

#### 1.2 等价表述
向量组 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m$ 线性相关当且仅当满足以下任一条件：
1. **存在性表述**：至少有一个向量可由其余向量线性表示
   $$
   \exists i, \text{使 } \boldsymbol{\alpha}_i = \sum_{j \neq i} c_j \boldsymbol{\alpha}_j
   $$
2. **秩表述**：$r(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m) < m$
3. **矩阵表述**：齐次方程组 $x_1\boldsymbol{\alpha}_1 + \cdots + x_m\boldsymbol{\alpha}_m = \boldsymbol{0}$ 有非零解
4. **线性组合表述**：存在某个向量可由前面向量线性表示（当向量按顺序排列时）

---

### 2. 判定方法与技巧

#### 2.1 基于定义的直接判定
**例题**：判断 $\boldsymbol{\alpha}_1 = (1,2,3)^T, \boldsymbol{\alpha}_2 = (2,4,6)^T$ 的线性相关性

解：设 $k_1\boldsymbol{\alpha}_1 + k_2\boldsymbol{\alpha}_2 = \boldsymbol{0}$
- $k_1 + 2k_2 = 0$
- $2k_1 + 4k_2 = 0$
- $3k_1 + 6k_2 = 0$

解得 $k_1 = -2k_2$，取 $k_2 = 1, k_1 = -2$（不全为零），故线性相关。

#### 2.2 秩判定法
**定理**：向量组 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m \in \mathbb{R}^n$ 
- 线性无关 $\Leftrightarrow$ $r(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m) = m$
- 线性相关 $\Leftrightarrow$ $r(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m) < m$

**操作步骤**：
1. 构造矩阵 $A = (\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m)$
2. 化为行阶梯形
3. 判断非零行数（秩）是否等于 $m$

#### 2.3 特殊情况判定

##### 2.3.1 含零向量的向量组必线性相关
$$
\boldsymbol{0}, \boldsymbol{\alpha}_2, \dots, \boldsymbol{\alpha}_m \text{ 总是线性相关}
$$
因为 $1 \cdot \boldsymbol{0} + 0 \cdot \boldsymbol{\alpha}_2 + \cdots + 0 \cdot \boldsymbol{\alpha}_m = \boldsymbol{0}$

##### 2.3.2 单个向量的情况
- $\boldsymbol{\alpha} = \boldsymbol{0}$：线性相关（$k=1$ 时 $1\cdot\boldsymbol{0}=\boldsymbol{0}$）
- $\boldsymbol{\alpha} \neq \boldsymbol{0}$：线性无关（$k\boldsymbol{\alpha}=\boldsymbol{0} \Rightarrow k=0$）

##### 2.3.3 两个向量的情况
$\boldsymbol{\alpha}, \boldsymbol{\beta}$ 线性相关 $\Leftrightarrow$ $\boldsymbol{\alpha} = k\boldsymbol{\beta}$ 或 $\boldsymbol{\beta} = k\boldsymbol{\alpha}$（成比例）

##### 2.3.4 向量个数 > 维数必线性相关
若 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m \in \mathbb{R}^n$ 且 $m > n$，则必线性相关。

**证明**：$r(A) \leq \min\{m, n\} = n < m$

---

### 3. 重要性质与定理

#### 3.1 基本性质
1. **部分相关则整体相关**：若向量组中有一部分向量线性相关，则整个向量组线性相关
   - 逆否命题：整体无关则部分无关
2. **添加向量性质**：若 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m$ 线性无关，在其中添加一个向量 $\boldsymbol{\beta}$ 后线性相关 $\Leftrightarrow$ $\boldsymbol{\beta}$ 可由 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m$ 线性表示

#### 3.2 替换定理（Steinitz替换定理）
设 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_r$ 线性无关，且每个 $\boldsymbol{\alpha}_i$ 可由 $\boldsymbol{\beta}_1, \dots, \boldsymbol{\beta}_s$ 线性表示，则：
1. $r \leq s$
2. 可用 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_r$ 替换 $\boldsymbol{\beta}_1, \dots, \boldsymbol{\beta}_s$ 中的 $r$ 个向量，使新向量组与原向量组等价

**推论**：等价的线性无关向量组所含向量个数相同。

#### 3.3 极大线性无关组
##### 定义
向量组 $A$ 的部分组 $A_0$ 满足：
1. $A_0$ 线性无关
2. $A$ 中任一向量都可由 $A_0$ 线性表示

##### 性质
- 极大无关组一般不唯一，但所含向量个数相同（等于秩）
- 向量组与其极大无关组等价
- 求法：行初等变换化为阶梯形，非零行首元所在列对应的原向量

#### 3.4 向量组等价
##### 定义
向量组 $A: \boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m$ 与 $B: \boldsymbol{\beta}_1, \dots, \boldsymbol{\beta}_s$ 等价 $\Leftrightarrow$ 它们可以互相线性表示。

##### 判定
<font color="red">$A$ 与 $B$ 等价 $\Leftrightarrow$ $r(A) = r(B) = r(A, B)$</font>

---

### 4. 几何直观与例子

#### 4.1 $\mathbb{R}^2$ 中的情形
1. **两个向量**：
   - 线性相关：两向量共线
   - 线性无关：两向量不共线（可张成整个平面）
2. **三个向量**：必线性相关（因为 $3 > 2$）

#### 4.2 $\mathbb{R}^3$ 中的情形
1. **两个向量**：
   - 线性相关：共线
   - 线性无关：不共线（张成一个平面）
2. **三个向量**：
   - 线性相关：共面
   - 线性无关：不共面（可张成整个空间）
3. **四个向量**：必线性相关（因为 $4 > 3$）

#### 4.3 多项式空间的例子
考虑 $P_2[x]$ 中的向量组：
- $\boldsymbol{p}_1 = 1 + x$
- $\boldsymbol{p}_2 = 1 - x$
- $\boldsymbol{p}_3 = x + x^2$

设 $k_1\boldsymbol{p}_1 + k_2\boldsymbol{p}_2 + k_3\boldsymbol{p}_3 = 0$：
$$
\begin{cases}
k_1 + k_2 &= 0 \\
k_1 - k_2 + k_3 &= 0 \\
k_3 &= 0
\end{cases}
$$
解得 $k_1 = k_2 = k_3 = 0$，故线性无关。

---

### 5. 与线性方程组的关系

#### 5.1 齐次方程组
$$
A\boldsymbol{x} = \boldsymbol{0} \quad (A \in \mathbb{R}^{n \times m})
$$
- 仅有零解 $\Leftrightarrow$ $A$ 的列向量组线性无关 $\Leftrightarrow$ $r(A) = m$
- 有非零解 $\Leftrightarrow$ $A$ 的列向量组线性相关 $\Leftrightarrow$ $r(A) < m$

#### 5.2 非齐次方程组
$$
A\boldsymbol{x} = \boldsymbol{b}
$$
有解 $\Leftrightarrow$ $\boldsymbol{b}$ 可由 $A$ 的列向量组线性表示

#### 5.3 基础解系
齐次方程组 $A\boldsymbol{x} = \boldsymbol{0}$ 的**基础解系**是其解空间的一组基，具有性质：
1. 基础解系中的向量线性无关
2. 方程组的所有解可由基础解系线性表示
3. 基础解系包含 $n - r(A)$ 个向量

---

### 6. 矩阵语言表述

#### 6.1 列向量组的线性相关性
对于矩阵 $A = (\boldsymbol{a}_1, \dots, \boldsymbol{a}_m) \in \mathbb{R}^{n \times m}$：
- 列向量组线性无关 $\Leftrightarrow$ $A\boldsymbol{x} = \boldsymbol{0}$ 仅有零解
- 列向量组线性相关 $\Leftrightarrow$ 存在非零 $\boldsymbol{x}$ 使 $A\boldsymbol{x} = \boldsymbol{0}$

#### 6.2 行向量组的线性相关性
考虑 $A$ 的行向量组 $\boldsymbol{\alpha}_1^T, \dots, \boldsymbol{\alpha}_n^T$：
- 行向量组线性无关 $\Leftrightarrow$ $r(A) = n$
- 行向量组线性相关 $\Leftrightarrow$ $r(A) < n$

#### 6.3 可逆矩阵的等价条件
$n$ 阶方阵 $A$ 可逆 $\Leftrightarrow$ 以下任一条件成立：
1. $A$ 的列向量组线性无关
2. $A$ 的行向量组线性无关
3. $r(A) = n$
4. $|A| \neq 0$

---

### 7. 进阶概念

#### 7.1 线性相关与线性表示的传递性
若向量组 $B$ 可由 $A$ 线性表示，且 $B$ 线性无关，则 $|B| \leq |A|$

#### 7.2 线性无关向量组的扩充
任何线性无关向量组都可扩充为所在向量空间的一组基。

**构造方法**：将向量空间的一组基添加到原向量组后面，然后逐步去除可由前面向量线性表示的向量。

#### 7.3 在不同数域下的相关性
向量组在 $\mathbb{C}$ 上线性相关 $\Rightarrow$ 在 $\mathbb{R}$ 上线性相关，但反之不一定成立。

**例**：$\boldsymbol{\alpha}_1 = (1, i)^T, \boldsymbol{\alpha}_2 = (i, -1)^T$ 在 $\mathbb{R}$ 上线性无关（系数为实数时），但在 $\mathbb{C}$ 上线性相关（取 $k_1 = i, k_2 = 1$）。

---

### 8. 常见错误与注意事项

1. **"线性无关" ≠ "两两正交"**：正交向量组必线性无关，但线性无关向量组不一定正交
2. **"线性相关" ≠ "成比例"**：两个向量线性相关等价于成比例，但三个以上向量线性相关不一定两两成比例
3. **注意前提条件**：讨论相关性时，向量必须在同一向量空间中
4. **零向量的特殊性**：包含零向量的向量组总是线性相关
5. **向量个数与维数的关系**：在 $\mathbb{R}^n$ 中，任何 $n+1$ 个向量必线性相关

---

## 5. 向量组的秩

### 5.1 定义
向量组 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m$ 的**秩**是它的极大线性无关组所含向量的个数，记作 $r(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m)$

### 5.2 矩阵的秩
向量组 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m$ 的秩 = 以这些向量为列构成的矩阵的秩

$$
r(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m) = r(A) \quad \text{其中} \quad A = (\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m)
$$

### 5.3 秩的性质
1. $0 \leq r(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m) \leq \min\{m, n\}$
2. $r(\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m) = r(\boldsymbol{\alpha}_{i_1}, \dots, \boldsymbol{\alpha}_{i_k})$（其中 $i_1, \dots, i_k$ 是极大无关组）
3. 初等变换不改变向量组的秩
4. 若向量组 $B$ 可由向量组 $A$ 线性表示，则 $r(B) \leq r(A)$

---

## 6. 基与维数

### 6.1 基的定义
向量空间 $V$ 中的向量组 $\boldsymbol{\varepsilon}_1, \dots, \boldsymbol{\varepsilon}_n$ 称为 $V$ 的一组**基**，如果：
1. $\boldsymbol{\varepsilon}_1, \dots, \boldsymbol{\varepsilon}_n$ 线性无关
2. $V$ 中任一向量都可由 $\boldsymbol{\varepsilon}_1, \dots, \boldsymbol{\varepsilon}_n$ 线性表示

### 6.2 维数定义
向量空间 $V$ 的**维数**是基所含向量的个数，记作 $\dim V$

### 6.3 标准基
$\mathbb{R}^n$ 的**标准基**（自然基）：
$$
\boldsymbol{e}_1 = \begin{pmatrix} 1 \\ 0 \\ \vdots \\ 0 \end{pmatrix},
\boldsymbol{e}_2 = \begin{pmatrix} 0 \\ 1 \\ \vdots \\ 0 \end{pmatrix},
\dots,
\boldsymbol{e}_n = \begin{pmatrix} 0 \\ 0 \\ \vdots \\ 1 \end{pmatrix}
$$

### 6.4 基的性质
1. 向量空间的维数是唯一的
2. $\dim \mathbb{R}^n = n$, $\dim \mathbb{C}^n = n$
3. $\dim P_n[x] = n$
4. $\dim M_{m \times n}(\mathbb{R}) = mn$

---

## 7. 坐标

### 7.1 坐标定义
设 $\boldsymbol{\varepsilon}_1, \dots, \boldsymbol{\varepsilon}_n$ 是 $V$ 的一组基，$\boldsymbol{\alpha} \in V$，且
$$
\boldsymbol{\alpha} = x_1\boldsymbol{\varepsilon}_1 + x_2\boldsymbol{\varepsilon}_2 + \dots + x_n\boldsymbol{\varepsilon}_n
$$
则称 $(x_1, x_2, \dots, x_n)^T$ 为 $\boldsymbol{\alpha}$ 在基 $\boldsymbol{\varepsilon}_1, \dots, \boldsymbol{\varepsilon}_n$ 下的**坐标**

### 7.2 坐标变换
设 $\boldsymbol{\varepsilon}_1, \dots, \boldsymbol{\varepsilon}_n$ 和 $\boldsymbol{\eta}_1, \dots, \boldsymbol{\eta}_n$ 是 $V$ 的两组基，且有
$$
(\boldsymbol{\eta}_1, \dots, \boldsymbol{\eta}_n) = (\boldsymbol{\varepsilon}_1, \dots, \boldsymbol{\varepsilon}_n)P
$$
其中 $P$ 是过渡矩阵（可逆矩阵）

若 $\boldsymbol{\alpha}$ 在两组基下的坐标分别为 $\boldsymbol{x}$ 和 $\boldsymbol{y}$，则：
$$
\boldsymbol{x} = P\boldsymbol{y} \quad \text{或} \quad \boldsymbol{y} = P^{-1}\boldsymbol{x}
$$

---

## 8. 向量的内积与正交性

### 8.1 内积定义
在实向量空间 $\mathbb{R}^n$ 上，定义**内积**（点积）：
$$
\langle \boldsymbol{\alpha}, \boldsymbol{\beta} \rangle = \boldsymbol{\alpha}^T \boldsymbol{\beta} = \sum_{i=1}^n a_i b_i
$$
其中 $\boldsymbol{\alpha} = (a_1, \dots, a_n)^T$, $\boldsymbol{\beta} = (b_1, \dots, b_n)^T$

### 8.2 内积性质
1. 对称性：$\langle \boldsymbol{\alpha}, \boldsymbol{\beta} \rangle = \langle \boldsymbol{\beta}, \boldsymbol{\alpha} \rangle$
2. 线性性：$\langle k\boldsymbol{\alpha} + l\boldsymbol{\beta}, \boldsymbol{\gamma} \rangle = k\langle \boldsymbol{\alpha}, \boldsymbol{\gamma} \rangle + l\langle \boldsymbol{\beta}, \boldsymbol{\gamma} \rangle$
3. 正定性：$\langle \boldsymbol{\alpha}, \boldsymbol{\alpha} \rangle \geq 0$，等号成立 $\Leftrightarrow \boldsymbol{\alpha} = \boldsymbol{0}$

### 8.3 向量长度（范数）
$$
\|\boldsymbol{\alpha}\| = \sqrt{\langle \boldsymbol{\alpha}, \boldsymbol{\alpha} \rangle} = \sqrt{\sum_{i=1}^n a_i^2}
$$

### 8.4 正交性
1. **正交**：$\langle \boldsymbol{\alpha}, \boldsymbol{\beta} \rangle = 0$，记作 $\boldsymbol{\alpha} \perp \boldsymbol{\beta}$
2. **正交向量组**：两两正交的非零向量组
3. **标准正交组**：正交且每个向量长度为1的向量组

### 8.5 夹角与柯西-施瓦茨不等式
**夹角**：
$$
\cos\theta = \frac{\langle \boldsymbol{\alpha}, \boldsymbol{\beta} \rangle}{\|\boldsymbol{\alpha}\| \cdot \|\boldsymbol{\beta}\|}
$$

**柯西-施瓦茨不等式**：
$$
|\langle \boldsymbol{\alpha}, \boldsymbol{\beta} \rangle| \leq \|\boldsymbol{\alpha}\| \cdot \|\boldsymbol{\beta}\|
$$

---

## 9. 正交基与正交化

### 9.1 正交基
若向量空间 $V$ 的一组基是正交向量组，则称为**正交基**；若还是标准正交组，则称为**标准正交基**

### 9.2 施密特正交化
将线性无关向量组 $\boldsymbol{\alpha}_1, \dots, \boldsymbol{\alpha}_m$ 化为正交向量组 $\boldsymbol{\beta}_1, \dots, \boldsymbol{\beta}_m$：

1. $\boldsymbol{\beta}_1 = \boldsymbol{\alpha}_1$
2. $\boldsymbol{\beta}_2 = \boldsymbol{\alpha}_2 - \frac{\langle \boldsymbol{\alpha}_2, \boldsymbol{\beta}_1 \rangle}{\langle \boldsymbol{\beta}_1, \boldsymbol{\beta}_1 \rangle}\boldsymbol{\beta}_1$
3. $\boldsymbol{\beta}_3 = \boldsymbol{\alpha}_3 - \frac{\langle \boldsymbol{\alpha}_3, \boldsymbol{\beta}_1 \rangle}{\langle \boldsymbol{\beta}_1, \boldsymbol{\beta}_1 \rangle}\boldsymbol{\beta}_1 - \frac{\langle \boldsymbol{\alpha}_3, \boldsymbol{\beta}_2 \rangle}{\langle \boldsymbol{\beta}_2, \boldsymbol{\beta}_2 \rangle}\boldsymbol{\beta}_2$
4. $\vdots$
5. $\boldsymbol{\beta}_m = \boldsymbol{\alpha}_m - \sum_{i=1}^{m-1} \frac{\langle \boldsymbol{\alpha}_m, \boldsymbol{\beta}_i \rangle}{\langle \boldsymbol{\beta}_i, \boldsymbol{\beta}_i \rangle}\boldsymbol{\beta}_i$

### 9.3 单位化
将正交向量组单位化得标准正交基：
$$
\boldsymbol{\gamma}_i = \frac{\boldsymbol{\beta}_i}{\|\boldsymbol{\beta}_i\|}, \quad i = 1, \dots, m
$$

### 9.4 正交矩阵
若 $n$ 阶实矩阵 $Q$ 满足 $Q^T Q = I$，则 $Q$ 为**正交矩阵**

**性质**：
1. $Q^{-1} = Q^T$
2. $|Q| = \pm 1$
3. $Q$ 的行（列）向量构成标准正交基
4. 保持内积和长度不变：$\langle Q\boldsymbol{x}, Q\boldsymbol{y} \rangle = \langle \boldsymbol{x}, \boldsymbol{y} \rangle$

---

## 总结
n维向量空间理论是线性代数的核心内容，它建立了从具体向量运算到抽象空间结构的桥梁。掌握向量空间、子空间、基与坐标、线性关系、秩、内积与正交性等概念，是理解线性代数后续内容（如线性变换、特征值、二次型等）的基础。