# 微积分：导数与微分完全深度指南

## 一、导数基础与极限理论

### 1.1 导数定义的三种形式

#### 1. 标准定义（增量比极限）
$$ f'(x_0) = \lim_{\Delta x \to 0} \frac{f(x_0 + \Delta x) - f(x_0)}{\Delta x} $$

**要点**：
- $\Delta x$可正可负，必须双侧趋近
- 极限存在且有限
- 几何意义：割线斜率的极限

#### 2. 差商定义（更常用）
$$ f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h} $$

#### 3. 增量定义（微分思想）
若存在常数A使：
$$ \Delta y = f(x_0+\Delta x) - f(x_0) = A\Delta x + o(\Delta x) $$
则$f'(x_0)=A$

**o(Δx)的含义**：$\lim_{\Delta x\to 0}\frac{o(\Delta x)}{\Delta x}=0$

### 1.2 左导数与右导数

#### 定义
- **右导数**：$f'_+(x_0) = \lim_{h \to 0^+} \frac{f(x_0+h)-f(x_0)}{h}$
- **左导数**：$f'_-(x_0) = \lim_{h \to 0^-} \frac{f(x_0+h)-f(x_0)}{h}$

#### 重要结论
1. **可导的充要条件**：$f'_+(x_0)=f'_-(x_0)$（存在且相等）
2. **连续不一定可导**：如$f(x)=|x|$在$x=0$
3. **可导必连续**：逆否命题：不连续⇒不可导

### 1.3 不可导点的分类

#### 1. 角点（Corner）
左右导数存在但不相等
**例**：$f(x)=|x|$在$x=0$：$f'_+(0)=1, f'_-(0)=-1$

#### 2. 尖点（Cusp）
左右导数至少一个为无穷大
**例**：$f(x)=x^{2/3}$在$x=0$：$f'_+(0)=+\infty, f'_-(0)=-\infty$

#### 3. 垂直切线
导数无穷大但符号相同
**例**：$f(x)=\sqrt[3]{x}$在$x=0$：$f'(0)=\infty$

#### 4. 间断点
函数不连续，导数不存在
**例**：$f(x)=\begin{cases} x^2 & x<0 \\ 1 & x\geq 0 \end{cases}$在$x=0$

## 二、基本求导公式与法则

### 2.1 基本初等函数导数表（必须牢记）

#### 1. 幂函数
$$ (x^a)' = a x^{a-1} $$
**特例**：
- $(x)' = 1$
- $(x^2)' = 2x$
- $(\sqrt{x})' = \frac{1}{2\sqrt{x}}$（$x>0$）
- $(\frac{1}{x})' = -\frac{1}{x^2}$（$x\neq 0$）

#### 2. 指数函数
$$ (a^x)' = a^x \ln a \quad (a>0, a\neq 1) $$
$$ (e^x)' = e^x \quad \text{(最重要的导数公式)} $$

#### 3. 对数函数
$$ (\log_a x)' = \frac{1}{x\ln a} \quad (a>0, a\neq 1, x>0) $$
$$ (\ln x)' = \frac{1}{x} \quad (x>0) $$
$$ (\ln|x|)' = \frac{1}{x} \quad (x\neq 0) $$

#### 4. 三角函数
$$
\begin{aligned}
&(\sin x)' = \cos x \\
&(\cos x)' = -\sin x \\
&(\tan x)' = \sec^2 x = \frac{1}{\cos^2 x} \\
&(\cot x)' = -\csc^2 x = -\frac{1}{\sin^2 x} \\
&(\sec x)' = \sec x \tan x \\
&(\csc x)' = -\csc x \cot x
\end{aligned}
$$

#### 5. 反三角函数
$$
\begin{aligned}
&(\arcsin x)' = \frac{1}{\sqrt{1-x^2}} \quad (|x|<1) \\
&(\arccos x)' = -\frac{1}{\sqrt{1-x^2}} \quad (|x|<1) \\
&(\arctan x)' = \frac{1}{1+x^2} \\
&(\operatorname{arccot} x)' = -\frac{1}{1+x^2}
\end{aligned}
$$

### 2.2 求导法则

#### 1. 线性法则
$$ (af(x) + bg(x))' = af'(x) + bg'(x) $$

#### 2. 乘积法则（Leibniz法则）
$$ (f(x)g(x))' = f'(x)g(x) + f(x)g'(x) $$

**推广到三项**：
$$ (fgh)' = f'gh + fg'h + fgh' $$

**记忆口诀**：轮流求导，其余不动

#### 3. 商法则
$$ \left(\frac{f(x)}{g(x)}\right)' = \frac{f'(x)g(x) - f(x)g'(x)}{[g(x)]^2} \quad (g(x)\neq 0) $$

**记忆口诀**：分子：上导下不导 减 上不导下导；分母：下平方

#### 4. 链式法则（复合函数求导）
设$y=f(u), u=g(x)$，则：
$$ \frac{dy}{dx} = \frac{dy}{du} \cdot \frac{du}{dx} = f'(u) \cdot g'(x) $$

**多层复合**：
$$ \frac{dy}{dx} = \frac{dy}{du} \cdot \frac{du}{dv} \cdot \frac{dv}{dx} $$

**关键**：从外到内，层层剥开

### 2.3 常见复合函数求导

#### 1. 指数型复合
$$ (e^{f(x)})' = e^{f(x)} \cdot f'(x) $$
$$ (a^{f(x)})' = a^{f(x)} \cdot \ln a \cdot f'(x) $$

#### 2. 对数型复合
$$ (\ln|f(x)|)' = \frac{f'(x)}{f(x)} \quad (f(x)\neq 0) $$

#### 3. 幂指型复合
$$ ([f(x)]^a)' = a[f(x)]^{a-1} \cdot f'(x) $$

#### 4. 三角函数复合
$$ (\sin f(x))' = \cos f(x) \cdot f'(x) $$
$$ (\cos f(x))' = -\sin f(x) \cdot f'(x) $$

## 三、隐函数与参数方程求导

### 3.1 隐函数求导方法

#### 基本方法
对等式$F(x,y)=0$两边对$x$求导，注意$y$是$x$的函数

**例1**：求$x^2 + y^2 = 1$的导数
$$
\begin{aligned}
\frac{d}{dx}(x^2 + y^2) &= \frac{d}{dx}(1) \\
2x + 2y \cdot \frac{dy}{dx} &= 0 \\
\frac{dy}{dx} &= -\frac{x}{y}
\end{aligned}
$$

#### 隐函数二阶导
对一阶导结果再求导，注意$\frac{dy}{dx}$也是$x$的函数

**续例1**：
$$
\frac{d^2y}{dx^2} = \frac{d}{dx}\left(-\frac{x}{y}\right) = -\frac{y - x\frac{dy}{dx}}{y^2}
$$
代入$\frac{dy}{dx} = -\frac{x}{y}$：
$$
\frac{d^2y}{dx^2} = -\frac{y - x(-\frac{x}{y})}{y^2} = -\frac{y + \frac{x^2}{y}}{y^2} = -\frac{y^2 + x^2}{y^3} = -\frac{1}{y^3}
$$

### 3.2 参数方程求导

#### 一阶导数
设$\begin{cases} x = \varphi(t) \\ y = \psi(t) \end{cases}$，则：
$$ \frac{dy}{dx} = \frac{dy/dt}{dx/dt} = \frac{\psi'(t)}{\varphi'(t)} $$

**要求**：$\varphi'(t) \neq 0$

#### 二阶导数
方法1（常用）：
$$ \frac{d^2y}{dx^2} = \frac{d}{dx}\left(\frac{dy}{dx}\right) = \frac{\frac{d}{dt}\left(\frac{dy}{dx}\right)}{\frac{dx}{dt}} $$

方法2（公式）：
$$ \frac{d^2y}{dx^2} = \frac{\varphi'(t)\psi''(t) - \varphi''(t)\psi'(t)}{[\varphi'(t)]^3} $$

**例**：$\begin{cases} x = t^2 \\ y = t^3 \end{cases}$
1. 一阶导：$\frac{dy}{dx} = \frac{3t^2}{2t} = \frac{3t}{2}$
2. 二阶导：$\frac{d^2y}{dx^2} = \frac{\frac{d}{dt}(\frac{3t}{2})}{2t} = \frac{3/2}{2t} = \frac{3}{4t}$

### 3.3 对数求导法

#### 适用情况
1. **幂指函数**：$y = [f(x)]^{g(x)}$
2. **多因子连乘除**：$y = \frac{f_1(x)f_2(x)\cdots}{g_1(x)g_2(x)\cdots}$

#### 步骤
1. 取绝对值对数：$\ln|y| = \ln|f(x)|^{g(x)} = g(x)\ln|f(x)|$
2. 两边对$x$求导：$\frac{y'}{y} = g'(x)\ln f(x) + g(x)\frac{f'(x)}{f(x)}$
3. 解出$y'$：$y' = y\left[g'(x)\ln f(x) + g(x)\frac{f'(x)}{f(x)}\right]$

#### 例：幂指函数
求$y = x^{\sin x}$的导数
$$
\begin{aligned}
\ln y &= \sin x \cdot \ln x \\
\frac{y'}{y} &= \cos x \cdot \ln x + \sin x \cdot \frac{1}{x} \\
y' &= x^{\sin x}\left(\cos x \ln x + \frac{\sin x}{x}\right)
\end{aligned}
$$

#### 例：多因子函数
求$y = \frac{(x+1)\sqrt{x-2}}{(x+3)^2}$的导数
$$
\begin{aligned}
\ln y &= \ln(x+1) + \frac{1}{2}\ln(x-2) - 2\ln(x+3) \\
\frac{y'}{y} &= \frac{1}{x+1} + \frac{1}{2(x-2)} - \frac{2}{x+3} \\
y' &= \frac{(x+1)\sqrt{x-2}}{(x+3)^2}\left[\frac{1}{x+1} + \frac{1}{2(x-2)} - \frac{2}{x+3}\right]
\end{aligned}
$$

## 四、高阶导数

### 4.1 高阶导数公式

#### 1. 幂函数
$$ (x^a)^{(n)} = a(a-1)\cdots(a-n+1)x^{a-n} $$

**特例**：
- $(x^m)^{(n)} = \begin{cases} 
    \frac{m!}{(m-n)!}x^{m-n}, & n \leq m \\
    0, & n > m
    \end{cases}$
- $(\frac{1}{x})^{(n)} = (-1)^n \frac{n!}{x^{n+1}}$

#### 2. 指数函数
$$ (a^x)^{(n)} = a^x (\ln a)^n $$
$$ (e^x)^{(n)} = e^x $$

#### 3. 对数函数
$$ (\ln x)^{(n)} = (-1)^{n-1} \frac{(n-1)!}{x^n} $$

#### 4. 三角函数
$$
\begin{aligned}
(\sin x)^{(n)} &= \sin\left(x + \frac{n\pi}{2}\right) \\
(\cos x)^{(n)} &= \cos\left(x + \frac{n\pi}{2}\right)
\end{aligned}
$$

**推导思路**：每次求导产生相位增加$\pi/2$

#### 5. $\frac{1}{ax+b}$型
$$ \left(\frac{1}{ax+b}\right)^{(n)} = (-1)^n \frac{a^n n!}{(ax+b)^{n+1}} $$

### 4.2 莱布尼茨公式（乘积高阶导）

$$ (uv)^{(n)} = \sum_{k=0}^n \binom{n}{k} u^{(k)} v^{(n-k)} $$
其中$\binom{n}{k} = \frac{n!}{k!(n-k)!}$

**记忆**：类似二项式定理：$(u+v)^n = \sum \binom{n}{k} u^k v^{n-k}$

**例**：求$(x^2 e^x)^{(5)}$
设$u=x^2$, $v=e^x$
- $u'=2x$, $u''=2$, $u^{(k)}=0$（当$k\geq 3$）
- $v^{(k)}=e^x$

$$
\begin{aligned}
(x^2 e^x)^{(5)} &= \sum_{k=0}^5 \binom{5}{k} u^{(k)} v^{(5-k)} \\
&= \binom{5}{0} x^2 e^x + \binom{5}{1} (2x) e^x + \binom{5}{2} (2) e^x \\
&= x^2 e^x + 10x e^x + 20 e^x \\
&= e^x (x^2 + 10x + 20)
\end{aligned}
$$

### 4.3 高阶导数的求法技巧

#### 1. 化为部分分式
求$\frac{1}{x^2-1}$的n阶导数
$$
\frac{1}{x^2-1} = \frac{1}{2}\left(\frac{1}{x-1} - \frac{1}{x+1}\right)
$$
分别求$\frac{1}{x\pm 1}$的n阶导

#### 2. 利用已知展开式
求$\frac{1}{1+x}$的n阶导数：
已知$\frac{1}{1+x} = \sum_{n=0}^\infty (-1)^n x^n$（$|x|<1$）
逐项求导对比

#### 3. 递推法
建立递推关系求高阶导

## 五、微分及其应用

### 5.1 微分定义与计算

#### 微分定义
若$\Delta y = f(x_0+\Delta x) - f(x_0) = A\Delta x + o(\Delta x)$
则$dy = A\Delta x = f'(x_0)dx$

**关键关系**：$dy = f'(x)dx$

#### 微分公式（由导数推得）
$$
\begin{aligned}
d(C) &= 0 \\
d(x^a) &= a x^{a-1} dx \\
d(\sin x) &= \cos x dx \\
d(\ln x) &= \frac{1}{x} dx \\
d(e^x) &= e^x dx
\end{aligned}
$$

#### 微分运算法则
$$
\begin{aligned}
d(u \pm v) &= du \pm dv \\
d(uv) &= v du + u dv \\
d\left(\frac{u}{v}\right) &= \frac{v du - u dv}{v^2} \quad (v\neq 0)
\end{aligned}
$$

### 5.2 微分形式不变性

#### 重要性质
无论$u$是自变量还是中间变量，都有：
$$ dy = f'(u) du $$

**例**：$y=\sin(2x+1)$
- 令$u=2x+1$，则$y=\sin u$
- $dy = \cos u du = \cos(2x+1) \cdot 2dx = 2\cos(2x+1)dx$

### 5.3 微分在近似计算中的应用

#### 线性近似公式
当$|\Delta x|$很小时：
$$ f(x_0+\Delta x) \approx f(x_0) + f'(x_0)\Delta x $$

#### 常用近似公式（$|x|$很小）
1. $\sqrt[n]{1+x} \approx 1 + \frac{x}{n}$
2. $\sin x \approx x$
3. $\tan x \approx x$
4. $e^x \approx 1+x$
5. $\ln(1+x) \approx x$

#### 例：计算$\sqrt{1.02}$
取$f(x)=\sqrt{x}$，$x_0=1$，$\Delta x=0.02$
$$
\sqrt{1.02} \approx \sqrt{1} + \frac{1}{2\sqrt{1}} \times 0.02 = 1 + 0.01 = 1.01
$$
精确值：$\sqrt{1.02} \approx 1.00995$，误差约0.005%

### 5.4 误差估计

#### 绝对误差与相对误差
设$x$的测量值为$x_0$，绝对误差限为$\delta_x$

1. **绝对误差限**：$\delta_y \approx |f'(x_0)| \delta_x$
2. **相对误差限**：$\frac{\delta_y}{|y|} \approx \left|\frac{f'(x_0)}{f(x_0)}\right| \delta_x$

#### 例：圆面积误差
测量圆半径$r=10\text{cm}$，误差$\delta_r=0.1\text{cm}$
面积$S=\pi r^2$
- $S'(r)=2\pi r$
- $\delta_S \approx |2\pi r| \delta_r = 2\pi \times 10 \times 0.1 = 2\pi \approx 6.28\text{cm}^2$
- 相对误差：$\frac{\delta_S}{S} \approx \frac{2\pi r \delta_r}{\pi r^2} = \frac{2\delta_r}{r} = 2\%$

## 六、特殊函数与分段函数求导

### 6.1 绝对值函数求导

#### 分段处理法
$f(x)=|g(x)| = \begin{cases} g(x), & g(x) \geq 0 \\ -g(x), & g(x) < 0 \end{cases}$

在$g(x)=0$处需特别检查：
- 若$g'(x_0)=0$，则$f'(x_0)=0$
- 若$g'(x_0)\neq 0$，则$f'(x_0)$不存在

#### 公式法（$g(x)\neq 0$时）
$$ |g(x)|' = \frac{g(x)}{|g(x)|} \cdot g'(x) = \operatorname{sgn}(g(x)) \cdot g'(x) $$

### 6.2 分段函数在分段点求导

#### 三步法
对$f(x) = \begin{cases} f_1(x), & x < x_0 \\ f_2(x), & x \geq x_0 \end{cases}$

1. **连续性检查**：$\lim_{x\to x_0^-} f_1(x) = f_2(x_0)$
2. **左导数**：$f'_-(x_0) = \lim_{x\to x_0^-} \frac{f_1(x)-f_1(x_0)}{x-x_0}$或$f_1'(x_0)$
3. **右导数**：$f'_+(x_0) = \lim_{x\to x_0^+} \frac{f_2(x)-f_2(x_0)}{x-x_0}$或$f_2'(x_0)$

#### 例
$$
f(x) = \begin{cases}
x^2, & x < 1 \\
2x-1, & x \geq 1
\end{cases}
$$

在$x=1$处：
1. 连续性：$\lim_{x\to 1^-} x^2 = 1$，$f(1)=2\times1-1=1$ ✓
2. 左导数：$f'_-(1) = 2x|_{x=1} = 2$
3. 右导数：$f'_+(1) = 2$
4. 结论：$f'(1)=2$

### 6.3 反函数求导

#### 定理
若$y=f(x)$在区间I上严格单调、可导且$f'(x)\neq 0$
则反函数$x=\varphi(y)$可导，且：
$$ \varphi'(y) = \frac{1}{f'(x)} $$

#### Leibniz表示
$$ \frac{dx}{dy} = \frac{1}{\frac{dy}{dx}} $$

#### 例：$y=\arcsin x$的导数
$y=\arcsin x$ ⇔ $x=\sin y$，$y\in[-\pi/2, \pi/2]$
$$
\frac{d}{dx}(\arcsin x) = \frac{1}{\frac{d}{dy}(\sin y)} = \frac{1}{\cos y}
$$
由$\sin^2 y + \cos^2 y = 1$，$\cos y = \sqrt{1-\sin^2 y} = \sqrt{1-x^2}$（取正号因$y\in[-\pi/2, \pi/2]$）
$$
(\arcsin x)' = \frac{1}{\sqrt{1-x^2}}
$$

## 七、导数与微分的应用

### 7.1 函数单调性判定

#### 定理
设$f(x)$在$[a,b]$连续，在$(a,b)$可导：
1. $f'(x)>0$ ⇒ $f(x)$严格单调增加
2. $f'(x)<0$ ⇒ $f(x)$严格单调减少
3. $f'(x)\geq 0$ ⇒ $f(x)$单调不减
4. $f'(x)\leq 0$ ⇒ $f(x)$单调不增

#### 驻点与单调区间
- **驻点**：$f'(x)=0$的点
- 用驻点划分区间，检查各区间的$f'(x)$符号

#### 例：$f(x)=x^3-3x$
1. $f'(x)=3x^2-3=3(x-1)(x+1)$
2. 驻点：$x=-1, 1$
3. 符号：
   - $x<-1$：$f'(x)>0$ ⇒ 增
   - $-1<x<1$：$f'(x)<0$ ⇒ 减
   - $x>1$：$f'(x)>0$ ⇒ 增

### 7.2 极值判定

#### 极值定义
- **极大值**：$f(x_0) \geq f(x)$（在$x_0$某邻域）
- **极小值**：$f(x_0) \leq f(x)$（在$x_0$某邻域）

#### 必要条件（Fermat定理）
若$f(x)$在$x_0$可导且取得极值，则$f'(x_0)=0$

**注意**：导数为零的点不一定是极值点（如$f(x)=x^3$在$x=0$）

#### 充分条件

##### 第一充分条件（左右导数变号）
$f(x)$在$x_0$连续，在$x_0$去心邻域可导：
1. $x<x_0$时$f'(x)>0$，$x>x_0$时$f'(x)<0$ ⇒ 极大值
2. $x<x_0$时$f'(x)<0$，$x>x_0$时$f'(x)>0$ ⇒ 极小值
3. $f'(x)$不变号 ⇒ 不是极值

##### 第二充分条件（二阶导）
$f'(x_0)=0$，$f''(x_0)\neq 0$：
1. $f''(x_0)>0$ ⇒ 极小值
2. $f''(x_0)<0$ ⇒ 极大值
3. $f''(x_0)=0$ ⇒ 无法判断，需用其他方法

##### 高阶导数判别法
设$f'(x_0)=f''(x_0)=\cdots=f^{(n-1)}(x_0)=0$，$f^{(n)}(x_0)\neq 0$：
1. $n$为偶数：
   - $f^{(n)}(x_0)>0$ ⇒ 极小值
   - $f^{(n)}(x_0)<0$ ⇒ 极大值
2. $n$为奇数 ⇒ 不是极值点

### 7.3 最值问题

#### 闭区间上连续函数
$f(x)$在$[a,b]$上的最值求法：
1. 求$f'(x)$，找出所有驻点和不可导点
2. 计算这些点及端点$a,b$的函数值
3. 最大值 = max{这些函数值}，最小值 = min{这些函数值}

#### 实际问题建模步骤
1. 建立目标函数$f(x)$
2. 确定定义域（通常有限制条件）
3. 求$f'(x)=0$的驻点
4. 比较驻点、边界点、不可导点的函数值

#### 例：最大容积问题
用边长为$a$的正方形铁皮，四角剪去小正方形后折成无盖盒子，求最大容积

解：
1. 设剪去小正方形边长为$x$，则盒子的：
   - 长 = $a-2x$
   - 宽 = $a-2x$
   - 高 = $x$
   - 容积：$V(x)=x(a-2x)^2$，$0<x<a/2$
2. $V'(x)=(a-2x)^2 + x\cdot 2(a-2x)(-2) = (a-2x)(a-6x)$
3. 驻点：$x=a/2$（舍去，此时容积为0），$x=a/6$
4. $V(0)=0$，$V(a/6)=\frac{2a^3}{27}$，$V(a/2)=0$
5. 最大容积：$\frac{2a^3}{27}$，在$x=a/6$时取得

## 八、中值定理与泰勒展开

### 8.1 微分中值定理

#### 罗尔定理（Rolle）
条件：
1. $f(x)$在$[a,b]$连续
2. 在$(a,b)$可导
3. $f(a)=f(b)$
结论：存在$\xi\in(a,b)$使$f'(\xi)=0$

#### 拉格朗日中值定理（Lagrange）
条件：
1. $f(x)$在$[a,b]$连续
2. 在$(a,b)$可导
结论：存在$\xi\in(a,b)$使$f'(\xi)=\frac{f(b)-f(a)}{b-a}$

**几何意义**：存在一点切线平行于割线

#### 柯西中值定理（Cauchy）
条件：
1. $f(x), g(x)$在$[a,b]$连续
2. 在$(a,b)$可导
3. $g'(x)\neq 0$（$x\in(a,b)$）
结论：存在$\xi\in(a,b)$使$\frac{f'(\xi)}{g'(\xi)}=\frac{f(b)-f(a)}{g(b)-g(a)}$

**注意**：当$g(x)=x$时，柯西定理退化为拉格朗日定理

### 8.2 泰勒公式

#### 带皮亚诺余项的泰勒公式
$f(x)$在$x_0$处有$n$阶导数：
$$ f(x) = \sum_{k=0}^n \frac{f^{(k)}(x_0)}{k!}(x-x_0)^k + o((x-x_0)^n) $$

#### 带拉格朗日余项的泰勒公式
$f(x)$在$x_0$邻域有$n+1$阶导数：
$$ f(x) = \sum_{k=0}^n \frac{f^{(k)}(x_0)}{k!}(x-x_0)^k + \frac{f^{(n+1)}(\xi)}{(n+1)!}(x-x_0)^{n+1} $$
其中$\xi$在$x_0$与$x$之间

#### 常见函数的麦克劳林展开（$x_0=0$）
$$
\begin{aligned}
e^x &= 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \cdots + \frac{x^n}{n!} + o(x^n) \\
\sin x &= x - \frac{x^3}{3!} + \frac{x^5}{5!} - \cdots + (-1)^n \frac{x^{2n+1}}{(2n+1)!} + o(x^{2n+2}) \\
\cos x &= 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \cdots + (-1)^n \frac{x^{2n}}{(2n)!} + o(x^{2n+1}) \\
\ln(1+x) &= x - \frac{x^2}{2} + \frac{x^3}{3} - \cdots + (-1)^{n-1} \frac{x^n}{n} + o(x^n) \\
(1+x)^a &= 1 + ax + \frac{a(a-1)}{2!}x^2 + \cdots + \frac{a(a-1)\cdots(a-n+1)}{n!}x^n + o(x^n)
\end{aligned}
$$

### 8.3 泰勒公式的应用

#### 1. 函数近似计算
用多项式近似复杂函数

**例**：计算$\sin 0.1$的近似值
$$
\sin 0.1 \approx 0.1 - \frac{0.1^3}{6} = 0.1 - 0.0001667 = 0.0998333
$$
精确值：$\sin 0.1 \approx 0.0998334$，误差约$10^{-7}$

#### 2. 极限计算（泰勒展开法）
比洛必达法则更系统的方法

**例**：$\lim_{x\to 0} \frac{\sin x - x}{x^3}$
展开$\sin x = x - \frac{x^3}{6} + o(x^4)$
$$
\frac{\sin x - x}{x^3} = \frac{-\frac{x^3}{6} + o(x^4)}{x^3} = -\frac{1}{6} + o(1) \to -\frac{1}{6}
$$

#### 3. 估计误差
用拉格朗日余项估计近似误差

## 九、多元函数微分简介

### 9.1 偏导数

#### 定义
函数$z=f(x,y)$在$(x_0,y_0)$处：
- 对$x$的偏导：$f_x(x_0,y_0)=\lim_{\Delta x\to 0}\frac{f(x_0+\Delta x,y_0)-f(x_0,y_0)}{\Delta x}$
- 对$y$的偏导：$f_y(x_0,y_0)=\lim_{\Delta y\to 0}\frac{f(x_0,y_0+\Delta y)-f(x_0,y_0)}{\Delta y}$

#### 计算方法
对某个变量求导时，将其他变量视为常数

**例**：$f(x,y)=x^2y+y^3$
- $f_x=2xy$（将$y$视为常数）
- $f_y=x^2+3y^2$（将$x$视为常数）

### 9.2 全微分

#### 定义
若$\Delta z = f(x_0+\Delta x,y_0+\Delta y)-f(x_0,y_0)=A\Delta x+B\Delta y+o(\rho)$
其中$\rho=\sqrt{(\Delta x)^2+(\Delta y)^2}$
则称$f$在$(x_0,y_0)$可微，全微分$dz=A\Delta x+B\Delta y$

#### 计算公式
若$f_x,f_y$连续，则$f$可微，且：
$$ dz = f_x(x,y)dx + f_y(x,y)dy $$

#### 例：$z=x^2y+y^2$
$z_x=2xy$，$z_y=x^2+2y$
$$ dz = 2xy dx + (x^2+2y)dy $$

### 9.3 链式法则（多元复合）

#### 情形1：$z=f(u,v)$，$u=u(x)$，$v=v(x)$
$$ \frac{dz}{dx} = \frac{\partial z}{\partial u}\frac{du}{dx} + \frac{\partial z}{\partial v}\frac{dv}{dx} $$

#### 情形2：$z=f(u,v)$，$u=u(x,y)$，$v=v(x,y)$
$$
\begin{aligned}
\frac{\partial z}{\partial x} &= \frac{\partial z}{\partial u}\frac{\partial u}{\partial x} + \frac{\partial z}{\partial v}\frac{\partial v}{\partial x} \\
\frac{\partial z}{\partial y} &= \frac{\partial z}{\partial u}\frac{\partial u}{\partial y} + \frac{\partial z}{\partial v}\frac{\partial v}{\partial y}
\end{aligned}
$$

#### 例：$z=e^{u}\sin v$，$u=xy$，$v=x+y$
$$
\begin{aligned}
\frac{\partial z}{\partial x} &= e^{u}\sin v \cdot y + e^{u}\cos v \cdot 1 \\
&= e^{xy}[y\sin(x+y) + \cos(x+y)]
\end{aligned}
$$

## 十、重要结论与技巧总结

### 10.1 导数存在性判定流程图

```
              函数f(x)在x0处
                    |
                    v
               是否连续？
               /          \
             否           是
              |            |
        不可导<----  检查左右导数
                      /        \
                 都存在且相等   至少一个不存在或不相等
                    |                    |
                可导               不可导
```

### 10.2 求导方法选择指南

| 函数类型 | 首选方法 | 备选方法 |
|---------|---------|---------|
| 基本初等函数 | 直接公式 | - |
| 四则运算 | 相应法则 | - |
| 复合函数 | 链式法则 | 对数求导 |
| 隐函数 | 隐函数求导法 | 化为显函数 |
| 参数方程 | 参数方程求导公式 | - |
| 幂指函数 | 对数求导法 | 化为指数函数 |
| 多因子乘积商 | 对数求导法 | 直接求导（繁琐） |

### 10.3 微分近似计算精度

| 公式 | 条件 | 一次近似精度 | 二次近似精度 |
|------|------|------------|------------|
| $(1+x)^a \approx 1+ax$ | $|x|\ll 1$ | $O(x^2)$ | $1+ax+\frac{a(a-1)}{2}x^2$ |
| $e^x \approx 1+x$ | $|x|\ll 1$ | $O(x^2)$ | $1+x+\frac{x^2}{2}$ |
| $\sin x \approx x$ | $|x|\ll 1$ | $O(x^3)$ | $x-\frac{x^3}{6}$ |
| $\ln(1+x) \approx x$ | $|x|\ll 1$ | $O(x^2)$ | $x-\frac{x^2}{2}$ |

### 10.4 常见错误与注意事项

1. **链式法则遗漏**：复合函数求导时忘记乘内层导数
2. **乘积法则误用**：$(fg)' \neq f'g'$
3. **隐函数求导**：忘记$y$是$x$的函数
4. **对数求导**：忘记取绝对值或最后乘以原函数
5. **分段函数**：在分段点只求了一侧导数
6. **高阶导数**：莱布尼茨公式中组合数系数错误
7. **微分近似**：$\Delta x$太大导致误差过大

---

## 学习建议

1. **基础公式必须熟记**：基本初等函数的导数公式要像乘法口诀一样熟练
2. **掌握核心法则**：乘积、商、链式三大法则要灵活运用
3. **多练特殊题型**：隐函数、参数方程、幂指函数等特殊求导要多练习
4. **理解几何意义**：导数=斜率，微分=线性近似，极值=局部最值
5. **联系实际应用**：最优化问题、近似计算、误差估计等实际问题

**终极检验**：能否在3分钟内正确求出$y = \frac{x^2 e^{2x} \sin x}{\sqrt{1+x^2}}$的导数？如果能，说明求导部分基本掌握。