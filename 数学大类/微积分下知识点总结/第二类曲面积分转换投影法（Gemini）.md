# 第二类曲面积分的转换投影法

## 一、第二类曲面积分的定义

设有向曲面为 $\Sigma$，向量场为：
$$\mathbf{F} = (P, Q, R)$$

曲面的单位法向量为：
$$\mathbf{n} = (\cos\alpha, \cos\beta, \cos\gamma)$$

则第二类曲面积分定义为：
$$\iint_{\Sigma} (P\cos\alpha + Q\cos\beta + R\cos\gamma) \,\mathrm{d}S$$

通常记作：
$$\iint_{\Sigma} P\,\mathrm{d}y\mathrm{d}z + Q\,\mathrm{d}z\mathrm{d}x + R\,\mathrm{d}x\mathrm{d}y$$

**其几何意义为：** 向量场通过曲面的总通量（Flux）。

---

## 二、为什么需要转换投影法

直接计算 $\iint_{\Sigma} (P\cos\alpha + Q\cos\beta + R\cos\gamma) \,\mathrm{d}S$ 往往比较困难。原因在于：
1. 曲面面积元 $\mathrm{d}S$ 不易计算；
2. 方向余弦 $\cos\alpha, \cos\beta, \cos\gamma$ 不易求出。

因此我们希望将曲面积分转化为平面区域上的二重积分，即：
$$\Sigma \longrightarrow D$$
这就是转换投影法的基本思想。

---

## 三、投影到 $xOy$ 平面的公式推导

设曲面方程为 $z=z(x,y)$，其在 $xOy$ 平面上的投影区域为 $D$。

### 第一步：求法向量
将曲面写成隐函数形式：
$$F(x,y,z) = z - z(x,y)$$

由梯度公式可得法向量：
$$\mathbf{n} = (-z_x, -z_y, 1)$$

其中偏导数记为 $z_x = \frac{\partial z}{\partial x}, z_y = \frac{\partial z}{\partial y}$。

对应的单位法向量为：
$$\frac{(-z_x, -z_y, 1)}{\sqrt{1+z_x^2+z_y^2}}$$

### 第二步：求方向余弦
由单位法向量可得：
$$\cos\alpha = \frac{-z_x}{\sqrt{1+z_x^2+z_y^2}}$$
$$\cos\beta = \frac{-z_y}{\sqrt{1+z_x^2+z_y^2}}$$
$$\cos\gamma = \frac{1}{\sqrt{1+z_x^2+z_y^2}}$$

### 第三步：求面积元
曲面面积元为：
$$\mathrm{d}S = \sqrt{1+z_x^2+z_y^2} \,\mathrm{d}x\mathrm{d}y$$

因此，三个投影分量分别为：
$$\cos\alpha\,\mathrm{d}S = -z_x\,\mathrm{d}x\mathrm{d}y = -\frac{\partial z}{\partial x}\,\mathrm{d}x\mathrm{d}y$$
$$\cos\beta\,\mathrm{d}S = -z_y\,\mathrm{d}x\mathrm{d}y = -\frac{\partial z}{\partial y}\,\mathrm{d}x\mathrm{d}y$$
$$\cos\gamma\,\mathrm{d}S = \mathrm{d}x\mathrm{d}y$$

### 第四步：代入定义
由定义：
$$I = \iint_{\Sigma} (P\cos\alpha + Q\cos\beta + R\cos\gamma) \,\mathrm{d}S$$

代入上述结果可得最终的投影公式：
$$\boxed{I = \pm \iint_D \left(-P\frac{\partial z}{\partial x} - Q\frac{\partial z}{\partial y} + R\right) \,\mathrm{d}x\mathrm{d}y}$$

**符号判定：**
* 当法向量与 $z$ 轴正方向同向时，取**正号**；
* 当法向量与 $z$ 轴正方向反向时，取**负号**。

---

## 四、投影到其他坐标面的公式

### 投影到 $yOz$ 平面
若曲面表示为 $x=x(y,z)$，则：
$$\boxed{I = \pm \iint_D \left(P - Q\frac{\partial x}{\partial y} - R\frac{\partial x}{\partial z}\right) \,\mathrm{d}y\mathrm{d}z}$$

**符号判定：**
* 法向量与 $x$ 轴正方向同向取**正号**；
* 法向量与 $x$ 轴正方向反向取**负号**。

### 投影到 $zOx$ 平面
若曲面表示为 $y=y(z,x)$，则：
$$\boxed{I = \pm \iint_D \left(-P\frac{\partial y}{\partial z} + Q - R\frac{\partial y}{\partial x}\right) \,\mathrm{d}z\mathrm{d}x}$$

**符号判定：**
* 法向量与 $y$ 轴正方向同向取**正号**；
* 法向量与 $y$ 轴正方向反向取**负号**。

---

## 五、统一记忆规律

对于第二类曲面积分 $\iint_{\Sigma} P\,\mathrm{d}y\mathrm{d}z + Q\,\mathrm{d}z\mathrm{d}x + R\,\mathrm{d}x\mathrm{d}y$，有如下三大规律：

* **规律一：投影到哪个坐标面，就保留哪个微分。**
  例如：投影到 $xOy$ 平面，则公式末尾一定是 $\mathrm{d}x\mathrm{d}y$。
* **规律二：投影轴对应的分量保持不变。**
  * 投影到 $xOy$ 平面时，缺失的是 $z$ 轴，因此公式中原样保留的是 $R$。
  * 投影到 $yOz$ 平面时，缺失的是 $x$ 轴，因此公式中原样保留的是 $P$。
  * 投影到 $zOx$ 平面时，缺失的是 $y$ 轴，因此公式中原样保留的是 $Q$。
* **规律三：符号永远放在积分号前面整体处理。**
  绝对不要试图单独修改括号内某一项的符号。统一采用 $\pm \iint_D (\cdots)$ 的形式，正负号完全由整体法向量相对于投影轴的指向决定。

---

## 六、考试速记版

* **投影到 $xOy$：**
  $$\boxed{I = \pm \iint_D \left(-P\frac{\partial z}{\partial x} - Q\frac{\partial z}{\partial y} + R\right) \,\mathrm{d}x\mathrm{d}y}$$

* **投影到 $yOz$：**
  $$\boxed{I = \pm \iint_D \left(P - Q\frac{\partial x}{\partial y} - R\frac{\partial x}{\partial z}\right) \,\mathrm{d}y\mathrm{d}z}$$

* **投影到 $zOx$：**
  $$\boxed{I = \pm \iint_D \left(-P\frac{\partial y}{\partial z} + Q - R\frac{\partial y}{\partial x}\right) \,\mathrm{d}z\mathrm{d}x}$$

> **💡 终极心法**
> **先按投影公式无脑写出被积函数，再根据整体法向量方向确定积分号最前面的正负号。**