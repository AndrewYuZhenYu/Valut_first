

为了方便你在 Obsidian 中使用，我将内容分为**基础符号**、**学科分类**（微积分、线代、概论等）以及**排版结构**（矩阵、多行公式）。

---

### 1. 基础语法与运算 (Basics & Operations)

这是所有数学分支通用的基础符号。

|**含义**|**LaTeX 代码**|**渲染效果**|**说明**|
|---|---|---|---|
|**上标/指数**|`x^2`, `e^{2x}`|$x^2, e^{2x}$|多个字符需用 `{}` 包裹|
|**下标**|`x_i`, `a_{ij}`|$x_i, a_{ij}$|同上|
|**分数**|`\frac{a}{b}`|$\frac{a}{b}$|分子在第一个 `{}`，分母在第二个|
|**根号**|`\sqrt{x}`, `\sqrt[3]{x}`|$\sqrt{x}, \sqrt[3]{x}$|方括号内为次数|
|**加减乘除**|`\pm`, `\times`, `\div`|$\pm, \times, \div$|点乘用 `\cdot` ($\cdot$)|
|**不等于**|`\neq`|$\neq$||
|**近似/恒等**|`\approx`, `\equiv`|$\approx, \equiv$||
|**无穷大**|`\infty`|$\infty$||
|**逻辑非**|`\neg`|$\neg$||

---

### 2. 希腊字母 (Greek Letters)

常用的变量符号。大写字母通常首字母大写即可。

|**小写代码**|**效果**|**大写代码**|**效果**|**常用场景**|
|---|---|---|---|---|
|`\alpha`|$\alpha$|`A`|$A$|角度、系数|
|`\beta`|$\beta$|`B`|$B$|角度、系数|
|`\gamma`|$\gamma$|`\Gamma`|$\Gamma$|伽马函数|
|`\delta`|$\delta$|`\Delta`|$\Delta$|变化量、判别式|
|`\epsilon` / `\varepsilon`|$\epsilon / \varepsilon$|`E`|$E$|极限、误差|
|`\theta`|$\theta$|`\Theta`|$\Theta$|角度|
|`\lambda`|$\lambda$|`\Lambda`|$\Lambda$|特征值、波长|
|`\mu`|$\mu$|`M`|$M$|均值、微米|
|`\sigma`|$\sigma$|`\Sigma`|$\Sigma$|标准差、求和|
|`\phi` / `\varphi`|$\phi / \varphi$|`\Phi`|$\Phi$|角度、函数|
|`\omega`|$\omega$|`\Omega`|$\Omega$|角速度、样本空间|

---

### 3. 集合论与逻辑 (Set Theory & Logic)

离散数学与概率论的基础。

|**含义**|**LaTeX 代码**|**渲染效果**|
|---|---|---|
|**属于/不属于**|`\in`, `\notin`|$\in, \notin$|
|**子集**|`\subset`, `\subseteq`|$\subset, \subseteq$|
|**并集/交集**|`\cup`, `\cap`|$\cup, \cap$|
|**空集**|`\emptyset`|$\emptyset$|
|**全称量词 (任意)**|`\forall`|$\forall$|
|**存在量词 (存在)**|`\exists`|$\exists$|
|**推出/等价**|`\implies`, `\iff`|$\implies, \iff$|
|**常见数集**|`\mathbb{R}, \mathbb{Z}, \mathbb{N}, \mathbb{Q}`|$\mathbb{R}, \mathbb{Z}, \mathbb{N}, \mathbb{Q}$|
|**花体字母**|`\mathcal{L}, \mathcal{F}`|$\mathcal{L}, \mathcal{F}$|

---

### 4. 微积分 (Calculus)

极限、导数、积分与级数。

|**含义**|**LaTeX 代码**|**渲染效果**|**备注**|
|---|---|---|---|
|**极限**|`\lim_{x \to \infty}`|$\lim_{x \to \infty}$|`\to` 是箭头|
|**求和**|`\sum\limits_{i=1}^{n}`|$\sum\limits_{i=1}^{n}$|若sum或prod后面加上\limits，就会将参数渲染在正上方和正下方，若不加，则会渲染在右侧上角和下角|
|**求积**|`\prod\limits_{i=1}^{n}`|$\prod\limits_{i=1}^{n}$|同上（反例）$\Large\sum_{i=1}^{n}$  $\Large\prod_{i=1}^{n}$(不加\limits效果)|
|**积分**|`\int_{a}^{b} f(x) dx`|$\int_{a}^{b} f(x) dx$|若需间隔用 `\,dx`|
|**二重/闭合积分**|`\iint`, `\oint`|$\iint, \oint$||
|**偏导数**|`\frac{\partial y}{\partial x}`|$\frac{\partial y}{\partial x}$|使用 `\partial`|
|**梯度算子**|`\nabla`|$\nabla$||
|**一阶/二阶导**|`f'`, `f''`, `\dot{y}`, `\ddot{y}`|$f', f'', \dot{y}, \ddot{y}$|`\dot` 常用于物理对时间求导|

---

### 5. 线性代数 (Linear Algebra)

高等代数核心：矩阵与向量。

#### 5.1 向量与范数

|**含义**|**LaTeX 代码**|**渲染效果**|
|---|---|---|
|**向量 (箭头)**|`\vec{v}`|$\vec{v}$|
|**向量 (加粗)**|`\mathbf{v}`|$\mathbf{v}$|
|**范数/绝对值**|`\|x\|`, `|x|
|**内积**|`\langle u, v \rangle`|$\langle u, v \rangle$|
|**正交**|`\perp`|$\perp$|

#### 5.2 矩阵环境 (Matrix Environments)

在 Obsidian 中，通常需要用 `$$` 包裹才能正确显示多行矩阵。

**代码示例：**

Code snippet

```
$$
\begin{bmatrix}
1 & 2 & 3 \\
a & b & c
\end{bmatrix}
$$
```

**不同括号的矩阵：**

|**类型**|**代码环境**|**效果示例**|
|---|---|---|
|**方括号**|`bmatrix`|$\begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}$|
|**圆括号**|`pmatrix`|$\begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}$|
|**行列式**|`vmatrix`|$\begin{vmatrix} 1 & 0 \\ 0 & 1 \end{vmatrix}$|
|**大括号**|`Bmatrix`|$\begin{Bmatrix} 1 & 0 \\ 0 & 1 \end{Bmatrix}$|

---

### 6. 概率论与统计 (Probability & Statistics)

|**含义**|**LaTeX 代码**|**渲染效果**|
|---|---|---|
|**期望**|`E[X]` 或 `\mathbb{E}[X]`|$E[X], \mathbb{E}[X]$|
|**方差**|`\text{Var}(X)`|$\text{Var}(X)$|
|**组合数**|`\binom{n}{k}`|$\binom{n}{k}$|
|**服从分布**|`X \sim N(\mu, \sigma^2)`|$X \sim N(\mu, \sigma^2)$|
|**估计量 (帽子)**|`\hat{p}, \bar{x}`|$\hat{p}, \bar{x}$|

---

### 7. 高级排版技巧 (Advanced Layout)

这对在 Obsidian 中做笔记至关重要。

#### 7.1 分段函数 (Cases)

用于定义分段函数。

**代码：**

Code snippet

```
$$
f(x) = 
\begin{cases} 
x^2, & \text{if } x > 0 \\
-x, & \text{if } x \le 0 
\end{cases}
$$
```

**渲染效果：**

$$f(x) = \begin{cases} x^2, & \text{if } x > 0 \\ -x, & \text{if } x \le 0 \end{cases}$$

#### 7.2 多行对齐公式 (Aligned)

用于推导过程，使等号对齐。

**代码：**

Code snippet

```
$$
\begin{aligned}
(a+b)^2 &= (a+b)(a+b) \\
        &= a^2 + ab + ba + b^2 \\
        &= a^2 + 2ab + b^2
\end{aligned}
$$
```

**渲染效果：**

$$\begin{aligned} (a+b)^2 &= (a+b)(a+b) \\ &= a^2 + ab + ba + b^2 \\ &= a^2 + 2ab + b^2 \end{aligned}$$

#### 7.3 上下堆叠与大尺寸算子

|**含义**|**LaTeX 代码**|**渲染效果**|**说明**|
|---|---|---|---|
|**文字上方**|`\overbrace{a+b}^{n}`|$\overbrace{a+b}^{n}$||
|**文字下方**|`\underbrace{a+b}_{n}`|$\underbrace{a+b}_{n}$||
|**堆叠符号**|`\stackrel{def}{=}`|$\stackrel{def}{=}$|定义等号|
|**强制大显示**|`\displaystyle \frac{a}{b}`|$\displaystyle \frac{a}{b}$|在行内公式中强制显示大尺寸|

---

### 8. 常用空格与文本

在公式中插入文字或调整间距。

- **小空格:** `\,` ($, $)
    
- **中空格:** `\;` ($; $)
    
- **大空格:** `\quad` ($\quad $)
    
- **超大空格:** `\qquad` ($\qquad $)
    
- **插入文本:** `\text{your text}` (例如：$x = 1 \quad \text{where } x>0$)
    

---

### 小建议：

**Would you like me to generate a specific complex formula using these rules (e.g., the Schrödinger equation or the Normal Distribution definition) to verify how they fit together?**