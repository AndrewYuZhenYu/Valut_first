

## 一、<stdio.h> 输入输出库
### 屏幕输入输出
- `printf("格式", 变量)` - 格式化输出 `printf("值:%d", 10)`
- `scanf("格式", &变量)` - 格式化输入 `scanf("%d", &num)`
- `getchar()` - 读取字符 `ch = getchar()`
- `putchar(字符)` - 输出字符 `putchar('A')`
- `puts(字符串)` - 输出字符串（自动换行） `puts("hello")`
- `gets(数组)` - 读取整行（不安全） `gets(str)`

### 文件操作
- `fopen("文件名", "模式")` - 打开文件 `fp = fopen("a.txt", "r")`
- `fclose(文件指针)` - 关闭文件 `fclose(fp)`
- `fprintf(文件指针, "格式", 变量)` - 写入文件
- `fscanf(文件指针, "格式", &变量)` - 读取文件
- `fgets(数组, 长度, 文件指针)` - 读取文件一行
- `fputs(字符串, 文件指针)` - 写入字符串到文件

### 字符串处理
- `sprintf(数组, "格式", 变量)` - 格式化到字符串
- `sscanf(字符串, "格式", &变量)` - 从字符串读取

---

## 二、<string.h> 字符串处理库
### 复制连接
- `strcpy(目标, 源)` - 字符串复制 `strcpy(s1, "hello")`
- `strncpy(目标, 源, 长度)` - 安全复制 `strncpy(s1, s2, 10)`
- `strcat(目标, 源)` - 字符串连接 `strcat(s1, " world")`
- `strncat(目标, 源, 长度)` - 安全连接

### 比较查找
- `strcmp(串1, 串2)` - 字符串比较 `if(strcmp(s1,s2)==0)`
- `strncmp(串1, 串2, 长度)` - 比较前N个字符
- `strchr(字符串, 字符)` - 查找字符 `p = strchr(s, '@')`
- `strstr(主串, 子串)` - 查找子串 `p = strstr(s, "abc")`

### 其他功能
- `strlen(字符串)` - 获取长度 `len = strlen("hello")`
- `strtok(字符串, 分隔符)` - 字符串分割 `p = strtok(s, ",")`
- `memset(地址, 值, 长度)` - 内存设置 `memset(arr, 0, 100)`
- `memcpy(目标, 源, 长度)` - 内存复制 `memcpy(dest, src, n)`

---

## 三、<stdlib.h> 标准库
### 内存管理
- `malloc(字节数)` - 动态分配 `p = malloc(100)`
- `calloc(数量, 大小)` - 分配并清零 `p = calloc(10, sizeof(int))`
- `realloc(指针, 新大小)` - 重新分配 `p = realloc(p, 200)`
- `free(指针)` - 释放内存 `free(p)`

### 类型转换
- `atoi(字符串)` - 转整数 `num = atoi("123")`
- `atof(字符串)` - 转浮点数 `val = atof("3.14")`
- `itoa(整数, 数组, 进制)` - 整数转字符串 `itoa(100, str, 10)`

### 随机数
- `rand()` - 生成随机数 `x = rand() % 100`
- `srand(种子)` - 设置随机种子 `srand(time(NULL))`

### 程序控制
- `exit(状态码)` - 退出程序 `exit(0)`
- `system("命令")` - 执行系统命令 `system("pause")`
- `abs(整数)` - 整数绝对值 `abs(-5)`
- `qsort(数组, 数量, 大小, 比较函数)` - 快速排序

---

## 四、<math.h> 数学库
### 基本运算
- `pow(x, y)` - x的y次方 `pow(2, 3)=8`
- `sqrt(x)` - 平方根 `sqrt(9)=3`
- `fabs(x)` - 浮点绝对值 `fabs(-3.5)=3.5`

### 指数对数
- `exp(x)` - e^x `exp(1)≈2.718`
- `log(x)` - 自然对数 `log(10)≈2.302`
- `log10(x)` - 以10为底 `log10(100)=2`

### 三角函数
- `sin(x)` - 正弦 `sin(PI/6)=0.5`
- `cos(x)` - 余弦 `cos(PI/3)=0.5`
- `tan(x)` - 正切 `tan(PI/4)=1`

### 取整函数
- `ceil(x)` - 向上取整 `ceil(3.1)=4`
- `floor(x)` - 向下取整 `floor(3.9)=3`
- `round(x)` - 四舍五入 `round(3.5)=4`

---

## 五、<ctype.h> 字符处理库
### 字符判断
- `isalpha(字符)` - 是否字母 `isalpha('A')=1`
- `isdigit(字符)` - 是否数字 `isdigit('5')=1`
- `isalnum(字符)` - 是否字母或数字
- `isspace(字符)` - 是否空白字符 `isspace(' ')=1`
- `islower(字符)` - 是否小写 `islower('a')=1`
- `isupper(字符)` - 是否大写 `isupper('A')=1`

### 字符转换
- `toupper(字符)` - 转大写 `toupper('a')='A'`
- `tolower(字符)` - 转小写 `tolower('A')='a'`

---

## 六、<time.h> 时间库（补充）
### 时间获取
- `time(指针)` - 获取当前时间 `time(&now)`
- `clock()` - 程序运行时间 `start = clock()`

### 时间转换
- `localtime(时间指针)` - 转本地时间 `tm = localtime(&now)`
- `strftime(字符串, 大小, 格式, 时间)` - 格式化时间

### 延时
- `sleep(秒)` - 秒级延时 `sleep(1)`
- `usleep(微秒)` - 微秒级延时 `usleep(1000)`

---

## 使用示例
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main() {
    // stdio.h 示例
    char name[20];
    printf("输入名字: ");
    scanf("%s", name);
    
    // string.h 示例
    char greeting[50] = "Hello, ";
    strcat(greeting, name);
    puts(greeting);
    
    // ctype.h 示例
    if (isalpha(name[0])) {
        printf("名字以字母开头\n");
    }
    
    // math.h 示例
    double root = sqrt(16);
    printf("16的平方根: %.0f\n", root);
    
    // stdlib.h 示例
    int r = rand() % 10 + 1;
    printf("随机数(1-10): %d\n", r);
    
    return 0;
}
```

## 编译注意事项
- 数学库需链接：`gcc file.c -lm`
- 部分函数有平台差异（如sleep）
- 字符串函数注意缓冲区大小