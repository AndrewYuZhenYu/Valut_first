# MATLAB 速成教程

> 从零开始，系统掌握 MATLAB 核心技能

---

## 目录

1. [[#1. MATLAB 简介]]
2. [[#2. 界面与基本操作]]
3. [[#3. 变量与数据类型]]
4. [[#4. 矩阵与数组（核心）]]
5. [[#5. 运算符]]
6. [[#6. 字符串操作]]
7. [[#7. 控制流]]
8. [[#8. 函数]]
9. [[#9. 绘图与可视化]]
10. [[#10. 文件读写]]
11. [[#11. 常用内置函数速查]]
12. [[#12. 调试技巧]]
13. [[#13. Cell 数组与结构体]]
14. [[#14. 面向对象编程]]
15. [[#15. 正则表达式]]
16. [[#16. 数值计算进阶]]
17. [[#17. 信号处理基础]]
18. [[#18. 符号计算（Symbolic Math）]]
19. [[#19. 并行计算]]
20. [[#20. 常见工程应用案例]]
21. [[#21. 实战练习]]

---

## 1. MATLAB 简介

MATLAB（Matrix Laboratory）是由 MathWorks 开发的数值计算环境，广泛应用于：

- 📐 **工程计算**：信号处理、控制系统
- 📊 **数据分析**：统计建模、机器学习
- 🔬 **科学研究**：数值仿真、图像处理
- 📈 **金融建模**：量化分析

### 核心特点

|特点|说明|
|---|---|
|矩阵优先|所有数据本质上都是矩阵|
|解释执行|无需编译，逐行运行|
|工具箱丰富|信号、图像、深度学习等专业工具箱|
|可视化强大|内置大量绘图函数|

---

## 2. 界面与基本操作

### 2.1 主要窗口

```
┌─────────────────────────────────────────────────┐
│  Command Window（命令窗口）  ← 主要交互区域      │
│  Workspace（工作区）        ← 显示当前变量       │
│  Command History（历史记录）← 已执行的命令       │
│  Current Folder（当前目录） ← 文件管理           │
└─────────────────────────────────────────────────┘
```

### 2.2 基本命令

```matlab
% 这是注释（百分号开头）

clc          % 清空命令窗口
clear        % 清除工作区所有变量
clear x      % 清除变量 x
close all    % 关闭所有图形窗口

who          % 列出工作区变量名
whos         % 列出变量名及详细信息

help sin     % 查看 sin 函数帮助
doc sin      % 打开 sin 的完整文档
```

### 2.3 分号的作用

```matlab
x = 5        % 执行并显示结果：x = 5
x = 5;       % 执行但不显示结果（加分号抑制输出）
```

### 2.4 路径管理

```matlab
pwd          % 显示当前工作目录
cd 'C:\mywork'   % 切换目录
addpath('C:\myfunctions')  % 添加路径
```

---

## 3. 变量与数据类型

### 3.1 变量命名规则

- 区分大小写：`x` 和 `X` 是不同变量
- 字母开头，可包含数字和下划线
- 不能使用关键字（`if`, `for`, `end` 等）

### 3.2 数值类型

```matlab
a = 3.14;          % double（默认，64位浮点）
b = int32(10);     % 32位整数
c = uint8(255);    % 8位无符号整数
d = single(3.14);  % 单精度浮点

% 查看类型
class(a)           % 返回 'double'
isa(a, 'double')   % 返回 1（true）
```

### 3.3 逻辑类型

```matlab
t = true;          % 逻辑真
f = false;         % 逻辑假
result = (3 > 2);  % 比较运算，返回 1（true）

% 类型转换
logical(1)         % → true
double(true)       % → 1
```

### 3.4 复数

```matlab
z1 = 3 + 4i;       % 复数
z2 = complex(3, 4);% 等价写法

real(z1)           % 实部 → 3
imag(z1)           % 虚部 → 4
abs(z1)            % 模 → 5
angle(z1)          % 辐角（弧度）
conj(z1)           % 共轭 → 3 - 4i
```

### 3.5 特殊常量

```matlab
pi        % 圆周率 3.14159...
exp(1)    % 自然常数 e ≈ 2.71828
Inf       % 正无穷大
-Inf      % 负无穷大
NaN       % 非数值（Not a Number）
eps       % 机器精度 ≈ 2.22e-16
```

---

## 4. 矩阵与数组（核心）

> MATLAB 的灵魂：一切皆矩阵！

### 4.1 创建矩阵

```matlab
% 行向量
v = [1, 2, 3, 4, 5];      % 逗号或空格分隔
v = [1 2 3 4 5];           % 等价

% 列向量
c = [1; 2; 3; 4; 5];      % 分号换行

% 矩阵（3行3列）
A = [1 2 3; 4 5 6; 7 8 9];

% 等差序列
x = 1:5;                   % [1 2 3 4 5]
x = 1:2:10;                % [1 3 5 7 9]（步长为2）
x = linspace(0, 1, 5);    % [0 0.25 0.5 0.75 1]（5个等分点）

% 特殊矩阵
zeros(3)       % 3×3 全零矩阵
ones(2, 4)     % 2×4 全一矩阵
eye(3)         % 3×3 单位矩阵
rand(3)        % 3×3 均匀随机矩阵 [0,1]
randn(3)       % 3×3 标准正态随机矩阵
diag([1 2 3])  % 以[1,2,3]为对角线的矩阵
```

### 4.2 矩阵索引

```matlab
A = [1 2 3; 4 5 6; 7 8 9];

% 单元素访问（行, 列）
A(2, 3)        % → 6（第2行第3列）
A(5)           % → 5（按列线性索引）

% 切片（冒号运算）
A(1, :)        % 第1行所有列 → [1 2 3]
A(:, 2)        % 所有行第2列 → [2; 5; 8]
A(1:2, 2:3)    % 子矩阵 → [2 3; 5 6]
A(end, :)      % 最后一行
A(end-1, :)    % 倒数第二行

% 逻辑索引
v = [10 20 30 40 50];
v(v > 25)      % → [30 40 50]
v([1 3 5])     % → [10 30 50]（按索引向量取值）
```

### 4.3 矩阵修改

```matlab
A(2, 3) = 99;        % 修改单个元素
A(:, 2) = [7;8;9];   % 修改整列
A(end+1, :) = [10 11 12];  % 添加一行

% 删除行/列
A(2, :) = [];        % 删除第2行
A(:, 1) = [];        % 删除第1列
```

### 4.4 矩阵运算

```matlab
A = [1 2; 3 4];
B = [5 6; 7 8];

% 矩阵运算
A + B          % 矩阵加法
A - B          % 矩阵减法
A * B          % 矩阵乘法（线性代数）
A ^ 2          % 矩阵幂（A*A）
A'             % 转置（共轭转置）
A.'            % 非共轭转置
inv(A)         % 逆矩阵
det(A)         % 行列式
rank(A)        % 秩
trace(A)       % 迹（对角元素之和）

% 逐元素运算（加点）
A .* B         % 逐元素乘法
A ./ B         % 逐元素除法
A .^ 2         % 逐元素平方
```

### 4.5 矩阵信息

```matlab
A = [1 2 3; 4 5 6];

size(A)        % → [2 3]（行数、列数）
size(A, 1)     % → 2（行数）
size(A, 2)     % → 3（列数）
length(A)      % → 3（最大维度）
numel(A)       % → 6（元素总数）
ndims(A)       % → 2（维度数）
isempty(A)     % 是否为空矩阵
```

### 4.6 矩阵拼接与重塑

```matlab
A = [1 2; 3 4];
B = [5 6; 7 8];

[A, B]         % 水平拼接 → 2×4
[A; B]         % 垂直拼接 → 4×2

reshape(A, 1, 4)   % 变为1×4：[1 3 2 4]（按列优先）
reshape(A, 4, 1)   % 变为列向量

A(:)           % 拉成列向量（常用技巧）
```

### 4.7 线性方程组求解

```matlab
% 求解 Ax = b
A = [2 1; 5 7];
b = [11; 13];

x = A \ b      % 推荐：左除（最小二乘）
x = inv(A) * b % 等价但效率低
```

### 4.8 特征值与分解

```matlab
A = [4 1; 2 3];

% 特征值与特征向量
[V, D] = eig(A)      % V：特征向量矩阵，D：特征值对角矩阵

% SVD 分解
[U, S, V] = svd(A)

% LU 分解
[L, U, P] = lu(A)

% QR 分解
[Q, R] = qr(A)
```

---

## 5. 运算符

### 5.1 算术运算符

|运算符|含义|示例|
|---|---|---|
|`+`|加|`3 + 2 = 5`|
|`-`|减|`3 - 2 = 1`|
|`*`|矩阵乘|`A * B`|
|`.*`|逐元素乘|`A .* B`|
|`/`|矩阵右除|`A / B`|
|`./`|逐元素除|`A ./ B`|
|`\`|矩阵左除|`A \ B`|
|`^`|矩阵幂|`A ^ 2`|
|`.^`|逐元素幂|`A .^ 2`|

### 5.2 比较运算符

```matlab
3 == 3     % 等于 → 1
3 ~= 4     % 不等于 → 1
3 > 2      % 大于 → 1
3 >= 3     % 大于等于 → 1
3 < 4      % 小于 → 1
3 <= 4     % 小于等于 → 1
```

### 5.3 逻辑运算符

```matlab
true & false    % 逻辑与（AND）→ 0
true | false    % 逻辑或（OR）→ 1
~true           % 逻辑非（NOT）→ 0
xor(true, false)% 异或 → 1

% 短路运算（推荐用于条件判断）
true && false   % 短路与
true || false   % 短路或
```

---

## 6. 字符串操作

### 6.1 字符串创建

```matlab
s1 = 'Hello';           % 字符数组（传统）
s2 = "Hello";           % string 对象（推荐，R2016b+）

% 两者的区别
length('abc')   % → 3
length("abc")   % → 1（string对象算1个元素）
```

### 6.2 常用字符串函数

```matlab
s = 'Hello, World';

length(s)              % 长度 → 12
upper(s)               % 转大写
lower(s)               % 转小写
strtrim(s)             % 去除首尾空格
strsplit(s, ', ')      % 按分隔符拆分
strjoin({'a','b'}, '-')% 拼接 → 'a-b'

% 查找与替换
strfind(s, 'l')        % 查找位置 → [3 4 10]
strrep(s, 'World', 'MATLAB')  % 替换

% 字符串拼接
['Hello' ' ' 'World']      % 字符数组拼接
strcat('Hello', ' World')  % 函数拼接
"Hello" + " " + "World"    % string对象拼接

% 类型转换
num2str(3.14)          % 数值转字符串
str2num('3.14')        % 字符串转数值
str2double('3.14')     % 更安全的转换

% 格式化输出
sprintf('x = %.2f', 3.14159)  % → 'x = 3.14'
fprintf('结果：%d\n', 42)      % 打印到命令窗口
```

---

## 7. 控制流

### 7.1 if-elseif-else

```matlab
x = 85;

if x >= 90
    disp('优秀');
elseif x >= 75
    disp('良好');
elseif x >= 60
    disp('及格');
else
    disp('不及格');
end
```

### 7.2 switch-case

```matlab
day = 'Mon';

switch day
    case 'Mon'
        disp('星期一');
    case {'Sat', 'Sun'}    % 多值匹配
        disp('周末');
    otherwise
        disp('其他工作日');
end
```

### 7.3 for 循环

```matlab
% 基本 for 循环
for i = 1:5
    fprintf('%d ', i);
end
% 输出：1 2 3 4 5

% 遍历向量
v = [10 20 30];
for val = v
    disp(val);
end

% 遍历矩阵（按列）
A = [1 2; 3 4];
for col = A
    disp(col);  % 每次取一列（列向量）
end
```

### 7.4 while 循环

```matlab
n = 1;
while n < 10
    n = n * 2;
end
disp(n)   % → 16

% 无限循环（需手动中断）
while true
    x = input('输入数字（0退出）：');
    if x == 0
        break;
    end
end
```

### 7.5 break / continue

```matlab
% break：跳出循环
for i = 1:10
    if i == 5
        break;
    end
    disp(i);
end
% 输出 1 2 3 4

% continue：跳过当次迭代
for i = 1:5
    if mod(i, 2) == 0
        continue;   % 跳过偶数
    end
    disp(i);
end
% 输出 1 3 5
```

### 7.6 try-catch（异常处理）

```matlab
try
    x = 1 / 0;           % 不会报错（Inf）
    y = inv([0 0; 0 0]);  % 奇异矩阵警告
    error('自定义错误: %s', '出问题了');
catch err
    fprintf('捕获错误: %s\n', err.message);
end
```

---

## 8. 函数

### 8.1 函数文件（.m 文件）

```matlab
% 文件名必须与函数名一致：myAdd.m
function result = myAdd(a, b)
    % 两数相加
    % 输入：a, b - 数值
    % 输出：result - 和
    result = a + b;
end
```

调用：

```matlab
r = myAdd(3, 5);   % r = 8
```

### 8.2 多返回值

```matlab
% 文件：stats.m
function [mn, mx, avg] = stats(v)
    mn  = min(v);
    mx  = max(v);
    avg = mean(v);
end
```

调用：

```matlab
v = [3 1 4 1 5 9 2 6];
[a, b, c] = stats(v);   % 接收全部返回值
[a, ~, c] = stats(v);   % 用~忽略第二个返回值
```

### 8.3 可变参数

```matlab
function result = flexFunc(varargin)
    n = nargin;           % 输入参数个数
    fprintf('收到 %d 个参数\n', n);
    result = 0;
    for k = 1:n
        result = result + varargin{k};
    end
end

% 调用
flexFunc(1, 2, 3)    % 收到 3 个参数，result = 6
```

### 8.4 匿名函数

```matlab
% 语法：@(参数列表) 表达式
square = @(x) x.^2;
square(5)            % → 25
square([1 2 3])      % → [1 4 9]

% 捕获外部变量
a = 3;
f = @(x) a * x + 1;
f(2)                 % → 7（使用创建时的 a 值）

% 常见用法：传递给其他函数
fplot(@sin, [0, 2*pi])    % 绘制 sin 函数
fzero(@(x) x^2 - 4, 1)   % 求零点 → 2
```

### 8.5 局部函数与嵌套函数

```matlab
% 同一文件中可定义多个函数（主函数在最前）
function main()
    r = helper(5);
    disp(r);
end

function y = helper(x)   % 局部函数，只有本文件可见
    y = x^2;
end
```

### 8.6 函数句柄

```matlab
f = @sin;              % 函数句柄
f(pi/2)                % → 1

% 传递函数
result = integrate(@sin, 0, pi);

% 检查函数存在
exist('sin', 'builtin') % → 5（内置函数）
```

---

## 9. 绘图与可视化

### 9.1 基本二维绘图

```matlab
x = linspace(0, 2*pi, 100);
y = sin(x);

figure;              % 新建图形窗口
plot(x, y);          % 基本折线图

% 添加标注
title('正弦函数');
xlabel('x');
ylabel('sin(x)');
legend('sin(x)');
grid on;             % 显示网格
axis([0, 2*pi, -1.2, 1.2]);  % 设置坐标范围
```

### 9.2 线型与颜色

```matlab
x = 0:0.1:2*pi;

plot(x, sin(x), 'r-',  'LineWidth', 2);    % 红色实线
plot(x, cos(x), 'b--', 'LineWidth', 1.5);  % 蓝色虚线
plot(x, tan(x), 'g:o', 'MarkerSize', 5);   % 绿色点线+圆形标记

% 颜色代码：r=红 g=绿 b=蓝 k=黑 m=品红 c=青 y=黄
% 线型：- 实线  -- 虚线  : 点线  -. 点划线
% 标记：o 圆  * 星  + 加  x 叉  s 方  d 菱形  ^ 三角
```

### 9.3 多图绘制

```matlab
x = linspace(0, 2*pi, 100);

% 方法一：hold on 在同一坐标系绘多条线
figure;
hold on;
plot(x, sin(x), 'b', 'DisplayName', 'sin');
plot(x, cos(x), 'r', 'DisplayName', 'cos');
hold off;
legend show;

% 方法二：subplot 分割画布
figure;
subplot(2, 2, 1);  plot(x, sin(x)); title('sin');
subplot(2, 2, 2);  plot(x, cos(x)); title('cos');
subplot(2, 2, 3);  plot(x, sin(x).^2); title('sin²');
subplot(2, 2, 4);  plot(x, cos(x).^2); title('cos²');
```

### 9.4 其他图形类型

```matlab
% 散点图
scatter(rand(50,1), rand(50,1), 50, 'filled');

% 条形图
bar([1 3 2 5 4]);
barh([1 3 2 5 4]);    % 水平条形图

% 直方图
data = randn(1000, 1);
histogram(data, 30);   % 30个区间

% 饼图
pie([30 25 20 15 10], {'A','B','C','D','E'});

% 误差棒图
x = 1:5;
y = [2 4 3 5 4];
err = [0.3 0.4 0.2 0.5 0.3];
errorbar(x, y, err);

% 极坐标图
theta = linspace(0, 2*pi, 100);
r = 1 + 0.5*cos(3*theta);
polarplot(theta, r);

% 对数坐标
semilogy(1:100, exp(0.1*(1:100)));  % y轴对数
loglog(1:100, (1:100).^2);          % 双对数
```

### 9.5 三维绘图

```matlab
% 三维折线
t = linspace(0, 4*pi, 100);
plot3(sin(t), cos(t), t);
xlabel('x'); ylabel('y'); zlabel('z');
grid on;

% 三维曲面
[X, Y] = meshgrid(-3:0.1:3, -3:0.1:3);
Z = sin(sqrt(X.^2 + Y.^2));

figure;
surf(X, Y, Z);         % 有色曲面
colorbar;              % 显示颜色条
shading interp;        % 平滑着色

figure;
mesh(X, Y, Z);         % 网格曲面

figure;
contour(X, Y, Z, 20);  % 等高线（20条）
contourf(X, Y, Z, 20); % 填充等高线
```

### 9.6 图形美化与导出

```matlab
% 美化
set(gca, 'FontSize', 14);          % 坐标轴字号
set(gca, 'LineWidth', 1.5);        % 坐标轴线宽
set(gcf, 'Color', 'white');        % 背景白色

% 导出图形
saveas(gcf, 'plot.png');           % 保存为PNG
saveas(gcf, 'plot.pdf');           % 保存为PDF
print(gcf, 'plot', '-dpng', '-r300'); % 300dpi高分辨率
```

---

## 10. 文件读写

### 10.1 读写文本文件

```matlab
% 写文本文件
fid = fopen('data.txt', 'w');     % 'w'写入，'a'追加
fprintf(fid, '姓名, 成绩\n');
fprintf(fid, 'Alice, %d\n', 95);
fprintf(fid, 'Bob, %d\n', 87);
fclose(fid);

% 读文本文件
fid = fopen('data.txt', 'r');
line = fgetl(fid);                 % 读一行（字符串）
while ischar(line)
    disp(line);
    line = fgetl(fid);
end
fclose(fid);
```

### 10.2 读写 CSV

```matlab
% 写 CSV
data = [1 2 3; 4 5 6; 7 8 9];
writematrix(data, 'output.csv');

% 读 CSV
M = readmatrix('data.csv');        % 数值矩阵
T = readtable('data.csv');         % 表格（含列名）

% 表格操作
T.Score                            % 访问列
T(T.Score > 80, :)                 % 筛选行
writetable(T, 'output.csv');       % 写回CSV
```

### 10.3 读写 MAT 文件（MATLAB 原生）

```matlab
x = 1:10;
y = sin(x);
A = rand(3);

% 保存工作区变量
save('mydata.mat', 'x', 'y', 'A');    % 保存指定变量
save('mydata.mat');                     % 保存所有变量

% 加载
load('mydata.mat');                     % 加载所有
load('mydata.mat', 'x', 'y');         % 加载指定变量
```

### 10.4 读写 Excel

```matlab
% 写 Excel
T = table({'Alice';'Bob'}, [95;87], 'VariableNames', {'Name','Score'});
writetable(T, 'result.xlsx', 'Sheet', 1);

% 读 Excel
T = readtable('data.xlsx');
M = readmatrix('data.xlsx', 'Sheet', 'Sheet1', 'Range', 'B2:D10');
```

---

## 11. 常用内置函数速查

### 11.1 数学函数

```matlab
% 基本数学
abs(-5)          % 绝对值 → 5
sqrt(16)         % 平方根 → 4
exp(1)           % e^1 ≈ 2.718
log(exp(1))      % 自然对数 → 1
log2(8)          % 以2为底 → 3
log10(100)       % 以10为底 → 2

% 三角函数（输入为弧度）
sin(pi/2)        % → 1
cos(0)           % → 1
tan(pi/4)        % → 1
asin(1)          % 反正弦 → π/2
atan2(y, x)      % 四象限反正切

% 取整
floor(3.7)       % 向下取整 → 3
ceil(3.2)        % 向上取整 → 4
round(3.5)       % 四舍五入 → 4
fix(3.9)         % 截断取整（向零）→ 3
mod(10, 3)       % 取模（余数）→ 1
rem(10, 3)       % 余数 → 1
```

### 11.2 统计函数

```matlab
v = [4 1 3 5 2 3];

min(v)           % → 1
max(v)           % → 5
[m, i] = min(v) % 最小值及其索引
sum(v)           % → 18
prod(v)          % 累积 → 360
mean(v)          % 均值 → 3
median(v)        % 中位数 → 3
std(v)           % 标准差
var(v)           % 方差
sort(v)          % 升序排列
sort(v, 'descend') % 降序
cumsum(v)        % 累加 → [4 5 8 13 15 18]
diff(v)          % 差分 → [-3 2 2 -3 1]
```

### 11.3 矩阵函数

```matlab
A = magic(3);    % 3×3 幻方

sum(A)           % 各列之和（行向量）
sum(A, 2)        % 各行之和（列向量）
sum(A(:))        % 所有元素之和

max(A)           % 各列最大值
max(A(:))        % 全局最大值
max(max(A))      % 等价写法

fliplr(A)        % 左右翻转
flipud(A)        % 上下翻转
rot90(A)         % 逆时针旋转90°
triu(A)          % 取上三角
tril(A)          % 取下三角
```

### 11.4 查找函数

```matlab
v = [3 0 5 0 8];

find(v)          % 非零元素索引 → [1 3 5]
find(v > 4)      % 满足条件的索引 → [3 5]
any(v)           % 是否有非零元素 → 1
all(v)           % 是否全为非零 → 0
ismember(5, v)   % 是否在数组中 → 1
unique(v)        % 去重 → [0 3 5 8]
```

---

## 12. 调试技巧

### 12.1 常用调试方法

```matlab
% 1. 去掉分号查看中间结果
x = computeSomething()   % 不加;，直接显示

% 2. disp / fprintf 打印
disp(x);
fprintf('当前x = %.4f\n', x);

% 3. keyboard - 暂停执行，进入调试模式
for i = 1:10
    keyboard;   % 在此暂停，可查看变量，输入 dbcont 继续
end

% 4. 使用断点（在编辑器行号处点击红点）
```

### 12.2 常见错误及解决

|错误信息|原因|解决|
|---|---|---|
|`Undefined variable 'x'`|变量未定义|检查变量名、确保先赋值|
|`Matrix dimensions must agree`|矩阵维度不匹配|用`size()`检查尺寸|
|`Index exceeds matrix dimensions`|索引越界|检查索引是否超过`length()`|
|`Singular matrix`|矩阵奇异，无法求逆|使用`pinv()`伪逆或检查数据|
|`Subscript indices must be integers`|索引不是整数|使用`round()`或`floor()`|

### 12.3 性能优化

```matlab
% ❌ 慢：在循环中动态扩展数组
result = [];
for i = 1:10000
    result = [result, i^2];
end

% ✅ 快：预分配内存
result = zeros(1, 10000);
for i = 1:10000
    result(i) = i^2;
end

% ✅ 更快：向量化（完全避免循环）
result = (1:10000).^2;

% 计时
tic;
% ... 你的代码 ...
elapsed = toc;
fprintf('耗时：%.4f 秒\n', elapsed);

% 性能分析
profile on;
% ... 你的代码 ...
profile viewer;   % 查看各函数耗时
```

---

---

## 13. Cell 数组与结构体

### 13.1 Cell 数组

Cell 数组可以存储**不同类型、不同大小**的数据，用花括号 `{}` 创建和访问。

```matlab
% 创建 Cell 数组
c = {1, 'hello', [1 2 3], true};
c = cell(3, 2);          % 3×2 空 Cell 数组

% 访问元素
c{1}                     % 取出内容（花括号）→ 1
c(1)                     % 取出 Cell 单元（圆括号）→ {1}
c{2}(3)                  % 先取字符串，再取第3个字符

% 修改
c{5} = struct('name', 'Alice');  % 自动扩展

% Cell 数组操作
numel(c)                 % 元素数量
iscell(c)                % 是否是 Cell → 1
cellfun(@length, c)      % 对每个元素应用函数
```

### 13.2 Cell 数组常见用法

```matlab
% 存储不同长度的字符串（最常见用途）
names  = {'Alice', 'Bob', 'Charlie', 'Diana'};
scores = {95, 87, 92, 78};

% 遍历
for i = 1:numel(names)
    fprintf('%s: %d\n', names{i}, scores{i});
end

% 查找字符串
strcmp('Bob', names)           % 逐元素比较 → [0 1 0 0]
idx = strcmp('Bob', names);
names{idx}                     % → 'Bob'

% Cell 与矩阵互转
mat = cell2mat({1,2;3,4})      % → [1 2; 3 4]
c   = num2cell([1 2 3])        % → {1} {2} {3}
```

### 13.3 结构体（struct）

```matlab
% 创建结构体
s.name  = 'Alice';
s.age   = 20;
s.score = [85 92 78];

% 等价方式
s = struct('name', 'Alice', 'age', 20, 'score', [85 92 78]);

% 访问字段
s.name             % → 'Alice'
s.score(2)         % → 92

% 动态字段名
field = 'age';
s.(field)          % → 20

% 字段管理
fieldnames(s)      % → {'name'; 'age'; 'score'}
isfield(s, 'age')  % → 1
rmfield(s, 'age')  % 删除字段（返回新结构体）

% 嵌套结构体
s.address.city = '北京';
s.address.zip  = '100000';
```

### 13.4 结构体数组

```matlab
% 逐个赋值（自动形成数组）
students(1).name = 'Alice'; students(1).score = 95;
students(2).name = 'Bob';   students(2).score = 87;
students(3).name = 'Carol'; students(3).score = 92;

% 批量创建
students = struct('name', {'Alice','Bob','Carol'}, ...
                  'score', {95, 87, 92});

% 提取所有字段值
[students.score]      % → [95 87 92]（合并为向量）
{students.name}       % → {'Alice','Bob','Carol'}（合并为Cell）

% 按字段排序
[~, idx] = sort([students.score], 'descend');
students = students(idx);
```

### 13.5 Table（表格）

```matlab
Name  = {'Alice'; 'Bob'; 'Carol'};
Age   = [20; 22; 21];
Score = [95; 87; 92];
T = table(Name, Age, Score);

% 访问
T.Score                      % 列
T(2, :)                      % 第2行（仍是Table）
T{2, 'Score'}                % 取标量值

% 筛选
T(T.Score > 90, :)
T(strcmp(T.Name, 'Bob'), :)

% 添加/删除列
T.Grade = T.Score >= 90;
T(:, 'Age') = [];

% 排序与汇总
sortrows(T, 'Score', 'descend')
groupsummary(T, 'Grade', 'mean', 'Score')
```

---

## 14. 面向对象编程

### 14.1 类的定义（classdef）

```matlab
% 文件：Circle.m
classdef Circle
    properties
        Radius
        Color = 'blue'    % 带默认值
    end

    properties (Access = private)
        Area_
    end

    methods
        function obj = Circle(r)       % 构造函数
            obj.Radius = r;
            obj.Area_  = pi * r^2;
        end

        function a = getArea(obj)
            a = obj.Area_;
        end

        function disp(obj)             % 重载显示
            fprintf('Circle(r=%.2f, color=%s)\n', obj.Radius, obj.Color);
        end
    end

    methods (Static)                   % 静态方法
        function c = fromDiameter(d)
            c = Circle(d / 2);
        end
    end
end
```

```matlab
% 使用
c = Circle(5);
c.getArea()                  % → 78.5398
c.Color = 'red';
disp(c);
c2 = Circle.fromDiameter(10);
```

### 14.2 继承

```matlab
% Shape.m（父类）
classdef Shape
    properties
        Color = 'black'
    end
    methods
        function draw(obj)
            fprintf('绘制 %s\n', class(obj));
        end
    end
end

% Rectangle.m（子类）
classdef Rectangle < Shape
    properties
        Width; Height
    end
    methods
        function obj = Rectangle(w, h)
            obj.Width = w; obj.Height = h;
        end
        function a = area(obj)
            a = obj.Width * obj.Height;
        end
        function draw(obj)          % 方法重写
            fprintf('矩形 %d×%d\n', obj.Width, obj.Height);
        end
    end
end
```

### 14.3 运算符重载

```matlab
classdef Vec2
    properties
        X, Y
    end
    methods
        function obj = Vec2(x, y)
            obj.X = x; obj.Y = y;
        end
        function r = plus(a, b)      % 重载 +
            r = Vec2(a.X+b.X, a.Y+b.Y);
        end
        function n = norm(obj)
            n = sqrt(obj.X^2 + obj.Y^2);
        end
        function r = mtimes(a, b)    % 重载 * （点积或数乘）
            if isnumeric(b)
                r = Vec2(a.X*b, a.Y*b);
            else
                r = a.X*b.X + a.Y*b.Y;
            end
        end
    end
end
```

---

## 15. 正则表达式

### 15.1 基本用法

```matlab
str = 'Phone: 138-1234-5678, Email: user@example.com';

% 匹配位置
idx = regexp(str, '\d+');

% 匹配内容
mat = regexp(str, '\d+', 'match');
% → {'138','1234','5678'}

% 忽略大小写
regexpi('Hello MATLAB', 'matlab', 'match')  % → {'MATLAB'}
```

### 15.2 常用元字符

|元字符|含义|
|---|---|
|`.`|任意字符（除换行）|
|`\d`|数字 [0-9]|
|`\D`|非数字|
|`\w`|单词字符 [a-zA-Z0-9_]|
|`\s`|空白字符|
|`^`|行首|
|`$`|行尾|
|`*`|0次或多次|
|`+`|1次或多次|
|`?`|0次或1次|
|`{n,m}`|n到m次|
|`(...)`|捕获组|
|`(?:...)`|非捕获组|

### 15.3 捕获、替换与验证

```matlab
% 捕获组提取日期
str = '生日：2000-03-15';
tok = regexp(str, '(\d{4})-(\d{2})-(\d{2})', 'tokens');
year = tok{1}{1};   month = tok{1}{2};   day = tok{1}{3};

% 替换：多空格压缩为单空格
regexprep('Hello   World', '\s+', ' ')   % → 'Hello World'

% 每个单词加方括号
regexprep('foo bar', '(\w+)', '[$1]')    % → '[foo] [bar]'

% 提取所有邮箱地址
text = 'a@b.com and c@d.org';
emails = regexp(text, '\w+@\w+\.\w+', 'match')

% 验证手机号格式
isValid = ~isempty(regexp('13812345678', '^1[3-9]\d{9}$', 'once'));
```

---

## 16. 数值计算进阶

### 16.1 数值微积分

```matlab
% 数值微分
x = linspace(0, 2*pi, 1000);
y = sin(x);
dy = diff(y) ./ diff(x);        % 一阶差商（长度-1）
x_mid = (x(1:end-1)+x(2:end))/2;

% 数值积分
integral(@(x) sin(x).^2, 0, pi)   % 高精度自适应积分 → 1.5708
trapz(x, y)                        % 梯形法（离散数据）
cumtrapz(x, y)                     % 累积积分

% 二重/三重积分
integral2(@(x,y) x.^2+y.^2, 0,1, 0,1)
integral3(@(x,y,z) x+y+z, 0,1, 0,1, 0,1)
```

### 16.2 常微分方程（ODE）

```matlab
% dy/dt = -2y, y(0)=1
f = @(t, y) -2*y;
[t, y] = ode45(f, [0 5], 1);
plot(t, y, 'b-', t, exp(-2*t), 'r--');
legend('ode45','解析解');

% 高阶ODE降阶：y'' + 0.5y' + 4y = 0
% 令 z = [y; y']
f2 = @(t, z) [z(2); -0.5*z(2) - 4*z(1)];
[t, z] = ode45(f2, [0 20], [1; 0]);
plot(t, z(:,1), t, z(:,2));
legend('位移', '速度');

% 求解器选择
% ode45   非刚性，最常用（RK4/5）
% ode23   非刚性，低精度
% ode15s  刚性方程（首选）
% ode23s  刚性方程，低精度
% ode113  非刚性，高精度变阶法
```

### 16.3 优化

```matlab
% 一维最优化
f = @(x) x.^2 - 4*x + 3;
[xmin, fmin] = fminbnd(f, 0, 5)   % → xmin≈2, fmin≈-1

% 多维无约束（fminsearch / fminunc）
f2 = @(x) (x(1)-3)^2 + (x(2)-2)^2;
[x, fval] = fminsearch(f2, [0 0])

% 有约束优化（fmincon）
% min f(x)  s.t. A*x<=b
f3  = @(x) -x(1)*x(2);
A   = [1 1]; b = 10;
[x] = fmincon(f3, [1 1], A, b)

% 线性规划（linprog）
c  = [-5; -4];
A  = [6 4; 1 2];
b  = [24; 6];
lb = [0; 0];
[x, fval] = linprog(c, A, b, [], [], lb)

% 非线性方程求根
fzero(@(x) cos(x) - x, 1)         % → 0.7391（不动点）
fsolve(@(x) [x(1)^2+x(2)^2-1; x(1)-x(2)], [1;0])  % 方程组
```

### 16.4 插值与拟合

```matlab
x = [0 1 2 3 4 5];
y = [0 1 4 9 16 25];
xi = linspace(0, 5, 200);

% 插值
yi_lin   = interp1(x, y, xi, 'linear');
yi_spline= interp1(x, y, xi, 'spline');
yi_pchip = interp1(x, y, xi, 'pchip');   % 保形（推荐）

plot(x,y,'o', xi,yi_spline,'-', xi,yi_pchip,'--');
legend('数据','样条','PCHIP');

% 二维插值
[X,Y] = meshgrid(1:5, 1:5);
Z = peaks(5);
[Xi,Yi] = meshgrid(1:0.2:5, 1:0.2:5);
Zi = interp2(X, Y, Z, Xi, Yi, 'cubic');

% 多项式拟合（最小二乘）
p = polyfit(x, y, 2);             % 2次多项式系数
y_fit = polyval(p, xi);
fprintf('y ≈ %.4fx^2 + %.4fx + %.4f\n', p);
```

### 16.5 FFT 与频谱分析

```matlab
Fs = 1000; t = 0:1/Fs:1-1/Fs;
x = sin(2*pi*50*t) + 0.5*sin(2*pi*120*t) + 0.2*randn(size(t));

N = length(x);
X = fft(x);
f = (0:N/2) * Fs/N;
mag = 2*abs(X(1:N/2+1)) / N;      % 单边幅度谱

subplot(2,1,1); plot(t(1:200), x(1:200)); title('时域');
subplot(2,1,2); plot(f, mag);      title('频谱'); xlim([0 200]);
xlabel('Hz');
```

### 16.6 统计检验

```matlab
rng(42);
a = randn(1,100);
b = randn(1,100) + 0.3;

% t 检验
[h, p, ci] = ttest2(a, b);         % 双样本t检验
fprintf('h=%d, p=%.4f\n', h, p);

% 方差分析（ANOVA）
g1 = randn(20,1); g2 = randn(20,1)+1; g3 = randn(20,1)+2;
p = anova1([g1; g2; g3], [ones(20,1); 2*ones(20,1); 3*ones(20,1)]);

% 相关性
[r, p_corr] = corrcoef(a, b);
fprintf('r=%.4f, p=%.4f\n', r(1,2), p_corr(1,2));

% 正态性检验
[h_ks, p_ks] = kstest((a-mean(a))/std(a));   % KS检验
```

---

## 17. 信号处理基础

> 需要 Signal Processing Toolbox

### 17.1 滤波器设计

```matlab
Fs = 1000; Fc = 100;

% Butterworth 低通
[b, a] = butter(4, Fc/(Fs/2));
y = filtfilt(b, a, x);            % 零相位滤波

% 高通 / 带通 / 带阻
[b, a] = butter(4, Fc/(Fs/2), 'high');
[b, a] = butter(4, [50 150]/(Fs/2), 'bandpass');
[b, a] = butter(4, [50 150]/(Fs/2), 'stop');

% designfilt（推荐接口）
d = designfilt('lowpassiir', 'FilterOrder', 4, ...
               'HalfPowerFrequency', Fc, 'SampleRate', Fs);
y = filtfilt(d, x);

% 查看频率响应
freqz(b, a, 1024, Fs);
```

### 17.2 时频分析

```matlab
% 短时傅里叶变换（STFT）
[S, F, T] = spectrogram(x, hamming(128), 64, 256, Fs);
imagesc(T, F, 20*log10(abs(S))); axis xy; colorbar;
xlabel('时间(s)'); ylabel('频率(Hz)');

% 功率谱密度（Welch 法）
[pxx, f] = pwelch(x, hamming(256), 128, 512, Fs);
plot(f, 10*log10(pxx));
xlabel('Hz'); ylabel('dB/Hz');

% 互相关（时延估计）
[c, lags] = xcorr(sig1, sig2, 'normalized');
[~, idx] = max(c);
delay = lags(idx) / Fs;
```

### 17.3 常用窗函数

```matlab
N = 256;
figure; hold on;
plot(hann(N));
plot(hamming(N));
plot(blackman(N));
plot(kaiser(N, 8));
legend('Hann','Hamming','Blackman','Kaiser');
title('窗函数比较');
```

---

## 18. 符号计算（Symbolic Math）

> 需要 Symbolic Math Toolbox

### 18.1 基本符号运算

```matlab
syms x y z t n

% 代数化简
expand((x+y)^3)              % 展开
simplify(sin(x)^2+cos(x)^2) % → 1
factor(x^3 - x^2 - x + 1)   % 因式分解
collect(x^2 + 2*x*y + y*x)  % 合并同类项
```

### 18.2 微积分

```matlab
syms x t

% 求导
diff(sin(x^2))               % → 2*x*cos(x^2)
diff(x^3, x, 2)              % 二阶导 → 6*x

% 偏导
syms x y
f = x^2*y + y^3;
gradient_f = [diff(f,x); diff(f,y)]    % 梯度

% 积分
int(x^2, x)                  % 不定积分 → x^3/3
int(sin(x), 0, pi)           % 定积分 → 2
int(exp(-x^2), -Inf, Inf)    % 广义积分 → pi^(1/2)

% 极限
limit(sin(x)/x, x, 0)        % → 1
limit((1+1/x)^x, x, Inf)     % → exp(1)

% Taylor 展开
taylor(sin(x), x, 0, 'Order', 9)
```

### 18.3 方程与ODE求解

```matlab
syms x y t

% 代数方程
solve(x^2 - 5*x + 6 == 0, x)         % → [2; 3]
[sx, sy] = solve([x+y==5, x-y==1], [x,y])

% 微分方程符号解
syms y(t)
ode  = diff(y,t) + 2*y == 0;
cond = y(0) == 3;
sol  = dsolve(ode, cond)              % → 3*exp(-2*t)

% 符号结果转数值
double(sol)                           % 在t=0处（需subs）
subs(sol, t, 1)                       % t=1时的值
```

### 18.4 符号线性代数

```matlab
syms a b
A = [a 1; 0 b];
det(A)                    % → a*b
inv(A)                    % 符号逆
eig(A)                    % → [a; b]

% 符号转数值
expr = sin(sym(pi)/3);
double(expr)              % → 0.8660
```

---

## 19. 并行计算

> 需要 Parallel Computing Toolbox

### 19.1 parfor 并行循环

```matlab
% parfor 与 for 语法相同，自动并行化
n = 200;
result = zeros(1, n);

parfor i = 1:n
    result(i) = sum(eig(rand(100)));   % 各次独立计算
end

% parfor 限制：
% - 循环体不能依赖前一次迭代（无数据依赖）
% - 不能用 break / continue
% - 切片变量需符合规范
```

### 19.2 并行池管理

```matlab
p = parpool(4);           % 开启4个worker
p.NumWorkers              % 查看worker数
delete(gcp('nocreate')); % 安全关闭

% parfeval（异步提交）
f1 = parfeval(@rand, 1, 500, 500);    % 异步计算
f2 = parfeval(@fft,  1, rand(1,1e6));
r1 = fetchOutputs(f1);                 % 阻塞等待结果
r2 = fetchOutputs(f2);
```

### 19.3 GPU 加速

```matlab
% 将数据传入GPU
A_gpu = gpuArray(rand(1000));

% 在GPU上执行（语法与普通矩阵相同）
B_gpu = A_gpu * A_gpu';
C_gpu = fft(A_gpu);

% 结果取回CPU
B = gather(B_gpu);

% GPU信息
g = gpuDevice(1);
fprintf('GPU: %s, 显存: %.1f GB\n', g.Name, g.AvailableMemory/1e9);
```

### 19.4 性能加速对比示例

```matlab
N = 500; iter = 100;
data = rand(N, N, iter);

% 串行
tic;
s_result = zeros(1, iter);
for i = 1:iter
    s_result(i) = sum(svd(data(:,:,i)));
end
t_s = toc;

% 并行
tic;
p_result = zeros(1, iter);
parfor i = 1:iter
    p_result(i) = sum(svd(data(:,:,i)));
end
t_p = toc;

fprintf('串行%.2fs  并行%.2fs  加速比%.1fx\n', t_s, t_p, t_s/t_p);
```

---

## 20. 常见工程应用案例

### 20.1 控制系统分析

```matlab
% 定义传递函数 G(s) = 10/(s^2+3s+10)
G = tf([10], [1 3 10]);

% 时域响应
figure;
subplot(1,2,1); step(G);    title('阶跃响应');
subplot(1,2,2); impulse(G); title('冲激响应');

% 频域分析
figure; bode(G); grid on;   % Bode 图
figure; nyquist(G);          % Nyquist 图

% 系统特性
pole(G)                      % 极点
zero(G)                      % 零点
isstable(G)                  % 稳定性

% 闭环系统（单位负反馈PID控制）
C   = pid(1.2, 0.5, 0.1);   % Kp=1.2, Ki=0.5, Kd=0.1
sys = feedback(C*G, 1);
figure; step(sys); title('PID控制阶跃响应');
stepinfo(sys)                % 上升时间、超调量、调节时间
```

### 20.2 图像处理流程

```matlab
% 读入并处理图像
img   = imread('peppers.png');
gray  = rgb2gray(img);

figure;
subplot(2,3,1); imshow(img);         title('原彩图');
subplot(2,3,2); imshow(gray);        title('灰度图');
subplot(2,3,3); imshow(imbinarize(gray)); title('二值化');

% 形态学
se = strel('disk', 3);
subplot(2,3,4); imshow(imerode(imbinarize(gray), se));  title('腐蚀');
subplot(2,3,5); imshow(imdilate(imbinarize(gray), se)); title('膨胀');

% 边缘检测
subplot(2,3,6); imshow(edge(gray,'Canny')); title('Canny边缘');

% 连通区域分析
bw  = imbinarize(gray);
[L, n] = bwlabel(bw);
stats  = regionprops(L,'Area','Centroid');
fprintf('连通区域数：%d\n', n);
```

### 20.3 机器学习（分类与回归）

```matlab
% 加载鸢尾花数据集
load fisheriris
X = meas; Y = species;

% 划分训练/测试集（7:3）
cv = cvpartition(Y, 'HoldOut', 0.3);
Xtr = X(cv.training,:); Ytr = Y(cv.training);
Xte = X(cv.test,:);     Yte = Y(cv.test);

% KNN 分类
knn  = fitcknn(Xtr, Ytr, 'NumNeighbors', 5);
Ypred = predict(knn, Xte);
acc   = mean(strcmp(Ypred, Yte));
fprintf('KNN 准确率: %.1f%%\n', acc*100);

% SVM（多分类）
svm   = fitcecoc(Xtr, Ytr);
Ypred_svm = predict(svm, Xte);

% 决策树
tree = fitctree(Xtr, Ytr, 'MaxNumSplits', 10);

% 混淆矩阵可视化
confusionchart(Yte, Ypred);

% 5折交叉验证
cv5  = crossval(knn,'KFold',5);
loss = kfoldLoss(cv5);
fprintf('交叉验证误差: %.4f\n', loss);

% 线性回归
load carsmall
mdl = fitlm(Weight, MPG);
disp(mdl);
plot(mdl);
```

### 20.4 数值求解热传导方程

```matlab
% 一维热传导：u_t = alpha*u_xx
% BC: u(0,t)=0, u(1,t)=0
% IC: u(x,0) = sin(pi*x)
% 解析解：u(x,t) = exp(-alpha*pi^2*t)*sin(pi*x)

alpha = 0.01;
Nx = 50; Nt = 500;
dx = 1/Nx; dt = 0.5/Nt;
r  = alpha*dt/dx^2;        % Courant数（需<0.5）

x  = (1:Nx-1)*dx;
u  = sin(pi*x);            % 初始条件
U  = zeros(Nt+1, Nx-1);
U(1,:) = u;

for n = 1:Nt
    u_new = u;
    u_new(2:end-1) = u(2:end-1) + r*(u(1:end-2)-2*u(2:end-1)+u(3:end));
    u_new(1)   = u(1)   + r*(0-2*u(1)+u(2));
    u_new(end) = u(end) + r*(u(end-1)-2*u(end)+0);
    u = u_new;
    U(n+1,:) = u;
end

t_vec = linspace(0, 0.5, Nt+1);
[XX, TT] = meshgrid(x, t_vec);
surf(XX, TT, U, 'EdgeColor','none');
xlabel('位置x'); ylabel('时间t'); zlabel('温度u');
colorbar; shading interp;
```

### 20.5 音频信号处理

```matlab
% 生成合成音频
Fs  = 44100; T = 1;
t   = 0:1/Fs:T-1/Fs;
f0  = 440;                          % A4音符
x   = 0.5*sin(2*pi*f0*t) + 0.3*sin(2*pi*2*f0*t);  % 基音+倍频

% 播放
sound(x, Fs);

% 频谱
N = length(x);
f = (0:N/2)*Fs/N;
mag = 2*abs(fft(x))/N;
plot(f, mag(1:N/2+1)); xlim([0 2000]);
xlabel('频率(Hz)'); ylabel('幅度');

% 加噪与滤波
noisy = x + 0.2*randn(size(x));
[b,a] = butter(6, 1000/(Fs/2));
clean = filtfilt(b, a, noisy);

% 保存
audiowrite('output.wav', clean, Fs);

% 短时能量（端点检测基础）
frame = 256;
energy = movsum(x.^2, frame);
plot(t, energy); xlabel('时间(s)');
```

---

---

## 21. 实战练习

### 练习 1：斐波那契数列

```matlab
function fib = fibonacci(n)
    fib = zeros(1, n);
    fib(1) = 1;
    if n >= 2
        fib(2) = 1;
    end
    for k = 3:n
        fib(k) = fib(k-1) + fib(k-2);
    end
end

% 调用
f = fibonacci(20);
plot(f, 'o-');
title('斐波那契数列');
```

### 练习 2：数据分析与可视化

```matlab
% 生成模拟成绩数据
scores = round(60 + 30*rand(1, 100));  % 60-90分

% 统计分析
fprintf('平均分：%.1f\n', mean(scores));
fprintf('最高分：%d\n', max(scores));
fprintf('最低分：%d\n', min(scores));
fprintf('标准差：%.1f\n', std(scores));

% 可视化
figure;
subplot(1, 2, 1);
histogram(scores, 10);
title('成绩分布');
xlabel('分数'); ylabel('人数');

subplot(1, 2, 2);
grades = {'不及格','及格','良好','优秀'};
counts = [sum(scores<60), sum(scores>=60 & scores<75), ...
          sum(scores>=75 & scores<90), sum(scores>=90)];
pie(counts, grades);
title('等级分布');
```

### 练习 3：数值积分（辛普森法）

```matlab
function I = simpson(f, a, b, n)
    % 用辛普森法计算定积分
    % f: 函数句柄, a,b: 积分区间, n: 区间数（偶数）
    if mod(n, 2) ~= 0
        n = n + 1;
    end
    h = (b - a) / n;
    x = a:h:b;
    y = f(x);
    I = h/3 * (y(1) + 4*sum(y(2:2:end-1)) + 2*sum(y(3:2:end-2)) + y(end));
end

% 测试：∫₀^π sin(x) dx = 2
result = simpson(@sin, 0, pi, 1000);
fprintf('数值积分结果：%.6f（真值：2）\n', result);
```

### 练习 4：图像处理入门

```matlab
% 读取图像
img = imread('cameraman.tif');   % MATLAB 内置测试图像

% 显示原图
figure;
subplot(1, 3, 1);
imshow(img);
title('原图（灰度）');

% 二值化
bw = img > 128;
subplot(1, 3, 2);
imshow(bw);
title('二值化');

% 边缘检测
edges = edge(img, 'Canny');
subplot(1, 3, 3);
imshow(edges);
title('Canny 边缘');
```

---

---

## 快速参考卡

```
变量与矩阵
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
a = 5;              赋值（不显示）
A = [1 2; 3 4]      创建矩阵（显示）
A(2,1)              元素访问
A(1,:) / A(:,2)     行/列切片
A'                  转置
size/numel/ndims    尺寸信息
zeros/ones/eye/rand 特殊矩阵
reshape/repmat      重塑/复制

数据容器
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
c = {1,'hi',[1 2]}  Cell数组（异构数据）
c{1}                取Cell内容
s.field = val       结构体赋值
s.(varname)         动态字段名
T = table(...)      表格（推荐数据分析）

控制流
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
if/elseif/else/end
switch/case/otherwise/end
for i=1:n ... end
while cond ... end
break / continue / return
try/catch/end

函数
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
function y=f(x)     函数定义
@(x) x.^2          匿名函数
nargin/nargout      参数个数
varargin/varargout  可变参数

绘图
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
figure/subplot(m,n,k)
plot/scatter/bar/histogram/pie
surf/mesh/contour/plot3
hold on/off
title/xlabel/ylabel/legend/grid
colorbar/colormap/shading interp
saveas/print

数值计算
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
integral/trapz       数值积分
ode45/ode15s         ODE求解
fminbnd/fminsearch   优化
polyfit/interp1      拟合插值
fft/ifft/fftshift    频域变换

调试与性能
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
clc/clear/close all
tic/toc              计时
profile on/viewer    性能分析
parfor               并行循环
gpuArray/gather      GPU加速
```

---

_本教程系统覆盖 MATLAB 从基础到进阶的核心知识，适合工程、科研、数据分析等场景速查与学习。更多工具箱细节（Simulink、深度学习、计算机视觉等）请参考官方文档：[mathworks.com/help/matlab](https://www.mathworks.com/help/matlab/)_