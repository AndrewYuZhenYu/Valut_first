# 一阶逻辑：命题符号化、合式公式及其解释

> [!abstract] 知识地图
> 本章围绕两条主线展开：**4.1 一阶逻辑命题符号化**——用个体词、谓词、函数与量词描述对象和关系；**4.2 一阶逻辑公式及其解释**——定义合法的符号结构，区分量词辖域、自由与约束出现，并在给定解释下判断真值与公式类型。先学会“写出来”，再学会“读懂、辨别、判断真假”。

## 一、从命题逻辑过渡到一阶逻辑

### 1. 为什么需要一阶逻辑

命题逻辑把一个完整句子整体看作命题 $p,q,r$，可以表达命题之间的逻辑联系，却不能在命题内部直接刻画“谁具有某种性质”“哪些对象之间存在关系”。

例如：

- 凡人都是要死的。
- 苏格拉底是人。
- 因而苏格拉底是要死的。

如果将三个整句简单记作 $p,q,r$，仅仅得到 $p\land q\to r$ 这一形式，**尚未表达“苏格拉底属于人，而人都有死亡属性”这一内部结构**。一阶逻辑可以把对象、性质和量化范围分开：

$$
\forall x(M(x)\to D(x)),\qquad M(a),\qquad D(a).
$$

其中 $a$ 是苏格拉底，$M(x)$ 表示“$x$ 是人”，$D(x)$ 表示“$x$ 会死”。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_object_relation_0033d635-529d-49a9-b32d-bcec29a356d3.png]]

> [!note] 一阶逻辑（First-Order Logic，FOL）
> 也称谓词逻辑（在本课程语境下），以**个体对象及其性质、关系**为描述基础。命题逻辑中已有的 $\neg,\land,\lor,\to,\leftrightarrow$ 等联结词仍可使用。

### 2. 自然推理与证明的衔接

形式系统通常包含符号库、公式、公理和推理规则。**证明**是一列公式，每一步或者是前提，或者由此前步骤依照推理规则得出，末项为结论。

设前提集合 $\Gamma=\{A_1,\ldots,A_k\}$，在指定推理系统中可证明 $B$ 时写作 $\Gamma\vdash B$。常见的命题推理规则包括附加、化简、假言推理、拒取式、析取三段论、假言三段论、合取引入、构造性与破坏性两难等。下面主要学习这些推理所需的一阶逻辑表达基础。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_socrates_inference_d7079f6d-6f1a-4265-ac2a-00117a4bd149.png]]

对上例先由 $\forall x(M(x)\to D(x))$ 代入 $a$，得到 $M(a)\to D(a)$，再结合 $M(a)$，利用假言推理得到 $D(a)$。这里体现了**全称实例化**与**命题推理**的配合。

## 二、4.1 一阶逻辑命题符号化

### 3. 个体词与个体域

**个体词**描述可以独立存在的对象，对象既可以是具体事物，也可以是抽象概念。

| 名称 | 意义 | 常用符号 |
| --- | --- | --- |
| 个体常项 | 某个特定对象 | $a,b,c,\ldots$ |
| 个体变项 | 不确定的、泛指的对象 | $x,y,z,\ldots$ |
| 个体域（论域） | 个体变量允许取值的集合 | $D$ |

课程符号化示例中经常使用**全总个体域**（万事万物）和**受限个体域**（如全体人、全体自然数）两种方式。同一句话在两个论域下可能写成不同但相应等价的表达式：受限论域已经把“是人”这种条件包含在取值范围里。

> [!warning] 论域必须明确
> 比如 $\forall x\,G(x)$，如果 $D$ 取全体人，意为“所有人都具有 $G$”；如果 $D$ 取所有事物，则要求一切对象都具有 $G$。没有论域和解释，单看字面无法判定其实际真值。

### 4. 谓词：性质与对象间的关系

谓词把对象映射为“真”或“假”。一元谓词 $F(x)$ 表示一个对象的性质，二元谓词 $G(x,y)$ 表示两个对象的关系；依此类推，$n$ 元谓词表示 $n$ 个对象之间的关系。

例如：

- $F(x)$：$x$ 是人。
- $G(x,y)$：$x$ 和 $y$ 是兄弟。
- $L(x,y)$：$x$ 小于 $y$。
- $R(x,y,z)$：$x+y=z$。

**谓词常项**表示固定意义的性质或关系；**谓词变项**表示待指定的性质或关系。此处介绍二者，是为了识别表达对象的类别；在标准一阶语言中，谓词符号一旦指定解释，其意义便固定。

> [!important] 参数顺序不可随意交换
> $L(x,y)$ 表示 $x<y$，通常与 $L(y,x)$ 不同。类似地，$R(x,y,z)$ 与 $R(z,y,x)$ 不能因为用了相同的字母就视为同义。即使个别关系（如“同岁”）具有对称性，也必须由该关系本身的意义来判断。

### 5. 函数：返回一个对象，而不是返回真假

用 $f,g,h$ 表示函数符号，例如 $f(x)=2x$，$g(x,y)=x+y$。$f(x)$、$g(x,y)$ 的结果仍是论域中的一个对象（在给定解释下，函数需要具有规定的元数并在论域内取值）。例如，在自然数域中设 $f(x)=2x$，$P(x)$ 表示“$x$ 是偶数”，则函数与谓词在相同输入下给出不同类别的结果。函数可以被嵌入谓词，如：

$$
L(f(x),y)\quad\text{可以解释为}\quad 2x<y.
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_function_predicate_3c0db329-ac36-4dbb-84c8-1c5afca7a99c.png]]

> [!note] 区分“项”与“公式”
> 函数表达式 $f(a)$ 是一个**项**，指称某个对象；谓词表达式 $F(f(a))$ 才是可能为真或假的**公式**。课件中曾将函数称为一种典型的谓词，但按本节随后使用的一阶语言严格定义，二者的语法类型应当区分。

### 6. 命题与 0 元谓词

当所有参数都已确定时，如 $F(a)$、$G(a,b)$，它们在给定解释下可以构成有确定真值的命题。例如 $Prime(4)\to Prime(2)$ 是真命题，因为前件是假、后件是真。

> [!warning] 严格术语校正
> **“不含个体变项”不等同于严格意义的“0 元谓词符号”。** $F(a)$ 仍是把常项 $a$ 代入一元谓词 $F$ 得到的原子公式；真正的 0 元谓词符号本身不带参数。学习时不要混淆“已封闭的命题”和“谓词的元数”。

### 7. 全称量词与存在量词

| 量词 | 形式 | 真值成立条件 | 真假判定方法 |
| --- | --- | --- | --- |
| 全称量词 $\forall$ | $\forall xP(x)$ | 论域中**每一个**对象满足 $P$ | 找到一个反例即可判假 |
| 存在量词 $\exists$ | $\exists xP(x)$ | 论域中**至少一个**对象满足 $P$ | 找到一个见证对象即可判真 |

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_quantifier_threshold_91476af6-bfdb-4854-a505-a574cf545413.png]]

当 $D=\{a_1,a_2,\ldots,a_n\}$ 是有限非空论域时：

$$
\forall xP(x)\equiv P(a_1)\land\cdots\land P(a_n),
$$

$$
\exists xP(x)\equiv P(a_1)\lor\cdots\lor P(a_n).
$$

两种量词都对**论域中**的对象量化，不是在不加说明时“对整个宇宙”量化。

### 8. 特性谓词：全称用蕴含，存在用合取

若当前论域是全总个体域，而只讨论其中满足 $M(x)$ 的一类对象，则常用两种结构：

$$
\boxed{\forall x\bigl(M(x)\to G(x)\bigr)}
\quad\text{“所有 M 都具有 G”}
$$

$$
\boxed{\exists x\bigl(M(x)\land G(x)\bigr)}
\quad\text{“存在具有 G 的 M”}
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_restricted_domain_de963522-ab44-4b5d-8bd8-1760246f096c.png]]

**例 1：有些人是要死的。** 令 $M(x)$：“$x$ 是人”，$D(x)$：“$x$ 是要死的”。全总论域下：

$$
\exists x\bigl(M(x)\land D(x)\bigr).
$$

若论域已经是全体人，可写为 $\exists xD(x)$。

**例 2：凡人都是要死的。** 全总论域下：

$$
\forall x\bigl(M(x)\to D(x)\bigr).
$$

论域为全体人时，写作 $\forall xD(x)$。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_exists_implication_trap_140766e2-8f6e-42c2-8681-1ed40558f619.png]]

> [!warning] 高发错误：把 $\exists$ 后的 $\land$ 写成 $\to$
> $\exists x(M(x)\to G(x))$ 不等于“某些 $M$ 是 $G$”。如果存在不属于 $M$ 的对象，该对象使蕴含式前件为假，从而使整个蕴含式为真，可能产生错误的见证。类似地，$\forall x(M(x)\land G(x))$ 会误要求**所有对象**都是 $M$ 且满足 $G$。

### 9. “有一些”与“全部”的具体语义差异

取 $S(x)$ 表示“$x$ 是天鹅”，$B(x)$ 表示“$x$ 是黑色的”。

$$
\text{有黑天鹅：}\quad \exists x(S(x)\land B(x)),
$$

$$
\text{所有天鹅都是黑的：}\quad \forall x(S(x)\to B(x)).
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_swan_quantification_6b7ac33c-8a44-4a8b-8e70-929f62856f4c.png]]

注意：第一句不仅要求至少存在天鹅，还要求它是黑的；第二句在**没有天鹅**的论域中也为真，这是全称蕴含的空满足现象。表述是否含“确实存在天鹅”必须依据原句判断，不可私自添加存在要求。

### 10. 多量词组合：排列次序决定“谁依赖谁”

令论域为全体实数，$Q(x,y)$ 表示 $x+y=0$。对比：

$$
\forall x\exists y\,Q(x,y)
\qquad\text{与}\qquad
\exists y\forall x\,Q(x,y).
$$

前者是“每给出一个 $x$，都**可以另外选择**一个 $y$”，取 $y=-x$ 即可，故真；后者是“**先固定同一个** $y$，它对所有 $x$ 都成立”，不可能，故假。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_quantifier_order_6618eabf-8dd6-4a5e-a458-828e9457e04e.png]]

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_quantifier_order_matrix_654da08d-9de1-406a-9018-2a582088f68d.png]]

> [!important] 量词交换规律
> 通常 $\forall x\exists yP(x,y)$ **不能**交换成 $\exists y\forall xP(x,y)$。但同种量词相邻时，$\forall x\forall yP(x,y)$ 与 $\forall y\forall xP(x,y)$ 等价；$\exists x\exists yP(x,y)$ 与 $\exists y\exists xP(x,y)$ 等价。

### 11. 命题符号化的系统步骤

1. **确定论域**：是全体事物，还是学生、自然数、实数等特定集合？
2. **确定谓词/函数**：把性质、关系、运算分别命名，并严格记录各参数的含义及顺序。
3. **找出量化范围**：对应“每个”“某些”“存在”“任意不同的”等词语。
4. **建立内层逻辑**：按限定条件使用蕴含或合取；对于“恰有一个”等复合描述，拆解为存在性和唯一性。
5. **核查方向和顺序**：逐字回读中文原句；通过具体对象或反例检查是否可能误表示。

### 12. 典型例题：自然数中的最小元与最大元

**例 3：存在最小的自然数。** 设 $N(x)$ 表示“$x$ 是自然数”，$L(x,y)$ 表示 $x\le y$。在全总论域下：

$$
\exists x\left(N(x)\land\forall y(N(y)\to L(x,y))\right).
$$

若论域为自然数，则可化为 $\exists x\forall y\,L(x,y)$。这句要求存在一个 $x$，它**不大于任意自然数 $y$**。若取自然数包括 $0$，则可选 $x=0$；若课程约定自然数从 $1$ 开始，则可选 $x=1$。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_least_natural_33c954e9-2f92-4507-8f71-78dfabd0e576.png]]

也可用严格小于关系 $H(x,y):x<y$ 与相等关系 $E(x,y):x=y$ 写为：

$$
\exists x\left[N(x)\land\forall y\bigl(N(y)\land\neg E(x,y)\to H(x,y)\bigr)\right].
$$

其中除自身外，其余自然数都比 $x$ 大。

**例 4：不存在最大的自然数。** 用 $L(x,y):x\le y$：

$$
\neg\exists x\left(N(x)\land\forall y(N(y)\to L(y,x))\right).
$$

等价地，说“对每个自然数 $x$，都存在一个更大的自然数 $y$”：

$$
\forall x\left(N(x)\to\exists y(N(y)\land x<y)\right).
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_no_largest_aae762d0-5d85-4d0b-a876-47fd9ed90671.png]]

> [!tip] 求“最小”“最大”先统一不等号方向
> 最小元素 $x$：对任意 $y$，$x\le y$；最大元素 $x$：对任意 $y$，$y\le x$。判断不存在最大值时可构造 $x+1$。

### 13. 典型例题：两个整数之间存在无理数

令 $I(x)$ 表示“$x$ 是整数”，$U(y)$ 表示“$y$ 是无理数”，$H(u,v)$ 表示 $u<v$。对于**不同**整数 $x_1,x_2$，不预先规定二者大小时：

$$
\begin{aligned}
\forall x_1\forall x_2\bigl(&I(x_1)\land I(x_2)\land x_1\ne x_2\to{}\\
&\exists y\,[U(y)\land((x_1<y\land y<x_2)\\
&\hspace{43mm}\lor(x_2<y\land y<x_1))]\bigr).
\end{aligned}
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_irrational_between_9954947a-8711-49f5-8b94-4cdc49817d11.png]]

> [!warning] “任意两个整数”的细化
> 如果允许 $x_1=x_2$，严格的“在二者之间”不可能成立。因此需要说“任意两个**不同**的整数”，或者按习惯将两个整数限定为有先后关系的不同端点。原题符号化列出的两种方向没有显式加入 $x_1\ne x_2$，当两端点相同时前件仍可能为真、后件为假；此处予以明确补足。

### 14. 典型例题：“恰有一条”与“未必”

**例 5：过任意不同两点恰有一条直线。** 设 $P(x)$ 表示“$x$ 是点”，$L(z)$ 表示“$z$ 是直线”，$F(x,y,z)$ 表示“$z$ 过点 $x,y$”，$E(u,v)$ 表示“$u=v$”。

$$
\begin{aligned}
\forall x\forall y\bigl(&P(x)\land P(y)\land\neg E(x,y)\to\\
&\exists z\,[L(z)\land F(x,y,z)\land\\
&\quad\forall w((L(w)\land F(x,y,w))\to E(z,w))]\bigr).
\end{aligned}
$$

这里 $\exists z$ 保证**至少一条**，而 $\forall w$ 保证**至多一条**。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_unique_line_8d81c7f1-4ddb-44c0-b019-acb3a2a30668.png]]

> [!warning] “唯一性”不能代替“存在性”
> 若只写 $\forall z\forall w((L(z)\land L(w)\land F(x,y,z)\land F(x,y,w))\to E(z,w))$，它至多说明“若有两条满足条件的直线，则二者相同”，**不能排除根本没有直线**的情形。必须补充存在条件才能完整表达“恰有一条”。

**例 6：每个不小于 6 的偶数都是两个奇素数之和。** 在整数论域，令 $Even(x)$ 表示偶数，$OddPrime(y)$ 表示奇素数，则：

$$
\forall x\left[(x\ge6\land Even(x))\to\exists y\exists z\bigl(OddPrime(y)\land OddPrime(z)\land y+z=x\bigr)\right].
$$

重点是“全称条件 $\to$ 存在两数的合取”，并且 $y,z$ 同时满足奇素数性质。**这是一条待讨论真假的数论命题，而不是仅凭符号化就已证明的定理**；它与哥德巴赫猜想直接相关。

**例 7：相等的两个角未必都是对顶角。** 令 $A(x)$：“$x$ 是角”，$EqMeasure(x,y)$：“$x,y$ 度数相等”，$Vertical(x,y)$：“$x,y$ 是对顶角”。可写为：

$$
\neg\forall x\forall y\bigl((A(x)\land A(y)\land EqMeasure(x,y))\to Vertical(x,y)\bigr).
$$

等价地：

$$
\exists x\exists y\bigl(A(x)\land A(y)\land EqMeasure(x,y)\land\neg Vertical(x,y)\bigr).
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_equal_angles_3eea74eb-fec0-4ecf-b6b7-d4440d71c512.png]]

> [!warning] 相等的角与同一个角不同
> 若把这里的“相等”直接写成 $x=y$，便把两个角当作**同一对象**，而不是两个角的**度数相同**。应使用表示度数相等的二元谓词，防止混淆对象恒等与性质相等。

### 15. 四道基础符号化练习（含结论）

以下例题默认采用包含相关数学对象或人的适当论域。

| 自然语言 | 符号化 | 判断 |
| --- | --- | --- |
| 凡正数都大于零，$Pos(x)$、$Gt0(x)$ | $\forall x(Pos(x)\to Gt0(x))$ | 真（按定义） |
| 存在小于 2 的素数，$P(x)$ 为素数 | $\exists x(P(x)\land x<2)$ | 假（正整数中的素数从 2 开始） |
| 没有不能表示成分数的有理数，$R(x)$、$Frac(x)$ | $\neg\exists x(R(x)\land\neg Frac(x))$ | 真（有理数定义） |
| 并非所有参加考试的人都取得好成绩，$Human,Exam,Good$ | $\exists x(Human(x)\land Exam(x)\land\neg Good(x))$ | 依实际情况而定 |

> [!note] “并非全部”与“全部不”
> $\neg\forall xP(x)$ 等价于 $\exists x\neg P(x)$，不等于 $\forall x\neg P(x)$。只要一人未取得好成绩，就足以使“并非所有人取得好成绩”成立。

## 三、4.2 一阶逻辑公式及其解释

### 16. 一阶语言 $L$ 及其字母表

一阶语言是表达一阶逻辑的形式语言，其符号依用途分成：

| 类型 | 组成 | 例子 |
| --- | --- | --- |
| 非逻辑符号 | 个体常元、函数符号、谓词符号 | $a,b$；$f,g$；$F,G$ |
| 逻辑符号 | 变量、量词、联结词、括号和逗号 | $x,y$；$\forall,\exists$；$\neg,\land,\lor,\to,\leftrightarrow$ |

非逻辑符号的具体含义由解释给出，逻辑符号按统一语义使用。不同函数与谓词符号通常还应指定其**元数**，例如 $f$ 是二元函数、$F$ 是一元谓词。

### 17. 项（term）的递归定义

1. 每个个体常项和个体变项都是项。
2. 若 $t_1,\ldots,t_n$ 都是项，而 $f$ 是 $n$ 元函数符号，则 $f(t_1,\ldots,t_n)$ 也是项。
3. 只有通过有限次应用上述规则得到的表达式才是项。

示例：$a$、$x$、$f(a)$、$g(a,x)$、$g(x,f(a))$。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_term_tree_5edabb3d-9572-4e5b-be6e-e8c052532238.png]]

> [!tip] 判断是不是项
> 看表达式最后是否**指称一个对象**：变量与常项是基本项，函数把若干项组合成新项。不要把 $F(x)$ 这样的真值表达式当作项。

### 18. 原子公式（atomic formula）

若 $R$ 是 $n$ 元谓词符号，$t_1,\ldots,t_n$ 都是项，则

$$
R(t_1,t_2,\ldots,t_n)
$$

是**原子公式**。例如 $F(a)$、$G(a,y)$、$F(f(a))$、$G(x,g(a,y))$。原子公式内部没有再使用量词或真值联结词组合其他公式。

### 19. 合式公式（well-formed formula）的递归规则

设 $A,B$ 都是合式公式：

1. 所有原子公式都是合式公式。
2. $\neg A$ 是合式公式。
3. $A\land B$、$A\lor B$、$A\to B$、$A\leftrightarrow B$ 都是合式公式。
4. 对任意个体变量 $x$，$\forall xA$ 与 $\exists xA$ 都是合式公式。
5. **只有有限次**使用上述规则生成的符号串才是合式公式。

例如：

$$
\exists x\left(F(x)\land\forall y(G(y)\to H(x,y))\right)
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_formula_tree_48d0abf5-3bde-4b0e-888b-fdb73e6aed34.png]]

**从下往上理解语法树**：$F(x)$、$G(y)$、$H(x,y)$ 先构成原子公式，$G(y)\to H(x,y)$ 构成复合公式，再依次加 $\forall y$、$\land$ 和 $\exists x$。

> [!warning] 括号和优先级
> 课程中为省略冗余括号约定：量词作用最紧，其次 $\neg$，然后 $\land,\lor$，最后 $\to,\leftrightarrow$。但**量词到底约束多大范围，必须由完整公式的括号确定**。例如 $\forall x(P(x)\to Q(x))$ 与 $(\forall xP(x))\to Q(x)$ 并不相同。对复杂表达式，宁可保留清晰的括号。

### 20. 量词辖域与指导变元

在 $\forall xA$ 或 $\exists xA$ 中：

- **量词辖域**：被量词直接作用的公式 $A$。
- **指导变元**：紧跟在量词符号后的个体变元，例如 $\forall x$ 中的 $x$。
- **约束出现**：变量在某个同名量词辖域内、受其作用的出现。
- **自由出现**：某一变量出现不受同名量词约束。

对于 $\exists x(F(x)\land\forall y(G(y)\to H(x,y)))$，外层 $\exists x$ 的辖域是整个括号内容；内层 $\forall y$ 的辖域是 $G(y)\to H(x,y)$。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_scope_nested_cd8d21f7-36f0-4ad1-96fa-c6f6f23d6722.png]]

在这个表达式里，$F(x)$ 中的 $x$ 与 $H(x,y)$ 中的 $x$ 受外层 $\exists x$ 约束；$G(y)$ 与 $H(x,y)$ 中的 $y$ 受内层 $\forall y$ 约束。**它没有自由变元。**

### 21. 同一个字母既可能自由，也可能被约束

考虑：

$$
H(x,y)\lor\exists xF(x)\lor\forall y(G(y)\to H(x,y)).
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_free_bound_54ffea68-ba24-49dd-a83a-2e84a43f0cfd.png]]

其中最前面的 $H(x,y)$ 中，$x,y$ 都自由出现；中间的 $F(x)$ 中，$x$ 被 $\exists x$ 约束；最后一段中，$y$ 被 $\forall y$ 约束，而 $H(x,y)$ 的 $x$ 仍自由出现。一个变量符号出现多次，**是否自由要逐次判断**。

### 22. 闭式（closed formula）

**不含任何自由出现的个体变元的合式公式**叫作闭式（或闭公式）。

| 公式 | 是否闭式 | 原因 |
| --- | --- | --- |
| $F(a)$ | 是 | 无个体变元 |
| $\exists xF(x)$ | 是 | $x$ 受到存在量词约束 |
| $F(x)$ | 否 | $x$ 自由 |
| $\forall y(G(y)\to H(x,y))$ | 否 | $x$ 仍自由 |
| $\forall x\exists yH(x,y)$ | 是 | 所有变量出现均受约束 |

> [!important] 语义后果
> 给定解释后，**闭式的真值不依赖对自由变量的赋值**；开放公式通常还要额外指定自由变量的取值才能判定真假。

### 23. 换名规则与代替规则：防止变量捕获

对某个量词的**指导变元及它所约束的出现**统一改名，只要不会改变原本的约束关系，就是合法的换名。例如：

$$
\forall xP(x)\equiv\forall zP(z).
$$

另一种操作是**代入**，即用某个项替换自由出现的变量。这时必须保证项内部的变量不会被公式中已有量词意外捕获。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_variable_capture_44ce1e4e-e2a7-4534-a0bf-65284e0ef282.png]]

例如 $\forall yR(x,y)$ 中 $x$ 是自由的。如果直接把 $x$ 替换为 $y$，变成 $\forall yR(y,y)$，原先自由的那个位置被 $\forall y$ 约束，改变了含义。因此需先把已有的约束变元安全换名，再进行代入。

> [!warning] 正确替换顺序
> 例如要在 $\forall yR(x,y)$ 中以项 $y$ 代替自由变量 $x$，可先将原量词换名为 $\forall zR(x,z)$，再代入，得到 $\forall zR(y,z)$。此时 $y$ 仍是自由变元，没有发生捕获。

## 四、解释、赋值与真值

### 24. 一阶语言的解释（interpretation）

一阶语言只给出结构，不直接规定每个 $a,f,F$ 意味着什么。一个解释通常需要明确：

1. **非空个体域** $D$；
2. **个体常元**在 $D$ 中指称的具体对象；
3. **函数符号**在 $D$ 上对应的实际函数；
4. **谓词符号**在 $D$ 上对应的实际性质或关系。

这四部分使符号能够被理解成具体的数学或现实陈述。对于带自由变量的公式，还需额外给出**赋值**，把每个自由变量指定为论域中的某个元素。

### 25. 同一个公式在不同解释下可有不同真值

考察公式 $F(f(a,a),b)$。

**解释 $I_1$：** $D$ 为自然数，$a=2$，$b=4$，$f(x,y)=x+y$，$F(u,v)$ 为 $u=v$，于是：

$$F(f(a,a),b)\quad\Longleftrightarrow\quad 2+2=4\quad\text{真。}$$

**解释 $I_2$：** $D$ 为实数，$a=3$，$b=5$，$f(x,y)=x-y$，$F(u,v)$ 为 $u>v$，于是：

$$F(f(a,a),b)\quad\Longleftrightarrow\quad 3-3>5\quad\text{假。}$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_interpretations_5cef357e-a359-4472-b2bb-407c9f5eeffb.png]]

这说明**公式不是脱离解释就具有固定真假**。两个解释中的符号串完全相同，但函数和谓词代表的实际含义不同。

### 26. 有限论域中的全称与存在判定

设 $D=\{1,2,3,4\}$，$P(x)$ 表示 $x^2<10$，则 $P(1)$、$P(2)$、$P(3)$ 为真，而 $P(4)$ 为假。

$$
\forall xP(x)=P(1)\land P(2)\land P(3)\land P(4)=0.
$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_finite_truth_f82817c5-4adb-45de-b3ef-a54c4caf2f65.png]]

若 $P(x)$ 改为 $x^2>10$，则 $\exists xP(x)$ 为真，因为可以取 $x=4$。**全称求合取，存在求析取。**

### 27. 二元关系可化为真值矩阵

设 $D=\{1,2,3\}$，$R(x,y)$ 为 $x<y$。在表中按行固定 $x$，按列变化 $y$。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_relation_matrix_a24e91dc-856a-47ed-9f7a-a7725a895228.png]]

- $\exists x\exists yR(x,y)$ 为真：例如 $1<2$。
- $\forall x\exists yR(x,y)$ 为假：当 $x=3$ 时，不存在大于 $3$ 的 $y$。
- $\exists x\forall yR(x,y)$ 为假：由于 $y=x$ 也在论域里，$x<y$ 不可能对所有 $y$ 成立。
- $\forall x\forall yR(x,y)$ 为假：例如 $x=y=1$ 就是假。

> [!tip] 读量词表格的方法
> $\forall x\exists y$：**每一行至少一个真**；$\exists x\forall y$：**存在一行全真**；$\forall x\forall y$：**所有格全真**；$\exists x\exists y$：**至少一个格真**。若要对调变量顺序，应同步明确表格中谁是行、谁是列。

### 28. 论域变化可能改变同一公式的真值

令 $P(x)$ 为 $x=1$、$Q(x)$ 为 $x=2$，考察：

$$\forall x(P(x)\lor Q(x)).$$

- 若 $D=\{1,2\}$，所有个体都满足 $P$ 或 $Q$，公式真。
- 若 $D=\{0,1,2\}$，对象 $0$ 不满足 $P$ 或 $Q$，公式假。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_domain_change_e0da222b-b5c1-438b-b8c9-3e020b7ed605.png]]

> [!warning] 解释改变时，不能沿用旧真值
> 比较公式时不仅要看符号串，还要检查论域、常元所指、函数、谓词是否一致。对于含自由变元的公式，还应检查赋值。

## 五、一阶逻辑公式的分类与等值

### 29. 永真式、矛盾式与可满足式

对于一阶逻辑公式，应综合考虑**所有允许的解释**，并在有自由变元时考虑相应赋值。

| 类型 | 严格含义 | 简单例子 |
| --- | --- | --- |
| 永真式（逻辑有效式） | 在所有解释和相应赋值下都为真 | $P(x)\lor\neg P(x)$ |
| 矛盾式（永假式） | 在所有解释和相应赋值下都为假 | $P(x)\land\neg P(x)$ |
| 可满足式 | 至少存在一种解释和相应赋值使它为真 | $P(x)$ |

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_formula_categories_c654508f-2329-4adc-8a9d-b6f4fd0283a5.png]]

**永真式一定可满足**，但可满足式不一定永真；矛盾式一定不可满足。这里不要误把“可满足”写成“有时为真有时为假”：**永真式也是可满足式**。

### 30. 命题公式的代换实例

若把命题公式 $A(p_1,\ldots,p_n)$ 中每个命题变项 $p_i$ 一致地替换为一个一阶逻辑公式 $B_i$，得到的公式称为原公式的**代换实例**。

例如：

$$p\to(q\to p)$$

把 $p$ 代为 $F(x)$、$q$ 代为 $G(y)$，得到：

$$F(x)\to(G(y)\to F(x)).$$

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_substitution_instance_da7c05fc-2da6-4fe9-8e2a-a82295e6ac42.png]]

**定理：** 命题重言式的任意一致代换实例仍是逻辑有效式；命题矛盾式的任意一致代换实例仍是矛盾式。

### 31. 量词否定等值式

$$
\boxed{\neg\forall xP(x)\ \Leftrightarrow\ \exists x\neg P(x)}
$$

$$
\boxed{\neg\exists xP(x)\ \Leftrightarrow\ \forall x\neg P(x)}
$$

这里 $\Leftrightarrow$ 表示两侧公式**逻辑等值**，不是新的一阶联结词。

![[Assets/DiscreteMath_20261031_FirstOrderLogic_5e3f4ad7a3804d0b_assets/images/fol_quantifier_negation_e4179d53-f653-4474-9dd4-0ada35d9b8b1.png]]

假设 $D$ 是某班学生集合，$P(x)$ 表示“$x$ 是优等生”，则 $\neg\forall xP(x)$ 表示“并非所有人都是优等生”，等值地就是 $\exists x\neg P(x)$：“至少有一人不是优等生”。

### 32. 四种公式类型判断示例

1. $\forall xF(x)\to\bigl(G(y)\to\forall xF(x)\bigr)$：永真式。把 $A=\forall xF(x)$、$B=G(y)$，其形式为 $A\to(B\to A)$。
2. $\exists xF(x)\to\forall yG(y)$：可满足，但非永真。例如取 $F$ 全假时前件假使整体真；取 $F$ 有真、$G$ 全假时整体假。
3. $\neg(\forall xF(x)\to\exists yG(y))\land\exists yG(y)$：矛盾式。由 $\neg(A\to B)\equiv A\land\neg B$，与 $B$ 合取必假。
4. $\neg\forall xF(x)\leftrightarrow\exists x\neg F(x)$：永真式，因量词否定等值式。

> [!important] 量词等值与换名的条件
> 量词否定可在不改变变量约束结构的前提下直接使用；跨越 $\land,\lor$ 或迁移量词时，必须注意变量是否在其他子公式中自由出现。不能无条件把量词从任意子式中“提取出去”。

## 六、归纳与综合应用

### 33. 需要反复核查的六类问题

| 类别 | 要问自己的问题 |
| --- | --- |
| 论域 | 变量实际能取哪些对象？ |
| 谓词 | 各个参数各自代表谁，顺序是否固定？ |
| 量词 | 是“所有”还是“至少一个”？“谁先选”影响结果吗？ |
| 限制 | 全称是否采用 $M\to G$，存在是否采用 $M\land G$？ |
| 语法 | 是项还是公式？每个括号和量词的辖域在哪里？ |
| 语义 | 真值依赖哪个解释、哪个自由变量赋值？ |

### 34. 综合练习（先独立思考）

1. 以全总论域为背景，令 $Student(x)$ 为“$x$ 是学生”、$Pass(x)$ 为“$x$ 通过考试”。写出“所有学生都通过考试”“存在学生没通过考试”“并非所有学生都通过考试”。比较后两种表达。
2. 以实数为论域，判断 $\forall x\exists y(x+y=10)$ 与 $\exists y\forall x(x+y=10)$ 的真值，并说明原因。
3. 对 $\forall y(P(x,y)\to\exists xQ(x,y))$，标明每个变量出现是自由还是约束；判断是否闭式。
4. 给出 $G(x,g(a,y))$ 中每一个项、函数及最外层原子公式的层级。
5. 用全总论域写出“存在唯一一个具有 $R$ 性质的对象”，令 $R(x)$ 表示该性质，$x=y$ 表示对象相同。
6. 判断 $\neg\exists xP(x)$ 与 $\forall x\neg P(x)$ 是否等值。
7. 设 $D=\{1,2\}$，$R(x,y)$ 表示 $x\le y$，判断 $\forall x\exists yR(x,y)$、$\exists x\forall yR(x,y)$。
8. 判断公式 $\neg(P(x)\to Q(x))\land Q(x)$ 的分类。
9. 解释为什么 $\forall yR(x,y)$ 里直接用 $y$ 代替自由出现的 $x$ 是危险的，并写出安全代入的结果。
10. 分别给出一个例子，说明“存在性不等于唯一性”“同一个公式换解释后真假可能变化”。

> [!example]- 参考答案（点击展开）
> 1. $\forall x(Student(x)\to Pass(x))$；$\exists x(Student(x)\land\neg Pass(x))$；$\neg\forall x(Student(x)\to Pass(x))$。后两种等值。
> 2. 前者真：对每个 $x$ 取 $y=10-x$；后者假：不存在一个固定实数 $y$ 与所有 $x$ 相加都为 $10$。
> 3. $y$ 在 $P(x,y)$、$Q(x,y)$ 中由外层 $\forall y$ 约束；$Q$ 的 $x$ 由内层 $\exists x$ 约束；$P$ 中的 $x$ 自由。因此不是闭式。
> 4. $a,x,y$ 是项；$g(a,y)$ 是复合项；$G(x,g(a,y))$ 是以两个项为参数的原子公式。
> 5. $\exists x\bigl(R(x)\land\forall y(R(y)\to y=x)\bigr)$。
> 6. 等值（存在量词否定律）。
> 7. 两者都真。前者对 $x=1,2$ 都可取 $y=2$；后者取 $x=1$，对所有 $y\in D$ 都满足 $1\le y$。
> 8. 矛盾式：$\neg(P\to Q)\equiv P\land\neg Q$，再与 $Q$ 合取恒假。
> 9. 会发生变量捕获。先改名 $\forall zR(x,z)$，再替换自由 $x$ 得 $\forall zR(y,z)$。
> 10. 任意集合中“至多一位满足 $R$”可能为零位；同一 $F(a)$ 可在解释 $F$ 为“偶数”、$a=2$ 时为真，在 $a=3$ 时为假。

> [!summary] 一页速记
> - **符号化**：全总论域中 $\forall x(M(x)\to G(x))$；$\exists x(M(x)\land G(x))$。
> - **量词顺序**：$\forall x\exists y$ 允许 $y$ 随 $x$ 变化；$\exists y\forall x$ 要求同一个 $y$ 适用于全部 $x$。
> - **语法链**：常元/变量 $\to$ 项；谓词加项 $\to$ 原子公式；联结词/量词 $\to$ 合式公式。
> - **变量**：是否自由按出现位置判定；**闭式**没有自由变元。
> - **语义**：解释给非逻辑符号赋义，开放公式还需自由变量赋值；永真看所有解释，可满足只需一个解释。
> - **等值**：$\neg\forall xP\Leftrightarrow\exists x\neg P$，$\neg\exists xP\Leftrightarrow\forall x\neg P$。

#离散数学/一阶逻辑
