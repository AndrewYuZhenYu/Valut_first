# 线性代数：矩阵与行列式完全指南

## 目录
1. [矩阵基础](#矩阵基础)
2. [特殊矩阵](#特殊矩阵)
3. [矩阵运算](#矩阵运算)
4. [行列式基础](#行列式基础)
5. [行列式性质](#行列式性质)
6. [行列式计算](#行列式计算)
7. [矩阵的逆](#矩阵的逆)
8. [矩阵的秩](#矩阵的秩)
9. [矩阵分块](#矩阵分块)
10. [特征值与特征向量](#特征值与特征向量)
11. [矩阵对角化](#矩阵对角化)
12. [特殊行列式](#特殊行列式)

## 矩阵基础

### 1.1 矩阵定义
矩阵是由$m \times n$个数排列成的矩形数表：

$$
A = \begin{pmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m1} & a_{m2} & \cdots & a_{mn}
\end{pmatrix}
$$

记作$A = (a_{ij})_{m \times n}$，其中：
- $a_{ij}$表示第$i$行第$j$列的元素
- $m$为行数，$n$为列数
- 当$m=n$时，称为**方阵**

### 1.2 矩阵类型
- **零矩阵**：所有元素为0，记作$O_{m \times n}$
- **行矩阵/行向量**：$1 \times n$矩阵
- **列矩阵/列向量**：$m \times 1$矩阵
- **同型矩阵**：行数和列数分别相等的矩阵

## 特殊矩阵

### 2.1 对角矩阵
$$
D = \begin{pmatrix}
d_1 & 0 & \cdots & 0 \\
0 & d_2 & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & d_n
\end{pmatrix}
\quad \text{或} \quad
D = \text{diag}(d_1, d_2, \ldots, d_n)
$$

**性质**：
- $D^k = \text{diag}(d_1^k, d_2^k, \ldots, d_n^k)$
- 若$d_i \neq 0$，则$D^{-1} = \text{diag}(1/d_1, 1/d_2, \ldots, 1/d_n)$

### 2.2 单位矩阵
主对角线元素为1，其余为0的方阵：
$$
I_n = \begin{pmatrix}
1 & 0 & \cdots & 0 \\
0 & 1 & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & 1
\end{pmatrix}
$$

**性质**：$AI_n = I_nA = A$

### 2.3 数量矩阵
$$
kI = \begin{pmatrix}
k & 0 & \cdots & 0 \\
0 & k & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & k
\end{pmatrix}
$$

### 2.4 上（下）三角矩阵
**上三角矩阵**：
$$
U = \begin{pmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
0 & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & a_{nn}
\end{pmatrix}
$$

**下三角矩阵**：
$$
L = \begin{pmatrix}
a_{11} & 0 & \cdots & 0 \\
a_{21} & a_{22} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & \cdots & a_{nn}
\end{pmatrix}
$$

**性质**：
- 三角矩阵的行列式等于主对角线元素的乘积
- 两个上（下）三角矩阵的乘积仍是上（下）三角矩阵

### 2.5 对称矩阵与反对称矩阵
**对称矩阵**：$A^T = A$，即$a_{ij} = a_{ji}$
$$
S = \begin{pmatrix}
a & b & c \\
b & d & e \\
c & e & f
\end{pmatrix}
$$

**反对称矩阵**：$A^T = -A$，即$a_{ij} = -a_{ji}$，且主对角线元素为0
$$
K = \begin{pmatrix}
0 & a & b \\
-a & 0 & c \\
-b & -c & 0
\end{pmatrix}
$$

### 2.6 正交矩阵
满足$A^TA = AA^T = I$，即$A^{-1} = A^T$

**性质**：
- 行列式的值为$\pm 1$
- 行（列）向量构成标准正交基
- 保持向量长度和夹角：$\|Ax\| = \|x\|$

### 2.7 幂等矩阵、幂零矩阵、对合矩阵
- **幂等矩阵**：$A^2 = A$
- **幂零矩阵**：存在$k$使得$A^k = O$
- **对合矩阵**：$A^2 = I$

### 2.8 行阶梯形矩阵与行最简形矩阵
**行阶梯形矩阵**：
1. 零行在底部
2. 非零行的首非零元（主元）的列标随行标递增
3. 主元下面的元素全为0

**行最简形矩阵**：
1. 是行阶梯形
2. 主元为1
3. 主元所在列的其他元素全为0

## 矩阵运算

### 3.1 矩阵加法
设$A=(a_{ij})_{m\times n}, B=(b_{ij})_{m\times n}$，则：
$$
A + B = (a_{ij} + b_{ij})_{m\times n}
$$

**性质**：
1. 交换律：$A+B = B+A$
2. 结合律：$(A+B)+C = A+(B+C)$
3. $A+O = O+A = A$
4. $A+(-A) = O$

### 3.2 数乘矩阵
设$k \in \mathbb{R}$，则：
$$
kA = (ka_{ij})_{m\times n}
$$

**性质**：
1. $k(A+B) = kA + kB$
2. $(k+l)A = kA + lA$
3. $(kl)A = k(lA)$
4. $1 \cdot A = A$

### 3.3 矩阵乘法
设$A=(a_{ij})_{m\times s}, B=(b_{ij})_{s\times n}$，则$C=AB=(c_{ij})_{m\times n}$，其中：
$$
c_{ij} = \sum_{k=1}^s a_{ik}b_{kj}
$$

**性质**：
1. 结合律：$(AB)C = A(BC)$
2. 分配律：$A(B+C) = AB+AC$，$(A+B)C = AC+BC$
3. $k(AB) = (kA)B = A(kB)$
4. $AI = IA = A$
5. **注意**：一般不满足交换律，即$AB \neq BA$

### 3.4 矩阵转置
将$A$的行列互换得到$A^T$：
$$
\text{若}A=(a_{ij})_{m\times n},\text{则}A^T=(a_{ji})_{n\times m}
$$

**性质**：
1. $(A^T)^T = A$
2. $(A+B)^T = A^T + B^T$
3. $(kA)^T = kA^T$
4. $(AB)^T = B^TA^T$（重要）
5. $(A_1A_2\cdots A_k)^T = A_k^T\cdots A_2^TA_1^T$

### 3.5 方阵的幂
$$
A^k = \underbrace{A \cdot A \cdots A}_{k\text{个}}
$$

**性质**：
1. $A^{k+l} = A^kA^l$
2. $(A^k)^l = A^{kl}$
3. 一般情况下$(AB)^k \neq A^kB^k$

### 3.6 矩阵多项式
设$f(x) = a_mx^m + a_{m-1}x^{m-1} + \cdots + a_1x + a_0$，则：
$$
f(A) = a_mA^m + a_{m-1}A^{m-1} + \cdots + a_1A + a_0I
$$

**性质**：若$AB=BA$，则$f(A)g(B)=g(B)f(A)$

### 3.7 矩阵的迹
方阵$A$主对角元素之和：
$$
\text{tr}(A) = \sum_{i=1}^n a_{ii}
$$

**性质**：
1. $\text{tr}(A+B) = \text{tr}(A) + \text{tr}(B)$
2. $\text{tr}(kA) = k\text{tr}(A)$
3. $\text{tr}(AB) = \text{tr}(BA)$
4. $\text{tr}(A) = \sum_{i=1}^n \lambda_i$（特征值之和）

## 行列式基础

### 4.1 排列与逆序数
**排列**：$n$个不同元素的有序排列，记作$i_1i_2\cdots i_n$

**逆序**：当$i_s > i_t$但$s < t$时，称这对数构成一个逆序

**逆序数**：排列中逆序的总数，记作$\tau(i_1i_2\cdots i_n)$

**奇排列与偶排列**：逆序数为奇数的排列称为奇排列，逆序数为偶数的排列称为偶排列

### 4.2 行列式定义
$n$阶行列式：
$$
\det(A) = |A| = \sum_{j_1j_2\cdots j_n} (-1)^{\tau(j_1j_2\cdots j_n)} a_{1j_1}a_{2j_2}\cdots a_{nj_n}
$$
其中求和取遍$1,2,\ldots,n$的所有排列$j_1j_2\cdots j_n$

**等价定义（按行展开）**：
$$
|A| = \sum_{i_1i_2\cdots i_n} (-1)^{\tau(i_1i_2\cdots i_n)} a_{i_11}a_{i_22}\cdots a_{i_nn}
$$

### 4.3 特殊行列式
**二阶行列式**：
$$
\begin{vmatrix}
a & b \\
c & d
\end{vmatrix} = ad - bc
$$

**三阶行列式**：
$$
\begin{vmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{vmatrix} = a_{11}a_{22}a_{33} + a_{12}a_{23}a_{31} + a_{13}a_{21}a_{32} \\
- a_{13}a_{22}a_{31} - a_{11}a_{23}a_{32} - a_{12}a_{21}a_{33}
$$
（可用对角线法则记忆）

## 行列式性质

### 5.1 基本性质
1. **转置不变性**：$|A^T| = |A|$
2. **线性性（对某一行/列）**：
   - $|a_1,\ldots,ka_i,\ldots,a_n| = k|a_1,\ldots,a_i,\ldots,a_n|$
   - $|a_1,\ldots,a_i+b_i,\ldots,a_n| = |a_1,\ldots,a_i,\ldots,a_n| + |a_1,\ldots,b_i,\ldots,a_n|$
3. **反对称性**：交换两行（列），行列式变号
4. **有两行（列）相同**：行列式为0
5. **有两行（列）成比例**：行列式为0
6. **行（列）全为0**：行列式为0

### 5.2 初等变换对行列式的影响
设$A$为$n$阶方阵：
1. **交换两行（列）**：$|A'| = -|A|$
2. **某行（列）乘以$k$**：$|A'| = k|A|$
3. **将某行（列）的$k$倍加到另一行（列）**：$|A'| = |A|$

### 5.3 行列式的乘积定理
$$
|AB| = |A| \cdot |B|
$$

**推论**：
1. $|A^k| = |A|^k$
2. $|kA| = k^n|A|$
3. 若$A$可逆，则$|A^{-1}| = |A|^{-1}$

### 5.4 分块矩阵的行列式
1. **准对角矩阵**：
$$
\begin{vmatrix}
A & O \\
O & B
\end{vmatrix} = |A| \cdot |B|
$$

2. **准三角矩阵**：
$$
\begin{vmatrix}
A & C \\
O & B
\end{vmatrix} = |A| \cdot |B|, \quad
\begin{vmatrix}
A & O \\
D & B
\end{vmatrix} = |A| \cdot |B|
$$

3. **一般分块**（Schur补公式）：
若$A$可逆，则：
$$
\begin{vmatrix}
A & B \\
C & D
\end{vmatrix} = |A| \cdot |D - CA^{-1}B|
$$
若$D$可逆，则：
$$
\begin{vmatrix}
A & B \\
C & D
\end{vmatrix} = |D| \cdot |A - BD^{-1}C|
$$

## 行列式计算

### 6.1 按行（列）展开（Laplace展开）
**余子式**：$M_{ij}$表示删除第$i$行第$j$列后的$n-1$阶行列式

**代数余子式**：$A_{ij} = (-1)^{i+j}M_{ij}$

**展开定理**：
$$
|A| = \sum_{j=1}^n a_{ij}A_{ij} \quad (\text{按第}i\text{行展开})
$$
$$
|A| = \sum_{i=1}^n a_{ij}A_{ij} \quad (\text{按第}j\text{列展开})
$$

**零元多的行（列）展开原则**：优先选择零元素多的行（列）展开

### 6.2 递推法
常用于三对角行列式或具有递推结构的行列式

**三对角行列式**：
$$
D_n = \begin{vmatrix}
a & b & 0 & \cdots & 0 & 0 \\
c & a & b & \cdots & 0 & 0 \\
0 & c & a & \cdots & 0 & 0 \\
\vdots & \vdots & \vdots & \ddots & \vdots & \vdots \\
0 & 0 & 0 & \cdots & a & b \\
0 & 0 & 0 & \cdots & c & a
\end{vmatrix}
$$
递推公式：$D_n = aD_{n-1} - bcD_{n-2}$

### 6.3 数学归纳法
1. 验证$n=1,2$时成立
2. 假设$n=k$时成立
3. 证明$n=k+1$时成立，通常利用展开建立递推关系

### 6.4 加边法（升阶法）
将$n$阶行列式转化为$n+1$阶行列式计算，适用于各行（列）元素之和相等的情况

### 6.5 拆项法
利用行列式的线性性质，将行列式拆分为若干个行列式之和

### 6.6 范德蒙德行列式
$$
V_n = \begin{vmatrix}
1 & 1 & 1 & \cdots & 1 \\
x_1 & x_2 & x_3 & \cdots & x_n \\
x_1^2 & x_2^2 & x_3^2 & \cdots & x_n^2 \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
x_1^{n-1} & x_2^{n-1} & x_3^{n-1} & \cdots & x_n^{n-1}
\end{vmatrix} = \prod_{1 \leq i < j \leq n} (x_j - x_i)
$$

### 6.7 爪型行列式
形如：
$$
\begin{vmatrix}
a_1 & b_2 & b_3 & \cdots & b_n \\
c_2 & a_2 & 0 & \cdots & 0 \\
c_3 & 0 & a_3 & \cdots & 0 \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
c_n & 0 & 0 & \cdots & a_n
\end{vmatrix}
$$
计算方法：将第$i$列乘以$-c_i/a_i$加到第一列（$i=2,3,\ldots,n$）

### 6.8 循环行列式
各行（列）元素循环出现的行列式，常利用单位根或递推法计算

%% ### 6.9 伴随矩阵法 %%
%% 若$A$可逆，则$|A| = \frac{1}{|A^{-1}|}$
 %%
## 矩阵的逆

### 7.1 逆矩阵定义
对于$n$阶方阵$A$，若存在$B$使得$AB=BA=I$，则称$A$可逆，$B$为$A$的逆矩阵，记作$A^{-1}$

**唯一性**：若逆矩阵存在，则唯一

### 7.2 可逆的充要条件
以下条件等价：
1. $|A| \neq 0$
2. $A$可逆
3. $A$满秩：$\text{rank}(A)=n$
4. $A$的行（列）向量线性无关
5. $Ax=0$只有零解
6. $A$的特征值全不为0

### 7.3 伴随矩阵法求逆
**伴随矩阵**：$A^* = (A_{ji})_{n\times n}$，其中$A_{ij}$是$a_{ij}$的代数余子式

**公式**：若$|A| \neq 0$，则$A^{-1} = \frac{1}{|A|}A^*$

**性质**：
1. $AA^* = A^*A = |A|I$
2. $|A^*| = |A|^{n-1}$
3. $(A^*)^{-1} = (A^{-1})^* = \frac{1}{|A|}A$
4. $(kA)^* = k^{n-1}A^*$
5. $(A^*)^T = (A^T)^*$
6. $(AB)^* = B^*A^*$
7. $(A^*)^{-1} = (A^{-1})^*$

### 7.4 初等变换法求逆
**原理**：$(A \mid I) \xrightarrow{\text{行变换}} (I \mid A^{-1})$

**步骤**：
1. 构造增广矩阵$(A \mid I_n)$
2. 对增广矩阵进行初等行变换，将$A$化为$I_n$
3. 此时右半部分即为$A^{-1}$

### 7.5 分块矩阵求逆
设分块矩阵$M = \begin{pmatrix} A & B \\ C & D \end{pmatrix}$

1. 若$A$可逆：
$$
M^{-1} = \begin{pmatrix}
A^{-1} + A^{-1}B(D-CA^{-1}B)^{-1}CA^{-1} & -A^{-1}B(D-CA^{-1}B)^{-1} \\
-(D-CA^{-1}B)^{-1}CA^{-1} & (D-CA^{-1}B)^{-1}
\end{pmatrix}
$$

2. 若$D$可逆：
$$
M^{-1} = \begin{pmatrix}
(A-BD^{-1}C)^{-1} & -(A-BD^{-1}C)^{-1}BD^{-1} \\
-D^{-1}C(A-BD^{-1}C)^{-1} & D^{-1} + D^{-1}C(A-BD^{-1}C)^{-1}BD^{-1}
\end{pmatrix}
$$

### 7.6 逆矩阵的性质
1. $(A^{-1})^{-1} = A$
2. $(kA)^{-1} = \frac{1}{k}A^{-1} \quad (k \neq 0)$
3. $(AB)^{-1} = B^{-1}A^{-1}$
4. $(A^T)^{-1} = (A^{-1})^T$
5. $|A^{-1}| = |A|^{-1}$
6. $(A^n)^{-1} = (A^{-1})^n$
7. 若$A$对称可逆，则$A^{-1}$也对称
8. 若$A$正交，则$A^{-1} = A^T$

### 7.7 广义逆（伪逆）
对于任意矩阵$A_{m\times n}$，满足以下Penrose条件之一的矩阵$X$称为广义逆：
1. $AXA = A$
2. $XAX = X$
3. $(AX)^T = AX$
4. $(XA)^T = XA$

满足所有四个条件的称为**Moore-Penrose逆**，记作$A^+$

## 矩阵的秩

### 8.1 秩的定义
**子式**：从$A$中任取$k$行$k$列交叉处的元素构成的$k$阶行列式

**秩**：$A$中非零子式的最高阶数，记作$\text{rank}(A)$或$r(A)$

**满秩**：若$\text{rank}(A)=\min(m,n)$，称$A$满秩

### 8.2 秩的性质
1. $0 \leq \text{rank}(A) \leq \min(m,n)$
2. $\text{rank}(A) = \text{rank}(A^T)$
3. $\text{rank}(kA) = \text{rank}(A) \quad (k \neq 0)$
4. $\text{rank}(AB) \leq \min\{\text{rank}(A), \text{rank}(B)\}$
5. $\text{rank}(A+B) \leq \text{rank}(A) + \text{rank}(B)$
6. $\text{rank}(A) + \text{rank}(B) - n \leq \text{rank}(AB)$（Sylvester秩不等式）
7. $\text{rank}(A) = \text{rank}(A^TA) = \text{rank}(AA^T)$
8. 初等变换不改变矩阵的秩

### 8.3 秩的求法
1. **定义法**：找非零子式的最高阶数
2. **初等变换法**：化为行阶梯形，非零行数即为秩
3. **标准形法**：通过初等变换化为$\begin{pmatrix} I_r & O \\ O & O \end{pmatrix}$
4. **利用线性方程组**：$\text{rank}(A)$等于列向量组的极大无关组所含向量个数
5. **利用特征值**：非零特征值的个数（重根按重数计）

### 8.4 满秩分解
任意矩阵$A_{m\times n}$可分解为$A = BC$，其中$B_{m\times r}$列满秩，$C_{r\times n}$行满秩，且$r=\text{rank}(A)$

**求法**：
1. 对$A$进行初等行变换化为行最简形$R$
2. $R$的非零行构成$C$
3. $A$中与$R$的主元列对应的列构成$B$

### 8.5 秩与行列式的关系
1. $\text{rank}(A) = r \iff A$有$r$阶非零子式，所有$r+1$阶子式为0
2. 若$|A| \neq 0$，则$\text{rank}(A)=n$
3. 若$|A|=0$，则$\text{rank}(A) < n$

### 8.6 秩与线性方程组
对于线性方程组$Ax=b$：
1. $\text{rank}(A) = \text{rank}(A|b) = n$：唯一解
2. $\text{rank}(A) = \text{rank}(A|b) < n$：无穷多解
3. $\text{rank}(A) < \text{rank}(A|b)$：无解

## 矩阵分块

### 9.1 分块矩阵的运算
设$A=\begin{pmatrix} A_{11} & A_{12} \\ A_{21} & A_{22} \end{pmatrix}$, $B=\begin{pmatrix} B_{11} & B_{12} \\ B_{21} & B_{22} \end{pmatrix}$

1. **加法**（分块一致）：
$$
A+B = \begin{pmatrix}
A_{11}+B_{11} & A_{12}+B_{12} \\
A_{21}+B_{21} & A_{22}+B_{22}
\end{pmatrix}
$$

2. **数乘**：
$$
kA = \begin{pmatrix}
kA_{11} & kA_{12} \\
kA_{21} & kA_{22}
\end{pmatrix}
$$

3. **乘法**（列分法与行分法匹配）：
$$
AB = \begin{pmatrix}
A_{11}B_{11}+A_{12}B_{21} & A_{11}B_{12}+A_{12}B_{22} \\
A_{21}B_{11}+A_{22}B_{21} & A_{21}B_{12}+A_{22}B_{22}
\end{pmatrix}
$$

4. **转置**：
$$
A^T = \begin{pmatrix}
A_{11}^T & A_{21}^T \\
A_{12}^T & A_{22}^T
\end{pmatrix}
$$

### 9.2 分块对角矩阵
$$
\Lambda = \begin{pmatrix}
A_1 & O & \cdots & O \\
O & A_2 & \cdots & O \\
\vdots & \vdots & \ddots & \vdots \\
O & O & \cdots & A_k
\end{pmatrix}
$$

**性质**：
1. $|\Lambda| = |A_1||A_2|\cdots|A_k|$
2. $\Lambda$可逆$\iff$每个$A_i$可逆，且$\Lambda^{-1} = \text{diag}(A_1^{-1}, A_2^{-1}, \ldots, A_k^{-1})$
3. $\Lambda^n = \text{diag}(A_1^n, A_2^n, \ldots, A_k^n)$

### 9.3 分块三角矩阵
**上分块三角**：
$$
U = \begin{pmatrix}
A & B \\
O & D
\end{pmatrix}
$$
若$A,D$可逆，则：
$$
U^{-1} = \begin{pmatrix}
A^{-1} & -A^{-1}BD^{-1} \\
O & D^{-1}
\end{pmatrix}
$$

**下分块三角**：
$$
L = \begin{pmatrix}
A & O \\
C & D
\end{pmatrix}
$$
若$A,D$可逆，则：
$$
L^{-1} = \begin{pmatrix}
A^{-1} & O \\
-D^{-1}CA^{-1} & D^{-1}
\end{pmatrix}
$$

### 9.4 分块矩阵的应用
1. **简化行列式计算**
2. **简化矩阵求逆**
3. **简化矩阵乘法**
4. **证明矩阵等式**
5. **求解线性方程组**

## 特征值与特征向量

### 10.1 定义与求法
对于$n$阶方阵$A$，若存在数$\lambda$和非零向量$x$使得：
$$
Ax = \lambda x
$$
则称$\lambda$为$A$的特征值，$x$为对应的特征向量

**特征多项式**：$f(\lambda) = |A - \lambda I|$

**特征方程**：$|A - \lambda I| = 0$

**求法**：
1. 计算特征多项式$|A-\lambda I|$
2. 解特征方程得特征值$\lambda_1, \lambda_2, \ldots, \lambda_n$
3. 对每个$\lambda_i$，解$(A-\lambda_i I)x=0$得特征向量

### 10.2 特征值的性质
设$A$的特征值为$\lambda_1, \lambda_2, \ldots, \lambda_n$：
1. $\sum_{i=1}^n \lambda_i = \text{tr}(A)$
2. $\prod_{i=1}^n \lambda_i = |A|$
3. $kA$的特征值为$k\lambda_i$
4. $A^k$的特征值为$\lambda_i^k$
5. 若$A$可逆，则$A^{-1}$的特征值为$1/\lambda_i$
6. $f(A)$的特征值为$f(\lambda_i)$
7. $A$与$A^T$有相同的特征值
8. 实对称矩阵的特征值都是实数

### 10.3 特征向量的性质
1. 不同特征值对应的特征向量线性无关
2. $k$重特征值至多有$k$个线性无关的特征向量
3. 若$\lambda$是$A$的特征值，则$\lambda^k$是$A^k$的特征值，且特征向量不变
4. 若$A$可逆，则$1/\lambda$是$A^{-1}$的特征值，特征向量不变

### 10.4 特征子空间
$V_\lambda = \{x \in \mathbb{R}^n \mid Ax = \lambda x\} = \text{Ker}(A-\lambda I)$
- 是$A$的属于$\lambda$的特征向量加上零向量构成的子空间
- $\dim V_\lambda$称为特征值$\lambda$的几何重数

### 10.5 代数重数与几何重数
**代数重数**：特征值作为特征多项式根的重数

**几何重数**：特征子空间的维数

**关系**：几何重数 $\leq$ 代数重数

### 10.6 谱半径
$\rho(A) = \max\{|\lambda_i| \mid i=1,2,\ldots,n\}$

**性质**：
1. $\rho(A) \leq \|A\|$（对任意矩阵范数）
2. $\rho(A^k) = [\rho(A)]^k$
3. 若$A$可逆，则$\rho(A^{-1}) = 1/\rho(A)$

## 矩阵对角化

### 11.1 相似矩阵
若存在可逆矩阵$P$使得$P^{-1}AP = B$，则称$A$与$B$相似，记作$A \sim B$

**性质**：
1. 反身性：$A \sim A$
2. 对称性：若$A \sim B$，则$B \sim A$
3. 传递性：若$A \sim B$，$B \sim C$，则$A \sim C$
4. 相似矩阵有相同的特征多项式、特征值、行列式、迹、秩
5. $A \sim B \Rightarrow f(A) \sim f(B)$

### 11.2 可对角化条件
$n$阶方阵$A$可对角化$\iff$满足以下任一条件：
1. $A$有$n$个线性无关的特征向量
2. $A$的每个特征值的代数重数等于几何重数
3. $A$的最小多项式无重根
4. $\mathbb{C}^n$能分解为$A$的特征子空间的直和

### 11.3 对角化方法
1. 求$A$的特征值$\lambda_1, \lambda_2, \ldots, \lambda_n$
2. 对每个特征值$\lambda_i$，求基础解系$x_{i1}, x_{i2}, \ldots, x_{ik_i}$
3. 若总共有$n$个线性无关的特征向量，则$A$可对角化
4. 令$P = (x_1, x_2, \ldots, x_n)$，则$P^{-1}AP = \text{diag}(\lambda_1, \lambda_2, \ldots, \lambda_n)$

### 11.4 实对称矩阵的对角化
**性质**：
1. 特征值都是实数
2. 不同特征值对应的特征向量正交
3. 必可正交对角化：存在正交矩阵$Q$使得$Q^TAQ = \text{diag}(\lambda_1, \lambda_2, \ldots, \lambda_n)$

**正交对角化步骤**：
1. 求特征值和特征向量
2. 对每个特征值，将特征向量正交化、单位化
3. 将所得正交单位向量按列排成矩阵$Q$

### 11.5 若尔当标准形
对于不可对角化的矩阵，存在可逆矩阵$P$使得：
$$
P^{-1}AP = J = \begin{pmatrix}
J_1(\lambda_1) & & \\
& J_2(\lambda_2) & \\
& & \ddots \\
& & & J_k(\lambda_k)
\end{pmatrix}
$$
其中$J_i(\lambda_i)$是若尔当块：
$$
J_i(\lambda_i) = \begin{pmatrix}
\lambda_i & 1 & & \\
& \lambda_i & \ddots & \\
& & \ddots & 1 \\
& & & \lambda_i
\end{pmatrix}
$$

### 11.6 应用
1. **计算矩阵幂**：若$A=PDP^{-1}$，则$A^n = PD^nP^{-1}$
2. **解微分方程组**
3. **矩阵函数**：$f(A) = Pf(D)P^{-1}$
4. **二次型化简**
5. **马尔可夫链**

## 特殊行列式

### 12.1 范德蒙德行列式及其变体
**标准形式**：如前所述

**变体1**：
$$
\begin{vmatrix}
1 & 1 & \cdots & 1 \\
x_1^m & x_2^m & \cdots & x_n^m \\
x_1^{m+1} & x_2^{m+1} & \cdots & x_n^{m+1} \\
\vdots & \vdots & \ddots & \vdots \\
x_1^{m+n-2} & x_2^{m+n-2} & \cdots & x_n^{m+n-2}
\end{vmatrix} = \prod_{1 \leq i < j \leq n} (x_j - x_i) \cdot \prod_{i=1}^n x_i^{m-1}
$$

**变体2**（缺行范德蒙德）：
$$
\begin{vmatrix}
1 & 1 & 1 \\
a & b & c \\
a^3 & b^3 & c^3
\end{vmatrix} = (b-a)(c-a)(c-b)(a+b+c)
$$

### 12.2 循环行列式
$$
C_n = \begin{vmatrix}
a_0 & a_1 & a_2 & \cdots & a_{n-1} \\
a_{n-1} & a_0 & a_1 & \cdots & a_{n-2} \\
a_{n-2} & a_{n-1} & a_0 & \cdots & a_{n-3} \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
a_1 & a_2 & a_3 & \cdots & a_0
\end{vmatrix}
= \prod_{k=0}^{n-1} f(\omega^k)
$$
其中$f(x) = a_0 + a_1x + a_2x^2 + \cdots + a_{n-1}x^{n-1}$，$\omega = e^{2\pi i/n}$

### 12.3 三对角行列式
1. **对称三对角**：
$$
D_n = \begin{vmatrix}
a & b & 0 & \cdots & 0 \\
b & a & b & \cdots & 0 \\
0 & b & a & \cdots & 0 \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
0 & 0 & 0 & \cdots & a
\end{vmatrix}
$$
递推式：$D_n = aD_{n-1} - b^2D_{n-2}$

2. **一般三对角**：
$$
T_n = \begin{vmatrix}
a_1 & b_1 & 0 & \cdots & 0 \\
c_1 & a_2 & b_2 & \cdots & 0 \\
0 & c_2 & a_3 & \cdots & 0 \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
0 & 0 & 0 & \cdots & a_n
\end{vmatrix}
$$
递推式：$T_n = a_nT_{n-1} - b_{n-1}c_{n-1}T_{n-2}$

### 12.4 箭形行列式
$$
\begin{vmatrix}
a_0 & b_1 & b_2 & \cdots & b_n \\
c_1 & a_1 & 0 & \cdots & 0 \\
c_2 & 0 & a_2 & \cdots & 0 \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
c_n & 0 & 0 & \cdots & a_n
\end{vmatrix} = \left(a_0 - \sum_{i=1}^n \frac{b_i c_i}{a_i}\right) \prod_{i=1}^n a_i
$$

### 12.5 两线型行列式
$$
\begin{vmatrix}
1 & a_1 & 0 & 0 & \cdots & 0 & 0 \\
1 & b_1 & a_2 & 0 & \cdots & 0 & 0 \\
0 & 1 & b_2 & a_3 & \cdots & 0 & 0 \\
\vdots & \vdots & \vdots & \vdots & \ddots & \vdots & \vdots \\
0 & 0 & 0 & 0 & \cdots & b_{n-1} & a_n \\
0 & 0 & 0 & 0 & \cdots & 1 & b_n
\end{vmatrix}
$$
可按第一行或最后一行展开得递推式

### 12.6 希尔伯特行列式
$$
H_n = \begin{vmatrix}
1 & \frac{1}{2} & \frac{1}{3} & \cdots & \frac{1}{n} \\
\frac{1}{2} & \frac{1}{3} & \frac{1}{4} & \cdots & \frac{1}{n+1} \\
\frac{1}{3} & \frac{1}{4} & \frac{1}{5} & \cdots & \frac{1}{n+2} \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
\frac{1}{n} & \frac{1}{n+1} & \frac{1}{n+2} & \cdots & \frac{1}{2n-1}
\end{vmatrix} = \frac{[1!2!\cdots(n-1)!]^4}{1!2!\cdots(2n-1)!}
$$

### 12.7 行列式的导数
若行列式元素是变量的函数，则：
$$
\frac{d}{dt}|A(t)| = \sum_{i=1}^n \sum_{j=1}^n \frac{\partial |A|}{\partial a_{ij}} \frac{da_{ij}}{dt} = |A(t)| \cdot \text{tr}\left(A^{-1}(t)\frac{dA}{dt}\right)
$$

## 附录：重要公式总结

### A.1 行列式展开公式
1. **按行展开**：$|A| = \sum_{j=1}^n a_{ij}A_{ij}$
2. **按列展开**：$|A| = \sum_{i=1}^n a_{ij}A_{ij}$
3. **异乘变零**：$\sum_{j=1}^n a_{ij}A_{kj} = 0 \quad (i \neq k)$

### A.2 矩阵恒等式
1. $(I - A)^{-1} = I + A + A^2 + \cdots + A^{k-1} + A^k(I-A)^{-1}$
2. **Woodbury公式**：$(A + UCV)^{-1} = A^{-1} - A^{-1}U(C^{-1} + VA^{-1}U)^{-1}VA^{-1}$
3. **矩阵行列式引理**：$|A + uv^T| = |A|(1 + v^T A^{-1} u)$

### A.3 特征多项式系数
设$f(\lambda) = |A - \lambda I| = (-1)^n[\lambda^n - c_1\lambda^{n-1} + c_2\lambda^{n-2} - \cdots + (-1)^n c_n]$
则：
- $c_1 = \text{tr}(A)$
- $c_n = |A|$
- $c_k$是所有$k$阶主子式之和

### A.4 凯莱-哈密顿定理
矩阵$A$满足其自身的特征多项式：
$$
f(A) = A^n - c_1A^{n-1} + c_2A^{n-2} - \cdots + (-1)^n c_n I = O
$$

---
*本指南涵盖了线性代数中矩阵与行列式的核心内容，包括基础概念、运算规则、重要性质和计算方法。掌握这些知识点对于深入理解线性代数及其应用至关重要。*