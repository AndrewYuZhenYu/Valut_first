# C语言结构体（struct）详细知识点整理

  

## 一、结构体基础

  

### 1. 结构体的定义

```c

// 方式1：先定义结构体类型，再声明变量

struct Student {

    char name[20];

    int age;

    float score;

};

struct Student stu1, stu2;

  

// 方式2：定义类型的同时声明变量

struct Person {

    char name[20];

    int age;

} p1, p2;

  

// 方式3：使用typedef创建别名

typedef struct Employee {

    char name[30];

    int id;

    double salary;

} Emp;  // Emp成为struct Employee的别名

Emp e1;  // 直接使用别名声明

  

// 方式4：匿名结构体（不推荐）

struct {

    int x;

    int y;

} point;

```

  

### 2. 结构体变量的初始化

```c

// 完全初始化

struct Student stu1 = {"张三", 18, 90.5};

  

// 部分初始化（未初始化的成员自动清零）

struct Student stu2 = {"李四"};  // age=0, score=0.0

  

// 指定初始化（C99标准）

struct Student stu3 = {

    .age = 19,

    .name = "王五",

    .score = 88.5

};

  

// 结构体数组初始化

struct Student class[3] = {

    {"Alice", 20, 85.0},

    {"Bob", 21, 92.5},

    {.name = "Charlie", .score = 78.5}  // age自动为0

};

```

  

## 二、结构体成员的访问

  

### 1. 成员运算符

```c

struct Point {

    int x;

    int y;

};

  

struct Point p1;

p1.x = 10;      // 直接访问

p1.y = p1.x * 2;

  

// 嵌套结构体访问

struct Line {

    struct Point start;

    struct Point end;

};

  

struct Line l1;

l1.start.x = 0;

l1.end.y = 100;

```

  

### 2. 指针访问成员

```c

struct Student {

    char name[20];

    int age;

};

  

struct Student stu = {"Tom", 20};

struct Student *ptr = &stu;

  

// 方式1：解引用后使用点运算符

(*ptr).age = 21;

  

// 方式2：箭头运算符（推荐）

ptr->age = 22;

strcpy(ptr->name, "Jerry");

  

// 结构体指针数组

struct Student *pArray[10];

pArray[0] = &stu;

printf("Name: %s\n", pArray[0]->name);

```

  

## 三、结构体内存对齐（重要）

  

### 1. 对齐原则

```c

struct Example1 {

    char a;      // 1字节

    int b;       // 4字节

    short c;     // 2字节

};

// 内存布局：a(1) + 填充(3) + b(4) + c(2) + 填充(2) = 12字节

  

struct Example2 {

    int b;       // 4字节

    char a;      // 1字节

    short c;     // 2字节

};

// 内存布局：b(4) + a(1) + c(1) + 填充(1) = 8字节（更优）

```

  

### 2. 修改对齐方式

```c

#pragma pack(1)  // 1字节对齐，取消填充

struct Compact {

    char a;

    int b;

    short c;

};  // 大小为1+4+2=7字节

#pragma pack()   // 恢复默认对齐

  

// GCC/Clang特有的属性语法

struct Aligned {

    char a;

    int b __attribute__((aligned(16)));  // b按16字节对齐

};

```

  

### 3. 计算偏移量和大小

```c

#include <stddef.h>

#include <stdio.h>

  

struct Data {

    char a;

    double b;

    char c;

};

  

int main() {

    printf("Sizeof: %zu\n", sizeof(struct Data));

    printf("Offset of b: %zu\n", offsetof(struct Data, b));

    return 0;

}

```

  

## 四、结构体高级特性

  

### 1. 结构体嵌套

```c

// 前向声明（不完全类型）

struct Class;

  

struct Teacher {

    char name[20];

    struct Class *teaching;  // 只能使用指针

};

  

struct Class {

    char className[20];

    struct Teacher headTeacher;

    int studentCount;

};

  

// 自引用结构体（链表节点）

struct Node {

    int data;

    struct Node *next;  // 必须使用指针

};

```

  

### 2. 结构体数组

```c

#define MAX_STUDENTS 100

  

typedef struct {

    char name[30];

    int scores[5];

    float average;

} Student;

  

// 结构体数组操作

Student classroom[MAX_STUDENTS];

  

// 遍历并计算平均分

for (int i = 0; i < count; i++) {

    int sum = 0;

    for (int j = 0; j < 5; j++) {

        sum += classroom[i].scores[j];

    }

    classroom[i].average = sum / 5.0;

}

  

// 按成绩排序（qsort示例）

#include <stdlib.h>

int compareStudent(const void *a, const void *b) {

    Student *stuA = (Student *)a;

    Student *stuB = (Student *)b;

    if (stuA->average < stuB->average) return 1;

    if (stuA->average > stuB->average) return -1;

    return 0;

}

qsort(classroom, count, sizeof(Student), compareStudent);

```

  

### 3. 结构体与函数

```c

// 结构体作为函数参数（传值，会复制）

void printStudent(struct Student s) {

    printf("Name: %s, Age: %d\n", s.name, s.age);

}

  

// 结构体指针作为参数（传地址，高效）

void updateStudent(struct Student *s, int newAge) {

    s->age = newAge;

}

  

// 返回结构体（C语言允许）

struct Point createPoint(int x, int y) {

    struct Point p = {x, y};

    return p;  // 返回副本

}

  

// 返回结构体指针（需注意生命周期）

struct Point* createDynamicPoint(int x, int y) {

    struct Point *p = malloc(sizeof(struct Point));

    if (p) {

        p->x = x;

        p->y = y;

    }

    return p;  // 调用者需负责释放

}

```

  

### 4. 位域（Bit Fields）

```c

// 节省内存的特殊用法

struct Status {

    unsigned int isReady : 1;     // 1位

    unsigned int isError : 1;     // 1位

    unsigned int errorCode : 4;   // 4位

    unsigned int padding : 2;     // 2位填充

    unsigned int value : 8;       // 8位

};  // 总共2字节（16位）

  

// 使用示例

struct Status s;

s.isReady = 1;

s.isError = 0;

s.errorCode = 5;  // 只能存储0-15

s.value = 100;

  

// 无名位域用于对齐

struct Bits {

    unsigned int a : 5;

    unsigned int   : 3;  // 无名位域，跳过3位

    unsigned int b : 8;

};

```

  

## 五、结构体与联合体（Union）

  

### 1. 联合体基础

```c

union Data {

    int i;

    float f;

    char str[20];

};

  

union Data data;

data.i = 10;           // 此时data.i有效

data.f = 220.5;        // 现在data.f有效，data.i被覆盖

strcpy(data.str, "hello");  // 现在str有效，其他被覆盖

```

  

### 2. 结构体中的联合体

```c

// 用于表示多种类型的数据

typedef struct {

    enum { INT, FLOAT, STRING } type;

    union {

        int intValue;

        float floatValue;

        char stringValue[50];

    } data;

} Variant;

  

Variant v;

v.type = INT;

v.data.intValue = 100;

  

// 使用技巧：匿名联合（C11标准）

struct Flexible {

    int type;

    union {

        int num;

        double dbl;

        char *str;

    };  // 匿名联合，成员可直接访问

};

  

struct Flexible f;

f.type = 1;

f.num = 42;  // 直接访问，无需中间名

```

  

## 六、结构体实用技巧

  

### 1. 柔性数组成员（C99）

```c

// 必须放在结构体末尾，且结构体至少有两个成员

struct DynamicArray {

    int length;

    double data[];  // 柔性数组，不占空间

};

  

// 使用：分配额外空间

struct DynamicArray *createArray(int n) {

    struct DynamicArray *arr = malloc(

        sizeof(struct DynamicArray) + n * sizeof(double)

    );

    arr->length = n;

    return arr;

}

  

// 访问

struct DynamicArray *arr = createArray(10);

for (int i = 0; i < arr->length; i++) {

    arr->data[i] = i * 1.5;

}

```

  

### 2. 结构体比较与复制

```c

struct Person {

    char name[20];

    int age;

};

  

struct Person p1 = {"Alice", 25};

struct Person p2;

  

// 结构体赋值（逐成员复制）

p2 = p1;  // C语言允许，会复制所有成员

  

// 结构体比较（不能直接使用==）

if (memcmp(&p1, &p2, sizeof(struct Person)) == 0) {

    printf("结构体内容相同\n");

}

  

// 手动比较

if (p1.age == p2.age && strcmp(p1.name, p2.name) == 0) {

    printf("相同\n");

}

```

  

### 3. 结构体与文件I/O

```c

// 二进制读写

struct Record {

    int id;

    char name[30];

    float salary;

};

  

// 写入文件

struct Record rec = {101, "John", 5000.0};

FILE *fp = fopen("data.bin", "wb");

fwrite(&rec, sizeof(struct Record), 1, fp);

  

// 读取文件

struct Record rec2;

fseek(fp, 0, SEEK_SET);

fread(&rec2, sizeof(struct Record), 1, fp);

  

// 注意事项：包含指针的结构体不能直接fwrite/fread

```

  

## 七、常见应用示例

  

### 1. 链表实现

```c

typedef struct ListNode {

    int data;

    struct ListNode *next;

} Node;

  

// 创建链表

Node* createNode(int value) {

    Node *newNode = malloc(sizeof(Node));

    if (newNode) {

        newNode->data = value;

        newNode->next = NULL;

    }

    return newNode;

}

  

// 插入节点

void insertNode(Node **head, int value) {

    Node *newNode = createNode(value);

    newNode->next = *head;

    *head = newNode;

}

```

  

### 2. 学生管理系统

```c

#define MAX_COURSES 10

  

typedef struct {

    char courseName[30];

    int credit;

    float score;

} Course;

  

typedef struct {

    int studentID;

    char name[30];

    Course courses[MAX_COURSES];

    int courseCount;

    float gpa;

} Student;

  

// 计算GPA

void calculateGPA(Student *stu) {

    float totalPoints = 0;

    int totalCredits = 0;

    for (int i = 0; i < stu->courseCount; i++) {

        totalPoints += stu->courses[i].score * stu->courses[i].credit;

        totalCredits += stu->courses[i].credit;

    }

    if (totalCredits > 0) {

        stu->gpa = totalPoints / totalCredits;

    }

}

```

  

## 八、最佳实践与注意事项

  

1. **初始化重要性**：始终初始化结构体变量，避免未定义行为

2. **内存对齐**：合理安排成员顺序以减少内存浪费

3. **深浅拷贝**：理解结构体赋值是浅拷贝，包含指针时需要额外处理

4. **跨平台问题**：不同平台对齐规则可能不同，涉及网络传输或文件存储时需注意

5. **类型安全**：使用typedef创建有意义的类型名，提高代码可读性

  

## 九、C11/C17新增特性

  

### 1. 指定初始化器增强

```c

struct Point3D {

    float x, y, z;

};

  

// C11允许重复指定

struct Point3D p = {

    .x = 1.0,

    .y = 2.0,

    .z = 3.0,

    .x = 4.0  // 后面的覆盖前面的

};

```

  

### 2. 匿名结构体和联合体

```c

// 在嵌套时直接访问

struct Widget {

    int type;

    union {

        struct { int x, y; } point;

        struct { int width, height; } rect;

    };  // 匿名联合

};

  

struct Widget w;

w.type = 1;

w.point.x = 10;  // 直接访问

```

  

这份整理涵盖了C语言结构体的核心知识点，从基础到高级应用，适合系统学习和备考复习。