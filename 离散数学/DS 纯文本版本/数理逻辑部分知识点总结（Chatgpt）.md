# 离散数学——数学逻辑知识体系

> 本章主要研究**命题、命题联结词、复合命题、命题公式、真值表、逻辑等价、范式、推理以及谓词逻辑**。
> 
> 可以把整个数学逻辑部分理解成两大块：
> 
> **命题逻辑 → 谓词逻辑**

---

# 一、命题逻辑

## 1. 命题的基本概念

### 1.1 什么是命题

**命题（Proposition）**是一个能够判断真假的陈述句。

一个命题必须满足：

1. 是一个陈述句；
    
2. 能够明确判断其真值；
    
3. 真值只有两种：
    
    - 真（True）
        
    - 假（False）
        

通常使用小写英文字母表示命题：

$p, q, r, \ldots$

例如：

> $p$：2 + 3 = 5

这是命题，并且为真。

> $q$：太阳从西方升起。

这是命题，但是为假。

---

### 1.2 不是命题的情况

#### 疑问句

> 你吃饭了吗？

不能判断真假，因此不是命题。

#### 祈使句

> 请把门关上。

不能判断真假，因此不是命题。

#### 感叹句

> 今天天气真好！

通常不能明确判断真假，因此不是命题。

#### 变量尚未确定的句子

例如：

> $x+1=3$

如果不知道 $x$ 的取值，不能确定真假。

因此它通常不是命题，而是**命题函数**。

---

## 2. 简单命题和复合命题

### 2.1 简单命题

不能再分解成更简单命题的命题称为**简单命题**。

例如：

> 北京是中国的首都。

可以记为：

$p$

---

### 2.2 复合命题

由一个或多个命题通过**逻辑联结词**组合而成的命题称为复合命题。

例如：

> 今天下雨并且今天很冷。

设：

$p$：今天下雨  
$q$：今天很冷

那么：

$p \land q$

就是一个复合命题。

---

# 二、命题符号化

## 1. 基本思想

将自然语言命题转换成逻辑符号表达式的过程称为：

**命题符号化。**

基本步骤：

1. 找出简单命题；
    
2. 分别用命题变元表示；
    
3. 找出自然语言中的逻辑关系；
    
4. 用逻辑联结词表示。
    

---

## 2. 常见逻辑联结词

| 自然语言 | 逻辑符号 |
|---|---|
| 不、不是、并非 | $\neg$ |
| 且、并且、同时 | $\land$ |
| 或者 | $\lor$ |
| 如果……那么…… | $\rightarrow$ |
| 当且仅当 | $\leftrightarrow$ |

---

## 3. 例子

### 例 1

> 刘晓月跑得快，跳得高。

设：

$p$：刘晓月跑得快  
$q$：刘晓月跳得高

则：

$p \land q$

---

### 例 2

> 老王是山东人或河北人。

设：

$p$：老王是山东人  
$q$：老王是河北人

则：

$p \lor q$

---

### 例 3

> 因为天气冷，所以我穿了羽绒服。

设：

$p$：天气冷  
$q$：我穿了羽绒服

则：

$p \rightarrow q$

---

### 例 4

> 王欢与李乐组成一个小组。

设：

$p$：王欢与李乐组成一个小组

则直接记为：

$p$

---

### 例 5

> 李辛与李末是兄弟。

设：

$p$：李辛与李末是兄弟

则：

$p$

---

### 例 6

> 王强与刘威都学过法语。

设：

$p$：王强学过法语  
$q$：刘威学过法语

则：

$p \land q$

---

# 三、逻辑联结词

## 1. 否定

否定使用：

$\neg p$

读作：

> 非 $p$

如果：

$p$：今天下雨

那么：

$\neg p$：今天不下雨

---

## 2. 合取

合取使用：

$p \land q$

读作：

> $p$ 且 $q$

只有当 $p$ 和 $q$ 都为真时，$p \land q$ 才为真。

真值表：

| $p$ | $q$ | $p \land q$ |
|---|---|---|
| T | T | T |
| T | F | F |
| F | T | F |
| F | F | F |

---

## 3. 析取

析取使用：

$p \lor q$

读作：

> $p$ 或 $q$

只要 $p$ 和 $q$ 至少一个为真，$p \lor q$ 就为真。

真值表：

| $p$ | $q$ | $p \lor q$ |
|---|---|---|
| T | T | T |
| T | F | T |
| F | T | T |
| F | F | F |

> 注意：
> 
> 数学逻辑中的“或”通常是**相容或**，即两个都为真时也算真。

---

## 4. 蕴含

蕴含使用：

$p \rightarrow q$

读作：

> 如果 $p$，那么 $q$

或者：

> $p$ 蕴含 $q$

真值表：

| $p$ | $q$ | $p \rightarrow q$ |
|---|---|---|
| T | T | T |
| T | F | F |
| F | T | T |
| F | F | T |

### 重点

蕴含只有一种情况为假：

$p = T, \quad q = F$

也就是：

> **前件真，后件假。**

---

## 5. 等价

等价使用：

$p \leftrightarrow q$

读作：

> $p$ 当且仅当 $q$

只有当 $p$ 和 $q$ 真值相同时，结果才为真。

真值表：

| $p$ | $q$ | $p \leftrightarrow q$ |
|---|---|---|
| T | T | T |
| T | F | F |
| F | T | F |
| F | F | T |

---

# 四、逻辑联结词的优先级

通常规定优先级从高到低：

$\neg > \land > \lor > \rightarrow > \leftrightarrow$

因此：

$\neg p \land q$

等价于：

$(\neg p) \land q$

而：

$p \lor q \rightarrow r$

等价于：

$(p \lor q) \rightarrow r$

---

## 建议

实际做题时，不要过度依赖优先级。

最安全的方法是**主动加括号**。

例如：

$p \rightarrow q \land r$

最好理解为：

$p \rightarrow (q \land r)$

---

# 五、复合命题的真值

## 1. 真值

命题的真假称为命题的**真值**。

通常：

$T = \text{True}$  
$F = \text{False}$

---

## 2. 真值表

如果一个复合命题中包含 $n$ 个不同的命题变元，那么真值表共有：

$2^n$

行。

例如：

### 一个命题变元

$2^1 = 2$

种情况。

### 两个命题变元

$2^2 = 4$

种情况。

### 三个命题变元

$2^3 = 8$

种情况。

---

# 六、复合命题真值的计算

例如：

$(p \leftrightarrow q) \rightarrow r$

已知：

$p$：$2+3=5$

因此：

$p = T$

又因为：

> 大熊猫产在中国。

所以：

$q = T$

而：

> 太阳从西方升起。

所以：

$r = F$

因此：

$p \leftrightarrow q = T$

所以：

$(p \leftrightarrow q) \rightarrow r$

变为：

$T \rightarrow F$

因此：

$(p \leftrightarrow q) \rightarrow r = F$

---

# 七、重言式、矛盾式和可满足式

## 1. 重言式

如果一个命题公式在所有可能的真值赋值下都为真，则称为：

**重言式（Tautology）**

记作：

$\top$

例如：

$p \lor \neg p$

无论 $p$ 为真还是假：

$p \lor \neg p = T$

因此它是重言式。

---

## 2. 矛盾式

如果一个命题公式在所有可能的真值赋值下都为假，则称为：

**矛盾式（Contradiction）**

记作：

$\bot$

例如：

$p \land \neg p$

无论 $p$ 为真还是假：

$p \land \neg p = F$

---

## 3. 可满足式

如果一个命题公式至少存在一种真值赋值使其为真，则称为：

**可满足式（Satisfiable Formula）**

例如：

$p \land q$

当：

$p = T, \quad q = T$

时：

$p \land q = T$

因此它是可满足的。

---

# 八、逻辑等价

## 1. 定义

如果两个命题公式 $A$ 和 $B$ 在所有可能的真值赋值下都有相同的真值，则称：

$A \leftrightarrow B$

是重言式。

记作：

$A \equiv B$

读作：

> $A$ 与 $B$ 逻辑等价。

---

## 2. 判断逻辑等价的方法

### 方法一：真值表

分别计算：

$A$

和：

$B$

的真值。

如果每一行都相同，则：

$A \equiv B$

---

### 方法二：等价演算

利用基本逻辑等价公式进行推导。

---

# 九、基本逻辑等价公式

这些公式是命题逻辑最重要的内容之一。

## 1. 双重否定律

$\neg\neg p \equiv p$

---

## 2. 幂等律

$p \lor p \equiv p$  
$p \land p \equiv p$

---

## 3. 交换律

$p \lor q \equiv q \lor p$  
$p \land q \equiv q \land p$

---

## 4. 结合律

$(p \lor q) \lor r \equiv p \lor (q \lor r)$  
$(p \land q) \land r \equiv p \land (q \land r)$

---

## 5. 分配律

$p \lor (q \land r) \equiv (p \lor q) \land (p \lor r)$  
$p \land (q \lor r) \equiv (p \land q) \lor (p \land r)$

---

## 6. 吸收律

$p \lor (p \land q) \equiv p$  
$p \land (p \lor q) \equiv p$

---

## 7. 德·摩根律

$\neg(p \land q) \equiv \neg p \lor \neg q$  
$\neg(p \lor q) \equiv \neg p \land \neg q$

这是考试中非常重要的公式。

---

## 8. 排中律

$p \lor \neg p \equiv T$

---

## 9. 矛盾律

$p \land \neg p \equiv F$

---

## 10. 零律

$p \lor T \equiv T$  
$p \land F \equiv F$

---

## 11. 同一律

$p \lor F \equiv p$  
$p \land T \equiv p$

---

## 12. 蕴含等价式

这是非常重要的转换公式：

$p \rightarrow q \equiv \neg p \lor q$

---

## 13. 逆否命题

$p \rightarrow q \equiv \neg q \rightarrow \neg p$

因此：

> 一个命题与它的逆否命题逻辑等价。

---

## 14. 双条件命题展开

$p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$

进一步：

$p \leftrightarrow q \equiv (p \land q) \lor (\neg p \land \neg q)$

---

# 十、对偶

在命题逻辑中，可以通过交换：

$\land$

和：

$\lor$

同时交换：

$T$

和：

$F$

得到公式的**对偶式**。

例如：

$p \lor (q \land r)$

的对偶式为：

$p \land (q \lor r)$

---

# 十一、范式

范式是命题逻辑中的重点内容。

主要包括：

1. 析取范式；
    
2. 合取范式；
    
3. 主析取范式；
    
4. 主合取范式。
    

---

# 十二、文字

命题变元或者命题变元的否定称为：

**文字（Literal）**

例如：

$p$

和：

$\neg p$

都是文字。

---

# 十三、析取范式

如果一个命题公式是若干个**合取式**通过 $\lor$ 连接起来的形式，则称为：

**析取范式（DNF）**

例如：

$(p \land q) \lor (\neg p \land r)$

是析取范式。

结构可以理解为：

$\boxed{\text{合取项}} \lor \boxed{\text{合取项}} \lor \cdots$

---

# 十四、合取范式

如果一个命题公式是若干个**析取式**通过 $\land$ 连接起来的形式，则称为：

**合取范式（CNF）**

例如：

$(p \lor q) \land (\neg p \lor r)$

是合取范式。

结构可以理解为：

$\boxed{\text{析取项}} \land \boxed{\text{析取项}} \land \cdots$

---

# 十五、主析取范式

## 1. 定义

主析取范式（PDNF）是由若干个**极小项**进行析取组成的析取范式。

---

## 2. 极小项

如果一个含有 $n$ 个命题变元的合取式中：

- 每个命题变元都出现一次；
    
- 每个命题变元或者以原形出现，或者以否定形式出现；
    

那么称其为一个：

**极小项（Minterm）**

例如，对于：

$p, q, r$

一个极小项可以是：

$p \land \neg q \land r$

另一个可以是：

$\neg p \land q \land \neg r$

---

## 3. 从真值表得到主析取范式

步骤：

1. 找出公式为真的行；
    
2. 每一行写出对应的极小项；
    
3. 用 $\lor$ 连接。
    

---

# 十六、主合取范式

## 1. 定义

主合取范式（PCNF）是由若干个**极大项**进行合取组成的合取范式。

---

## 2. 极大项

如果一个含有 $n$ 个命题变元的析取式中：

- 每个命题变元都出现一次；
    
- 每个命题变元或者以原形出现，或者以否定形式出现；
    

那么称其为一个：

**极大项（Maxterm）**

---

## 3. 从真值表得到主合取范式

步骤：

1. 找出公式为假的行；
    
2. 每一行写出对应的极大项；
    
3. 用 $\land$ 连接。
    

---

# 十七、范式之间的关系

可以记住：

$\text{析取范式} = \text{合取项的析取}$  
$\text{合取范式} = \text{析取项的合取}$

进一步：

$\text{主析取范式} = \text{极小项的析取}$  
$\text{主合取范式} = \text{极大项的合取}$

---

# 十八、逻辑推理

## 1. 推理的基本概念

推理通常由：

- 前提；
    
- 结论
    

组成。

形式：

$P_1, P_2, \ldots, P_n \therefore Q$

如果所有前提都为真时，结论 $Q$ 必然为真，则称这个推理是：

**有效推理。**

---

# 十九、常见推理规则

## 1. 假言推理

$p \rightarrow q$  
$p$  

因此：

$q$

即：

> 如果 $p$ 那么 $q$；  
> $p$ 成立；  
> 所以 $q$ 成立。

---

## 2. 拒取式

$p \rightarrow q$  
$\neg q$  

因此：

$\neg p$

---

## 3. 析取三段论

$p \lor q$  
$\neg p$  

因此：

$q$

---

## 4. 假言三段论

$p \rightarrow q$  
$q \rightarrow r$  

因此：

$p \rightarrow r$

---

## 5. 合取引入

如果：

$p$

和：

$q$

都成立，则：

$p \land q$

成立。

---

## 6. 合取消去

由：

$p \land q$

可以得到：

$p$

也可以得到：

$q$

---

## 7. 附加

由：

$p$

可以得到：

$p \lor q$

---

# 二十、常见错误推理

## 1. 肯定后件

错误形式：

$p \rightarrow q$  
$q$  

因此：

$p$

这是错误的。

例如：

> 如果下雨，那么地面湿。

不能因为：

> 地面湿。

就推出：

> 下雨了。

因为地面湿可能有其他原因。

---

## 2. 否定前件

错误形式：

$p \rightarrow q$  
$\neg p$  

因此：

$\neg q$

也是错误的。

例如：

> 如果下雨，那么地面湿。

不能因为：

> 没有下雨。

就推出：

> 地面一定不湿。

---

# 二十一、判断推理是否有效

## 方法一：真值表法

将前提和结论列出真值表。

如果不存在：

$P_1 = P_2 = \cdots = P_n = T$

但：

$Q = F$

的情况，则推理有效。

也就是说：

$P_1 \land P_2 \land \cdots \land P_n \rightarrow Q$

是重言式。

---

## 方法二：等价演算法

通过逻辑等价公式将：

$P_1 \land P_2 \land \cdots \land P_n \rightarrow Q$

化为重言式。

---

## 方法三：直接证明

从前提出发，通过推理规则逐步得到结论。

---

## 方法四：反证法

假设结论为假：

$\neg Q$

然后与前提一起推出矛盾。

---

# 二十二、联结词完备集

如果一组逻辑联结词可以表示所有命题逻辑公式，则称其为：

**功能完备集。**

例如：

$\{\neg, \land, \lor\}$

是一个功能完备集。

因为：

$p \rightarrow q \equiv \neg p \lor q$

而：

$p \leftrightarrow q \equiv (p \land q) \lor (\neg p \land \neg q)$

因此其他联结词都可以通过它们表示。

---

## 1. NAND

与非：

$p \uparrow q \equiv \neg(p \land q)$

---

## 2. NOR

或非：

$p \downarrow q \equiv \neg(p \lor q)$

NAND 和 NOR 都具有功能完备性。

---

# 二十三、命题逻辑与谓词逻辑

命题逻辑只能处理：

> 整体是真是假。

例如：

$p$：张三是学生

但是它不能方便地表达：

> 所有人都是学生。

因为这里涉及：

> “所有人”

这就需要：

**谓词逻辑。**

---

# 二十四、谓词逻辑

## 1. 个体

研究对象称为：

**个体（Individual）**

例如：

- 张三；
    
- 李四；
    
- 北京；
    
- 5。
    

---

## 2. 个体常项

表示确定的个体。

例如：

$a, b, c$

---

## 3. 个体变项

表示不确定的个体。

通常使用：

$x, y, z$

---

## 4. 谓词

描述个体性质或者个体之间关系的表达式称为：

**谓词（Predicate）**

例如：

$P(x)$

表示：

> $x$ 是学生。

又例如：

$L(x, y)$

可以表示：

> $x$ 喜欢 $y$。

---

## 5. 函数

函数用于表示由一个或多个个体得到另一个个体。

例如：

$f(x)$

---

# 二十五、量词

谓词逻辑最重要的新内容就是：

**量词。**

主要有两个：

$\forall$

和：

$\exists$

---

# 二十六、全称量词

$\forall x$

读作：

> 对所有的 $x$

或者：

> 任意一个 $x$

例如：

> 所有人都是学生。

可以表示为：

$\forall x \, P(x)$

其中：

$P(x)$：$x$ 是学生

---

# 二十七、存在量词

$\exists x$

读作：

> 存在一个 $x$

或者：

> 至少存在一个 $x$

例如：

> 有人是学生。

可以表示为：

$\exists x \, P(x)$

---

# 二十八、量词的否定

这是谓词逻辑中的重点。

## 1. 全称量词的否定

$\neg \forall x \, P(x) \equiv \exists x \, \neg P(x)$

意思是：

> 并非所有人都具有性质 $P$。

等价于：

> 至少存在一个人不具有性质 $P$。

---

## 2. 存在量词的否定

$\neg \exists x \, P(x) \equiv \forall x \, \neg P(x)$

意思是：

> 不存在具有性质 $P$ 的个体。

等价于：

> 所有个体都不具有性质 $P$。

---

# 二十九、量词的分配

## 1. 全称量词与合取

通常有：

$\forall x (P(x) \land Q(x)) \equiv (\forall x P(x)) \land (\forall x Q(x))$

---

## 2. 存在量词与析取

通常有：

$\exists x (P(x) \lor Q(x)) \equiv (\exists x P(x)) \lor (\exists x Q(x))$

---

## 3. 注意

并不是所有量词都可以随意分配。

例如：

$\exists x (P(x) \land Q(x))$

一般不能直接写成：

$(\exists x P(x)) \land (\exists x Q(x))$

因为两个存在量词可能分别对应不同的个体。

---

# 三十、量词顺序

量词的顺序非常重要。

例如：

$\forall x \exists y \, P(x, y)$

表示：

> 对于每一个 $x$，都存在一个 $y$，使得 $P(x, y)$ 成立。

而：

$\exists y \forall x \, P(x, y)$

表示：

> 存在一个统一的 $y$，使得对于所有 $x$，$P(x, y)$ 都成立。

二者一般不等价：

$\forall x \exists y \, P(x, y) \not\equiv \exists y \forall x \, P(x, y)$

---

# 三十一、自由变元与约束变元

## 1. 约束变元

如果变量出现在某个量词的作用范围内，则称为：

**约束变元。**

例如：

$\forall x \, P(x)$

其中 $x$ 是约束变元。

---

## 2. 自由变元

没有受到量词约束的变量称为：

**自由变元。**

例如：

$P(x) \land Q(y)$

其中 $x$ 和 $y$ 都是自由变元。

---

## 3. 谓词公式中的变量

一个谓词公式如果包含自由变元，则通常称为：

**开放公式。**

如果没有自由变元，则称为：

**闭公式。**

---

# 三十二、谓词逻辑符号化

## 例 1

> 所有人都是学生。

设：

$P(x)$：$x$ 是学生

则：

$\forall x \, P(x)$

---

## 例 2

> 有人是学生。

$\exists x \, P(x)$

---

## 例 3

> 没有人是学生。

$\neg \exists x \, P(x)$

也可以写成：

$\forall x \, \neg P(x)$

---

## 例 4

> 所有学生都喜欢数学。

设：

$S(x)$：$x$ 是学生  
$M(x)$：$x$ 喜欢数学

则：

$\forall x (S(x) \rightarrow M(x))$

---

## 例 5

> 有学生喜欢数学。

$\exists x (S(x) \land M(x))$

---

# 三十三、谓词逻辑中的推理

主要推理规则包括：

1. 全称实例化；
    
2. 存在实例化；
    
3. 全称概括；
    
4. 存在概括。
    

---

# 三十四、全称实例化

由：

$\forall x \, P(x)$

可以得到：

$P(a)$

其中 $a$ 是论域中的任意个体。

---

# 三十五、存在实例化

由：

$\exists x \, P(x)$

可以引入一个新的个体常项 $a$，得到：

$P(a)$

但这里的 $a$ 必须表示某个满足条件的个体，而不能随意指定成已有的某个具体对象。

---

# 三十六、全称概括

如果能够证明一个任意的个体 $x$ 都满足：

$P(x)$

则可以得到：

$\forall x \, P(x)$

---

# 三十七、存在概括

由：

$P(a)$

可以推出：

$\exists x \, P(x)$

即：

> 如果某一个具体对象具有性质 $P$，那么至少存在一个对象具有性质 $P$。

---

# 三十八、前束范式

谓词逻辑中，如果一个公式写成：

$Q_1 x_1 Q_2 x_2 \cdots Q_n x_n M$

其中：

$Q_i \in \{\forall, \exists\}$

并且 $M$ 中不含量词，那么称为：

**前束范式（Prenex Normal Form）**

例如：

$\forall x \exists y (P(x, y) \lor Q(x))$

其中：

$\forall x \exists y$

称为量词串。

而：

$P(x, y) \lor Q(x)$

称为矩阵。

---

# 三十九、Skolem 标准形

Skolem 标准形主要用于消除存在量词。

例如：

$\forall x \exists y \, P(x, y)$

可以使用 Skolem 函数：

$y = f(x)$

将其转化为：

$\forall x \, P(x, f(x))$

其核心思想是：

> 用 Skolem 函数或 Skolem 常项代替存在量词。

---

# 四十、归结

**归结法（Resolution）**是一种重要的自动定理证明方法。

命题逻辑中的基本归结形式：

$p \lor q$  
$\neg p \lor r$  

可以得到：

$q \lor r$

因为：

$p$

和：

$\neg p$

相互抵消。

归结法在自动推理、人工智能和逻辑程序设计中具有重要作用。

---

# 四十一、命题逻辑与谓词逻辑的区别

| 对比 | 命题逻辑 | 谓词逻辑 |
|---|---|---|
| 基本单位 | 命题 | 谓词 |
| 能否表示个体 | 较弱 | 可以 |
| 能否表示性质 | 有限 | 可以 |
| 能否表示关系 | 有限 | 可以 |
| 能否表示“所有” | 不方便 | 可以 |
| 能否表示“存在” | 不方便 | 可以 |
| 主要工具 | 联结词 | 联结词 + 量词 |

---

# 四十二、数学逻辑整体知识框架

可以把整个数学逻辑部分压缩成下面这个结构：

$\boxed{ \text{命题} \rightarrow \text{联结词} \rightarrow \text{复合命题} \rightarrow \text{真值表} \rightarrow \text{逻辑等价} \rightarrow \text{范式} \rightarrow \text{推理} }$

然后进入：

$\boxed{ \text{谓词} \rightarrow \text{量词} \rightarrow \text{谓词公式} \rightarrow \text{量词规则} \rightarrow \text{谓词推理} \rightarrow \text{前束范式} \rightarrow \text{Skolem 标准形} \rightarrow \text{归结} }$

---

# 四十三、考试常见题型

## 第一类：判断是否为命题

判断一个句子是否能够确定真假。

---

## 第二类：命题符号化

把自然语言转换成：

$\neg, \land, \lor, \rightarrow, \leftrightarrow$

组成的公式。

---

## 第三类：求复合命题真值

给出：

$p, q, r$

的真假，求：

$(p \leftrightarrow q) \rightarrow r$

等复合命题的真值。

---

## 第四类：真值表

要求列出完整真值表。

若有 $n$ 个不同命题变元，则：

$2^n$

行。

---

## 第五类：判断重言式、矛盾式

判断公式是否：

$\text{永真}$

或：

$\text{永假}$

---

## 第六类：判断逻辑等价

证明：

$A \equiv B$

常用：

- 真值表；
    
- 等价公式。
    

---

## 第七类：等价演算

利用：

$\neg, \land, \lor, \rightarrow, \leftrightarrow$

的基本等价公式进行化简。

重点掌握：

$p \rightarrow q \equiv \neg p \lor q$

以及：

$\neg(p \land q) \equiv \neg p \lor \neg q$  
$\neg(p \lor q) \equiv \neg p \land \neg q$

---

## 第八类：求范式

包括：

- 析取范式；
    
- 合取范式；
    
- 主析取范式；
    
- 主合取范式。
    

---

## 第九类：判断推理是否有效

将推理转换为：

$P_1 \land P_2 \land \cdots \land P_n \rightarrow Q$

然后判断是否为重言式。

---

## 第十类：谓词符号化

将：

> 所有、存在、至少一个、没有、某些……

转换为：

$\forall$

和：

$\exists$

---

## 第十一类：量词否定

重点掌握：

$\neg \forall x \, P(x) \equiv \exists x \, \neg P(x)$

以及：

$\neg \exists x \, P(x) \equiv \forall x \, \neg P(x)$

---

# 四十四、必须重点掌握的公式

如果准备考试，下面这些公式应当熟练到可以直接写出。

## 命题逻辑

$\neg\neg p \equiv p$  
$p \lor p \equiv p$  
$p \land p \equiv p$  
$p \lor q \equiv q \lor p$  
$p \land q \equiv q \land p$  
$p \lor (q \lor r) \equiv (p \lor q) \lor r$  
$p \land (q \land r) \equiv (p \land q) \land r$  
$p \lor (q \land r) \equiv (p \lor q) \land (p \lor r)$  
$p \land (q \lor r) \equiv (p \land q) \lor (p \land r)$  
$p \lor (p \land q) \equiv p$  
$p \land (p \lor q) \equiv p$  
$\neg(p \land q) \equiv \neg p \lor \neg q$  
$\neg(p \lor q) \equiv \neg p \land \neg q$  
$p \lor \neg p \equiv T$  
$p \land \neg p \equiv F$  
$p \lor T \equiv T$  
$p \land F \equiv F$  
$p \lor F \equiv p$  
$p \land T \equiv p$  
$p \rightarrow q \equiv \neg p \lor q$  
$p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$  
$p \leftrightarrow q \equiv (p \land q) \lor (\neg p \land \neg q)$

---

## 谓词逻辑

$\neg \forall x \, P(x) \equiv \exists x \, \neg P(x)$  
$\neg \exists x \, P(x) \equiv \forall x \, \neg P(x)$  
$\forall x (P(x) \land Q(x)) \equiv (\forall x P(x)) \land (\forall x Q(x))$  
$\exists x (P(x) \lor Q(x)) \equiv (\exists x P(x)) \lor (\exists x Q(x))$

---

# 四十五、学习顺序建议

如果按照考试和知识体系来学习，建议按照以下顺序：

$\boxed{ \text{命题} }$

↓

$\boxed{ \text{命题符号化} }$

↓

$\boxed{ \text{五种基本联结词} }$

↓

$\boxed{ \text{真值表} }$

↓

$\boxed{ \text{重言式、矛盾式、可满足式} }$

↓

$\boxed{ \text{逻辑等价} }$

↓

$\boxed{ \text{基本等价公式} }$

↓

$\boxed{ \text{等价演算} }$

↓

$\boxed{ \text{析取范式、合取范式} }$

↓

$\boxed{ \text{主析取范式、主合取范式} }$

↓

$\boxed{ \text{逻辑推理} }$

↓

$\boxed{ \text{谓词} }$

↓

$\boxed{ \text{量词} }$

↓

$\boxed{ \text{谓词公式符号化} }$

↓

$\boxed{ \text{量词等价与否定} }$

↓

$\boxed{ \text{谓词推理} }$

↓

$\boxed{ \text{前束范式} }$

↓

$\boxed{ \text{Skolem 标准形} }$

↓

$\boxed{ \text{归结} }$

---

# 四十六、最终知识体系总结

整个数学逻辑部分最核心的思想，可以概括成：

> **用形式化符号描述命题，用逻辑联结词构造复杂命题，用真值表研究命题的真假，用逻辑等价研究公式之间的关系，用范式规范化公式，用推理规则研究结论是否能够由前提得到，再使用谓词和量词进一步描述个体、性质、关系以及“所有”和“存在”。**

最核心的五个命题逻辑符号：

$\boxed{ \neg, \quad \land, \quad \lor, \quad \rightarrow, \quad \leftrightarrow }$

最核心的两个量词：

$\boxed{ \forall, \quad \exists }$

最核心的三个工具：

$\boxed{ \text{真值表} \quad \text{逻辑等价} \quad \text{逻辑推理} }$

最终可以形成：

$\boxed{ \text{命题逻辑} + \text{谓词逻辑} = \text{数学逻辑} }$