没问题，这正是理科生最核心的“战斗力”。我为你整理了一份**数学全领域 LaTeX 语法速查表**。

在 Obsidian 中，你只需要在 `$公式$`（行内）或 `$$公式$$`（独立行）之间输入这些代码即可。

---

## 1. 基础算术与通用符号

|**类别**|**代码**|**预览**|
|---|---|---|
|上下标|`a^n, a_{ij}`|$a^n, a_{ij}$|
|分式|`\frac{numerator}{denominator}`|$\frac{a}{b}$|
|根号|`\sqrt{x}, \sqrt[n]{x}`|$\sqrt{x}, \sqrt[n]{x}$|
|运算符|`\times, \div, \pm, \mp`|$\times, \div, \pm, \mp$|
|关系符|`\approx, \sim, \equiv, \le, \ge`|$\approx, \sim, \equiv, \le, \ge$|
|逻辑|`\forall, \exists, \because, \therefore`|$\forall, \exists, \because, \therefore$|

---

## 2. 微积分 (Calculus)

这是你目前笔记中最常用的部分：

- **极限：** `\lim_{n \to \infty}` $\to \lim_{n \to \infty}$
    
- **导数：** `\frac{dy}{dx}, \phi'(x), \dot{x}` $\to \frac{dy}{dx}, \phi'(x), \dot{x}$
    
- **偏导：** `\frac{\partial f}{\partial x}` $\to \frac{\partial f}{\partial x}$
    
- **积分：**
    
    - 不定积分：`\int f(x) dx` $\to \int f(x) dx$
        
    - 定积分：`\int_{a}^{b} f(x) dx` $\to \int_{a}^{b} f(x) dx$
        
    - 多重积分：`\iint_D, \iiint_V` $\to \iint_D, \iiint_V$
        
    - 环路积分：`\oint_C` $\to \oint_C$
        

---

## 3. 线性代数 (Linear Algebra)

线代涉及大量的矩阵和向量：

- **向量：** `\vec{a}` 或加粗 `\mathbf{v}` $\to \vec{a}, \mathbf{v}$
    
- **矩阵环境：**
    
    Code snippet
    
    ```
    \begin{pmatrix} a & b \\ c & d \end{pmatrix} % 圆括号 ()
    \begin{bmatrix} a & b \\ c & d \end{bmatrix} % 方括号 []
    \begin{vmatrix} a & b \\ c & d \end{vmatrix} % 行列式 | |
    ```
    
    渲染效果：$\begin{pmatrix} a & b \\ c & d \end{pmatrix}, \begin{bmatrix} a & b \\ c & d \end{bmatrix}, \begin{vmatrix} a & b \\ c & d \end{vmatrix}$
    
- **常用符号：**
    
    - 转置：`A^T` 或 `A^\top` $\to A^\top$
        
    - 特征值：`\lambda` $\to \lambda$
        
    - 省略号（矩阵常用）：`\dots` (横), `\vdots` (竖), `\ddots` (对角线)
        

---

## 4. 概率论与数理统计 (Probability & Statistics)

- **集合：** `\cup, \cap, \in, \notin, \subseteq` $\to \cup, \cap, \in, \notin, \subseteq$
    
- **期望与方差：** `E(X), D(X), \text{Var}(X)` $\to E(X), D(X), \text{Var}(X)$
    
- **组合数：** `\binom{n}{k}` $\to \binom{n}{k}$
    
- **统计分布：**
    
    - 正态分布：`N(\mu, \sigma^2)` $\to N(\mu, \sigma^2)$
        
    - 波动符号：`X \sim N(0,1)` $\to X \sim N(0,1)$
        
    - 均值：`\bar{x}` $\to \bar{x}$
        

---

## 5. 希腊字母 (Greek Letters)

这是理工科的“字母表”，必须掌握：

|**小写**|**代码**|**大写**|**代码**|
|---|---|---|---|
|$\alpha$|`\alpha`|$A$|`A`|
|$\beta$|`\beta`|$B$|`B`|
|$\gamma$|`\gamma`|$\Gamma$|`\Gamma`|
|$\delta$|`\delta`|$\Delta$|`\Delta`|
|$\epsilon, \varepsilon$|`\epsilon, \varepsilon`|$E$|`E`|
|$\theta$|`\theta`|$\Theta$|`\Theta`|
|$\lambda$|`\lambda`|$\Lambda$|`\Lambda`|
|$\sigma$|`\sigma`|$\Sigma$|` \Sigma$|

---

## 6. 排版美化小技巧

- **空格：** LaTeX 默认忽略公式里的空格。强制加空格用 `\,` (小), `\;` (中), `\quad` (大)。
    
- **正体文字：** 在公式里写中文或单位，要用 `\text{...}`，例如：`v = 5 \text{ m/s}` $\to v = 5 \text{ m/s}$。
    
- **大括号：** 写分段函数或方程组：
    
    Code snippet
    
    ```
    f(x) = \begin{cases} x, & x > 0 \\ -x, & x \le 0 \end{cases}
    ```
    
    渲染效果：$f(x) = \begin{cases} x, & x > 0 \\ -x, & x \le 0 \end{cases}$
    

---

**建议把这一篇收藏或粘贴到你的 Obsidian 独立页面（比如命名为 `LaTeX_Cheat_Sheet`）。**

**接下来，你想让我用这些语法帮你把刚才那个“小船过河”的物理推导过程写成一份标准的数学笔记模板吗？**