2026年9月26日18:09:20
# 数理逻辑：命题逻辑知识手册

> 本文档根据《第1讲_命题逻辑-命题与联结词-命题公式》《第2讲_命题逻辑-逻辑的等值式-联结词完备集》《第3讲+命题逻辑-范式》三份课件整理，覆盖命题逻辑的基本概念、命题公式与真值表、逻辑等值演算、范式与联结词完备集。全文按照“基础概念 → 核心理论 → 计算与应用 → 知识联系与复习”组织，不按 PPT 页码顺序照搬。

---

# 第一部分 基础概念与知识框架

## 一、数理逻辑概述

### 1.1 逻辑学与数理逻辑

**逻辑学**：探索、阐述和确立有效推理原则的学科。其核心任务是研究怎样的推理是有效的、正确的。

**数理逻辑（Mathematical Logic）**：又称**符号逻辑（Symbolic Logic）**，是用数学方法研究推理的形式结构和推理规律的数学学科。它不关心推理的具体内容，只关心推理的形式结构。

**数理逻辑的四大分支**：

| 分支 | 研究对象 |
| ---- | -------- |
| 证明论 | 数学系统的逻辑结构与证明规律 |
| 模型论 | 形式系统与数学模型之间的关系 |
| 递归论 | 可计算性理论 |
| 公理集合论 | 集合论的无矛盾性问题 |

本课程介绍数理逻辑最基本的内容：**逻辑演算中的命题逻辑和一阶逻辑**。

### 1.2 数理逻辑的发展简史

| 时期 | 人物 | 贡献 |
| ---- | ---- | ---- |
| 公元前 | 亚里士多德 | 《工具论》，建立三段论，奠定演绎推理基本法则 |
| 17世纪 | 莱布尼兹 | 提出用通用科学语言将推理过程公式化计算 |
| 1847年 | 布尔 | 《逻辑的数学分析》，建立符号系统与运算法则，奠定数理逻辑基础 |
| 1884年 | 弗雷格 | 《数论的基础》，引入量词符号，使符号系统更完备 |

**亚里士多德三段论示例**：

- 所有的人都是要死的；
- 苏格拉底是人；
- 所以苏格拉底是要死的。

这是演绎推理的基本法则，也是逻辑学研究的经典对象。

### 1.3 命题逻辑的内容框架

命题逻辑是数理逻辑的入门部分，主要包含以下内容：

1. **命题与联结词**：命题的定义、五个基本逻辑联结词、命题符号化
2. **命题公式与真值表**：命题常项与变项、命题公式的定义、真值指派、公式类型、真值表
3. **逻辑等值式**：等值的定义、基本等值式、等值演算、代入规则与置换规则
4. **范式**：简单析取/合取式、析取/合取范式、极小项/极大项、主析取/主合取范式
5. **推理理论与形式结构**：推理的形式结构、推理规则

对应教材章节：

- 第1章 命题逻辑的基本概念
- 第2章 命题逻辑等值演算
- 第3章 命题逻辑的推理理论

本课程命题逻辑共 8 学时，一阶逻辑共 8 学时。

---

## 二、命题与联结词

### 2.1 命题的定义

**命题**：真假值唯一确定的**陈述句**。

判断一个语句是否为命题，需要同时满足：

1. 它是**陈述句**；
2. 它的真假值**唯一确定**。

**不是命题的情况**：

| 类型 | 例子 | 原因 |
| ---- | ---- | ---- |
| 感叹句 | 多冷啊！ | 非陈述句 |
| 祈使句 | 关上门吧！ | 非陈述句 |
| 疑问句 | 你去锻炼身体了吗？ | 非陈述句 |
| 悖论 | 这句话是假的。 | 真假值不唯一确定 |
| 含变量的陈述句 | $x+1=3$ | 真假值随 $x$ 变化 |

**命题的例子**：

- 地球围绕太阳转。（真命题）
- $2+2=5$。（假命题）
- 火星上有生命。（真值确定，只是目前未知）

### 2.2 原子命题与复合命题

| 概念 | 定义 | 例子 |
| ---- | ---- | ---- |
| 原子命题 | 不能再分解的命题，不含联结词，又称简单命题 | 老王要去出差。 |
| 复合命题 | 包含原子命题和逻辑联结词的命题 | 老王或老李中的一个人去出差。 |

**注意**：原子命题与复合命题的区分不是绝对的，取决于分析粒度。例如“俞伯牙和钟子期是好朋友”中的“和”表示两人之间的关系，不是逻辑合取，因此该命题应视为原子命题，符号化为 $Friend(\text{俞伯牙}, \text{钟子期})$，而不能拆成两个命题的合取。

### 2.3 五个基本逻辑联结词

| 联结词 | 符号 | 名称 | 真值规则 |
| ------ | ---- | ---- | -------- |
| 否定 | $\neg$ | negation | $\neg p$ 为真当且仅当 $p$ 为假 |
| 合取 | $\land$ | conjunction | $p \land q$ 为真当且仅当 $p,q$ 同时为真 |
| 析取 | $\lor$ | disjunction | $p \lor q$ 为真当且仅当 $p,q$ 至少一个为真 |
| 蕴涵 | $\to$ | conditional | $p \to q$ 为假当且仅当 $p$ 真而 $q$ 假 |
| 等价 | $\leftrightarrow$ | biconditional | $p \leftrightarrow q$ 为真当且仅当 $p,q$ 同真同假 |

### 2.4 否定联结词

**定义**：设 $p$ 为一个命题，“非 $p$”称为 $p$ 的**否定式**，记为 $\neg p$。“$\neg$”称为**否定联结词**。

**真值表**：

| $p$ | $\neg p$ |
| --- | -------- |
| 0 | 1 |
| 1 | 0 |

**自然语言对应**：“不”“没有”“无”“否定”“并非”“取反”等。

**例**：13不是偶数。设 $p$：13是偶数，则符号化为 $\neg p$。

### 2.5 合取联结词

**定义**：设 $p,q$ 为两个命题，复合命题“$p$ 而且 $q$”称为 $p,q$ 的**合取式**，记为 $p \land q$。“$\land$”称为**合取联结词**。

**真值表**：

| $p$ | $q$ | $p \land q$ |
| --- | --- | ----------- |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

**自然语言对应**：“和”“与”“且”“同时”“并且”“以及”“而且”“既……又……”“不但……而且……”“尽管……依然……”“虽然……但是……”等。

**例**：13是偶数也是奇数。设 $p$：13是偶数，$q$：13是奇数，则符号化为 $p \land q$。

**注意**：合取联结词在自然语言中对应多种表达，但并非所有含“和”“与”的句子都是合取。例如“俞伯牙和钟子期是好朋友”中的“和”表示关系，不是逻辑合取。

### 2.6 析取联结词

**定义**：设 $p,q$ 为两个命题，复合命题“$p$ 或者 $q$”称为 $p,q$ 的**析取式**，记为 $p \lor q$。“$\lor$”称为**析取联结词**。

**真值表**：

| $p$ | $q$ | $p \lor q$ |
| --- | --- | ---------- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

**自然语言对应**：“或者”“要么……要么……”“不是……就是……”等。

**相容或与排斥或**：

| 类型 | 含义 | 符号表示 |
| ---- | ---- | -------- |
| 相容或 | 二者至少有一个发生，也可二者都发生 | $p \lor q$ |
| 排斥或（异或） | 二者只有一个发生，非此即彼 | $p \oplus q \Leftrightarrow (p \land \neg q) \lor (\neg p \land q)$ |

**例**：

- “小明或许数学成绩好，或许英语成绩好” → 相容或，$p \lor q$
- “小明只能挑选203或者204房间” → 排斥或，$p \oplus q$
- “张晓静是江西人或湖南人” → 排斥或，$(p \land \neg q) \lor (\neg p \land q)$

### 2.7 蕴涵联结词

**定义**：设 $p,q$ 为命题，复合命题“如果 $p$，则 $q$”称为 $p$ 对 $q$ 的**蕴涵式**，记作 $p \to q$。“$\to$”称为**蕴涵联结词**。$p$ 称为**前件**，$q$ 称为**后件**。

**真值表**：

| $p$ | $q$ | $p \to q$ |
| --- | --- | --------- |
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

**核心规则**：$p \to q$ 为假，当且仅当 $p$ 真而 $q$ 假。当前件 $p$ 为假时，无论 $q$ 真假，$p \to q$ 都为真。

**自然语言对应**：

| 自然语言表述 | 符号化 |
| ------------ | ------ |
| 如果 $p$，则 $q$ | $p \to q$ |
| 因为 $p$，所以 $q$ | $p \to q$ |
| 只要 $p$，就 $q$ | $p \to q$ |
| 只有 $q$，才 $p$ | $p \to q$ |
| 仅当 $q$，则 $p$ | $p \to q$ |
| $p$ 是 $q$ 的充分条件 | $p \to q$ |
| $q$ 是 $p$ 的必要条件 | $p \to q$ |
| 既然 $p$，那么 $q$ | $p \to q$ |
| 除非 $q$，否则不 $p$ | $p \to q$ |

**注意**：日常语言中“如果……则……”往往表示因果关系，但数理逻辑中前件与后件可以毫不相关。例如“如果 $2+2=5$，那么美国位于非洲”在逻辑中为真。

**易错点**：

- “只有 $p$，才 $q$” 符号化为 $q \to p$，不是 $p \to q$；
- “除非 $p$，否则不 $q$” 符号化为 $q \to p$；
- “仅当 $p$，才 $q$” 符号化为 $q \to p$。

### 2.8 等价联结词

**定义**：设 $p,q$ 为命题，复合命题“$p$ 当且仅当 $q$”称为 $p,q$ 的**等价式**，记作 $p \leftrightarrow q$。“$\leftrightarrow$”称为**等价联结词**。

**真值表**：

| $p$ | $q$ | $p \leftrightarrow q$ |
| --- | --- | --------------------- |
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

**自然语言对应**：“$p$ 当且仅当 $q$”“$p$ 是 $q$ 的充分必要条件”“$p,q$ 含义相同”等。

### 2.9 命题符号化

**符号约定**：

- 原子命题：$p, q, r, p_1, q_1, r_1, \dots$
- 联结词：$\neg, \land, \lor, \to, \leftrightarrow$
- 逻辑真值：$0, 1$ 或 $F, T$

**符号化步骤**：

1. 找出所有原子命题，分别用符号表示；
2. 确定各原子命题之间的逻辑关系；
3. 选择合适的联结词连接；
4. 必要时添加括号以明确优先级。

**典型例题**：

| 自然语言命题 | 符号化 |
| ------------ | ------ |
| 小李是一名本科生，他的专业是数学或计算机 | $p \land (q \lor r)$ |
| IF P THEN Q ELSE R | $(p \to q) \land (\neg p \to r)$ |
| 只要别人有困难，老王就帮助别人，除非困难解决了 | $\neg r \to (p \to q)$ 或 $(p \land \neg r) \to q$ |
| 老王或老李中的一个人去出差，当且仅当不是他们都去或者都不去 | $((p \land \neg q) \lor (\neg p \land q)) \leftrightarrow \neg((p \land q) \lor (\neg p \land \neg q))$ |
| 仅当天气好，我才去锻炼 | $q \to p$ |
| 除非天气好，否则我不去锻炼 | $q \to p$ |
| 当天气好，我就去锻炼 | $p \to q$ |
| 两个圆的面积相等当且仅当它们的半径相等 | $p \leftrightarrow q$ |

**程序语句符号化示例**：

把程序语句 `IF P THEN Q ELSE R` 表达为复合命题：

$$
(p \to q) \land (\neg p \to r)
$$

其含义是：若 $p$ 为真，则执行 $q$；若 $p$ 为假，则执行 $r$。两者合取表示整个条件语句的逻辑结构。

### 2.10 使用联结词的注意事项

1. **不能“对号入座”**：见到“或”不一定表示为 $\lor$（可能是排斥或）；“但是”也可表示为 $\land$。
2. **真值由定义决定**：复合命题的真假值必须根据联结词的定义理解，不能根据日常语言含义理解。
3. **只关心真假关系**：数理逻辑关心命题间的真假值关系，不讨论命题的具体内容。
4. **前件为假时蕴涵为真**：这是蕴涵联结词最容易出错的地方。
5. **自然语言中语句一般具有内在联系**，而数理逻辑中的联结词仅是命题的一种连接，不一定具有内在联系。

---

## 三、命题公式与真值表

### 3.1 命题常项与命题变项

| 概念 | 定义 | 说明 |
| ---- | ---- | ---- |
| 命题常项（命题常元） | 真值确定的简单命题 | 是命题逻辑中最基本的研究单位 |
| 命题变项（命题变元） | 表示真值可以变化的陈述句 | **不是命题**，真值待指派 |

两者都用符号 $p, q, r, p_1, q_1, r_1, \dots$ 表示。

**注意**：在命题逻辑中，只研究形式推演的正确性，不关心表示式所代表的实际含义。

### 3.2 命题公式的定义

**命题公式（well-formed formula, wff）** 递归定义如下：

1. 单个命题变项 $p, q, r, \dots$ 是命题公式；
2. 如果 $A$ 是命题公式，则 $(\neg A)$ 也是命题公式；
3. 如果 $A$ 和 $B$ 是命题公式，则 $(A \land B)$、$(A \lor B)$、$(A \to B)$、$(A \leftrightarrow B)$ 也是命题公式；
4. 只有有限次应用 (1)–(3) 构成的符号串才是命题公式。

命题公式也称为**合式公式**，简称**公式**。

**不是命题公式的例子**：$pq \to pq \lor t$，$(p \to w) \land q)$（括号不匹配、缺少联结词等）。

**例**：判断以下符号串是否为命题公式：

- $p$ —— 是（规则1）
- $\neg\neg p$ —— 是（规则2两次）
- $p \land \neg p$ —— 是（规则2、3）
- $p \land q$ —— 是（规则3）
- $pq$ —— 否（两个变项直接相连，缺少联结词）
- $(p \to q) \land$ —— 否（不完整）

### 3.3 命题公式的层次

1. 若公式 $A$ 是单个命题变元，则称 $A$ 是 **0 层公式**；
2. 称 $A$ 是 **$n+1$ 层公式** 是指以下情况之一：
   - $A = \neg B$，$B$ 是 $n$ 层公式；
   - $A = B \land C$，$B,C$ 分别是 $i$ 层和 $j$ 层公式，$n = \max(i,j)$；
   - $A = B \lor C$，$B,C$ 层次同上；
   - $A = B \to C$，$B,C$ 层次同上；
   - $A = B \leftrightarrow C$，$B,C$ 层次同上。
3. 若公式 $A$ 的层次是 $k$，称 $A$ 是 **$k$ 层公式**。

**例**：$(\neg(p \to \neg q)) \land ((r \lor s) \leftrightarrow \neg q)$ 是 4 层公式。

**分析**：

- $p,q,r,s$ 是 0 层；
- $\neg q$ 是 1 层；
- $p \to \neg q$ 是 2 层；
- $\neg(p \to \neg q)$ 是 3 层；
- $r \lor s$ 是 1 层；
- $(r \lor s) \leftrightarrow \neg q$ 是 2 层；
- 整个公式的层次为 $\max(3,2)+1 = 4$ 层。

### 3.4 括号省略规则

为简化公式形式，作如下规定：

1. **优先级**：$\neg > (\land, \lor) > (\to, \leftrightarrow)$；
2. $(\neg p)$ 的括号可以省略，写成 $\neg p$；
3. 整个公式最外层的括号可以省略。

**例**：$p \to q \land r \to s$ 与 $(p \to q) \land (r \to s)$ 含义不同。前者按优先级理解为 $p \to (q \land r) \to s$，但 $\to$ 的结合性需要进一步明确。通常约定 $\to$ 是右结合的，即 $p \to q \to r$ 理解为 $p \to (q \to r)$。

### 3.5 真值指派与赋值

- 如果一个命题公式 $A$ 含有 $n$ 个命题变项 $p_1, p_2, \dots, p_n$，则该公式称为 **$n$ 元命题公式**；
- 在 $A$ 中，对变项组 $(p_1, p_2, \dots, p_n)$ 指定的一组确定真值称为该公式的一个**真值指派**或**赋值**（assignment）；
- 若指定的一组值使 $A$ 的真值为真，则称这组值为 $A$ 的**成真指派**或**成真赋值**；
- 若使 $A$ 的真值为假，则称这组值为 $A$ 的**成假指派**或**成假赋值**。

**表示**：在命题变项次序确定的情况下，一个真值指派可以表示为一个由 0 和 1 组成的 $n$ 位符号串。

**数量**：$n$ 元命题公式共有 $2^n$ 个不同的真值指派。

**例**：$(p \land q) \to r$

- $(0,1,0)$ 为成真赋值；
- $(1,1,0)$ 为成假赋值。

**求成真/成假赋值的方法**：

- 要使 $A$ 为假，根据公式结构逐步反推；
- 例：$A = (p \land q) \to (\neg(q \lor r))$，要使 $A$ 为假，必须 $p \land q$ 为真且 $\neg(q \lor r)$ 为假，即 $p,q$ 都真且 $q \lor r$ 为真。故成假赋值为 $(1,1,1)$ 和 $(1,1,0)$；其余为成真赋值。

**完整求解过程**：

$A = (p \land q) \to (\neg(q \lor r))$

要使 $A$ 为假，需要：

- 前件 $p \land q$ 为真，即 $p=1, q=1$；
- 后件 $\neg(q \lor r)$ 为假，即 $q \lor r$ 为真。由于 $q=1$，$q \lor r$ 自动为真，$r$ 可以是 0 或 1。

故成假赋值为 $(1,1,1)$ 和 $(1,1,0)$。

其余 $2^3 - 2 = 6$ 个赋值为成真赋值：$(0,0,0)$、$(1,0,0)$、$(0,1,0)$、$(0,0,1)$、$(0,1,1)$、$(1,0,1)$。

### 3.6 命题公式的类型

假设 $A$ 为一个 $n$ 元命题公式：

| 类型 | 定义 | 别名 |
| ---- | ---- | ---- |
| 永真式 | 所有 $2^n$ 个真值指派都是成真指派 | 重言式（tautology） |
| 永假式 | 所有 $2^n$ 个真值指派都是成假指派 | 矛盾式（contradiction） |
| 可满足式 | 至少存在一个成真指派 | satisfiable formula |

**例子**：

- 永假公式：$p \land \neg p$
- 永真公式：$p \lor \neg p$，$p \to p$，$(p \to q) \leftrightarrow (\neg q \to \neg p)$

**重言式的性质**：

1. 任何两个重言式的合取与析取仍然是一个重言式；
2. 设 $A,B$ 是两个命题公式，如果 $A$ 和 $A \to B$ 都是重言式，则 $B$ 也是重言式。

**思考**：第一条性质中重言式可换为矛盾式吗？

- 合取：矛盾式 $\land$ 矛盾式仍是矛盾式，可以替换；
- 析取：矛盾式 $\lor$ 矛盾式仍是矛盾式，可以替换；
- 但第二条性质不能替换，因为 $A$ 为矛盾式时 $A \to B$ 自动为真，无法推出 $B$ 为矛盾式。

### 3.7 真值表

**真值表（truth-table）**：一个命题公式在每种真值指派上的值可以直观地用真值表来计算和表示。

- 对于一个 $n$ 元命题公式 $A$，其真值表的输入端（最左 $n$ 列）的 $2^n$ 行对应于它的 $2^n$ 个真值指派；
- 输出端（最右一列）对应于命题公式在它的 $2^n$ 个真值指派下的真值。

**基本联结词真值表汇总**：

| $p$ | $q$ | $\neg p$ | $p \land q$ | $p \lor q$ | $p \to q$ | $p \leftrightarrow q$ |
| --- | --- | -------- | ----------- | ---------- | --------- | --------------------- |
| 0 | 0 | 1 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 1 | 1 |

**构造真值表的步骤**：

1. 列出公式中所有命题变项；
2. 按二进制顺序列出所有 $2^n$ 个真值指派；
3. 按公式的层次从内到外逐步计算各子公式的真值；
4. 最后一列即为公式的真值。

**真值表的作用**：

1. 表示出公式的成真或成假赋值；
2. 判断公式类型：
   - 若最后一列全为 1，则为重言式；
   - 若最后一列全为 0，则为矛盾式；
   - 若最后一列至少有一个 1，则为可满足式。

**例1**：构造 $(p \to q) \land r$ 的真值表。

| $p$ | $q$ | $r$ | $p \to q$ | $(p \to q) \land r$ |
| --- | --- | --- | --------- | ------------------- |
| 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 |

**例2**：构造 $\neg(p \to q) \land q$ 的真值表。

| $p$ | $q$ | $p \to q$ | $\neg(p \to q)$ | $\neg(p \to q) \land q$ |
| --- | --- | --------- | --------------- | ----------------------- |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 0 | 0 |

该公式为矛盾式。

**例3**：构造 $p \to (q \to r)$ 的真值表。

| $p$ | $q$ | $r$ | $q \to r$ | $p \to (q \to r)$ |
| --- | --- | --- | --------- | ------------------ |
| 0 | 0 | 0 | 1 | 1 |
| 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 0 | 0 | 1 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 |

该公式为可满足式，成假赋值为 $(1,1,0)$。

**例4**：构造 $(p \land q) \to r$ 的真值表。

| $p$ | $q$ | $r$ | $p \land q$ | $(p \land q) \to r$ |
| --- | --- | --- | ----------- | -------------------- |
| 0 | 0 | 0 | 0 | 1 |
| 0 | 0 | 1 | 0 | 1 |
| 0 | 1 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 |

该公式为可满足式，成假赋值为 $(1,1,0)$。

**注意**：$p \to (q \to r)$ 与 $(p \land q) \to r$ 等值，两者真值表最后一列完全相同。

---

# 第二部分 核心理论与方法

## 四、逻辑等值式

### 4.1 逻辑等值的定义

**定义**：若两个公式 $A, B$ 在所有赋值下都有相同的真值，则称这两个公式是**逻辑等价**或**逻辑等值式**，记作 $A \Leftrightarrow B$。

**判定条件**：$A \Leftrightarrow B$ 当且仅当 $A \leftrightarrow B$ 是永真式。

**注意区分**：

- $A \leftrightarrow B$ 是一个命题公式（对象语言）；
- $A \Leftrightarrow B$ 表示两个公式之间的等值关系（元语言）。

### 4.2 判断等值的主要方法

| 方法 | 操作 | 适用场景 |
| ---- | ---- | -------- |
| 真值表法 | 列出两个公式的真值表，判断输出列是否相同 | 变项少、公式简单 |
| 等值演算法 | 由已知等值式推演出新的等值式 | 变项多、需要化简 |
| 范式法 | 求主析取范式或主合取范式，比较是否相同 | 系统化判断 |

**真值表法示例**：判断 $p \to (q \to r)$、$(p \to q) \to r$、$(p \land q) \to r$ 之间的等值关系。

| $p$ | $q$ | $r$ | $p \to (q \to r)$ | $(p \to q) \to r$ | $(p \land q) \to r$ |
| --- | --- | --- | ------------------ | ------------------ | -------------------- |
| 0 | 0 | 0 | 1 | 0 | 1 |
| 0 | 0 | 1 | 1 | 1 | 1 |
| 0 | 1 | 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 | 1 |

可以看出：

- $p \to (q \to r) \Leftrightarrow (p \land q) \to r$（两者最后一列相同）；
- $(p \to q) \to r$ 与它们不等值（第1行和第3行不同）。

### 4.3 基本等值式

以下等值式模式中，$A,B,C$ 代表任意公式。

**幂等律（idempotent laws）**

$$
A \lor A \Leftrightarrow A
$$

$$
A \land A \Leftrightarrow A
$$

**交换律（commutative laws）**

$$
A \lor B \Leftrightarrow B \lor A
$$

$$
A \land B \Leftrightarrow B \land A
$$

$$
A \leftrightarrow B \Leftrightarrow B \leftrightarrow A
$$

**结合律（associative laws）**

$$
(A \lor B) \lor C \Leftrightarrow A \lor (B \lor C)
$$

$$
(A \land B) \land C \Leftrightarrow A \land (B \land C)
$$

**分配律（distributive laws）**

$$
A \lor (B \land C) \Leftrightarrow (A \lor B) \land (A \lor C)
$$

$$
A \land (B \lor C) \Leftrightarrow (A \land B) \lor (A \land C)
$$

**吸收律（absorption laws）**

$$
A \lor (A \land B) \Leftrightarrow A
$$

$$
A \land (A \lor B) \Leftrightarrow A
$$

**双重否定律（double negation law）**

$$
\neg \neg A \Leftrightarrow A
$$

**德·摩根律（DeMorgan's laws）**

$$
\neg(A \lor B) \Leftrightarrow \neg A \land \neg B
$$

$$
\neg(A \land B) \Leftrightarrow \neg A \lor \neg B
$$

**零律（dominance laws）**

$$
A \lor 1 \Leftrightarrow 1
$$

$$
A \land 0 \Leftrightarrow 0
$$

**同一律（identity laws）**

$$
A \lor 0 \Leftrightarrow A
$$

$$
A \land 1 \Leftrightarrow A
$$

**排中律（excluded middle）**

$$
A \lor \neg A \Leftrightarrow 1
$$

**矛盾律（contradiction）**

$$
A \land \neg A \Leftrightarrow 0
$$

**蕴涵等值式（conditional as disjunction）**

$$
A \to B \Leftrightarrow \neg A \lor B
$$

**假言易位（contrapositive law）**

$$
A \to B \Leftrightarrow \neg B \to \neg A
$$

**归谬论**

$$
(A \to B) \land (A \to \neg B) \Leftrightarrow \neg A
$$

**等价等值式（biconditional as implication）**

$$
A \leftrightarrow B \Leftrightarrow (A \to B) \land (B \to A)
$$

**等价否定等值式**

$$
A \leftrightarrow B \Leftrightarrow \neg A \leftrightarrow \neg B
$$

### 4.4 等值式模式与等值演算

上述等值式称为**等值式模式**，每个模式都给出了无穷多个同类型的具体的等值式。由已知等值式推演出另外一些等值式的过程称为**等值演算**。

**例**：由 $A \to B \Leftrightarrow \neg A \lor B$

- 取 $A=p, B=q$，得 $p \to q \Leftrightarrow \neg p \lor q$；
- 取 $A=p \lor q \lor r, B=p \land q$，得 $(p \lor q \lor r) \to (p \land q) \Leftrightarrow \neg(p \lor q \lor r) \lor (p \land q)$。

### 4.5 代入规则与置换规则

**代入规则**：

假设 $A$ 是一个重言式，对其中所有相同的命题变项都用同一命题公式进行代换，所得到的结果仍为一重言式。

**例**：已知 $p \leftrightarrow \neg \neg p$ 是重言式，用 $p \land q$ 替换 $p$，得 $(p \land q) \leftrightarrow \neg \neg(p \land q)$ 也是重言式。

**置换规则**：

设 $\varphi(A)$ 是含公式 $A$ 的命题公式，$\varphi(B)$ 是用公式 $B$ 置换 $\varphi(A)$ 中所有出现的 $A$ 后得到的命题公式。若 $B \Leftrightarrow A$，则 $\varphi(A) \Leftrightarrow \varphi(B)$。

**例**：$((p \lor q) \land p) \lor (p \land r) \Leftrightarrow p \lor (p \land r) \Leftrightarrow p$（吸收律）。

**代入规则与置换规则对比**：

| 比较项 | 代入规则 | 置换规则 |
| ------ | -------- | -------- |
| 使用对象 | 任意重言式 | 任一命题公式 |
| 代换对象 | 任一命题变项 | 任一子公式 |
| 被代换物 | 任一命题公式 | 任一与代换对象等值的命题公式 |
| 代换方式 | 代换同一命题变项的所有出现 | 代换子公式的某些出现 |
| 代换结果 | 仍为重言式 | 与原公式等值 |

**注意**：置换规则不要求全部出现都替换。

### 4.6 等值演算的应用

#### 应用1：验证等值式

**例**：证明 $(p \land q) \to r \Leftrightarrow \neg p \lor \neg q \lor r$

$$
\begin{aligned}
(p \land q) \to r &\Leftrightarrow \neg(p \land q) \lor r \quad (\text{蕴涵等值式}) \\
&\Leftrightarrow (\neg p \lor \neg q) \lor r \quad (\text{德·摩根律}) \\
&\Leftrightarrow \neg p \lor \neg q \lor r \quad (\text{结合律})
\end{aligned}
$$

**例**：证明 $p \to (q \to r) \Leftrightarrow (p \land q) \to r$

$$
\begin{aligned}
p \to (q \to r) &\Leftrightarrow \neg p \lor (\neg q \lor r) \quad (\text{蕴涵等值式}) \\
&\Leftrightarrow \neg p \lor \neg q \lor r \quad (\text{结合律}) \\
(p \land q) \to r &\Leftrightarrow \neg(p \land q) \lor r \quad (\text{蕴涵等值式}) \\
&\Leftrightarrow (\neg p \lor \neg q) \lor r \quad (\text{德·摩根律}) \\
&\Leftrightarrow \neg p \lor \neg q \lor r \quad (\text{结合律})
\end{aligned}
$$

两式均等值于 $\neg p \lor \neg q \lor r$，故原等值式成立。

**例**：证明 $p \to (q \to r) \Leftrightarrow (p \to q) \to (p \to r)$

$$
\begin{aligned}
p \to (q \to r) &\Leftrightarrow \neg p \lor (\neg q \lor r) \quad (\text{蕴涵等值式}) \\
&\Leftrightarrow \neg p \lor \neg q \lor r \quad (\text{结合律}) \\
(p \to q) \to (p \to r) &\Leftrightarrow \neg(\neg p \lor q) \lor (\neg p \lor r) \quad (\text{蕴涵等值式}) \\
&\Leftrightarrow (p \land \neg q) \lor \neg p \lor r \quad (\text{德·摩根律}) \\
&\Leftrightarrow ((p \lor \neg p) \land (\neg q \lor \neg p)) \lor r \quad (\text{分配律}) \\
&\Leftrightarrow (1 \land (\neg q \lor \neg p)) \lor r \quad (\text{排中律}) \\
&\Leftrightarrow \neg p \lor \neg q \lor r \quad (\text{同一律})
\end{aligned}
$$

两式均等值于 $\neg p \lor \neg q \lor r$，故原等值式成立。

#### 应用2：判定公式类型

**例**：判断 $q \lor \neg((\neg p \lor q) \land p)$ 的类型。

$$
\begin{aligned}
& q \lor \neg((\neg p \lor q) \land p) \\
\Leftrightarrow & q \lor \neg(\neg p \lor q) \lor \neg p \quad (\text{德·摩根律}) \\
\Leftrightarrow & q \lor (p \land \neg q) \lor \neg p \quad (\text{德·摩根律}) \\
\Leftrightarrow & (q \lor p) \lor \neg p \quad (\text{分配律}) \\
\Leftrightarrow & q \lor (p \lor \neg p) \quad (\text{交换律、结合律}) \\
\Leftrightarrow & q \lor 1 \quad (\text{排中律}) \\
\Leftrightarrow & 1 \quad (\text{零律})
\end{aligned}
$$

所以它是重言式。

**例**：判断 $(p \lor \neg p) \to ((q \land \neg q) \land r)$ 的类型。

$$
\begin{aligned}
& (p \lor \neg p) \to ((q \land \neg q) \land r) \\
\Leftrightarrow & 1 \to (0 \land r) \quad (\text{排中律、矛盾律}) \\
\Leftrightarrow & 0 \lor (0 \land r) \quad (\text{蕴涵等值式}) \\
\Leftrightarrow & 0 \lor 0 \quad (\text{零律}) \\
\Leftrightarrow & 0 \quad (\text{同一律})
\end{aligned}
$$

所以它是矛盾式。

#### 应用3：解决实际问题

**例（比赛名次问题）**：A, B, C, D 四人做百米竞赛，观众甲、乙、丙预测比赛名次为：

- 甲：C第一，B第二；
- 乙：C第二，D第三；
- 丙：A第二，D第四。

结果甲、乙、丙各对一半，试问实际名次（无并列）。

**解答**：设 $A_i, B_i, C_i, D_i$ 分别表示 A, B, C, D 第 $i$ 名，$i=1,2,3,4$。

由题意：

$$
\begin{aligned}
& (C_1 \land \neg B_2) \lor (\neg C_1 \land B_2) \Leftrightarrow 1 \\
& (C_2 \land \neg D_3) \lor (\neg C_2 \land D_3) \Leftrightarrow 1 \\
& (A_2 \land \neg D_4) \lor (\neg A_2 \land D_4) \Leftrightarrow 1
\end{aligned}
$$

三式同时成立。通过等值演算和排除矛盾（同一人不能有两个名次，同一名次不能有两人），最终得到：

$$
1 \Leftrightarrow C_1 \land A_2 \land D_3 \land \neg B_2 \land \neg C_2 \land \neg D_4
$$

故实际名次为：C第一，A第二，D第三，B第四。

**例（选派方案问题）**：某高校计划从3名青年教师A, B, C中挑选1~2名出国进修，需满足：

1. 若A去，则C同去；
2. 若B去，则C不能去；
3. 若C不去，则A或B可以去。

问有哪些选派方案？

**解答**：设 $p$：派A去；$q$：派B去；$r$：派C去。

条件符号化：

$$
(p \to r) \land (q \to \neg r) \land (\neg r \to (p \lor q))
$$

求主析取范式：

$$
\begin{aligned}
& (p \to r) \land (q \to \neg r) \land (\neg r \to (p \lor q)) \\
\Leftrightarrow & (\neg p \land \neg q \land r) \lor (\neg p \land \neg q \land \neg r) \lor (p \land \neg q \land r) \\
\Leftrightarrow & m_1 \lor m_2 \lor m_5 \\
\Leftrightarrow & \Sigma(1,2,5)
\end{aligned}
$$

对应方案为：

- $m_1$：$\neg p \land \neg q \land r$ —— 只派C去；
- $m_2$：$\neg p \land q \land \neg r$ —— 只派B去；
- $m_5$：$p \land \neg q \land r$ —— 派A和C去。

### 4.7 等值演算的应用总结

1. 验证等值式；
2. 判定公式类型（重言式、矛盾式、可满足式）；
3. 对公式进行化简，求解成真解释和成假解释；
4. 解决工作生活中的判断问题。

---

## 五、范式

### 5.1 范式的引入

**问题**：与一个给定的命题公式等值而形式不同的命题公式可以有无穷多个。例如：

- $p \to (q \to r) \Leftrightarrow \neg p \lor (\neg q \lor r) \Leftrightarrow \neg p \lor \neg q \lor r$
- $(p \land q) \to r \Leftrightarrow \neg(p \land q) \lor r \Leftrightarrow (\neg p \lor \neg q) \lor r \Leftrightarrow \neg p \lor \neg q \lor r$

**解决**：引入**标准型（范式）**。同一真值函数所对应的所有命题公式具有相同的标准型。

### 5.2 文字、简单析取式与简单合取式

**文字**：命题变元及其否定统称为**文字**。

| 概念 | 定义 | 例子 |
| ---- | ---- | ---- |
| 简单析取式 | 仅由有限个文字构成的析取式 | $p \lor q$，$\neg p \lor q$，$p \lor \neg q \lor r$ |
| 简单合取式 | 仅由有限个文字构成的合取式 | $\neg p$，$p \land q$，$\neg p \land q \land r$ |

**注意**：一个文字既是简单析取式，又是简单合取式。

**性质**：

1. 一个简单析取式是永真式，当且仅当它同时含有一个命题变项及其否定；
2. 一个简单合取式是永假式，当且仅当它同时含有一个命题变项及其否定。

### 5.3 析取范式与合取范式

| 概念 | 定义 | 型式 |
| ---- | ---- | ---- |
| 析取范式 | 仅由有限个简单合取式构成的析取式 | $A = B_1 \lor B_2 \lor \dots \lor B_n$，其中 $B_i$ 是简单合取式 |
| 合取范式 | 仅由有限个简单析取式构成的合取式 | $A = B_1 \land B_2 \land \dots \land B_n$，其中 $B_i$ 是简单析取式 |

**例子**：

- $(p \land q \land r) \lor (p \land q) \lor (p \land p)$ 为析取范式；
- $(p \lor q \lor r) \land (p \lor \neg r \lor q) \land (p \lor \neg r \lor \neg p)$ 为合取范式；
- $p \lor q \lor r$ 既是合取范式又是析取范式。

**性质**：

1. 一个析取范式是永假式，当且仅当其每个简单合取式是永假式；
2. 一个合取范式是永真式，当且仅当其每个简单析取式是永真式。

### 5.4 范式存在定理

**定理**：任一命题公式都存在与之等值的析取范式和合取范式。

**求范式的一般步骤**：

1. **消去除 $\neg, \land, \lor$ 外的其它联结词**：
   - $A \to B \Leftrightarrow \neg A \lor B$
   - $A \leftrightarrow B \Leftrightarrow (A \to B) \land (B \to A)$
2. **否定联结词内移或消去**：
   - $\neg \neg p \Leftrightarrow p$
   - $\neg(p \land q) \Leftrightarrow \neg p \lor \neg q$
   - $\neg(p \lor q) \Leftrightarrow \neg p \land \neg q$
3. **利用分配律**：
   - 求析取范式：利用 $\land$ 对 $\lor$ 的分配律；
   - 求合取范式：利用 $\lor$ 对 $\land$ 的分配律。

**注意**：析取范式和合取范式都**不唯一**。

**例1**：求 $((p \lor q) \to r) \to p$ 的析取范式和合取范式。

$$
\begin{aligned}
& ((p \lor q) \to r) \to p \\
\Leftrightarrow & (\neg(\neg(p \lor q) \lor r)) \lor p \quad (\text{蕴涵等值式}) \\
\Leftrightarrow & ((p \lor q) \land \neg r) \lor p \quad (\text{德·摩根律、双重否定律}) \\
\Leftrightarrow & (p \land \neg r) \lor (q \land \neg r) \lor p \quad (\text{分配律})
\end{aligned}
$$

析取范式（不唯一）：$p \lor (q \land \neg r)$ 或 $(p \land \neg r) \lor (q \land \neg r) \lor p$。

合取范式：$(p \lor q) \land (p \lor \neg r)$。

**例2**：求 $(p \to q) \land \neg p \to \neg q$ 的析取范式和合取范式。

$$
\begin{aligned}
& (p \to q) \land \neg p \to \neg q \\
\Leftrightarrow & \neg((\neg p \lor q) \land \neg p) \lor \neg q \quad (\text{蕴涵等值式}) \\
\Leftrightarrow & \neg(\neg p \land (\neg p \lor q)) \lor \neg q \quad (\text{吸收律、交换律}) \\
\Leftrightarrow & \neg(\neg p) \lor \neg q \quad (\text{吸收律}) \\
\Leftrightarrow & p \lor \neg q \quad (\text{双重否定律})
\end{aligned}
$$

析取范式：$p \lor \neg q$。

合取范式：$(p \lor \neg q)$ 本身既是析取范式又是合取范式。

### 5.5 极小项

**定义**：在 $n$ 个命题变项的简单合取式中，若每个命题变项与其否定不同时出现，但二者之一必出现且仅出现一次，且命题变项与其否定按下标从小到大或字典序排列，这样的简单合取式称为**极小项**。

**例**：$\neg p \land \neg q \land \neg r$，$p \land \neg q \land r$ 等。

**数量**：$n$ 个命题变项可形成 $2^n$ 个极小项。

**编码**：把命题变项看成 1，否定看成 0，则每个极小项对应一个二进制数，也对应一个十进制数。二进制数正是该极小项的成真赋值，十进制数可做该极小项抽象表示法的角码，用 $m_i$ 表示。

**极小项与二进制数的对应（以三个变项 $p,q,r$ 为例）**：

| 极小项 | 成真赋值 | 名称 |
| ------ | -------- | ---- |
| $\neg p \land \neg q \land \neg r$ | 000 | $m_0$ |
| $\neg p \land \neg q \land r$ | 001 | $m_1$ |
| $\neg p \land q \land \neg r$ | 010 | $m_2$ |
| $\neg p \land q \land r$ | 011 | $m_3$ |
| $p \land \neg q \land \neg r$ | 100 | $m_4$ |
| $p \land \neg q \land r$ | 101 | $m_5$ |
| $p \land q \land \neg r$ | 110 | $m_6$ |
| $p \land q \land r$ | 111 | $m_7$ |

**性质**：

1. 极小项只有在对应二进制数的编码赋值时取值为 1，其余 $2^n-1$ 种赋值全为 0；
2. 所有极小项的析取式为永真式：$m_0 \lor m_1 \lor \dots \lor m_{2^n-1} \Leftrightarrow 1$。

### 5.6 主析取范式

**定义**：设命题公式 $A$ 中含有 $n$ 个命题变项，如果 $A$ 的某个析取范式中的简单合取式都是极小项，则称该析取范式为 $A$ 的**主析取范式**。

**定理**：任何命题公式的主析取范式都是存在的，并且是**唯一的**（不计极小项的次序）。

**唯一性证明（反证法）**：假设公式 $A$ 存在两个不同的主析取范式 $B$ 和 $C$。由于 $A \Leftrightarrow B$ 且 $A \Leftrightarrow C$，所以 $B \Leftrightarrow C$。因为 $B$ 和 $C$ 不同，一定存在某个极小项 $m_i$ 只出现在 $B$ 中而不出现在 $C$ 中。这样 $m_i$ 的成真赋值是 $B$ 的成真赋值，却是 $C$ 的成假赋值，与 $B \Leftrightarrow C$ 矛盾。故主析取范式唯一。

**性质**：命题公式 $A$ 与 $\neg A$ 的主析取范式互补，即所有极小项或出现在 $A$ 的主析取范式中，或（不可兼）出现在 $\neg A$ 的主析取范式中。

**求法一：等值演算法**

1. 求出析取范式；
2. 若有某简单合取式中不含变元 $p_i$，则把 $p_i \lor \neg p_i$ 合取上去：
   $$
   B \Leftrightarrow B \land (p_i \lor \neg p_i) \Leftrightarrow (B \land p_i) \lor (B \land \neg p_i)
   $$
3. 消去重复出现的命题变元及极小项、矛盾式：$p \land p$ 用 $p$ 置换，$p \land \neg p$ 用 $0$ 置换；
4. 按次序排列，用 $m_i$ 表示，最后用 $\Sigma(i_1, i_2, \dots, i_k)$ 表示。

**例**：求 $((p \lor q) \to r) \to p$ 的主析取范式。

由前已知析取范式为 $p \lor (q \land \neg r)$。

$$
\begin{aligned}
& p \lor (q \land \neg r) \\
\Leftrightarrow & (p \land (q \lor \neg q) \land (r \lor \neg r)) \lor ((p \lor \neg p) \land q \land \neg r) \\
\Leftrightarrow & (p \land q \land r) \lor (p \land q \land \neg r) \lor (p \land \neg q \land r) \lor (p \land \neg q \land \neg r) \lor (\neg p \land q \land \neg r) \\
\Leftrightarrow & m_7 \lor m_6 \lor m_5 \lor m_4 \lor m_2 \\
\Leftrightarrow & \Sigma(2,4,5,6,7)
\end{aligned}
$$

**求法二：真值表法**

把所有取真值 1 的指派对应的极小项析取。

**例**：$(p \land q) \to r$ 的真值表成真赋值为 000, 001, 010, 011, 100, 101, 111，故：

$$
(p \land q) \to r \Leftrightarrow m_0 \lor m_1 \lor m_2 \lor m_3 \lor m_4 \lor m_5 \lor m_7 \Leftrightarrow \Sigma(0,1,2,3,4,5,7)
$$

### 5.7 极大项

**定义**：在 $n$ 个命题变项的简单析取式中，若每个命题变项与其否定不同时出现，而二者之一必出现且仅出现一次，且命题变项与其否定按下标从小到大或字典序排列，这样的简单析取式称为**极大项**。

**例**：$\neg p \lor \neg q \lor \neg r$ 等。

**数量**：$n$ 个命题变项可形成 $2^n$ 个极大项。

**编码**：把命题变项看成 0，否定看成 1，则每个极大项对应一个二进制数，也对应一个十进制数。二进制数正是该极大项的成假赋值，十进制数可做该极大项抽象表示法的角码，用 $M_i$ 表示。

**极大项与二进制数的对应（以三个变项 $p,q,r$ 为例）**：

| 极大项 | 成假赋值 | 名称 |
| ------ | -------- | ---- |
| $p \lor q \lor r$ | 000 | $M_0$ |
| $p \lor q \lor \neg r$ | 001 | $M_1$ |
| $p \lor \neg q \lor r$ | 010 | $M_2$ |
| $p \lor \neg q \lor \neg r$ | 011 | $M_3$ |
| $\neg p \lor q \lor r$ | 100 | $M_4$ |
| $\neg p \lor q \lor \neg r$ | 101 | $M_5$ |
| $\neg p \lor \neg q \lor r$ | 110 | $M_6$ |
| $\neg p \lor \neg q \lor \neg r$ | 111 | $M_7$ |

**性质**：

1. 极大项只有在对应二进制数的编码赋值时取值为 0，其余 $2^n-1$ 种赋值全为 1；
2. 所有极大项的合取式为永假式：$M_0 \land M_1 \land \dots \land M_{2^n-1} \Leftrightarrow 0$。

**极大项与极小项的关系**：

$$
m_i \Leftrightarrow \neg M_i, \quad \neg m_i \Leftrightarrow M_i
$$

### 5.8 主合取范式

**定义**：设命题公式 $A$ 中含有 $n$ 个命题变项，如果 $A$ 的某个合取范式中的简单析取式都是极大项，则称该合取范式为 $A$ 的**主合取范式**。

**定理**：任何命题公式的主合取范式都是存在的，并且是**唯一的**（不计极大项的次序）。

**求法一：等值演算法**

1. 求出合取范式；
2. 若有某简单析取式中不含变元 $p_i$，则把 $p_i \land \neg p_i$ 析取上去：
   $$
   B \Leftrightarrow B \lor (p_i \land \neg p_i) \Leftrightarrow (B \lor p_i) \land (B \lor \neg p_i)
   $$
3. 消去重复出现的命题变元及极大项、永真式：$p \lor p$ 用 $p$ 置换，$p \lor \neg p$ 用 $1$ 置换；
4. 按次序排列，用 $M_i$ 表示，用 $\Pi(i_1, i_2, \dots, i_k)$ 表示。

**求法二：真值表法**

把所有取假值 0 的指派对应的极大项合取。

**例**：$(p \land q) \to r$ 的成假赋值为 110，故：

$$
(p \land q) \to r \Leftrightarrow M_6
$$

**求法三：由主析取范式构造主合取范式**

1. 求出 $A$ 的主析取范式中没包含的极小项 $m_{j_1}, m_{j_2}, \dots, m_{j_k}$；
2. 求出与这些极小项下标相同的极大项 $M_{j_1}, M_{j_2}, \dots, M_{j_k}$；
3. 由这些极大项构成的合取式即为 $A$ 的主合取范式。

**例**：$(p \to q) \land q \Leftrightarrow m_1 \lor m_3$（主析取范式）$\Leftrightarrow M_0 \land M_2$（主合取范式）。

**证明**：

设 $m_{j_1}, m_{j_2}, \dots, m_{j_k}$ 为没出现在 $A$ 的主析取范式中的极小项，则：

$$
\neg A \Leftrightarrow m_{j_1} \lor m_{j_2} \lor \dots \lor m_{j_k}
$$

$$
\begin{aligned}
A &\Leftrightarrow \neg \neg A \\
&\Leftrightarrow \neg(m_{j_1} \lor m_{j_2} \lor \dots \lor m_{j_k}) \\
&\Leftrightarrow \neg m_{j_1} \land \neg m_{j_2} \land \dots \land \neg m_{j_k} \\
&\Leftrightarrow M_{j_1} \land M_{j_2} \land \dots \land M_{j_k}
\end{aligned}
$$

### 5.9 范式的应用

#### 应用1：判断公式类型

| 公式类型 | 主析取范式条件 | 主合取范式条件 |
| -------- | -------------- | -------------- |
| 重言式 | 含全部 $2^n$ 个极小项 | 不含任何极大项，记为 $1$ |
| 矛盾式 | 不含任何极小项，记为 $0$ | 含全部 $2^n$ 个极大项 |
| 可满足式 | 至少含一个极小项 | 极大项个数小于 $2^n$ |

**例**：

- $\neg(p \to q) \land q \Leftrightarrow 0$，为永假/矛盾式；
- $((p \to q) \land p) \to q \Leftrightarrow \Sigma(0,1,2,3)$，为永真/重言式；
- $(p \to q) \land q \Leftrightarrow \Sigma(1,3)$，为可满足式。

#### 应用2：判断两公式是否等值

设公式 $A, B$ 共含有 $n$ 个命题变项，按 $n$ 个命题变项求出 $A$ 与 $B$ 的主析取范式 $A'$ 与 $B'$，若 $A' = B'$ 则 $A \Leftrightarrow B$，否则不等值。

**例**：判断 $p \leftrightarrow (q \leftrightarrow r)$ 与 $(p \leftrightarrow q) \leftrightarrow (p \leftrightarrow r)$ 是否等值。

左式主析取范式：$\Sigma(0,3,5,6)$

右式主析取范式：$\Sigma(1,2,5,6)$

两者不同，故不等值。

#### 应用3：求真值表、成真赋值及成假赋值

- 极小项对应成真赋值（命题变项看成 1，否定看成 0）；
- 极大项对应成假赋值（命题变项看成 0，否定看成 1）。

**例**：$(p \to q) \land q \Leftrightarrow (\neg p \land q) \lor (p \land q) \Leftrightarrow m_1 \lor m_3$，故成真赋值为 $(0,1)$ 和 $(1,1)$。

**例**：$(p \to q) \land q \Leftrightarrow (p \lor q) \land (\neg p \lor q) \Leftrightarrow M_0 \land M_2$，故成假赋值为 $(0,0)$ 和 $(1,0)$。

**真值表与范式的相互构造**：

| 方向 | 方法 |
| ---- | ---- |
| 真值表 → 范式 | 成真赋值对应极小项，主析取范式；成假赋值对应极大项，主合取范式 |
| 范式 → 真值表 | 极小项对应成真赋值；极大项对应成假赋值 |

#### 应用4：解决实际问题

同 4.6 节选派方案问题，通过求主析取范式得到所有可行方案。

### 5.10 范式相关概念总结

| 概念 | 定义要点 | 唯一性 |
| ---- | -------- | ------ |
| 文字 | 命题变元或其否定 | — |
| 简单析取式 | 有限个文字的析取 | — |
| 简单合取式 | 有限个文字的合取 | — |
| 析取范式 | 有限个简单合取式的析取 | 不唯一 |
| 合取范式 | 有限个简单析取式的合取 | 不唯一 |
| 极小项 | 每个变项与其否定恰出现一个的简单合取式 | — |
| 极大项 | 每个变项与其否定恰出现一个的简单析取式 | — |
| 主析取范式 | 所有简单合取式都是极小项的析取范式 | 唯一 |
| 主合取范式 | 所有简单析取式都是极大项的合取范式 | 唯一 |

---

## 六、联结词的完备集

### 6.1 真值函数

**定义**：$n$ 元真值函数是 $F: \{0,1\}^n \to \{0,1\}$，每个变元的定义域是 $\{0,1\}$，值域是 $\{0,1\}$。

**数量**：

- $n$ 元真值函数共有 $2^{2^n}$ 个；
- $n$ 元联结词总共有 $2^{2^n}$ 种；
- $n$ 元联结词的真值指派有 $2^n$ 种。

**例**：1 元真值函数共有 $2^{2^1} = 4$ 个：

| $p$ | $F_1$ | $F_2$ | $F_3$ | $F_4$ |
| --- | ----- | ----- | ----- | ----- |
| 0 | 0 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 |

**例**：2 元真值函数共有 $2^{2^2} = 16$ 个，对应 16 个二元联结词。

### 6.2 真值函数与联结词的关系

- 每个（二元）联结词确定了一个（二元）真值函数；
- 每个（二元）真值函数也确定了一个（二元）联结词。

**例**：设 $f$ 为如下二元真值函数：

| $p$ | $q$ | $f(p,q)$ |
| --- | --- | -------- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

则 $f$ 确定了联结词 $C_f$，$p C_f q$ 在指派 $\langle t_1, t_2 \rangle$ 下的值为 $f(t_1, t_2)$。

### 6.3 其他联结词

除了五个基本联结词外，常用的其他联结词包括：

| 联结词 | 符号 | 定义 | 名称 |
| ------ | ---- | ---- | ---- |
| 不可兼或（异或） | $\oplus$ 或 $\nabla$ | $p \oplus q \Leftrightarrow \neg(p \leftrightarrow q)$ | 排斥或 |
| 蕴涵否定 | $\not\to$ | $p \not\to q \Leftrightarrow \neg(p \to q)$ | 与非蕴涵 |
| 与非 | $\uparrow$ | $p \uparrow q \Leftrightarrow \neg(p \land q)$ | NAND |
| 或非 | $\downarrow$ | $p \downarrow q \Leftrightarrow \neg(p \lor q)$ | NOR |

**二元联结词总共有 16 个**，包括：

| 联结词 | 符号 | 定义 |
| ------ | ---- | ---- |
| 永假 | $0$ | 恒为假 |
| 合取 | $p \land q$ | $p$ 且 $q$ |
| 左投影 | $p$ | 取 $p$ |
| 右投影 | $q$ | 取 $q$ |
| 异或 | $p \oplus q$ | $p$ 与 $q$ 不同时为真 |
| 析取 | $p \lor q$ | $p$ 或 $q$ |
| 或非 | $p \downarrow q$ | $p$ 或 $q$ 的否定 |
| 等价 | $p \leftrightarrow q$ | $p$ 与 $q$ 同真同假 |
| 等价否定 | $p \not\leftrightarrow q$ | $p$ 与 $q$ 不同真同假 |
| 右蕴涵 | $p \leftarrow q$ | $q \to p$ |
| 左蕴涵 | $p \to q$ | $p \to q$ |
| 与非 | $p \uparrow q$ | $p$ 且 $q$ 的否定 |
| 永真 | $1$ | 恒为真 |

### 6.4 联结词完备集

**定义**：设 $S$ 是联结词的一个集合，称 $S$ 为联结词的一个**完备集**，如果任一个命题公式都能够逻辑等值于仅包含 $S$ 中联结词的公式。

**极小完备联结词集**：若一个完备集的任何真子集都不是完备集，则称该完备集为**极小完备联结词集**（最小联结词组）。

### 6.5 完备集举例

| 联结词集 | 是否完备 | 说明 |
| -------- | -------- | ---- |
| $\{\neg, \land, \lor, \to, \leftrightarrow\}$ | 是 | 基本完备集 |
| $\{\neg, \land, \lor\}$ | 是 | $\to$ 和 $\leftrightarrow$ 可被表示 |
| $\{\neg, \lor\}$ | 是 | $p \land q \Leftrightarrow \neg(\neg p \lor \neg q)$ |
| $\{\neg, \land\}$ | 是 | $p \lor q \Leftrightarrow \neg(\neg p \land \neg q)$ |
| $\{\neg, \to\}$ | 是 | $p \lor q \Leftrightarrow \neg p \to q$ |
| $\{\uparrow\}$ | 是 | 与非单独构成完备集 |
| $\{\downarrow\}$ | 是 | 或非单独构成完备集 |
| $\{\land, \lor, \to, \leftrightarrow\}$ | 否 | 无法表示 $p$ 的否定 |
| $\{\land\}$ | 否 | 无法表示否定 |
| $\{\lor\}$ | 否 | 无法表示否定 |
| $\{\neg\}$ | 否 | 无法表示二元运算 |
| $\{\to\}$ | 否 | 无法表示否定 |
| $\{\leftrightarrow\}$ | 否 | 所有公式真值中 1 和 0 的个数都是偶数 |

**证明 $\{\uparrow\}$ 是完备集**：

$$
\neg p \Leftrightarrow \neg(p \land p) \Leftrightarrow p \uparrow p
$$

$$
p \land q \Leftrightarrow \neg\neg(p \land q) \Leftrightarrow \neg(p \uparrow q) \Leftrightarrow (p \uparrow q) \uparrow (p \uparrow q)
$$

由于 $\{\neg, \land\}$ 是完备集，而 $\neg$ 和 $\land$ 都可由 $\uparrow$ 表示，故 $\{\uparrow\}$ 是完备集。

**证明 $\{\downarrow\}$ 是完备集**：

$$
\neg p \Leftrightarrow \neg(p \lor p) \Leftrightarrow p \downarrow p
$$

$$
p \lor q \Leftrightarrow \neg\neg(p \lor q) \Leftrightarrow \neg(p \downarrow q) \Leftrightarrow (p \downarrow q) \downarrow (p \downarrow q)
$$

由于 $\{\neg, \lor\}$ 是完备集，而 $\neg$ 和 $\lor$ 都可由 $\downarrow$ 表示，故 $\{\downarrow\}$ 是完备集。

### 6.6 将公式化为指定完备集上的公式

**例**：将 $C = (p \land \neg q) \lor r$ 化成 $S = \{\neg, \to\}$ 上的公式。

$$
\begin{aligned}
C &= (p \land \neg q) \lor r \\
&\Leftrightarrow (p \lor r) \land (\neg q \lor r) \quad (\text{分配律}) \\
&\Leftrightarrow (\neg p \to r) \land (q \to r) \quad (\text{蕴涵等值式}) \\
&\Leftrightarrow \neg(\neg(\neg p \to r) \lor \neg(q \to r)) \quad (\text{德·摩根律}) \\
&\Leftrightarrow \neg((\neg p \to r) \to \neg(q \to r)) \quad (\text{蕴涵等值式})
\end{aligned}
$$

### 6.7 排队线路例题

**例**：一个排队线路，输入为 A、B、C，输出分别为 $F_A, F_B, F_C$。同一时间内只能有一个信号通过，如果同时有两个或两个以上信号通过，则按 A、B、C 的顺序输出。写出 $F_A, F_B, F_C$ 在完备集 $\{\neg, \land\}$ 中的逻辑表达式。

**解**：设 $p$：A 输入；$q$：B 输入；$r$：C 输入。

$$
\begin{aligned}
F_A &= (p \land \neg q \land \neg r) \lor (p \land \neg q \land r) \lor (p \land q \land \neg r) \lor (p \land q \land r) \\
&\Leftrightarrow (p \land \neg q) \lor (p \land q) \Leftrightarrow p
\end{aligned}
$$

$$
F_B = (\neg p \land q \land \neg r) \lor (\neg p \land q \land r) \Leftrightarrow (\neg p \land q)
$$

$$
F_C = (\neg p \land \neg q \land r)
$$

---

# 第三部分 应用与问题解决

## 七、综合应用与典型例题

### 7.1 命题符号化综合题

**例1**：将下列命题符号化。

1. 若今天是星期一，则明天是星期二。
2. 只有今天是星期一，明天才是星期二。
3. 今天是星期一当且仅当明天是星期二。
4. 若今天是星期一，则明天是星期三。

设 $p$：今天是星期一；$q$：明天是星期二；$r$：明天是星期三。

| 命题 | 符号化 | 真值 |
| ---- | ------ | ---- |
| 1 | $p \to q$ | 1 |
| 2 | $q \to p$ | 1 |
| 3 | $p \leftrightarrow q$ | 1 |
| 4 | $p \to r$ | 不确定 |

**例2**：符号化“只要别人有困难，老王就帮助别人，除非困难解决了。”

设 $p$：别人有困难；$q$：老王帮助别人；$r$：困难解决了。

$$
\neg r \to (p \to q) \quad \text{或} \quad (p \land \neg r) \to q
$$

**例3**：符号化“老王或老李中的一个人去出差，当且仅当不是他们都去或者都不去。”

设 $p$：老王去出差；$q$：老李去出差。

$$
((p \land \neg q) \lor (\neg p \land q)) \leftrightarrow \neg((p \land q) \lor (\neg p \land \neg q))
$$

**例4**：符号化“小李是一名本科生，他的专业是数学或计算机。”

设 $p$：小李是一名本科生；$q$：小李的专业是数学；$r$：小李的专业是计算机。

$$
p \land (q \lor r)
$$

### 7.2 真值表与公式类型判断

**例**：构造 $(p \to q) \to (\neg q \to \neg p)$ 的真值表，判断类型并求成真/成假赋值。

| $p$ | $q$ | $\neg p$ | $\neg q$ | $p \to q$ | $\neg q \to \neg p$ | $(p \to q) \to (\neg q \to \neg p)$ |
| --- | --- | -------- | -------- | --------- | ------------------- | ----------------------------------- |
| 0 | 0 | 1 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 | 1 | 1 |

该公式为重言式，所有赋值均为成真赋值。

### 7.3 等值演算证明题

**例**：证明 $(\neg p \land (\neg q \land r)) \lor (q \land r) \lor (p \land r) \Leftrightarrow r$。

$$
\begin{aligned}
& (\neg p \land (\neg q \land r)) \lor (q \land r) \lor (p \land r) \\
\Leftrightarrow & (\neg p \land (\neg q \land r)) \lor ((q \lor p) \land r) \quad (\text{分配律}) \\
\Leftrightarrow & ((\neg p \land \neg q) \land r) \lor ((q \lor p) \land r) \quad (\text{结合律}) \\
\Leftrightarrow & (\neg(p \lor q) \land r) \lor ((q \lor p) \land r) \quad (\text{德·摩根律}) \\
\Leftrightarrow & (\neg(p \lor q) \lor (q \lor p)) \land r \quad (\text{分配律}) \\
\Leftrightarrow & 1 \land r \quad (\text{排中律}) \\
\Leftrightarrow & r \quad (\text{同一律})
\end{aligned}
$$

**例**：证明 $((p \lor q) \land \neg(\neg p \land (\neg q \lor \neg r))) \lor (\neg p \land \neg q) \lor (\neg p \land \neg r)$ 是重言式。

$$
\begin{aligned}
& ((p \lor q) \land \neg(\neg p \land (\neg q \lor \neg r))) \lor (\neg p \land \neg q) \lor (\neg p \land \neg r) \\
\Leftrightarrow & ((p \lor q) \land (p \lor (q \land r))) \lor \neg(p \lor q) \lor \neg(p \lor r) \\
\Leftrightarrow & ((p \lor q) \land ((p \lor q) \land (p \lor r))) \lor \neg(p \lor q) \lor \neg(p \lor r) \\
\Leftrightarrow & ((p \lor q) \land (p \lor r)) \lor \neg((p \lor q) \land (p \lor r)) \\
\Leftrightarrow & 1
\end{aligned}
$$

### 7.4 主析取范式与主合取范式综合题

**例**：求 $A = (p \to q) \land \neg p \to \neg q$ 的主析取范式。

$$
\begin{aligned}
& (p \to q) \land \neg p \to \neg q \\
\Leftrightarrow & (\neg p \lor q) \land \neg p \to \neg q \quad (\text{蕴涵等值式}) \\
\Leftrightarrow & (\neg p \land (\neg p \lor q)) \to \neg q \quad (\text{吸收律、交换律}) \\
\Leftrightarrow & \neg p \to \neg q \quad (\text{吸收律}) \\
\Leftrightarrow & p \lor \neg q \quad (\text{蕴涵等值式、双重否定律}) \\
\Leftrightarrow & M_1 \quad (\text{主合取范式})
\end{aligned}
$$

因主合取范式为 $M_1$，故主析取范式为 $m_0 \lor m_2 \lor m_3$。

### 7.5 联结词完备集应用题

**例**：将公式 $C = (p \land \neg q) \lor r$ 化成 $S = \{\neg, \to\}$ 上的公式。

见 6.6 节。

### 7.6 趣味逻辑题

**土耳其商人和帽子的故事**：

一个土耳其商人想找一个十分聪明的助手协助他经商，有两个人前来应聘。商人把两个人带到一间漆黑的屋子里，打开电灯后说：“这张桌子上有五顶帽子，两顶是红色的，三顶是黑色的。现在，我把灯关掉，把帽子位置摆乱，然后我们三人每人摸一顶帽子戴在头上，在我开灯后，请你们尽快地说出自己头上戴的帽子是什么颜色的。”

说完，商人将灯关掉，然后三人都摸了一顶帽子戴在头上。这时，那两个应试者看到商人头上戴的是一顶红帽子。过了一会儿，其中一个人便喊道：“我戴的是黑帽子。”

请问这个人猜得对吗？是怎么推导出来的？

**解答**：

设 $p_1$：猜对的人戴红帽子；$p_2$：猜对的人戴黑帽子；$q_1$：另一个人戴红帽子；$q_2$：另一个人戴黑帽子；$r_1$：商人戴红帽子。

根据题设条件，可以得到如下公式：

$$
\begin{aligned}
& r_1 \land p_1 \to q_2 \\
& r_1 \land q_1 \to p_2 \\
& \neg p_1 \to p_2 \\
& \neg q_1 \to q_2 \\
& r_1
\end{aligned}
$$

推演步骤：

设 $P_1$（猜对的人戴红帽子）：

1. $P_1$（根据假设）；
2. $R_1$（根据题设）；
3. $R_1 \land P_1$（合取构成）；
4. $R_1 \land P_1 \to Q_2$（根据题设）；
5. $Q_2$（③④分离）。

这就是说，“另一个人戴黑帽子”这个判定是必然可以作出的。但是这与题设条件（即“另一个人没有作出判定”）相矛盾，因此 $P_1$ 为假，即 $\neg P_1$ 为真。

6. $\neg P_1$；
7. $\neg P_1 \to P_2$（根据题设）；
8. $P_2$（⑥⑦分离）。

这就是说，“猜对的人戴黑帽子”是真的，所以猜对的人肯定地说：“我戴的是黑帽子。”

**巧猜围棋子**：

甲手里有一个围棋子，要乙来猜棋子的颜色是白的还是黑的。条件是：只允许乙问一个只能回答“是”或“否”的问题，但甲可以说真话，也可以说假话。问乙可以向甲提出一个什么问题，然后从甲回答“是”或“否”中就能判断出甲手中棋子的颜色？

**提示**：可以构造一个复合问题，使得无论甲说真话还是假话，回答都能提供确定信息。例如问：“如果我问你‘你手里是白棋子吗’，你会回答‘是’吗？”这类问题利用了双重否定，使得真假话的影响被抵消。

---

# 第四部分 知识联系与复习

## 八、知识之间的联系

### 8.1 命题逻辑内部的知识联系

```
命题的定义
    ↓
原子命题 / 复合命题
    ↓
五个基本联结词（¬, ∧, ∨, →, ↔）
    ↓
命题公式（递归定义、层次、括号省略）
    ↓
真值指派 / 赋值
    ↓
真值表 ←→ 公式类型（重言式、矛盾式、可满足式）
    ↓
逻辑等值式（定义、基本等值式、等值演算）
    ↓
范式（析取范式、合取范式）
    ↓
主析取范式 / 主合取范式（极小项、极大项）
    ↓
联结词完备集（真值函数、完备集、极小完备集）
```

### 8.2 核心概念之间的对应关系

| 概念 A | 关系 | 概念 B |
| ------ | ---- | ------ |
| 真值表 | 表示 | 成真/成假赋值 |
| 主析取范式 | 由成真赋值构造 | 极小项 |
| 主合取范式 | 由成假赋值构造 | 极大项 |
| 极小项 $m_i$ | 互补 | 极大项 $M_i$ |
| 重言式 | 主析取范式含全部极小项 | 主合取范式为 1 |
| 矛盾式 | 主析取范式为 0 | 主合取范式含全部极大项 |
| 等值演算 | 使用 | 基本等值式、代入规则、置换规则 |
| 联结词完备集 | 基于 | 真值函数 |

## 九、核心知识总结

### 9.1 核心概念表

| 知识点 | 核心定义 | 主要作用 |
| ------ | -------- | -------- |
| 命题 | 真假值唯一确定的陈述句 | 命题逻辑的基本单位 |
| 原子命题 | 不能再分解的命题 | 符号化的最小单位 |
| 复合命题 | 含联结词的命题 | 由原子命题和联结词构成 |
| 命题变项 | 真值可变的陈述句 | 构成命题公式 |
| 命题公式 | 递归定义的合式公式 | 命题的形式表示 |
| 真值指派 | 对变项组指定的一组真值 | 确定公式真值 |
| 重言式 | 所有指派均为真 | 逻辑规律 |
| 矛盾式 | 所有指派均为假 | 逻辑矛盾 |
| 可满足式 | 至少一个指派为真 | 有解 |
| 逻辑等值 | 所有指派下真值相同 | 公式化简与证明 |
| 极小项 | 每个变项与其否定恰出现一个的简单合取式 | 主析取范式的组成单位 |
| 极大项 | 每个变项与其否定恰出现一个的简单析取式 | 主合取范式的组成单位 |
| 主析取范式 | 所有简单合取式都是极小项的析取范式 | 公式的唯一标准型 |
| 主合取范式 | 所有简单析取式都是极大项的合取范式 | 公式的唯一标准型 |
| 联结词完备集 | 能表示所有命题公式的联结词集合 | 逻辑电路设计 |

### 9.2 核心等值式速查表

| 名称 | 等值式 |
| ---- | ------ |
| 幂等律 | $A \lor A \Leftrightarrow A$，$A \land A \Leftrightarrow A$ |
| 交换律 | $A \lor B \Leftrightarrow B \lor A$，$A \land B \Leftrightarrow B \land A$ |
| 结合律 | $(A \lor B) \lor C \Leftrightarrow A \lor (B \lor C)$，$(A \land B) \land C \Leftrightarrow A \land (B \land C)$ |
| 分配律 | $A \lor (B \land C) \Leftrightarrow (A \lor B) \land (A \lor C)$，$A \land (B \lor C) \Leftrightarrow (A \land B) \lor (A \land C)$ |
| 吸收律 | $A \lor (A \land B) \Leftrightarrow A$，$A \land (A \lor B) \Leftrightarrow A$ |
| 双重否定律 | $\neg \neg A \Leftrightarrow A$ |
| 德·摩根律 | $\neg(A \lor B) \Leftrightarrow \neg A \land \neg B$，$\neg(A \land B) \Leftrightarrow \neg A \lor \neg B$ |
| 零律 | $A \lor 1 \Leftrightarrow 1$，$A \land 0 \Leftrightarrow 0$ |
| 同一律 | $A \lor 0 \Leftrightarrow A$，$A \land 1 \Leftrightarrow A$ |
| 排中律 | $A \lor \neg A \Leftrightarrow 1$ |
| 矛盾律 | $A \land \neg A \Leftrightarrow 0$ |
| 蕴涵等值式 | $A \to B \Leftrightarrow \neg A \lor B$ |
| 假言易位 | $A \to B \Leftrightarrow \neg B \to \neg A$ |
| 归谬论 | $(A \to B) \land (A \to \neg B) \Leftrightarrow \neg A$ |
| 等价等值式 | $A \leftrightarrow B \Leftrightarrow (A \to B) \land (B \to A)$ |
| 等价否定等值式 | $A \leftrightarrow B \Leftrightarrow \neg A \leftrightarrow \neg B$ |

### 9.3 公式类型判断速查表

| 判断方法 | 操作 |
| -------- | ---- |
| 真值表法 | 最后一列全 1 → 重言式；全 0 → 矛盾式；有 1 → 可满足式 |
| 主析取范式法 | 含全部极小项 → 重言式；不含极小项（记为 0）→ 矛盾式；至少一个 → 可满足式 |
| 主合取范式法 | 不含极大项（记为 1）→ 重言式；含全部极大项 → 矛盾式；个数小于 $2^n$ → 可满足式 |
| 等值演算法 | 化简到 1 → 重言式；化简到 0 → 矛盾式；否则可满足 |

### 9.4 求主析取范式与主合取范式的方法对比

| 方法 | 主析取范式 | 主合取范式 |
| ---- | ---------- | ---------- |
| 等值演算法 | 先求析取范式，补全变项，消去重复，排列 | 先求合取范式，补全变项，消去重复，排列 |
| 真值表法 | 所有成真赋值对应的极小项析取 | 所有成假赋值对应的极大项合取 |
| 互相构造 | 由主合取范式中未出现的极大项下标对应的极小项析取 | 由主析取范式中未出现的极小项下标对应的极大项合取 |

### 9.5 联结词完备集速查表

| 联结词集 | 是否完备 | 说明 |
| -------- | -------- | ---- |
| $\{\neg, \land, \lor, \to, \leftrightarrow\}$ | 是 | 基本完备集 |
| $\{\neg, \land, \lor\}$ | 是 | $\to, \leftrightarrow$ 可被表示 |
| $\{\neg, \lor\}$ | 是 | $\land$ 可通过德·摩根律表示 |
| $\{\neg, \land\}$ | 是 | $\lor$ 可通过德·摩根律表示 |
| $\{\neg, \to\}$ | 是 | $\lor$ 可通过蕴涵等值式表示 |
| $\{\uparrow\}$ | 是 | 与非单独完备 |
| $\{\downarrow\}$ | 是 | 或非单独完备 |
| $\{\land, \lor, \to, \leftrightarrow\}$ | 否 | 无法表示否定 |
| $\{\land\}, \{\lor\}, \{\neg\}, \{\to\}, \{\leftrightarrow\}$ | 否 | 单独均不完备 |

### 9.6 易错点表

| 知识点 | 常见错误 | 正确理解 |
| ------ | -------- | -------- |
| 蕴涵联结词 | 认为前件为假时蕴涵为假 | 前件为假时，$p \to q$ 为真 |
| 析取联结词 | 见到“或”就写 $\lor$ | 注意区分相容或与排斥或 |
| 合取联结词 | 认为“但是”不能表示为 $\land$ | “但是”可表示为 $\land$ |
| 命题公式 | 认为命题公式就是命题 | 命题公式本身无真值，代入后才成为命题 |
| 主析取范式 | 认为析取范式唯一 | 析取范式不唯一，主析取范式才唯一 |
| 极小项编码 | 把命题变项看成 0，否定看成 1 | 极小项：变项为 1，否定为 0 |
| 极大项编码 | 把命题变项看成 1，否定看成 0 | 极大项：变项为 0，否定为 1 |
| 重言式与矛盾式 | 混淆主析取范式和主合取范式的条件 | 重言式：主析取含全部极小项，主合取为 1 |
| 代入与置换 | 混淆代入规则和置换规则 | 代入针对重言式中的变项，置换针对子公式 |
| 只有……才…… | 符号化为 $p \to q$ | 应符号化为 $q \to p$ |
| 除非……否则…… | 符号化为 $p \to q$ | 应符号化为 $\neg q \to p$ 或 $q \to p$（视具体语境） |

### 9.7 符号表

| 符号 | 含义 |
| ---- | ---- |
| $\neg$ | 否定 |
| $\land$ | 合取 |
| $\lor$ | 析取 |
| $\to$ | 蕴涵 |
| $\leftrightarrow$ | 等价 |
| $\oplus$ / $\nabla$ | 异或（不可兼或） |
| $\uparrow$ | 与非 |
| $\downarrow$ | 或非 |
| $\Leftrightarrow$ | 逻辑等值 |
| $m_i$ | 第 $i$ 个极小项 |
| $M_i$ | 第 $i$ 个极大项 |
| $\Sigma(i_1, \dots, i_k)$ | 主析取范式简写 |
| $\Pi(i_1, \dots, i_k)$ | 主合取范式简写 |
| $1$ | 永真式 |
| $0$ | 永假式 |

---

## 十、复习建议

1. **掌握基本概念**：命题、原子命题、复合命题、命题变项、命题公式、真值指派、重言式、矛盾式、可满足式。
2. **熟练五个联结词**：能准确写出真值表，能对自然语言命题进行符号化。
3. **理解等值演算**：熟记基本等值式，能熟练使用代入规则和置换规则进行等值证明和化简。
4. **掌握范式**：能求析取范式、合取范式、主析取范式、主合取范式，理解极小项和极大项的编码规则。
5. **理解联结词完备集**：知道哪些联结词集是完备的，能证明 $\{\uparrow\}$ 和 $\{\downarrow\}$ 的完备性。
6. **能解决综合问题**：利用等值演算和范式解决实际判断问题，如比赛名次、选派方案等。

---

> **说明**：本手册根据提供的三讲课件整理，覆盖命题逻辑的基本概念、命题公式与真值表、逻辑等值式、范式以及联结词完备集。内容以课件为主要知识边界，在边界内补充了必要的解释、例题和知识联系，未扩展至一阶逻辑等后续内容。所有公式均使用 Obsidian 兼容的 LaTeX 格式，可直接用于 Obsidian 笔记系统。