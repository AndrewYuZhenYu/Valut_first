好的，我整理一份纯干货、无例题、知识点全覆盖的总结，适合考前快速回顾。

---

# 微积分（下）月考二 纯知识点总结

---

## 第九章 重积分

---

### 一、三重积分的基本概念

**形式：**

$$
\iiint_{\Omega} f(x,y,z) \, dV = \iiint_{\Omega} f(x,y,z) \, dxdydz
$$

**几何意义：** 当 $f(x,y,z) = 1$ 时，积分值 $=$ 区域 $\Omega$ 的体积。

---

### 二、三重积分的对称性

#### 1. 关于坐标平面对称

**(1) 关于 $x=0$（$YOZ$ 平面）对称：**

$$
\iiint_{\Omega} f \, dV =
\begin{cases}
0, & f(-x,y,z) = -f(x,y,z) \quad (\text{关于 }x\text{ 为奇函数}) \\[8pt]
\displaystyle 2 \iiint_{\Omega_1} f \, dV, & f(-x,y,z) = f(x,y,z) \quad (\text{关于 }x\text{ 为偶函数})
\end{cases}
$$

$\Omega_1$ 是 $\Omega$ 在 $x > 0$ 的部分。

**(2) 关于 $y=0$（$XOZ$ 平面）对称完全类似。**
**(3) 关于 $z=0$（$XOY$ 平面）对称完全类似。**

---

#### 2. 关于多个坐标平面对称

**关于 $x=0$ 和 $y=0$ 均对称：**

- 关于 $x$ 或 $y$ 为奇函数 → 积分为 $0$
- 关于 $x$ 且 $y$ 均为偶函数 → 积分 $= 4$ 倍第一象限部分

**关于 $x=0$、$y=0$、$z=0$ 均对称：**

- 关于任一变量为奇函数 → 积分为 $0$
- 关于三个变量均为偶函数 → 积分 $= 8$ 倍第一卦限部分

---

#### 3. 奇偶函数快速判断

**奇函数（对称区域上积分为 0）：**
- 单个变量的奇次幂：$x$、$x^3$、$xyz$（对 $x$ 是奇函数）
- $\sin x$、$\tan x$、$\arctan x$

**偶函数：**
- $x^2$、$y^2$、$z^2$、$|x|$、$\cos x$
- $f(x^2+y^2+z^2)$ 形式（关于每个变量都是偶函数）

---

### 三、轮换对称性

若 $\Omega$ 的方程交换 $x,y,z$ 任意两个不变，则：

$$
\iiint_{\Omega} f(x) \, dV = \iiint_{\Omega} f(y) \, dV = \iiint_{\Omega} f(z) \, dV
$$

**核心应用：**

$$
\iiint_{\Omega} x^2 \, dV = \frac{1}{3} \iiint_{\Omega} (x^2 + y^2 + z^2) \, dV
$$

---

### 四、三重积分的计算方法

#### 1. 直角坐标——投影法（先一后二）

**公式：**

$$
\iiint_{\Omega} f(x,y,z) \, dV = \iint_{D_{xy}} \left[ \int_{z_1(x,y)}^{z_2(x,y)} f(x,y,z) \, dz \right] dxdy
$$

**操作步骤：**
1. 联立曲面方程消去 $z$，得投影区域 $D_{xy}$ 的边界（等式变不等式）
2. 过 $D_{xy}$ 内一点作 $z$ 轴平行线确定上下限
3. 先积 $z$，再处理 $x,y$ 的二重积分

---

#### 2. 直角坐标——截面法（先二后一）

**公式：**

$$
\iiint_{\Omega} f(z) \, dV = \int_{c_1}^{c_2} f(z) \cdot S(z) \, dz
$$

$S(z)$ 是截面 $D_z$ 的面积。

**适用条件：**
- 被积函数只含一个变量（$z$ 或 $x$ 或 $y$）
- 截面形状规则，面积易求

---

#### 3. 柱面坐标

**变换：**

$$
\begin{cases}
x = \rho \cos \theta, & 0 \leqslant \rho < +\infty \\
y = \rho \sin \theta, & 0 \leqslant \theta \leqslant 2\pi \\
z = z, & -\infty < z < +\infty
\end{cases}
$$

**体积微元：**

$$
dV = \rho \, d\rho d\theta dz
$$

**积分公式：**

$$
\iiint_{\Omega} f \, dV = \int_{\alpha}^{\beta} d\theta \int_{\rho_1(\theta)}^{\rho_2(\theta)} d\rho \int_{z_1(\rho,\theta)}^{z_2(\rho,\theta)} f(\rho \cos \theta, \rho \sin \theta, z) \, \rho dz
$$

**适用场景：**
- 积分区域为圆柱体、圆锥体、旋转抛物面
- 被积函数含 $x^2 + y^2$

---

#### 4. 球面坐标

**变换：**

$$
\begin{cases}
x = r \sin \phi \cos \theta, & 0 \leqslant r < +\infty \\
y = r \sin \phi \sin \theta, & 0 \leqslant \phi \leqslant \pi \\
z = r \cos \phi, & 0 \leqslant \theta \leqslant 2\pi
\end{cases}
$$

**体积微元：**

$$
dV = r^2 \sin \phi \, dr d\phi d\theta
$$

**变量含义：**
- $r$：点到原点的距离
- $\phi$：向量与 $z$ 轴正方向的夹角
- $\theta$：投影到 $XOY$ 面后与 $x$ 轴的夹角

**积分公式：**

$$
\iiint_{\Omega} f \, dV = \int_{a}^{b} d\theta \int_{\phi_1(\theta)}^{\phi_2(\theta)} d\phi \int_{r_1(\phi,\theta)}^{r_2(\phi,\theta)} f(r \sin \phi \cos \theta, r \sin \phi \sin \theta, r \cos \phi) \, r^2 \sin \phi \, dr
$$

**常见 $\phi$ 值：**
- 整个球：$\phi \in [0,\pi]$
- 上半球：$\phi \in [0,\frac{\pi}{2}]$
- 锥面 $z = \sqrt{x^2+y^2}$ 对应 $\phi = \frac{\pi}{4}$

**适用场景：**
- 积分区域为球体、球冠、锥体
- 被积函数含 $x^2 + y^2 + z^2$

---

#### 5. 坐标系选择策略

| 特征 | 选择 |
|------|------|
| 长方体、四面体等方形区域 | 直角坐标 |
| 圆柱体、圆锥体、旋转抛物面 | 柱面坐标 |
| 被积函数含 $x^2+y^2$ | 柱面坐标 |
| 球体、球冠、球锥 | 球面坐标 |
| 被积函数含 $x^2+y^2+z^2$ | 球面坐标 |
| 被积函数只含一个变量 | 截面法（先二后一） |

---

## 第十章 曲线积分与曲面积分

---

### 一、第一型曲线积分（对弧长的曲线积分）

#### 1. 形式

平面曲线：
$$
\int_{L} f(x,y) \, ds
$$

空间曲线：
$$
\int_{L} f(x,y,z) \, ds
$$

闭合曲线记为：
$$
\oint_{L} f \, ds
$$

---

#### 2. 性质

- **与方向无关：** $\int_{L(AB)} f \, ds = \int_{L(BA)} f \, ds$
- **可以代入曲线方程化简被积函数**

---

#### 3. 几何意义

- $f \equiv 1$ 时：曲线 $L$ 的长度
- $f(x,y)$ 时：以 $L$ 为准线、母线垂直于 $XOY$ 平面的柱面面积

---

#### 4. 对称性

- 曲线关于 $x=0$ 对称，$f$ 关于 $x$ 为奇函数 → 积分为 $0$
- 曲线关于 $y=0$ 对称，$f$ 关于 $y$ 为奇函数 → 积分为 $0$
- 曲线关于 $y=x$ 对称 → $\int_L f(x,y) ds = \int_L f(y,x) ds$

---

#### 5. 计算方法

**平面曲线（参数方程）：**

$$
\int_{L} f(x,y) \, ds = \int_{\alpha}^{\beta} f(x(t), y(t)) \sqrt{[x'(t)]^2 + [y'(t)]^2} \, dt
$$

**空间曲线（参数方程）：**

$$
\int_{L} f(x,y,z) \, ds = \int_{\alpha}^{\beta} f(x(t), y(t), z(t)) \sqrt{[x'(t)]^2 + [y'(t)]^2 + [z'(t)]^2} \, dt
$$

**空间曲线参数化：** 两个曲面联立 → 消元得到 $x,y$ 关系 → 写出 $x,y$ 的参数 → 代回求 $z$ 的参数。

---

### 二、第二型曲线积分（对坐标的曲线积分）

#### 1. 形式

平面：
$$
\int_{L} P(x,y) \, dx + Q(x,y) \, dy
$$

空间：
$$
\int_{L} P(x,y,z) \, dx + Q(x,y,z) \, dy + R(x,y,z) \, dz
$$

---

#### 2. 性质

- **与方向有关：** $\int_{L(AB)} = -\int_{L(BA)}$（反向变号）
- 闭合曲线：逆时针为正，顺时针为负
- **一般不使用奇偶对称性**

---

#### 3. 计算方法

**(1) 直接法（参数方程）**

$$
\int_{L} P \, dx + Q \, dy = \int_{\alpha}^{\beta} \bigl[ P \cdot x'(t) + Q \cdot y'(t) \bigr] \, dt
$$

空间加上 $R \cdot z'(t)$。

---

**(2) 格林公式**

$L$ 为平面闭曲线（逆时针），围成区域 $D$：

$$
\oint_{L} P \, dx + Q \, dy = \iint_{D} \left( \frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y} \right) dxdy
$$

**使用条件：**
- $L$ 闭合
- $P,Q$ 在 $D$ 内有一阶连续偏导数（无奇点）

---

**(3) 补线用格林公式**

$L$ 不封闭时，补一条线使其封闭，再用格林公式，最后减去补线的积分。

---

**(4) 含有奇点的处理**

当分母含 $x^2+y^2$ 在 $(0,0)$ 无定义时：

**核心结论：**
- $\frac{\partial P}{\partial y} = \frac{\partial Q}{\partial x}$ 在除 $(0,0)$ 外处处成立
- 不包含原点的闭曲线积分 $= 0$
- 包含原点的同向闭曲线积分相等

**处理方法：** 作小圆 $x^2+y^2 = \varepsilon^2$ 挖去原点，转化为小圆上的积分。

---

#### 4. 积分与路径无关

以下四条等价：

1. $\int_L Pdx + Qdy$ 与路径无关
2. 沿 $D$ 内任意闭曲线积分为 $0$
3. $\frac{\partial P}{\partial y} = \frac{\partial Q}{\partial x}$ 在 $D$ 内处处成立
4. $Pdx + Qdy$ 是某函数 $F(x,y)$ 的全微分

---

### 三、第一型曲面积分（对面积的曲面积分）

#### 1. 形式

$$
\iint_{\Sigma} f(x,y,z) \, dS
$$

#### 2. 性质

- 与方向无关
- 对称性与三重积分一致
- 轮换对称性适用

#### 3. 几何意义

$f \equiv 1$ 时，积分值 $=$ 曲面 $\Sigma$ 的面积。

#### 4. 计算方法

曲面 $z = z(x,y)$，投影到 $XOY$ 面 $D_{xy}$：

$$
\iint_{\Sigma} f(x,y,z) \, dS = \iint_{D_{xy}} f(x,y,z(x,y)) \sqrt{1 + z_x^2 + z_y^2} \, dxdy
$$

$dS = \sqrt{1 + z_x^2 + z_y^2} \, dxdy$ 是曲面面积微元。

---

### 四、第二型曲面积分（对坐标的曲面积分）

#### 1. 形式

$$
\iint_{\Sigma} P \, dydz + Q \, dzdx + R \, dxdy
$$

#### 2. 性质

- **与方向有关：** 反向变号
- 上侧（法向量与 $z$ 轴夹角为锐角）→ 正
- 下侧（法向量与 $z$ 轴夹角为钝角）→ 负
- 一般不使用奇偶对称性

---

#### 3. 计算方法

**(1) 分面投影法**

若 $\Sigma: z = z(x,y)$，投影到 $XOY$ 面 $D_{xy}$：

$$
\iint_{\Sigma} R(x,y,z) \, dxdy = \pm \iint_{D_{xy}} R(x,y,z(x,y)) \, dxdy
$$

上侧取正，下侧取负。

**(2) 合一投影法**

投影到 $XOY$ 面时，将 $dydz$ 和 $dzdx$ 也转化：

$$
\iint_{\Sigma} P \, dydz + Q \, dzdx + R \, dxdy = \iint_{D_{xy}} \bigl[ P \cdot (-z_x) + Q \cdot (-z_y) + R \bigr] \, dxdy
$$

---

**(3) 高斯公式**

$\Sigma$ 为空间闭区域 $\Omega$ 的外侧：

$$
\oiint_{\Sigma} P \, dydz + Q \, dzdx + R \, dxdy = \iiint_{\Omega} \left( \frac{\partial P}{\partial x} + \frac{\partial Q}{\partial y} + \frac{\partial R}{\partial z} \right) dV
$$

**不封闭时：** 补面封闭后用高斯公式，再减去补面部分。

**补面技巧：** 常补 $z = \text{常数}$ 的平面，此时 $dz = 0$ 简化大量计算。

---

#### 4. 两类曲面积分的关系

$$
\iint_{\Sigma} P \, dydz + Q \, dzdx + R \, dxdy = \iint_{\Sigma} (P \cos \alpha + Q \cos \beta + R \cos \gamma) \, dS
$$

$(\cos \alpha, \cos \beta, \cos \gamma)$ 为曲面单位法向量。

---

### 五、多元积分的物理应用

#### 1. 质心

密度 $\rho(x,y,z)$：

$$
\bar{x} = \frac{\iiint_{\Omega} x \rho \, dV}{\iiint_{\Omega} \rho \, dV}, \quad \bar{y} = \frac{\iiint_{\Omega} y \rho \, dV}{\iiint_{\Omega} \rho \, dV}, \quad \bar{z} = \frac{\iiint_{\Omega} z \rho \, dV}{\iiint_{\Omega} \rho \, dV}
$$

#### 2. 转动惯量

$$
I_x = \iiint_{\Omega} (y^2+z^2) \rho \, dV
$$

$$
I_y = \iiint_{\Omega} (x^2+z^2) \rho \, dV
$$

$$
I_z = \iiint_{\Omega} (x^2+y^2) \rho \, dV
$$

#### 3. 通量

$\mathbf{A} = (P,Q,R)$，$n$ 为单位外法向量：

$$
\iint_{\Sigma} \mathbf{A} \cdot \mathbf{n} \, dS = \iint_{\Sigma} P \, dydz + Q \, dzdx + R \, dxdy
$$

---

### 六、梯度、散度、旋度

#### 1. 梯度（标量场 → 向量场）

$$
\operatorname{grad} u = \left( \frac{\partial u}{\partial x}, \frac{\partial u}{\partial y}, \frac{\partial u}{\partial z} \right) = \frac{\partial u}{\partial x} \mathbf{i} + \frac{\partial u}{\partial y} \mathbf{j} + \frac{\partial u}{\partial z} \mathbf{k}
$$

---

#### 2. 散度（向量场 → 标量场）

$$
\operatorname{div} \mathbf{A} = \frac{\partial P}{\partial x} + \frac{\partial Q}{\partial y} + \frac{\partial R}{\partial z}
$$

散度 $= 0$ → 无源场。

---

#### 3. 旋度（向量场 → 向量场）

$$
\operatorname{rot} \mathbf{A} = \begin{vmatrix}
\mathbf{i} & \mathbf{j} & \mathbf{k} \\[6pt]
\dfrac{\partial}{\partial x} & \dfrac{\partial}{\partial y} & \dfrac{\partial}{\partial z} \\[8pt]
P & Q & R
\end{vmatrix}
$$

展开：

$$
\operatorname{rot} \mathbf{A} = \left( \frac{\partial R}{\partial y} - \frac{\partial Q}{\partial z}, \; \frac{\partial P}{\partial z} - \frac{\partial R}{\partial x}, \; \frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y} \right)
$$

旋度 $= \mathbf{0}$ → 无旋场（保守场）。

---

#### 4. 两个重要恒等式

$$
\operatorname{rot}(\operatorname{grad} u) = \mathbf{0}
$$

梯度场必无旋。

$$
\operatorname{div}(\operatorname{rot} \mathbf{A}) = 0
$$

旋度场必无源。

---

#### 5. 常用混合运算

$$
\operatorname{div}(\operatorname{grad} u) = \frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2} + \frac{\partial^2 u}{\partial z^2}
$$

即 Laplace 算子 $\nabla^2 u$ 或 $\Delta u$。

---

#### 6. 常见结果

对于 $u = r = \sqrt{x^2+y^2+z^2}$：

- $\operatorname{grad} r = \left( \dfrac{x}{r}, \dfrac{y}{r}, \dfrac{z}{r} \right) = \dfrac{\mathbf{r}}{r}$
- $\operatorname{div}(\operatorname{grad} r) = \dfrac{2}{r}$

---

