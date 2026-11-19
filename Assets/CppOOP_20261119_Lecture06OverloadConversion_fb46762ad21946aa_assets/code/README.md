# 第六讲随包代码（C++17）

## 复数三文件示例

进入 `ComplexDemo/` 目录后运行：

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Complex.cpp main.cpp -o complex_demo
./complex_demo
```

第一行输出是 `a=3+4i b=1+2i`，随后包含加减法、前后置运算、模长转换、`Add(5)` 的演示。`CComplex` 使用 `std::string` 管理名称，**不把原课件的原始指针复制问题直接带入可运行代码**。

## 相关向量示例

在 `AssociatedVectorDemo.cpp` 所在目录运行：

```bash
g++ -std=c++17 -Wall -Wextra -pedantic AssociatedVectorDemo.cpp -o assoc_demo
./assoc_demo
```

结果先输出 `Apple=8 / Orange=2 / Banana=10`（每行有等号两侧空格），再输出新键 `Fruit = 6`。这份示例保留课件**新建键默认值为 `mUsed+1`** 的规则，但改用 `std::string` / `std::vector` 自动管理资源并在容量满时报错。保留 `int&` 下标访问；请勿跨可能引发 `std::vector` 扩容的插入操作长期保存该引用。

两个示例已经在 `g++ -std=c++17 -Wall -Wextra -pedantic -Werror` 下通过编译与运行检查。
