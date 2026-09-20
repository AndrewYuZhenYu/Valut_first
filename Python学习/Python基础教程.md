```markdown
# Python语法完全指南

## 第一部分：基础语法

### 1.1 Python解释器与运行环境
```python
# 查看Python版本
import sys
print(sys.version)

# 运行方式对比
"""
1. 交互模式: python 或 python3
2. 脚本执行: python script.py
3. IDE直接运行
"""
```

### 1.2 注释与文档字符串
```python
# 单行注释

"""
多行注释方式1
三个双引号
"""

'''
多行注释方式2
三个单引号
'''

def function():
    """
    文档字符串(docstring)
    用于函数/模块说明
    """
    pass
```

### 1.3 变量与数据类型
```python
# 基本类型
x = 10              # int: ℤ
y = 3.14            # float: ℝ
name = "Python"     # str
flag = True         # bool
z = None            # NoneType

# 类型检查与转换
print(type(x))                    # <class 'int'>
print(isinstance(3.14, float))    # True
print(int("123") + float("45.6")) # 168.6
```

### 1.4 运算符

#### 1.4.1 算术运算符
$$
\begin{align*}
&+, -, \times( * ), \div( / ), \div_{\text{floor}}( // ), \% , ^{**}
\end{align*}
$$

```python
a, b = 10, 3
print(a + b)    # 13
print(a - b)    # 7  
print(a * b)    # 30
print(a / b)    # 3.333...
print(a // b)   # 3  整除
print(a % b)    # 1  取模
print(a ** b)   # 1000  乘方
```

#### 1.4.2 比较与逻辑运算符
```python
# 比较运算: >, <, >=, <=, ==, !=
# 逻辑运算: and, or, not
# 身份运算: is, is not
# 成员运算: in, not in

# 链式比较
print(1 < 2 <= 3)  # True

# 短路求值
result = False and expensive_func()  # 不调用函数
```

#### 1.4.3 海象运算符(Python 3.8+)
```python
# := 赋值表达式
if (n := len(data)) > 10:
    print(f"数据过长: {n}")
    
# 循环中使用
while (line := input()) != "quit":
    print(f"输入: {line}")
```

### 1.5 格式化字符串
```python
name, age = "Alice", 25

# f-string (Python 3.6+)
msg1 = f"{name} is {age} years old"

# str.format()
msg2 = "{} is {} years old".format(name, age)

# % 格式化
msg3 = "%s is %d years old" % (name, age)

# 数字格式化
pi = 3.1415926
print(f"π ≈ {pi:.2f}")        # π ≈ 3.14
print(f"二进制: {10:b}")       # 二进制: 1010
```

## 第二部分：数据结构

### 2.1 序列类型操作
```python
seq = [1, 2, 3, 4, 5]

# 通用操作
len(seq)        # 长度: 5
seq[0]          # 索引: 1
seq[1:4]        # 切片: [2, 3, 4]
seq[::2]        # 步长: [1, 3, 5]
seq[::-1]       # 反转: [5, 4, 3, 2, 1]
```

### 2.2 列表(List)
```python
# 创建列表
lst = [1, 2, 3, "hello", 3.14]
lst2 = list(range(5))          # [0, 1, 2, 3, 4]
lst3 = [x**2 for x in range(5)] # 推导式

# 修改操作
lst.append(6)           # 末尾添加
lst.insert(2, 99)       # 插入
lst.extend([7, 8])      # 扩展
lst.remove(3)           # 删除值
value = lst.pop()       # 弹出末尾
del lst[1:3]            # 删除切片

# 列表推导式
squares = [x**2 for x in range(10)]                     # 简单推导
even_squares = [x**2 for x in range(10) if x % 2 == 0]  # 条件推导
matrix = [[i*j for j in range(3)] for i in range(3)]    # 嵌套推导
```

### 2.3 元组(Tuple)
```python
# 不可变序列
point = (10, 20)
single = (42,)          # 单元素需加逗号
empty = ()

# 元组解包
x, y = point            # x=10, y=20
a, *b, c = 1, 2, 3, 4   # a=1, b=[2,3], c=4

# 命名元组
from collections import namedtuple
Point = namedtuple('Point', ['x', 'y'])
p = Point(10, 20)
print(p.x, p.y)         # 10 20
```

### 2.4 字典(Dictionary)
```python
# 创建字典
d = {"name": "Alice", "age": 25}
d2 = dict(name="Bob", age=30)
d3 = dict([("a", 1), ("b", 2)])

# 字典操作
d["city"] = "NY"        # 添加/修改
value = d.get("age")    # 安全获取
value = d.pop("name")   # 弹出
keys = d.keys()         # 键视图
values = d.values()     # 值视图
items = d.items()       # 键值对视图

# 字典推导式
squares = {x: x**2 for x in range(5)}
inverted = {v: k for k, v in d.items()}

# defaultdict
from collections import defaultdict
dd = defaultdict(list)
dd["key"].append(1)     # 自动创建列表
```

### 2.5 集合(Set)
```python
# 无序不重复集合
s1 = {1, 2, 3, 4}
s2 = set([3, 4, 5, 6])

# 集合运算
union = s1 | s2         # 并集: {1,2,3,4,5,6}
intersection = s1 & s2  # 交集: {3,4}
difference = s1 - s2    # 差集: {1,2}
symmetric = s1 ^ s2     # 对称差: {1,2,5,6}

# 集合推导式
unique_chars = {c for c in "hello world" if c != " "}
```

## 第三部分：流程控制

### 3.1 条件语句
```python
# if-elif-else
score = 85

if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
elif score >= 70:
    grade = "C"
else:
    grade = "D"

# 三元表达式
status = "成年" if age >= 18 else "未成年"
max_val = a if a > b else b

# 条件链
if 0 < x < 10:      # Python特色语法
    print("x在区间内")
```

### 3.2 循环结构
```python
# for循环
for i in range(5):          # 0-4
    print(i)

for i in range(2, 10, 2):   # 2,4,6,8
    print(i)

# while循环
count = 0
while count < 5:
    print(count)
    count += 1

# 循环控制
for i in range(10):
    if i == 3:
        continue    # 跳过本次
    if i == 7:
        break       # 终止循环
    print(i)
else:               # 循环正常结束执行
    print("完成")

# enumerate索引遍历
for idx, value in enumerate(["a", "b", "c"]):
    print(f"索引{idx}: {value}")

# zip并行遍历
for x, y in zip([1, 2, 3], ["a", "b", "c"]):
    print(x, y)
```

### 3.3 异常处理
```python
try:
    result = 10 / 0
    data = int("abc")
except ZeroDivisionError as e:
    print(f"除零错误: {e}")
except (ValueError, TypeError) as e:
    print(f"值/类型错误: {e}")
except Exception as e:
    print(f"其他错误: {e}")
else:
    print("无错误发生")
finally:
    print("总会执行")

# 抛出异常
def validate_age(age):
    if age < 0:
        raise ValueError("年龄不能为负")
    return age

# 自定义异常
class MyError(Exception):
    def __init__(self, msg):
        self.msg = msg
    
    def __str__(self):
        return f"MyError: {self.msg}"
```

## 第四部分：函数

### 4.1 函数定义
```python
# 基础定义
def greet(name="World"):
    """返回问候语"""
    return f"Hello, {name}!"

# 类型提示(Python 3.5+)
def add(a: int, b: int) -> int:
    """两数相加"""
    return a + b

# 多返回值(实质是元组)
def min_max(numbers):
    return min(numbers), max(numbers)
```

### 4.2 参数类型
```python
def func(a, b, c=10, *args, d=20, **kwargs):
    """
    a, b: 位置参数
    c: 默认参数
    *args: 可变位置参数(元组)
    d: 仅关键字参数
    **kwargs: 可变关键字参数(字典)
    """
    print(f"a={a}, b={b}, c={c}")
    print(f"args={args}")
    print(f"d={d}, kwargs={kwargs}")

# 调用示例
func(1, 2, 3, 4, 5, d=30, e=40, f=50)
```

### 4.3 Lambda表达式
```python
# 匿名函数
square = lambda x: x**2
add = lambda x, y: x + y

# 立即调用
result = (lambda x: x * 2)(5)  # 10

# 高阶函数应用
nums = [1, 2, 3, 4, 5]
squares = list(map(lambda x: x**2, nums))      # [1, 4, 9, 16, 25]
evens = list(filter(lambda x: x % 2 == 0, nums)) # [2, 4]

from functools import reduce
sum_all = reduce(lambda x, y: x + y, nums)     # 15
```

### 4.4 作用域
```python
global_var = 100

def outer():
    outer_var = 50
    
    def inner():
        global global_var        # 声明全局变量
        nonlocal outer_var       # 声明外层变量
        global_var = 200
        outer_var = 100
        local_var = 300          # 局部变量
    
    inner()
    print(outer_var)  # 100

print(global_var)     # 200
```

### 4.5 装饰器
```python
def timer(func):
    """计时装饰器"""
    import time
    from functools import wraps
    
    @wraps(func)  # 保留原函数信息
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"{func.__name__} 耗时: {end-start:.4f}s")
        return result
    return wrapper

@timer
def slow_function(n):
    """模拟耗时函数"""
    import time
    time.sleep(n)
    return "完成"

# 带参数装饰器
def repeat(n):
    def decorator(func):
        def wrapper(*args, **kwargs):
            for i in range(n):
                result = func(*args, **kwargs)
            return result
        return wrapper
    return decorator

@repeat(3)
def say_hello():
    print("Hello!")
```

### 4.6 生成器与协程
```python
# 生成器函数
def count_up_to(max_val):
    """生成器示例"""
    count = 1
    while count <= max_val:
        yield count
        count += 1

# 使用
for num in count_up_to(5):
    print(num)  # 1,2,3,4,5

# 生成器表达式
squares = (x**2 for x in range(10))

# 协程
def coroutine():
    """协程示例"""
    while True:
        value = yield
        print(f"收到: {value}")

coro = coroutine()
next(coro)        # 启动
coro.send("Hello")
coro.send("World")

# yield from
def chain(*iterables):
    for it in iterables:
        yield from it
```

## 第五部分：面向对象编程

### 5.1 类与对象基础
```python
class Dog:
    """狗类示例"""
    
    # 类属性
    species = "Canis familiaris"
    
    # 初始化方法
    def __init__(self, name, age):
        # 实例属性
        self.name = name
        self.age = age
    
    # 实例方法
    def bark(self):
        return f"{self.name} says woof!"
    
    # 字符串表示
    def __str__(self):
        return f"{self.name} ({self.age}岁)"
    
    # 正式表示
    def __repr__(self):
        return f"Dog('{self.name}', {self.age})"

# 使用
buddy = Dog("Buddy", 5)
print(buddy)           # Buddy (5岁)
print(buddy.bark())    # Buddy says woof!
```

### 5.2 继承与多态
```python
class Animal:
    """动物基类"""
    def __init__(self, name):
        self.name = name
    
    def speak(self):
        raise NotImplementedError("子类需实现")
    
    def move(self):
        print(f"{self.name} 在移动")

class Dog(Animal):
    """狗子类"""
    def __init__(self, name, breed):
        super().__init__(name)  # 调用父类初始化
        self.breed = breed
    
    def speak(self):
        return f"{self.name} 说: 汪汪!"
    
    # 扩展方法
    def fetch(self):
        return f"{self.name} 去捡球"

class Cat(Animal):
    """猫子类"""
    def speak(self):
        return f"{self.name} 说: 喵喵!"

# 多态示例
animals = [Dog("Buddy", "金毛"), Cat("Kitty")]
for animal in animals:
    print(animal.speak())
```

### 5.3 封装与属性
```python
class BankAccount:
    """银行账户类"""
    
    def __init__(self, owner, balance=0):
        self.owner = owner
        self._balance = balance  # 保护属性
        self.__secret = 1234     # 私有属性
    
    # Getter属性
    @property
    def balance(self):
        return self._balance
    
    # Setter属性
    @balance.setter
    def balance(self, amount):
        if amount >= 0:
            self._balance = amount
        else:
            raise ValueError("余额不能为负")
    
    # 只读属性
    @property
    def info(self):
        return f"户主: {self.owner}, 余额: ${self._balance:.2f}"
    
    # 实例方法
    def deposit(self, amount):
        self._balance += amount
        return self._balance
    
    def withdraw(self, amount):
        if amount <= self._balance:
            self._balance -= amount
            return amount
        raise ValueError("余额不足")

# 使用
account = BankAccount("Alice", 1000)
print(account.balance)    # 1000
account.deposit(500)      # 1500
print(account.info)       # 户主: Alice, 余额: $1500.00
```

### 5.4 特殊方法(魔术方法)
```python
class Vector:
    """向量类"""
    
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    # 算术运算
    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)
    
    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)
    
    # 比较运算
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    
    def __lt__(self, other):
        return self.magnitude() < other.magnitude()
    
    # 字符串表示
    def __str__(self):
        return f"Vector({self.x}, {self.y})"
    
    def __repr__(self):
        return f"Vector({self.x}, {self.y})"
    
    # 容器方法
    def __len__(self):
        return 2
    
    def __getitem__(self, index):
        if index == 0:
            return self.x
        elif index == 1:
            return self.y
        raise IndexError("向量只有2个分量")
    
    # 调用方法
    def __call__(self):
        return (self.x, self.y)
    
    # 辅助方法
    def magnitude(self):
        return (self.x**2 + self.y**2) ** 0.5

# 使用
v1 = Vector(1, 2)
v2 = Vector(3, 4)
print(v1 + v2)      # Vector(4, 6)
print(v1 * 3)       # Vector(3, 6)
print(v1[0])        # 1
print(v1())         # (1, 2)
```

### 5.5 类方法与静态方法
```python
class Date:
    """日期类"""
    
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day
    
    # 实例方法
    def display(self):
        return f"{self.year}-{self.month:02d}-{self.day:02d}"
    
    # 类方法
    @classmethod
    def from_string(cls, date_str):
        """从字符串创建实例"""
        year, month, day = map(int, date_str.split('-'))
        return cls(year, month, day)
    
    # 静态方法
    @staticmethod
    def is_leap_year(year):
        """判断闰年"""
        return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

# 使用
d1 = Date(2023, 12, 25)
d2 = Date.from_string("2023-12-31")
print(Date.is_leap_year(2024))  # True
```

### 5.6 抽象基类
```python
from abc import ABC, abstractmethod

class Shape(ABC):
    """形状抽象基类"""
    
    @abstractmethod
    def area(self):
        """计算面积"""
        pass
    
    @abstractmethod
    def perimeter(self):
        """计算周长"""
        pass
    
    # 具体方法
    def describe(self):
        return f"这是一个{self.__class__.__name__}"

class Rectangle(Shape):
    """矩形类"""
    
    def __init__(self, width, height):
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def perimeter(self):
        return 2 * (self.width + self.height)

# 使用
rect = Rectangle(5, 3)
print(f"面积: {rect.area()}")          # 15
print(f"周长: {rect.perimeter()}")     # 16
print(rect.describe())                 # 这是一个Rectangle
```

## 第六部分：模块与包

### 6.1 模块导入
```python
# 完整导入
import math
print(math.sqrt(16))  # 4.0

# 部分导入
from math import pi, sin, cos
print(sin(pi/2))      # 1.0

# 别名导入
import numpy as np
import pandas as pd

# 导入所有(不推荐)
from math import *

# 相对导入(包内部)
# from . import module
# from ..parent import module

# 条件导入
try:
    import torch
    HAS_TORCH = True
except ImportError:
    HAS_TORCH = False

# 动态导入
module_name = "json"
module = __import__(module_name)
data = module.loads('{"key": "value"}')
```

### 6.2 包结构示例
```python
"""
mypackage/
├── __init__.py           # 包初始化
├── module1.py           # 模块1
├── module2.py           # 模块2
├── subpackage/
│   ├── __init__.py
│   └── module3.py
└── utils/
    └── helpers.py
"""
```

### 6.3 创建模块
```python
# calculator.py
"""
计算器模块
提供基本数学运算
"""

VERSION = "1.0.0"

def add(a, b):
    """加法运算"""
    return a + b

def multiply(a, b):
    """乘法运算"""
    return a * b

class Calculator:
    """计算器类"""
    def __init__(self):
        self.memory = 0
    
    def reset(self):
        self.memory = 0
    
    def store(self, value):
        self.memory = value

# 测试代码
if __name__ == "__main__":
    # 模块作为脚本运行时执行
    print(f"Calculator模块 v{VERSION}")
    print(f"2 + 3 = {add(2, 3)}")
```

### 6.4 常用标准库
```python
# os - 操作系统接口
import os
print(os.getcwd())        # 当前目录
print(os.listdir('.'))    # 目录列表
os.makedirs('path/to/dir', exist_ok=True)

# sys - 系统参数
import sys
print(sys.version)        # Python版本
print(sys.argv)           # 命令行参数
sys.exit(0)               # 退出程序

# datetime - 日期时间
from datetime import datetime, timedelta
now = datetime.now()
tomorrow = now + timedelta(days=1)
print(now.strftime("%Y-%m-%d %H:%M:%S"))

# json - JSON处理
import json
data = {"name": "Alice", "age": 25}
json_str = json.dumps(data, indent=2)  # 序列化
parsed = json.loads(json_str)          # 反序列化

# re - 正则表达式
import re
pattern = r"\d+"  # 匹配数字
matches = re.findall(pattern, "abc123def456")

# collections - 容器扩展
from collections import Counter, defaultdict, deque
cnt = Counter("hello world")      # 计数
dd = defaultdict(list)            # 默认字典
dq = deque([1, 2, 3])             # 双端队列

# itertools - 迭代工具
import itertools
for combo in itertools.combinations([1, 2, 3, 4], 2):
    print(combo)  # (1,2), (1,3), (1,4), (2,3)...

# functools - 高阶函数
from functools import lru_cache, partial

@lru_cache(maxsize=128)
def fibonacci(n):
    if n < 2:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

# 部分函数
print_with_prefix = partial(print, "INFO:")
print_with_prefix("程序启动")  # INFO: 程序启动
```

## 第七部分：文件与IO

### 7.1 文件操作
```python
# 读取文件
with open("file.txt", "r", encoding="utf-8") as f:
    content = f.read()          # 全部内容
    lines = f.readlines()       # 所有行列表
    line = f.readline()         # 单行

# 逐行读取(推荐)
with open("large_file.txt", "r") as f:
    for line in f:
        process(line.strip())

# 写入文件
with open("output.txt", "w") as f:
    f.write("第一行\n")
    f.writelines(["第二行\n", "第三行\n"])

# 追加模式
with open("log.txt", "a") as f:
    f.write(f"[{datetime.now()}] 日志记录\n")

# 二进制文件
with open("image.jpg", "rb") as f:
    image_data = f.read()

with open("output.bin", "wb") as f:
    f.write(b"binary data")

# 文件定位
with open("file.txt", "r") as f:
    f.seek(10)           # 移动到第10字节
    position = f.tell()  # 当前位置
    chunk = f.read(100)  # 读取100字节
```

### 7.2 上下文管理器
```python
# 自定义上下文管理器
class DatabaseConnection:
    """数据库连接管理器"""
    
    def __init__(self, db_name):
        self.db_name = db_name
        self.connection = None
    
    def __enter__(self):
        print(f"连接数据库: {self.db_name}")
        self.connection = f"Connection to {self.db_name}"
        return self
    
    def execute(self, query):
        print(f"执行查询: {query}")
        return "查询结果"
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        print("关闭数据库连接")
        self.connection = None
        if exc_type:
            print(f"发生错误: {exc_val}")
            return False  # 传播异常
        return True       # 抑制异常

# 使用
with DatabaseConnection("test.db") as db:
    result = db.execute("SELECT * FROM users")
    print(result)
```

### 7.3 标准输入输出
```python
# 标准输出
print("Hello", "World", sep=", ", end="!\n")
print(f"格式化: {10 + 20}")

# 标准输入
name = input("请输入姓名: ")
print(f"你好, {name}!")

# 文件描述符操作
import sys
sys.stdout.write("直接写入标准输出\n")
sys.stderr.write("错误信息\n")

# 重定向
import sys
original_stdout = sys.stdout
sys.stdout = open("output.log", "w")
print("这会被写入文件")
sys.stdout = original_stdout  # 恢复
```

## 第八部分：高级特性

### 8.1 迭代器与可迭代对象
```python
class MyRange:
    """自定义范围迭代器"""
    
    def __init__(self, start, end):
        self.current = start
        self.end = end
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current >= self.end:
            raise StopIteration
        value = self.current
        self.current += 1
        return value

# 使用
for num in MyRange(1, 5):
    print(num)  # 1,2,3,4

# iter()和next()
my_iter = iter([1, 2, 3])
print(next(my_iter))  # 1
print(next(my_iter))  # 2
```

### 8.2 描述符
```python
class TypedAttribute:
    """类型检查描述符"""
    
    def __init__(self, name, expected_type):
        self.name = name
        self.expected_type = expected_type
        self.storage_name = f"_{name}"
    
    def __get__(self, instance, owner):
        if instance is None:
            return self
        return getattr(instance, self.storage_name)
    
    def __set__(self, instance, value):
        if not isinstance(value, self.expected_type):
            raise TypeError(
                f"{self.name} 必须是 {self.expected_type.__name__}"
            )
        setattr(instance, self.storage_name, value)
    
    def __delete__(self, instance):
        delattr(instance, self.storage_name)

class Person:
    name = TypedAttribute("name", str)
    age = TypedAttribute("age", int)
    
    def __init__(self, name, age):
        self.name = name
        self.age = age

# 使用
p = Person("Alice", 25)
# p.age = "25"  # TypeError: age 必须是 int
```

### 8.3 元类
```python
# 使用type动态创建类
MyClass = type('MyClass', (), {'x': 10, 'y': 20})
obj = MyClass()
print(obj.x, obj.y)  # 10 20

# 自定义元类
class SingletonMeta(type):
    """单例模式元类"""
    
    _instances = {}
    
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super().__call__(*args, **kwargs)
        return cls._instances[cls]

class Singleton(metaclass=SingletonMeta):
    def __init__(self, value):
        self.value = value

# 测试单例
s1 = Singleton(10)
s2 = Singleton(20)
print(s1 is s2)      # True
print(s1.value)      # 10
print(s2.value)      # 10
```

### 8.4 异步编程
```python
import asyncio

async def fetch_data(url):
    """异步获取数据"""
    print(f"开始获取: {url}")
    await asyncio.sleep(2)  # 模拟IO操作
    print(f"完成获取: {url}")
    return f"来自 {url} 的数据"

async def main():
    """主协程"""
    # 并发执行
    task1 = asyncio.create_task(fetch_data("url1"))
    task2 = asyncio.create_task(fetch_data("url2"))
    task3 = asyncio.create_task(fetch_data("url3"))
    
    # 等待所有任务完成
    results = await asyncio.gather(task1, task2, task3)
    print(f"所有结果: {results}")

# 运行
asyncio.run(main())

# 异步上下文管理器
class AsyncDatabase:
    async def __aenter__(self):
        print("连接数据库")
        await asyncio.sleep(0.5)
        return self
    
    async def __aexit__(self, exc_type, exc_val, exc_tb):
        print("关闭数据库")
        await asyncio.sleep(0.5)
    
    async def query(self, sql):
        await asyncio.sleep(1)
        return "查询结果"

# 异步迭代器
class AsyncCounter:
    def __init__(self, limit):
        self.limit = limit
        self.current = 0
    
    def __aiter__(self):
        return self
    
    async def __anext__(self):
        if self.current >= self.limit:
            raise StopAsyncIteration
        await asyncio.sleep(0.5)
        self.current += 1
        return self.current - 1

async def count_async():
    async for num in AsyncCounter(5):
        print(num)
```

## 第九部分：测试与调试

### 9.1 单元测试
```python
import unittest

def add(a, b):
    """加法函数"""
    return a + b

def divide(a, b):
    """除法函数"""
    if b == 0:
        raise ValueError("除数不能为0")
    return a / b

class TestMathFunctions(unittest.TestCase):
    """数学函数测试类"""
    
    def setUp(self):
        """测试前置设置"""
        self.test_cases = [(1, 2), (0, 5), (-3, 7)]
    
    def tearDown(self):
        """测试后置清理"""
        pass
    
    def test_add(self):
        """加法测试"""
        self.assertEqual(add(1, 2), 3)
        self.assertEqual(add(0, 0), 0)
        self.assertEqual(add(-1, -1), -2)
    
    def test_add_types(self):
        """加法类型测试"""
        self.assertIsInstance(add(1, 2), int)
        self.assertIsInstance(add(1.5, 2.5), float)
    
    def test_divide(self):
        """除法测试"""
        self.assertEqual(divide(6, 2), 3)
        self.assertEqual(divide(5, 2), 2.5)
    
    def test_divide_by_zero(self):
        """除零异常测试"""
        with self.assertRaises(ValueError):
            divide(1, 0)
    
    @unittest.skip("跳过此测试")
    def test_skipped(self):
        self.fail("不应执行")
    
    @unittest.skipIf(True, "条件跳过")
    def test_conditional_skip(self):
        pass

if __name__ == "__main__":
    unittest.main()
```

### 9.2 调试技巧
```python
import pdb
import logging
import traceback

# pdb调试
def buggy_function():
    x = 1
    y = 0
    pdb.set_trace()  # 设置断点
    result = x / y   # 错误
    return result

# 常用pdb命令
"""
n(ext) - 执行下一行
s(tep) - 进入函数内部
c(ontinue) - 继续执行
l(ist) - 显示当前代码
p(rint) - 打印变量
q(uit) - 退出调试
"""

# 日志记录
logging.basicConfig(
    level=logging.DEBUG,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    handlers=[
        logging.FileHandler('app.log'),
        logging.StreamHandler()
    ]
)

logger = logging.getLogger(__name__)

def process_data(data):
    """带日志的数据处理"""
    logger.debug(f"处理数据: {data}")
    try:
        result = data * 2
        logger.info(f"处理成功: {result}")
        return result
    except Exception as e:
        logger.error(f"处理失败: {e}", exc_info=True)
        raise

# 异常追踪
def safe_execute(func):
    """安全执行装饰器"""
    def wrapper(*args, **kwargs):
        try:
            return func(*args, **kwargs)
        except Exception:
            print("异常追踪:")
            traceback.print_exc()
            return None
    return wrapper

@safe_execute
def risky_operation():
    return 1 / 0
```

## 第十部分：性能优化

### 10.1 代码优化技巧
```python
import time
import sys
from functools import lru_cache

# 1. 局部变量提升性能
def slow_loop():
    result = []
    for i in range(1000000):
        result.append(i * 2)  # 每次查找append
    return result

def fast_loop():
    result = []
    append = result.append  # 局部变量
    for i in range(1000000):
        append(i * 2)
    return result

# 2. 列表推导式 vs 循环
def test_performance():
    n = 1000000
    
    # 列表推导式
    start = time.time()
    squares = [x**2 for x in range(n)]
    print(f"推导式: {time.time() - start:.4f}s")
    
    # 普通循环
    start = time.time()
    squares = []
    for x in range(n):
        squares.append(x**2)
    print(f"循环: {time.time() - start:.4f}s")

# 3. 生成器节省内存
def process_large_data():
    # 生成器不一次性加载所有数据
    return sum(x for x in range(10000000))

# 4. 字符串连接优化
def bad_concat():
    s = ""
    for i in range(10000):
        s += str(i)  # 每次创建新字符串
    return s

def good_concat():
    parts = []
    for i in range(10000):
        parts.append(str(i))
    return "".join(parts)  # 一次性连接

# 5. 缓存结果
@lru_cache(maxsize=128)
def fibonacci(n):
    """带缓存的斐波那契"""
    if n < 2:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

# 6. 使用timeit测试
import timeit

code = '''
result = sum(x**2 for x in range(1000))
'''
execution_time = timeit.timeit(code, number=1000)
print(f"执行时间: {execution_time:.4f}秒")

# 7. 使用profiler分析
import cProfile

def profile_me():
    cProfile.run('sum([i**2 for i in range(1000000)])')
```

### 10.2 内存管理
```python
import sys
import gc
import weakref

# 查看对象内存
large_list = [1] * 1000000
print(f"列表大小: {sys.getsizeof(large_list)} bytes")

# 循环引用检测
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def create_circular_ref():
    """创建循环引用"""
    a = Node(1)
    b = Node(2)
    a.next = b
    b.next = a  # 循环引用
    return a

# 垃圾回收控制
print(f"GC阈值: {gc.get_threshold()}")
gc.collect()  # 手动回收

# 使用弱引用避免循环引用
class Tree:
    def __init__(self, value):
        self.value = value
        self._parent = None
        self._children = []
    
    @property
    def parent(self):
        return self._parent() if self._parent else None
    
    @parent.setter
    def parent(self, node):
        # 使用弱引用
        self._parent = weakref.ref(node) if node else None
    
    def add_child(self, child):
        self._children.append(child)
        child.parent = self

# 内存分析
import tracemalloc

tracemalloc.start()

# 执行要分析的代码
data = [[i*j for j in range(1000)] for i in range(1000)]

snapshot = tracemalloc.take_snapshot()
top_stats = snapshot.statistics('lineno')

print("内存使用最多的10行:")
for stat in top_stats[:10]:
    print(stat)

tracemalloc.stop()
```

## 第十一部分：代码规范

### 11.1 PEP 8指南要点
```python
"""
Python代码风格指南(PEP 8)

1. 缩进: 4个空格(非Tab)
2. 行宽: ≤79字符
3. 导入顺序:
   - 标准库
   - 第三方库  
   - 本地模块
4. 命名约定:
   - 变量/函数: snake_case
   - 类: PascalCase
   - 常量: UPPER_CASE
   - 私有: _leading_underscore
5. 空格规则:
   - 运算符两侧
   - 逗号后
   - 冒号后(字典中)
6. 文档字符串: 三重引号
"""

# 良好示例
import os
import sys
from typing import List, Dict, Optional

MAX_RETRIES = 3
DEFAULT_TIMEOUT = 30

class DataProcessor:
    """数据处理类"""
    
    def __init__(self, data: List[int]):
        self.data = data
        self._cache = {}  # 私有属性
        
    def process(self) -> Dict[str, float]:
        """
        处理数据并返回结果
        
        Returns:
            包含处理结果的字典
        """
        if not self.data:
            return {}
        
        result = {}
        for item in self.data:
            processed = self._process_item(item)
            result[str(item)] = processed
            
        return result
    
    def _process_item(self, item: int) -> float:
        """私有处理方法"""
        return item * 1.5

# 工具检查
# pylint mymodule.py    # 代码质量检查
# flake8 mymodule.py    # 风格检查  
# black mymodule.py     # 自动格式化
# isort mymodule.py     # 导入排序
```

### 11.2 类型提示
```python
from typing import List, Dict, Tuple, Optional, Union, Any, Callable

def process_data(
    data: List[int],
    multiplier: float = 1.0,
    callback: Optional[Callable[[int], str]] = None
) -> Dict[str, Union[int, float]]:
    """
    处理数据的函数
    
    Args:
        data: 整数列表
        multiplier: 乘数因子
        callback: 可选回调函数
        
    Returns:
        包含处理结果的字典
    """
    result = {}
    for i, value in enumerate(data):
        processed = value * multiplier
        result[f"item_{i}"] = processed
        
        if callback:
            callback(value)
            
    return result

# 类型别名
Vector = List[float]
Matrix = List[Vector]

def add_vectors(v1: Vector, v2: Vector) -> Vector:
    return [x + y for x, y in zip(v1, v2)]

# 泛型
from typing import TypeVar, Generic

T = TypeVar('T')

class Stack(Generic[T]):
    """泛型栈"""
    def __init__(self):
        self._items: List[T] = []
    
    def push(self, item: T) -> None:
        self._items.append(item)
    
    def pop(self) -> T:
        return self._items.pop()
```

## 总结

### 关键概念回顾
1. **基础语法**: 变量、运算符、流程控制
2. **数据结构**: 列表、字典、集合、元组
3. **函数编程**: 定义、参数、装饰器、生成器
4. **面向对象**: 类、继承、多态、魔术方法
5. **模块系统**: 导入、创建、包管理
6. **高级特性**: 迭代器、描述符、元类、异步
7. **测试调试**: 单元测试、性能分析、调试技巧

### 学习建议
```python
"""
1. 动手实践: 运行所有示例代码
2. 项目驱动: 用实际项目巩固知识
3. 阅读源码: 学习优秀开源项目
4. 持续学习: 关注Python新特性
5. 社区参与: 加入Python社区交流
"""
```

### Python应用领域
$$
\begin{aligned}
&\text{Web开发: Django, Flask} \\
&\text{数据分析: Pandas, NumPy} \\
&\text{机器学习: Scikit-learn, TensorFlow} \\
&\text{自动化运维: Ansible, Fabric} \\
&\text{网络爬虫: Scrapy, Requests} \\
&\text{科学计算: SciPy, SymPy}
\end{aligned}
$$

---
*文档更新日期: 2024年*
*Python版本: 3.8+*
```
```

这个Markdown文档包含了完整的Python语法教程，具有以下特点：

1. **完整的代码结构**：所有代码都放在代码块中，可以直接复制运行
2. **LaTeX数学公式**：在合适的地方使用数学公式表示
3. **清晰的层次结构**：用标题层级组织内容
4. **实用示例**：每个知识点都有可运行的代码示例
5. **Obsidian友好**：标准的Markdown格式，完全兼容Obsidian

你可以直接将这段代码复制到Obsidian中，它会正确渲染所有的Markdown语法、代码高亮和LaTeX公式。