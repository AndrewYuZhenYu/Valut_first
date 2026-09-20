**你老师要求的这种形式，**大概率就是 C++ 里非常经典、也非常工程化的“三文件组织方式”**：

```text
MyClass.h        ← 类的声明 / 接口
MyClass.cpp      ← 类的成员函数实现
main.cpp         ← 主程序，使用这个类
```

这其实是在训练你一个很重要的概念：

> **把“这个类有什么”与“这个类怎么实现”分开，再把使用者和类本身分开。**

在真正的 C++ 工程中，这种组织方式非常常见。

---

# 一、先看一个完整例子

假设老师让你自己设计一个 `Student` 类。

整个工程：

```text
StudentProject/
│
├── Student.h
├── Student.cpp
└── main.cpp
```

---

## 1. `Student.h`：类的定义/声明

```cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    std::string name;
    int age;
    double score;

public:
    Student(std::string name, int age, double score);

    void showInfo();
    void study();
    double getScore();
};

#endif
```

这个文件主要回答：

> **Student 这个类“长什么样”？**

也就是告诉编译器：

```text
Student
 ├── name
 ├── age
 ├── score
 ├── Student(...)
 ├── showInfo()
 ├── study()
 └── getScore()
```

但是这里**没有写具体怎么做**。

例如：

```cpp
void showInfo();
```

只是告诉编译器：

> Student 有一个叫 `showInfo()` 的成员函数。

至于它到底干什么，暂时不说。

---

# 二、`Student.cpp`：成员函数的实现

这个文件就是你记不清的那个。

它通常叫：

> **类的实现文件 / 成员函数实现文件 / 源文件**

内容：

```cpp
#include "Student.h"
#include <iostream>

Student::Student(std::string name, int age, double score)
{
    this->name = name;
    this->age = age;
    this->score = score;
}

void Student::showInfo()
{
    std::cout << "姓名：" << name << std::endl;
    std::cout << "年龄：" << age << std::endl;
    std::cout << "成绩：" << score << std::endl;
}

void Student::study()
{
    std::cout << name << " 正在学习。" << std::endl;
}

double Student::getScore()
{
    return score;
}
```

这里就是真正实现：

```cpp
void Student::showInfo()
{
    ...
}
```

---

# 三、为什么这里出现 `Student::`？

这个是你现在非常值得搞明白的地方。

在 `.h` 中：

```cpp
class Student
{
public:
    void showInfo();
};
```

表示：

> Student 类里面存在一个 `showInfo()`。

而在 `.cpp` 中：

```cpp
void Student::showInfo()
{
    ...
}
```

这里的：

```cpp
Student::
```

叫做**作用域解析运算符**。

意思是：

> “这个 `showInfo()` 是属于 `Student` 类的。”

所以：

```cpp
Student::showInfo()
```

就是：

```text
Student 类的 showInfo 函数
```

同理：

```cpp
Student::study()
```

就是：

```text
Student 类的 study 函数
```

---

# 四、第三个文件 `main.cpp`

这个才是整个程序真正开始运行的地方。

```cpp
#include <iostream>
#include "Student.h"

int main()
{
    Student student("张三", 19, 95.5);

    student.showInfo();

    student.study();

    std::cout << "成绩：" << student.getScore() << std::endl;

    return 0;
}
```

你可以发现一个非常重要的特点：

**main.cpp 根本不知道 Student 的具体实现。**

它只需要：

```cpp
#include "Student.h"
```

然后就可以：

```cpp
Student student("张三", 19, 95.5);

student.showInfo();
student.study();
```

至于：

```cpp
showInfo()
```

内部到底怎么实现的？

`main.cpp` **不关心**。

---

# 五、三个文件实际上形成了这样的关系

这是理解这种作业最重要的一张图：

```text
                    Student.h
                 类的声明 / 接口
                       │
             ┌─────────┴─────────┐
             ↓                   ↓
       Student.cpp            main.cpp
       类的具体实现             使用 Student
             │                   │
             └─────────┬─────────┘
                       ↓
                  最终可执行程序
```

换句话说：

```text
Student.h
   ↓
“Student 有哪些东西？”

Student.cpp
   ↓
“Student 这些东西具体怎么工作？”

main.cpp
   ↓
“我怎么使用 Student？”
```

这就是老师让你拆成三个文件的核心目的。

---

# 六、为什么不能全部写在 `.h` 里面？

当然**可以**。

例如：

```cpp
class Student
{
public:
    void study()
    {
        std::cout << "正在学习";
    }
};
```

完全可以编译。

甚至你也可以全部塞进：

```cpp
main.cpp
```

例如：

```cpp
class Student
{
    ...
};

int main()
{
    ...
}
```

小程序这么干完全没问题。

但是工程上通常不希望这么组织。

因为假设你的项目有：

```text
Student
Teacher
Course
Classroom
School
Car
Engine
...
```

如果所有东西都写进：

```text
main.cpp
```

最终可能变成：

```text
main.cpp

几千行
几万行
甚至几十万行
```

这就非常难维护。

---

# 七、`.h` 到底是什么？

`.h` 是：

> **Header File，头文件**

它最重要的作用之一，就是提供**声明（declaration）**。

例如：

```cpp
class Student
{
public:
    void study();
};
```

这是告诉其他代码：

> “有这么一个 Student 类，它有一个 study() 函数。”

这就类似于一个**说明书 / 接口说明**。

例如你去使用一个汽车：

```text
汽车说明书告诉你：

启动()
加速()
刹车()
转向()
```

但是它不需要把发动机内部结构全部给你。

C++ 里面也类似：

```cpp
class Car
{
public:
    void start();
    void accelerate();
    void brake();
};
```

使用者只需要知道：

```cpp
car.start();
car.accelerate();
car.brake();
```

而不需要知道：

```text
发动机内部到底怎么工作
```

---

# 八、`.cpp` 文件是什么？

`.cpp` 是：

> **源文件（Source File）**

在这种经典结构中：

```text
.h
```

主要放：

> **声明**

而：

```text
.cpp
```

主要放：

> **实现**

比如：

### Student.h

```cpp
class Student
{
public:
    void study();
};
```

### Student.cpp

```cpp
#include "Student.h"

void Student::study()
{
    std::cout << "Student is studying.";
}
```

所以可以把它理解成：

```text
Student.h
   ↓
“我保证 Student 有 study()”

Student.cpp
   ↓
“这里就是 study() 真正的代码”
```

---

# 九、那么 `main.cpp` 是什么？

`main.cpp` 一般就是：

> **程序入口 + 测试/使用代码**

例如：

```cpp
int main()
{
    Student student("张三", 19, 95);

    student.study();

    return 0;
}
```

注意：

**不是说所有项目都必须只有一个 `main.cpp`。**

而是一个最终生成的可执行程序通常需要一个：

```cpp
main()
```

作为入口。

所以老师让你：

```text
Student.h
Student.cpp
main.cpp
```

其实是在让你体验一个最小的 C++ 工程。

---

# 十、这里还有一个非常重要的问题：为什么 `.cpp` 要 `#include "Student.h"`？

因为：

```cpp
Student.cpp
```

里面写：

```cpp
void Student::study()
{
    ...
}
```

编译器需要知道：

> Student 到底是什么？

所以：

```cpp
#include "Student.h"
```

相当于先告诉它：

```cpp
class Student
{
    ...
};
```

然后它才能理解：

```cpp
Student::study()
```

---

# 十一、为什么 `main.cpp` 也要 `#include "Student.h"`？

因为 `main.cpp` 要创建：

```cpp
Student student;
```

它必须知道：

```text
Student 是一个什么类型？
有哪些构造函数？
有哪些 public 成员？
```

所以：

```cpp
#include "Student.h"
```

也是必须的。

---

# 十二、但是 `main.cpp` 为什么不 `#include "Student.cpp"`？

这个问题特别好。

**一般不要这么做。**

正确的是：

```cpp
#include "Student.h"
```

而不是：

```cpp
#include "Student.cpp"
```

因为 `.h` 是给你：

> 声明

`.cpp` 是给编译系统：

> 独立编译的实现

正常工程的思路是：

```text
Student.cpp ──────→ 编译
                     ↓
                 Student.o
                     
main.cpp ─────────→ 编译
                     ↓
                  main.o
                     
Student.o + main.o
        ↓
      链接
        ↓
   executable
```

也就是：

```text
编译阶段：

Student.cpp → Student.o
main.cpp    → main.o

链接阶段：

Student.o
    +
main.o
    ↓
最终程序
```

---

# 十三、你可以把整个过程理解成“拼装”

例如：

```text
Student.h
```

告诉大家：

```text
我这里有一个 Student
Student 有：
    Student(...)
    showInfo()
    study()
    getScore()
```

然后：

```text
Student.cpp
```

负责：

```text
Student(...) 怎么实现
showInfo() 怎么实现
study() 怎么实现
getScore() 怎么实现
```

最后：

```text
main.cpp
```

负责：

```text
创建 Student
调用 Student
让程序跑起来
```

---

# 十四、一个更加工程化的例子

假设你以后写一个：

```text
BankSystem
```

你可能会有：

```text
BankAccount.h
BankAccount.cpp

User.h
User.cpp

Bank.h
Bank.cpp

main.cpp
```

例如：

```cpp
// BankAccount.h

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double money);

    void deposit(double money);
    void withdraw(double money);
    double getBalance();
};
```

然后：

```cpp
// BankAccount.cpp

#include "BankAccount.h"

BankAccount::BankAccount(double money)
{
    balance = money;
}

void BankAccount::deposit(double money)
{
    balance += money;
}

void BankAccount::withdraw(double money)
{
    if (money <= balance)
        balance -= money;
}

double BankAccount::getBalance()
{
    return balance;
}
```

然后：

```cpp
// main.cpp

#include <iostream>
#include "BankAccount.h"

int main()
{
    BankAccount account(1000);

    account.deposit(500);
    account.withdraw(200);

    std::cout << account.getBalance();

    return 0;
}
```

这时候你就能体会到：

```text
BankAccount.h
       ↓
     定义接口
       ↓
BankAccount.cpp
       ↓
     实现功能
       ↓
   main.cpp
       ↓
     使用功能
```

---

# 十五、这种方式最大的好处是什么？

我认为你现在应该重点记住 **5 个好处**。

## ① 结构清晰

不用把所有东西塞在一个文件。

```text
.h     → 类长什么样
.cpp   → 类怎么实现
main   → 怎么使用
```

非常清楚。

---

## ② 便于维护

例如：

```cpp
void Student::study()
{
    // 100 行代码
}
```

你以后修改学习逻辑，只需要去：

```text
Student.cpp
```

而不是在：

```text
main.cpp
```

里面翻来翻去。

---

## ③ 便于复用

假如你写好了：

```text
Student.h
Student.cpp
```

以后另一个项目：

```text
AnotherProject
```

也需要 Student。

你可以直接把：

```text
Student.h
Student.cpp
```

放进去。

然后：

```cpp
#include "Student.h"
```

就可以使用。

这就是**代码复用**。

---

## ④ 隐藏实现细节

这点非常重要。

别人使用：

```cpp
Student
```

只需要知道：

```cpp
student.study();
student.getScore();
```

不需要知道：

```cpp
study()
```

内部到底有多少代码。

这就是一种非常重要的思想：

> **封装（Encapsulation）**

---

## ⑤ 大型项目可以多人协作

例如：

```text
张三：
Student.h / Student.cpp

李四：
Teacher.h / Teacher.cpp

王五：
Course.h / Course.cpp

赵六：
main.cpp
```

大家可以相对独立地工作。

这就是为什么工程项目非常强调模块化。

---

# 十六、`.h` 中到底应该放什么？

对于你老师这种基础 C++ 作业，你可以按照这个规则：

### `.h`：

```cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    // 成员变量

public:
    // 构造函数声明

    // 成员函数声明
};

#endif
```

主要放：

- 类名
    
- 成员变量
    
- 成员函数声明
    
- 构造函数声明
    
- 析构函数声明
    
- 必要的类型声明
    
- 必要的 `#include`
    

---

# 十七、`.cpp` 中应该放什么？

例如：

```cpp
#include "Student.h"

Student::Student(...)
{
    ...
}

void Student::study()
{
    ...
}

double Student::getScore()
{
    ...
}
```

主要放：

- 构造函数实现
    
- 析构函数实现
    
- 成员函数实现
    
- 其他类相关实现
    

---

# 十八、`main.cpp` 应该放什么？

主要：

```cpp
#include "Student.h"

int main()
{
    // 创建对象

    // 调用成员函数

    // 测试类

    return 0;
}
```

例如：

```cpp
Student s("Tom", 20, 90);

s.study();

s.showInfo();
```

**不要把 Student 类的具体实现重新写一遍。**

---

# 十九、你老师可能还会要求“头文件保护”

你上面看到：

```cpp
#ifndef STUDENT_H
#define STUDENT_H

...

#endif
```

这个叫：

> **Include Guard（头文件保护）**

目的主要是防止：

```cpp
Student.h
```

被重复包含。

你现在可以先记住这个模板：

```cpp
#ifndef XXX_H
#define XXX_H

// 内容

#endif
```

例如：

```cpp
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    ...
};

#endif
```

现代 C++ 也经常使用：

```cpp
#pragma once
```

于是可以简化成：

```cpp
#pragma once

class Student
{
    ...
};
```

对于你现在的课程作业，我反而建议你**两种都认识**，但实际写作业可以按照老师的要求来。

---

# 二十、一个容易搞混的地方：“定义”与“声明”

你老师如果说：

> “把 class 定义写到 `.h` 里面”

严格从 C++ 术语上讲，这里面有一点容易混淆。

例如：

```cpp
class Student
{
public:
    void study();
};
```

这是：

> **类定义（class definition）**

而：

```cpp
void study();
```

是：

> **成员函数声明（declaration）**

真正的函数实现：

```cpp
void Student::study()
{
    ...
}
```

是：

> **定义 / 实现（definition / implementation）**

所以整个结构可以更严谨地说：

```text
Student.h

    类的定义
        ↓
    成员变量
    成员函数声明


Student.cpp

    成员函数定义 / 实现
        ↓
    构造函数
    成员函数
    析构函数


main.cpp

    程序入口
        ↓
    创建对象
    调用成员函数
```

---

# 二十一、你现在写作业时可以直接套这个模板

假设老师让你：

> 自定义一个 `Car` 类。

那么：

### `Car.h`

```cpp
#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
    std::string brand;
    int speed;

public:
    Car(std::string brand);

    void accelerate();
    void brake();
    void showInfo();
};

#endif
```

### `Car.cpp`

```cpp
#include "Car.h"
#include <iostream>

Car::Car(std::string brand)
{
    this->brand = brand;
    speed = 0;
}

void Car::accelerate()
{
    speed += 10;
}

void Car::brake()
{
    if (speed >= 10)
        speed -= 10;
}

void Car::showInfo()
{
    std::cout << "品牌：" << brand << std::endl;
    std::cout << "速度：" << speed << " km/h" << std::endl;
}
```

### `main.cpp`

```cpp
#include "Car.h"

int main()
{
    Car car("Toyota");

    car.accelerate();
    car.accelerate();

    car.showInfo();

    car.brake();

    car.showInfo();

    return 0;
}
```

这就是一个非常标准的：

```text
      Car.h
   类的定义
       │
       ├──────────────┐
       ↓              ↓
   Car.cpp         main.cpp
   类的实现          程序主体
       │              │
       └──────┬───────┘
              ↓
          最终程序
```

---

## 最后给你一个最值得背下来的口诀

如果你这次是为了**完成 C++ 老师的作业**，不要把它想得太复杂：

> **`.h` 写“有什么”，`.cpp` 写“怎么做”，`main.cpp` 写“怎么用”。**

即：

```text
.h
↓
class Student
{
    数据成员;
    函数声明;
};

.cpp
↓
Student::函数()
{
    具体实现;
}

main.cpp
↓
int main()
{
    Student 对象;
    对象.函数();
}
```

这基本就是你老师要求“三个文件”的核心。

而且你现在已经学过 C，实际上这套东西和 C 的：

```text
.h        → 函数声明、结构体声明
.c        → 函数实现
main.c    → 主程序
```

**本质上是一脉相承的。** C++ 只是进一步把这种“声明与实现分离”的思想和 `class`、封装、面向对象结合起来了。**