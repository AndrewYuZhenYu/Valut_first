# 第八讲 C++17 可运行课堂演示

所有演示均根据 PPT 案例重新编写为标准 C++17，保留课件的关键语义和预期输出；不直接复制旧编译器环境中的 `<iostream.h>` 和 `void main()`。

各目录可在该目录内独立编译：

```bash
# 除 02 之外的单文件项目
cd 01_nonvirtual
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o demo
./demo

# 三文件拆分为多个类文件的动物虚函数示例
cd ../02_virtual_animal
g++ -std=c++17 -Wall -Wextra -pedantic Animal.cpp Beast.cpp Bird.cpp main.cpp -o demo
./demo

# 其余可将目录名依次改为 03_bat_multiple、04_bat_all_virtual、
# 05_ctor_dtor、06_abstract_shapes、07_student_copy，并重复单文件命令。
```

预期输出：

- `01_nonvirtual`: 动物版本；兽类版本
- `02_virtual_animal`: 我不是飞禽就是走兽！；我是森林之王！；我是一只小小鸟！
- `03_bat_multiple`: 我不是飞禽就是走兽！；我是森林之王！；我是蝙蝠大侠！
- `04_bat_all_virtual`: 蝙蝠；蝙蝠；蝙蝠
- `05_ctor_dtor`: Base；Derived；Derived；Derived；Base
- `06_abstract_shapes`: 12.5664；12
- `07_student_copy`: Alice；Lily；Lily

不建议把不同目录中的 `main.cpp` 一起编译，因为每个演示都是**独立的小程序**。
