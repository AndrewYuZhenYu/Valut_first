

---

# 离散数学公式总表

## 一、命题逻辑

### 1. 命题与逻辑联结词

设 $p,q$ 为命题。

| 名称 | 符号 | 含义 |
|---|---|---|
| 非 | $\neg p$ | $p$ 不成立 |
| 合取 | $p\land q$ | $p$ 且 $q$ |
| 析取 | $p\lor q$ | $p$ 或 $q$ |
| 异或 | $p\oplus q$ | $p$、$q$ 恰有一个成立 |
| 蕴含 | $p\to q$ | 若 $p$ 则 $q$ |
| 双条件 | $p\leftrightarrow q$ | $p$ 当且仅当 $q$ |

### 2. 基本等价公式

**双重否定**

$\neg\neg p\equiv p$

**幂等律**

$p\lor p\equiv p$

$p\land p\equiv p$

**交换律**

$p\lor q\equiv q\lor p$

$p\land q\equiv q\land p$

**结合律**

$(p\lor q)\lor r\equiv p\lor(q\lor r)$

$(p\land q)\land r\equiv p\land(q\land r)$

**分配律**

$p\lor(q\land r)\equiv(p\lor q)\land(p\lor r)$

$p\land(q\lor r)\equiv(p\land q)\lor(p\land r)$

### 3. 德·摩根律

$\boxed{\neg(p\land q)\equiv\neg p\lor\neg q}$

$\boxed{\neg(p\lor q)\equiv\neg p\land\neg q}$

### 4. 吸收律

$p\lor(p\land q)\equiv p$

$p\land(p\lor q)\equiv p$

### 5. 常量律

$p\lor 0\equiv p$

$p\land 1\equiv p$

$p\lor 1\equiv 1$

$p\land 0\equiv 0$

$p\lor\neg p\equiv 1$

$p\land\neg p\equiv 0$

### 6. 蕴含式

非常重要：

$\boxed{p\to q\equiv\neg p\lor q}$

$\boxed{\neg(p\to q)\equiv p\land\neg q}$

逆命题：

$q\to p$

否命题：

$\neg p\to\neg q$

逆否命题：

$\boxed{\neg q\to\neg p}$

其中：

$\boxed{p\to q\equiv\neg q\to\neg p}$

### 7. 双条件

$p\leftrightarrow q\equiv(p\to q)\land(q\to p)$

也可以写成：

$\boxed{p\leftrightarrow q\equiv(p\land q)\lor(\neg p\land\neg q)}$

### 8. 异或

$p\oplus q\equiv(p\lor q)\land\neg(p\land q)$

$\boxed{p\oplus q\equiv(p\land\neg q)\lor(\neg p\land q)}$

---

## 二、命题公式的判定

### 1. 重言式

任何情况下都为真：

$P\equiv 1$

### 2. 矛盾式

任何情况下都为假：

$P\equiv 0$

### 3. 可满足式

至少存在一种赋值使：

$P=1$

### 4. 逻辑等价

$P\equiv Q$

表示所有赋值下真值都相同。

等价于：

$P\leftrightarrow Q$

是重言式。

### 5. 逻辑蕴含

$P\models Q$

表示：

$P=1\Rightarrow Q=1$

等价于：

$P\to Q$

是重言式。

---

## 三、范式

### 1. 析取范式 DNF

若公式表示为：

$P_1\lor P_2\lor\cdots\lor P_n$

其中每个 $P_i$ 是若干命题变元或其否定的合取，则为析取范式。

例如：

$(p\land q)\lor(\neg p\land r)$

### 2. 合取范式 CNF

$P_1\land P_2\land\cdots\land P_n$

其中每个 $P_i$ 是若干命题变元或其否定的析取。

例如：

$(p\lor q)\land(\neg p\lor r)$

### 3. 主析取范式

对于真值表中：

$P=1$

的每一行，构造一个极小项，然后全部析取。

若有 $n$ 个命题变元：

$\boxed{\text{主析取范式项数}=\text{真值表中1的个数}}$

### 4. 主合取范式

对于：

$P=0$

的每一行构造一个极大项，然后全部合取。

$\boxed{\text{主合取范式项数}=\text{真值表中0的个数}}$

---

## 四、谓词逻辑

### 1. 全称量词

$\forall xP(x)$

表示所有 $x$ 都满足 $P(x)$。

### 2. 存在量词

$\exists xP(x)$

表示至少存在一个 $x$ 满足 $P(x)$。

### 3. 量词否定

这是考试重点：

$\boxed{\neg\forall xP(x)\equiv\exists x\neg P(x)}$

$\boxed{\neg\exists xP(x)\equiv\forall x\neg P(x)}$

### 例

$\neg(\forall xP(x))$

变成：

$\exists x\neg P(x)$

---

## 五、集合

设全集为 $U$。

### 1. 基本运算

并集：

$A\cup B$

交集：

$A\cap B$

差集：

$A-B$

补集：

$\bar A=U-A$

对称差：

$A\triangle B$

其中：

$\boxed{A\triangle B=(A-B)\cup(B-A)}$

也有：

$\boxed{A\triangle B=(A\cup B)-(A\cap B)}$

---

## 六、集合恒等式

### 1. 交换律

$A\cup B=B\cup A$

$A\cap B=B\cap A$

### 2. 结合律

$(A\cup B)\cup C=A\cup(B\cup C)$

$(A\cap B)\cap C=A\cap(B\cap C)$

### 3. 分配律

$A\cup(B\cap C)=(A\cup B)\cap(A\cup C)$

$A\cap(B\cup C)=(A\cap B)\cup(A\cap C)$

### 4. 德·摩根律

$\boxed{\overline{A\cup B}=\bar A\cap\bar B}$

$\boxed{\overline{A\cap B}=\bar A\cup\bar B}$

### 5. 吸收律

$A\cup(A\cap B)=A$

$A\cap(A\cup B)=A$

### 6. 补集

$A\cup\bar A=U$

$A\cap\bar A=\varnothing$

$\overline{\bar A}=A$

---

## 七、集合的基数

集合 $A$ 的元素个数：

$|A|$

### 1. 两集合容斥

$\boxed{|A\cup B|=|A|+|B|-|A\cap B|}$

### 2. 三集合容斥

$\boxed{|A\cup B\cup C|=|A|+|B|+|C|-|A\cap B|-|A\cap C|-|B\cap C|+|A\cap B\cap C|}$

### 3. 一般容斥

$\boxed{\left|\bigcup_{i=1}^{n}A_i\right|=\sum |A_i|-\sum |A_i\cap A_j|+\sum |A_i\cap A_j\cap A_k|-\cdots+(-1)^{n+1}|A_1\cap\cdots\cap A_n|}$

---

## 八、幂集

集合 $A$ 的幂集：

$P(A)$

如果：

$|A|=n$

则：

$\boxed{|P(A)|=2^n}$

空集：

$P(\varnothing)=\{\varnothing\}$

所以：

$|P(\varnothing)|=1$

---

## 九、笛卡尔积

$A\times B=\{(a,b)\mid a\in A,b\in B\}$

若：

$|A|=m,\qquad |B|=n$

则：

$\boxed{|A\times B|=mn}$

$n$ 个集合：

$|A_1\times A_2\times\cdots\times A_n|=\prod_{i=1}^{n}|A_i|$

---

## 十、关系

设：

$R\subseteq A\times B$

称 $R$ 为从 $A$ 到 $B$ 的关系。

如果：

$R\subseteq A\times A$

则称为 $A$ 上的关系。

---

## 十一、关系的性质

### 1. 自反性

$\boxed{\forall x\in A,\quad xRx}$

即：

$\Delta_A\subseteq R$

其中：

$\Delta_A=\{(x,x)\mid x\in A\}$

### 2. 反自反

$\boxed{\forall x\in A,\quad x\not Rx}$

### 3. 对称性

$\boxed{xRy\Rightarrow yRx}$

即：

$(a,b)\in R\Rightarrow(b,a)\in R$

### 4. 反对称性

$\boxed{xRy\land yRx\Rightarrow x=y}$

注意：

**反对称 $\ne$ 不对称。**

### 5. 传递性

$\boxed{xRy\land yRz\Rightarrow xRz}$

---

## 十二、特殊关系

### 1. 等价关系

同时满足：

$\boxed{\text{自反}+\text{对称}+\text{传递}}$

等价关系产生：

$\boxed{\text{等价类}}$

$[x]=\{y\in A\mid xRy\}$

不同等价类：

$[x]\cap[y]=\varnothing$

或者：

$[x]=[y]$

等价类构成集合的一个：

$\boxed{\text{划分}}$

---

## 十三、偏序关系

偏序关系满足：

$\boxed{\text{自反}+\text{反对称}+\text{传递}}$

记：

$(A,\preceq)$

如果任意两个元素都可比较，则称为全序：

$\boxed{\forall a,b\in A,\quad a\preceq b\lor b\preceq a}$

---

## 十四、关系的运算

关系复合：

$R\circ S$

定义：

$\boxed{R\circ S=\{(x,z)\mid\exists y,\ xSy\land yRz\}}$

逆关系：

$\boxed{R^{-1}=\{(y,x)\mid(x,y)\in R\}}$

关系幂：

$R^2=R\circ R$

$R^n=R^{n-1}\circ R$

---

## 十五、传递闭包

关系 $R$ 的传递闭包：

$R^+$

通常：

$\boxed{R^+=R\cup R^2\cup R^3\cup\cdots}$

自反传递闭包：

$\boxed{R^*=I_A\cup R\cup R^2\cup\cdots}$

其中：

$I_A=\{(x,x)\mid x\in A\}$

---

## 十六、函数

函数：

$f:A\to B$

表示：

$\forall x\in A$

存在唯一：

$y\in B$

使：

$f(x)=y$

### 定义域

$A$

### 陪域

$B$

### 值域

$f(A)$

---

## 十七、单射、满射、双射

### 1. 单射

$\boxed{f(x_1)=f(x_2)\Rightarrow x_1=x_2}$

不同输入不会得到相同输出。

若有限集合：

$\boxed{|A|\le |B|}$

### 2. 满射

$\boxed{\forall y\in B,\exists x\in A:f(x)=y}$

有限集合：

$\boxed{|A|\ge |B|}$

### 3. 双射

同时：

$\boxed{\text{单射}+\text{满射}}$

有限集合：

$\boxed{|A|=|B|}$

---

## 十八、函数复合

若：

$f:A\to B$

$g:B\to C$

则：

$\boxed{(g\circ f)(x)=g(f(x))}$

一般：

$g\circ f\ne f\circ g$

---

## 十九、逆函数

如果 $f$ 是双射，则存在：

$f^{-1}$

满足：

$\boxed{f^{-1}\circ f=I_A}$

$\boxed{f\circ f^{-1}=I_B}$

---

## 二十、组合数学基础

这是离散数学中非常重要的一块。

### 1. 加法原理

如果任务有 $m$ 种方式或 $n$ 种方式，且两类互斥：

$\boxed{m+n}$

### 2. 乘法原理

第一步 $m$ 种，第二步 $n$ 种：

$\boxed{mn}$

---

## 二十一、阶乘

$\boxed{n!=n(n-1)\cdots2\cdot1}$

规定：

$\boxed{0!=1}$

---

## 二十二、排列

从 $n$ 个不同元素中取 $r$ 个排列：

$\boxed{P(n,r)=\frac{n!}{(n-r)!}}$

也写：

$A_n^r$

### 全排列

$\boxed{P(n,n)=n!}$

---

## 二十三、组合

从 $n$ 个元素中选 $r$ 个：

$\boxed{C_n^r=\binom nr=\frac{n!}{r!(n-r)!}}$

### 基本性质

$\boxed{\binom nr=\binom n{n-r}}$

$\boxed{\binom n0=\binom nn=1}$

### Pascal 公式

$\boxed{\binom nr=\binom{n-1}{r-1}+\binom{n-1}{r}}$

---

## 二十四、二项式定理

$\boxed{(x+y)^n=\sum_{k=0}^{n}\binom nk x^{n-k}y^k}$

特别：

$(x+y)^2=x^2+2xy+y^2$

---

## 二十五、二项式系数的重要公式

$\boxed{\sum_{k=0}^{n}\binom nk=2^n}$

$\boxed{\sum_{k=0}^{n}(-1)^k\binom nk=0}$

当 $n>0$。

还有：

$\boxed{\sum_{k=0}^{n}k\binom nk=n2^{n-1}}$

---

## 二十六、可重复排列

从 $n$ 种元素中取 $r$ 个，每次可重复：

$\boxed{n^r}$

---

## 二十七、可重复组合

从 $n$ 种元素中选 $r$ 个，可以重复：

$\boxed{\binom{n+r-1}{r}}$

这是“隔板法”的核心公式。

---

## 二十八、含重复元素的排列

总共有：

$n$

个元素，其中：

$n_1,n_2,\cdots,n_k$

类相同元素，则排列数：

$\boxed{\frac{n!}{n_1!n_2!\cdots n_k!}}$

---

## 二十九、圆排列

$n$ 个不同元素围成一圈：

$\boxed{(n-1)!}$

如果考虑顺时针、逆时针相同：

$\boxed{\frac{(n-1)!}{2}}$

---

## 三十、抽屉原理

### 基本形式

把：

$n+1$

个物体放入：

$n$

个抽屉：

$\boxed{\text{至少一个抽屉有2个}}$

### 一般形式

把 $N$ 个物体放入 $k$ 个抽屉，则至少一个抽屉中有：

$\boxed{\left\lceil\frac Nk\right\rceil}$

个物体。

---

## 三十一、二元关系矩阵

若：

$A=\{a_1,\dots,a_m\}$

关系 $R$ 可以表示成矩阵：

$M_R=(m_{ij})$

其中：

$\boxed{m_{ij}=\begin{cases}1 & (a_i,a_j)\in R\\0 & (a_i,a_j)\notin R\end{cases}}$

### 矩阵判断

自反：

$\boxed{\text{主对角线全为1}}$

反自反：

$\boxed{\text{主对角线全为0}}$

对称：

$\boxed{M_R=M_R^T}$

---

## 三十二、图论基础

图：

$G=(V,E)$

其中：

- $V$：顶点集
- $E$：边集

顶点数：

$|V|=n$

边数：

$|E|=m$

---

## 三十三、顶点度数

顶点 $v$ 的度：

$d(v)$

### 握手定理

$\boxed{\sum_{v\in V}d(v)=2|E|}$

所以：

$\boxed{\sum d(v)=2m}$

---

## 三十四、奇度顶点

图中奇度顶点数量一定是：

$\boxed{\text{偶数}}$

因此：

$\boxed{\#\{v:d(v)\text{为奇数}\}\equiv0\pmod2}$

---

## 三十五、简单图最大边数

$n$ 个顶点的无向简单图：

$\boxed{m_{\max}=\binom n2=\frac{n(n-1)}2}$

完全图：

$K_n$

边数：

$\boxed{|E(K_n)|=\frac{n(n-1)}2}$

每个顶点：

$\boxed{d(v)=n-1}$

---

## 三十六、有向图

有向图中：

出度：

$d^+(v)$

入度：

$d^-(v)$

满足：

$\boxed{\sum_v d^+(v)=|E|}$

$\boxed{\sum_v d^-(v)=|E|}$

因此：

$\boxed{\sum_v(d^+(v)+d^-(v))=2|E|}$

---

## 三十七、完全二部图

$K_{m,n}$

顶点数：

$\boxed{m+n}$

边数：

$\boxed{|E|=mn}$

---

## 三十八、二部图判定

图 $G$ 是二部图：

$\boxed{G\text{ 是二部图}\iff G\text{ 不含奇环}}$

---

## 三十九、图的补图

简单图 $G$ 的补图：

$\bar G$

满足：

$\boxed{E(G)\cap E(\bar G)=\varnothing}$

且：

$\boxed{E(G)\cup E(\bar G)=E(K_n)}$

因此：

$\boxed{|E(G)|+|E(\bar G)|=\frac{n(n-1)}2}$

---

## 四十、路径与回路

路径：

$v_0,v_1,\cdots,v_k$

长度：

$\boxed{k}$

简单路径：顶点不重复。

闭迹：

起点 $=$ 终点。

回路：

通常要求除起终点外顶点不重复。

---

## 四十一、连通图

无向图中任意两个顶点之间存在路径：

$\boxed{\text{连通图}}$

连通分支数：

$c(G)$

---

## 四十二、欧拉图

### 欧拉回路

经过每条边恰好一次，并回到起点。

无向图存在欧拉回路的条件：

$\boxed{G\text{ 连通且所有顶点度数均为偶数}}$

### 欧拉通路

每条边恰好经过一次，但起点和终点可以不同。

条件：

$\boxed{G\text{ 连通且恰有0个或2个奇度顶点}}$

---

## 四十三、哈密顿图

哈密顿回路：

经过每个顶点恰好一次并回到起点。

注意：

$\boxed{\text{哈密顿图没有像欧拉图那样简单的充要条件}}$

常用充分条件：

### Dirac 定理

若 $n\ge3$，且：

$\boxed{d(v)\ge\frac n2}$

对所有顶点 $v$ 成立，则 $G$ 是哈密顿图。

### Ore 定理

若对任意不相邻顶点 $u,v$：

$\boxed{d(u)+d(v)\ge n}$

则 $G$ 是哈密顿图。

---

## 四十四、平面图

平面图可以画在平面上且边之间不交叉。

### 欧拉公式

对于连通平面图：

$\boxed{V-E+F=2}$

即：

$\boxed{n-m+f=2}$

其中：

- $n$：顶点数
- $m$：边数
- $f$：面数

---

## 四十五、平面图边数限制

对于简单连通平面图：

$n\ge3$

有：

$\boxed{m\le3n-6}$

如果平面图不存在三角形：

$\boxed{m\le2n-4}$

---

## 四十六、树

树：

$\boxed{\text{连通且无回路的无向图}}$

若树有 $n$ 个顶点，则边数：

$\boxed{m=n-1}$

因此：

$\boxed{|E|=|V|-1}$

---

## 四十七、树的重要性质

以下几个条件互相等价：

一个 $n$ 阶无向图 $G$ 是树，当且仅当：

$\boxed{G\text{ 连通且无环}}$

$\boxed{|E|=|V|-1\text{ 且连通}}$

$\boxed{|E|=|V|-1\text{ 且无环}}$

$\boxed{\text{任意两点之间存在唯一简单路径}}$

---

## 四十八、树的度数

树有：

$n\ge2$

个顶点，则至少存在两个叶节点：

$\boxed{\text{至少2个度为1的顶点}}$

握手定理：

$\sum d(v)=2(n-1)$

---

## 四十九、生成树

图 $G$ 的生成树：

$T$

满足：

$V(T)=V(G)$

且：

$\boxed{|E(T)|=|V|-1}$

如果 $G$ 连通，则至少存在一棵生成树。

---

## 五十、最小生成树

常用算法：

- Kruskal
- Prim

### Kruskal 基本思想

按照边权：

$w_1\le w_2\le\cdots$

从小到大选边，但：

$\boxed{\text{不能形成回路}}$

直到选：

$\boxed{n-1}$

条边。

---

## 五十一、根树

根树中：

根节点：

$\text{root}$

节点的父节点：

$\text{parent}$

子节点：

$\text{children}$

叶节点：

$\boxed{d_{\text{children}}=0}$

---

## 五十二、二叉树

每个节点最多：

$\boxed{2}$

个孩子。

满二叉树：

每个非叶节点都有两个孩子。

完全二叉树：

除最后一层外全部填满，最后一层从左到右排列。

---

## 五十三、二叉树节点数量

若二叉树高度为 $h$，根的层数记为 $0$：

最大节点数：

$\boxed{2^{h+1}-1}$

第 $i$ 层最大节点数：

$\boxed{2^i}$

若高度按层数 $h$ 计，则最大节点数：

$\boxed{2^h-1}$

**考试时一定看老师对“高度”的定义。**

---

## 五十四、二叉树叶节点

对于严格二叉树：

设：

- $n_0$：叶节点数
- $n_2$：度为 2 的节点数

则：

$\boxed{n_0=n_2+1}$

---

## 五十五、图的矩阵

邻接矩阵：

$A=(a_{ij})$

简单无向图：

$a_{ij}=\begin{cases}1 & (v_i,v_j)\in E\\0 & \text{otherwise}\end{cases}$

无向图：

$\boxed{A=A^T}$

---

## 五十六、邻接矩阵的重要性质

$\boxed{(A^k)_{ij}}$

表示从：

$v_i$

到：

$v_j$

长度为 $k$ 的**步行数量**。

特别：

$(A^2)_{ij}$

表示长度为 2 的步行数量。

---

## 五十七、图的可达矩阵

如果：

$A$

是邻接矩阵，则可达矩阵可以由：

$\boxed{A\lor A^2\lor A^3\lor\cdots\lor A^{n-1}}$

得到。

如果包含长度 0 的路径：

$\boxed{I\lor A\lor A^2\lor\cdots\lor A^{n-1}}$

---

## 五十八、Warshall 算法

用于求传递闭包。

核心思想：

$\boxed{R^{(k)}_{ij}=R^{(k-1)}_{ij}\lor(R^{(k-1)}_{ik}\land R^{(k-1)}_{kj})}$

矩阵形式：

$\boxed{r_{ij}^{(k)}=r_{ij}^{(k-1)}\lor(r_{ik}^{(k-1)}\land r_{kj}^{(k-1)})}$

---

## 五十九、最短路径

### Dijkstra

适用于：

$\boxed{\text{边权非负}}$

从单个源点求最短路径。

### Floyd

所有顶点对之间最短路径：

$\boxed{D_{ij}^{(k)}=\min\left(D_{ij}^{(k-1)},D_{ik}^{(k-1)}+D_{kj}^{(k-1)}\right)}$

---

## 六十、组合计数与图论结合

## 正则图

如果所有顶点度数都是 $r$：

$\boxed{r\text{-正则图}}$

则：

$\boxed{nr=2m}$

所以：

$\boxed{m=\frac{nr}{2}}$

---

## 六十一、递推关系

### 等差型

$a_n=a_{n-1}+d$

通项：

$\boxed{a_n=a_1+(n-1)d}$

### 等比型

$a_n=ra_{n-1}$

通项：

$\boxed{a_n=a_1r^{n-1}}$

---

## 六十二、递推数列求和

等差：

$\boxed{S_n=\frac{n(a_1+a_n)}2}$

或者：

$\boxed{S_n=\frac n2[2a_1+(n-1)d]}$

等比：

$\boxed{S_n=a_1\frac{r^n-1}{r-1}}$

$r\ne1$。

也可写：

$\boxed{S_n=a_1\frac{1-r^n}{1-r}}$

---

## 六十三、常见递推式

### Fibonacci

$\boxed{F_n=F_{n-1}+F_{n-2}}$

通常：

$F_0=0,\quad F_1=1$

通项：

$\boxed{F_n=\frac{\varphi^n-\psi^n}{\sqrt5}}$

其中：

$\varphi=\frac{1+\sqrt5}{2}$

$\psi=\frac{1-\sqrt5}{2}$

---

## 六十四、线性递推关系

一般形式：

$\boxed{a_n=c_1a_{n-1}+c_2a_{n-2}+\cdots+c_ka_{n-k}}$

对应特征方程：

$\boxed{r^k-c_1r^{k-1}-c_2r^{k-2}-\cdots-c_k=0}$

---

## 六十五、特征根解法

若特征方程有互异根：

$r_1,r_2,\cdots,r_k$

则：

$\boxed{a_n=C_1r_1^n+C_2r_2^n+\cdots+C_kr_k^n}$

若有重根 $r$，重数为 $s$：

$\boxed{(C_0+C_1n+\cdots+C_{s-1}n^{s-1})r^n}$

---

## 六十六、数学归纳法

证明：

$P(n)$

成立。

### 第一步：基础情况

证明：

$\boxed{P(n_0)}$

成立。

### 第二步：归纳假设

假设：

$\boxed{P(k)}$

成立。

### 第三步：归纳证明

证明：

$\boxed{P(k+1)}$

成立。

所以：

$\boxed{\forall n\ge n_0,\ P(n)}$

---

## 六十七、强归纳法

假设：

$P(n_0),P(n_0+1),\cdots,P(k)$

全部成立，然后证明：

$P(k+1)$

成立。

---

## 六十八、数论基础

## 整除

$a\mid b$

表示：

$\boxed{\exists k\in\mathbb Z,\quad b=ak}$

### 整除性质

若：

$a|b,\quad a|c$

则：

$\boxed{a|(mb+nc)}$

其中：

$m,n\in\mathbb Z$

---

## 六十九、最大公因数

$\gcd(a,b)$

满足：

$d|a,\quad d|b$

且 $d$ 最大。

### Bézout 定理

$\boxed{\gcd(a,b)=ax+by}$

其中：

$x,y\in\mathbb Z$

---

## 七十、最小公倍数

$\operatorname{lcm}(a,b)$

重要公式：

$\boxed{\gcd(a,b)\operatorname{lcm}(a,b)=|ab|}$

---

## 七十一、Euclid 算法

$\boxed{\gcd(a,b)=\gcd(b,a\bmod b)}$

递归：

$\gcd(a,0)=|a|$

---

## 七十二、素数

大于 1 且只有：

$1,p$

两个正因数的整数。

若：

$p\mid ab$

且 $p$ 是素数，则：

$\boxed{p|a\quad\text{或}\quad p|b}$

---

## 七十三、模运算

$a\equiv b\pmod m$

等价于：

$\boxed{m|(a-b)}$

也就是：

$\boxed{a\bmod m=b\bmod m}$

---

## 七十四、模运算基本性质

若：

$a\equiv b\pmod m$

$c\equiv d\pmod m$

则：

$\boxed{a+c\equiv b+d\pmod m}$

$\boxed{a-c\equiv b-d\pmod m}$

$\boxed{ac\equiv bd\pmod m}$

$\boxed{a^n\equiv b^n\pmod m}$

---

## 七十五、欧拉函数

$\varphi(n)$

表示：

$1\le k\le n$

中与 $n$ 互质的数的个数。

若 $p$ 为素数：

$\boxed{\varphi(p)=p-1}$

若：

$n=p_1^{a_1}p_2^{a_2}\cdots p_k^{a_k}$

则：

$\boxed{\varphi(n)=n\prod_{i=1}^{k}\left(1-\frac1{p_i}\right)}$

---

## 七十六、欧拉定理

若：

$\gcd(a,n)=1$

则：

$\boxed{a^{\varphi(n)}\equiv1\pmod n}$

---

## 七十七、费马小定理

若 $p$ 为素数，且：

$p\nmid a$

则：

$\boxed{a^{p-1}\equiv1\pmod p}$

---

## 七十八、中国剩余定理

若：

$m_1,m_2,\cdots,m_k$

两两互质，则同余方程组：

$x\equiv a_1\pmod {m_1}$

$x\equiv a_2\pmod {m_2}$

$\cdots$

有唯一解模：

$\boxed{M=m_1m_2\cdots m_k}$

---

## 七十九、代数系统

### 半群

集合 $S$ 上有二元运算 $*$，满足：

$\boxed{\text{封闭性}+\text{结合律}}$

### 独异点 / 幺半群 Monoid

半群 $+$ 单位元：

$\boxed{\text{半群}+\text{单位元}}$

存在 $e$：

$\boxed{e*a=a*e=a}$

### 群 Group

$\boxed{\text{封闭}+\text{结合}+\text{单位元}+\text{逆元}}$

对于每个 $a$：

$\boxed{\exists a^{-1},\quad aa^{-1}=a^{-1}a=e}$

### 阿贝尔群

群再满足：

$\boxed{a*b=b*a}$

---

## 八十、群的重要结论

有限群 $G$：

$|G|=n$

则：

### Lagrange 定理

任意子群 $H$：

$\boxed{|H|\mid |G|}$

元素 $a$ 的阶：

$o(a)$

满足：

$\boxed{o(a)\mid |G|}$

---

## 八十一、图论 + 树 + 组合：最重要的数字关系

这几个建议直接背下来：

$\boxed{\sum d(v)=2|E|}$

$\boxed{|E(K_n)|=\frac{n(n-1)}2}$

$\boxed{|E(K_{m,n})|=mn}$

$\boxed{G\text{为树}\Rightarrow |E|=|V|-1}$

$\boxed{\text{树至少有两个叶节点}}$

$\boxed{V-E+F=2}$

$\boxed{m_{\text{平面简单图}}\le3n-6}$

$\boxed{m_{\text{无三角形平面图}}\le2n-4}$

$\boxed{\text{欧拉回路}\iff\text{连通+所有度数为偶数}}$

$\boxed{\text{欧拉通路}\iff\text{连通+奇度顶点数为0或2}}$

$\boxed{G\text{二部图}\iff G\text{不含奇环}}$

---

## 八十二、离散数学最值得背的“核心公式”

如果最后压缩成**考试前一页纸**，优先背这些：

### 逻辑

$p\to q\equiv\neg p\lor q$

$p\to q\equiv\neg q\to\neg p$

$\neg(p\land q)\equiv\neg p\lor\neg q$

$\neg(p\lor q)\equiv\neg p\land\neg q$

$\neg\forall xP(x)\equiv\exists x\neg P(x)$

$\neg\exists xP(x)\equiv\forall x\neg P(x)$

### 集合

$|A\cup B|=|A|+|B|-|A\cap B|$

$|P(A)|=2^{|A|}$

$|A\times B|=|A||B|$

$\overline{A\cup B}=\bar A\cap\bar B$

$\overline{A\cap B}=\bar A\cup\bar B$

### 关系

$\text{等价关系}=\text{自反}+\text{对称}+\text{传递}$

$\text{偏序关系}=\text{自反}+\text{反对称}+\text{传递}$

$R^+=R\cup R^2\cup R^3\cup\cdots$

### 函数

$\text{双射}=\text{单射}+\text{满射}$

$(g\circ f)(x)=g(f(x))$

### 组合

$n!$

$P(n,r)=\frac{n!}{(n-r)!}$

$\binom nr=\frac{n!}{r!(n-r)!}$

$\binom nr=\binom n{n-r}$

$\binom nr=\binom{n-1}{r-1}+\binom{n-1}{r}$

$(x+y)^n=\sum_{k=0}^n\binom nk x^{n-k}y^k$

$\sum_{k=0}^{n}\binom nk=2^n$

$\text{可重复排列}=n^r$

$\text{可重复组合}=\binom{n+r-1}{r}$

$\text{重复元素排列}=\frac{n!}{n_1!\cdots n_k!}$

$\text{圆排列}=(n-1)!$

$\text{抽屉原理}=\left\lceil\frac Nk\right\rceil$

### 数论

$a\equiv b\pmod m \iff m|(a-b)$

$\gcd(a,b)=\gcd(b,a\bmod b)$

$\gcd(a,b)\operatorname{lcm}(a,b)=|ab|$

$\gcd(a,b)=ax+by$

$\varphi(n)=n\prod_{p|n}\left(1-\frac1p\right)$

$a^{\varphi(n)}\equiv1\pmod n$

$a^{p-1}\equiv1\pmod p$

### 图论

$\sum d(v)=2|E|$

$|E(K_n)|=\frac{n(n-1)}2$

$|E(K_{m,n})|=mn$

$V-E+F=2$

$|E_{\text{tree}}|=|V|-1$

$n_0=n_2+1$

$m_{\text{planar}}\le3n-6$

$m_{\text{triangle-free planar}}\le2n-4$

$\text{欧拉回路}\iff 0\text{ 个奇度顶点}$

$\text{欧拉通路}\iff 0\text{ 或 }2\text{ 个奇度顶点}$

$G\text{ 二部}\iff G\text{ 无奇环}$

$(A^k)_{ij}=\text{从 }i\text{ 到 }j\text{ 长度为 }k\text{ 的步行数}$

### 递推

$a_n=c_1a_{n-1}+\cdots+c_ka_{n-k}$

$r^k-c_1r^{k-1}-\cdots-c_k=0$

$a_n=C_1r_1^n+\cdots+C_kr_k^n$

$F_n=F_{n-1}+F_{n-2}$

### 树 / 二叉树

$\boxed{|E|=|V|-1}$

$\boxed{\sum d(v)=2(|V|-1)}$

$\boxed{\text{树中任意两点有且仅有一条简单路径}}$

$\boxed{\text{树至少有两个叶节点}}$

$\boxed{\text{高度为 }h\text{ 的二叉树最多 }2^{h+1}-1\text{ 个节点}}$

---

如果你是为了**大学离散数学考试 / 期末复习**，上面这份已经覆盖了绝大多数教材的核心公式；但严格说“所有公式”还可以继续扩展到**代数系统、格与布尔代数、组合设计、生成函数、容斥高级形式、递推高级解法、图的着色、网络流、匹配、树的遍历、最小生成树、最短路径、拓扑排序**等。

如果按你平时学习 C/C++ 那种“**知识点必须完整，但不要教材式废话**”的方式，我更建议下一步把它整理成一份《离散数学期末考试公式速查表》：按**逻辑 → 集合 → 关系 → 函数 → 组合 → 数论 → 图论 → 树 → 代数系统 → 递推**逐章压缩成“**公式 + 适用条件 + 一句话怎么用**”，这样会比单纯堆公式实用得多。