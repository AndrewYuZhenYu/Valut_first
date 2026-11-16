
---

### 第一章：为什么要用 `std::string`（背景解析）

**C 字符串的问题：**
```cpp
char str[10];
strcpy(str, "hello world");  // 缓冲区溢出！只分配了10个字节，却要复制11个字符（含'\0'）
```

**解析：**  
- `strcpy` 不检查目标缓冲区大小，导致写入越界，可能覆盖其他变量或破坏栈帧，引发崩溃或安全漏洞。  
- `std::string` 自动管理内存，动态扩容，永远不会发生这种越界写入。

---

### 第二章：构造与初始化（含详细解析）

```cpp
#include <string>
using namespace std;

// 1. 默认构造
string s1;                    
// 解析：创建一个空字符串，size() = 0，内部可能指向一个静态的空字符串或空指针。
// 不分配堆内存（SSO 下直接在对象内部存储）。

// 2. 从 C 字符串构造
string s2("hello");           
// 解析：编译器将 "hello" 视为 const char[6]，构造函数会计算长度（不含'\0'），
// 然后拷贝5个字符到内部存储。如果"hello"长度 ≤ SSO阈值（通常15），直接存在栈上；否则堆分配。

// 3. 拷贝构造
string s3(s2);                
// 解析：深拷贝。s3 独立拥有 s2 的一份副本，修改 s2 不影响 s3。
// 注意：这里会复制所有字符，性能开销 O(n)。

// 4. 移动构造（C++11）
string s4(std::move(s3));     
// 解析：std::move 将 s3 转为右值引用，触发移动构造。
// s4 直接“窃取”s3 的堆内存指针，s3 变为空（或有效但未指定状态）。
// 复杂度 O(1)，非常高效，适用于临时对象或明确不再使用的字符串。

// 5. 从子串构造
string s5("hello world", 6, 5);  
// 解析：从 "hello world" 的下标6开始，取5个字符 -> "world"。
// 参数1：源C字符串；参数2：起始位置；参数3：取多少个字符。
// 如果参数3超过源字符串长度，取到末尾为止（不抛异常，实际取到末尾）。

// 6. 从 C 字符串前 n 个字符构造
string s6("hello world", 5);     
// 解析：取前5个字符 -> "hello"。
// 注意：这里只有两个参数，编译器会调用 string(const char* s, size_t count) 重载。

// 7. 填充构造（n 个 char）
string s7(5, 'a');               
// 解析：创建包含5个 'a' 的字符串 -> "aaaaa"。
// 参数顺序是 (count, char)，注意不要写反成 ('a', 5)，那会调用其他重载。

// 8. 迭代器区间构造
string s8(s2.begin(), s2.end()); 
// 解析：用 s2 的迭代器范围构造副本，效果同拷贝构造。
// 通用性好，可用于从 vector<char>、数组等构造 string。

// 9. 初始化列表构造（C++11）
string s9 = {'a', 'b', 'c'};     
// 解析：C++11 引入的列表初始化，等价于 string s9("abc")。
// 注意：必须用大括号，且元素类型为 char。

// 10. 赋值运算符（也是构造）
string s10 = "hello";            
// 解析：这是拷贝初始化（copy initialization），编译器会隐式调用 string(const char*) 构造函数。
// 与 s2 的构造方式本质一样，只是语法糖。
```

**易错提示：**
- `string s(5, 'a')` 和 `string s('a', 5)` 含义完全不同，后者可能将 'a' 的 ASCII 值（97）当作长度，产生 97 个乱码字符，务必小心！

---

### 第三章：赋值操作（assign 系列详细解析）

```cpp
string s;

// 1. 直接赋值
s = "hello";                
// 解析：调用 operator=(const char*)，先释放原有内存（如果有），再拷贝新字符串。
// 如果原字符串容量足够，可能复用内存，避免重新分配。

// 2. assign 基本用法
s.assign("world");          
// 解析：等价于 s = "world"，但 assign 有更多重载，更灵活。

// 3. 填充赋值
s.assign(3, 'x');           
// 解析：将 s 的内容替换为 "xxx"。先清空，再填充。
// 执行过程：释放旧数据，分配3个字符空间，拷贝3个 'x'，设置长度为3。

// 4. 从子串赋值
s.assign("abcdef", 2, 3);   
// 解析：从 "abcdef" 的下标2开始取3个字符 -> "cde"。
// 参数1：源字符串；参数2：起始位置；参数3：取多少个。
// 如果源字符串长度不足，会抛出 out_of_range 异常。

// 5. 拷贝赋值
s.assign(s2);               
// 解析：拷贝 s2 的全部内容给 s。
// 内部会检查是否自我赋值（s.assign(s) 是安全的）。

// 6. 从另一个 string 的子串赋值
s.assign(s2, 1, 3);         
// 解析：从 s2 的下标1起取3个字符。
// 如果 s2 长度小于 1+3，抛出 out_of_range 异常。

// 7. 初始化列表赋值（C++11）
s.assign({ 'a', 'b' });     
// 解析：将 s 变为 "ab"。使用花括号初始化列表。
```

**性能提示：**
- `assign` 比 `operator=` 更灵活，但也更冗长。优先用 `operator=` 或 `+=` 提高可读性。

---

### 第四章：访问字符（含边界检查解析）

```cpp
string s = "hello";

// 1. operator[]（无边界检查）
char c1 = s[0];   // 'h'
s[1] = 'a';       // s 变为 "hallo"
// 解析：operator[] 直接返回底层数组的引用，不检查索引是否越界。
// 如果越界（如 s[100]），行为未定义——可能读到垃圾数据、崩溃，或修改了不该改的内存。
// 性能最高，适合在确定索引合法的情况下使用。

// 2. at()（有边界检查）
char c2 = s.at(0);  // 'h'
try {
    char c3 = s.at(100);  // 抛出 std::out_of_range 异常
} catch (const out_of_range& e) {
    // 处理异常
}
// 解析：at() 会检查索引是否 < size()，如果越界则抛出异常。
// 安全性高，但有轻微性能开销（函数调用 + 分支判断）。
// 适合在索引可能非法的情况下（如用户输入）使用。

// 3. front() 和 back()（C++11）
char first = s.front();  // 'h'
char last = s.back();    // 'o'
// 解析：返回首尾字符的引用，但**不检查空字符串**。
// 如果 s.empty() 为 true，调用 front()/back() 是未定义行为！
// 使用前务必确保字符串非空。
```

**最佳实践：**
- 性能关键且保证索引合法 → 用 `operator[]`。
- 索引来自外部输入或不确定 → 用 `at()`。
- 需要快速访问首尾且确保非空 → 用 `front()`/`back()`。

---

### 第五章：迭代器与遍历（详细解析）

```cpp
string s = "hello";

// 1. 下标 for 循环
for (size_t i = 0; i < s.size(); ++i) {
    cout << s[i];
}
// 解析：最原始的方式，用 size_t 类型（无符号整数）作为索引。
// 注意：i < s.size()，由于 size() 返回 size_t（无符号），如果 i 为 -1 会隐式转为大整数，导致无限循环。
// 因此务必用 i < s.size()，不要用 i <= s.size() - 1。

// 2. 范围 for（C++11，推荐）
for (char ch : s) {
    cout << ch;
}
// 解析：编译器的语法糖，实际展开为迭代器循环。
// 这里 ch 是副本，修改 ch 不影响原字符串。如果想修改原字符串，用 char&。
// 例：for (char& ch : s) { ch = toupper(ch); }

// 3. 正向迭代器
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it;
}
// 解析：begin() 返回指向第一个字符的迭代器，end() 返回尾后迭代器（不指向有效字符）。
// 使用 auto 自动推导类型为 string::iterator。
// *it 返回字符引用，可以修改原字符串。

// 4. 反向迭代器
for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
    cout << *rit;   // 输出 "olleh"
}
// 解析：rbegin() 返回反向迭代器，指向最后一个字符；rend() 指向第一个字符之前。
// 反向迭代器递增会向前移动，实现逆序遍历。

// 5. C++17 的 for_each + lambda
std::for_each(s.begin(), s.end(), [](char c){ cout << c; });
// 解析：用算法库的 for_each，配合 lambda 表达式。
// 灵活性高，但可读性不如范围 for，一般只在对算法组合使用时采用。
```

**迭代器失效警告：**
- 在遍历过程中，如果修改了字符串（如 `s.insert`、`s.erase`、`s.push_back` 等），可能导致迭代器失效，继续使用旧迭代器是未定义行为。

---

### 第六章：容量与大小（含内存分配解析）

```cpp
string s = "hello";

// size() 与 length() 完全等价
size_t len = s.size();     // 5
size_t len2 = s.length();  // 5
// 解析：两者返回值相同，推荐统一用 size()，因为符合所有 STL 容器的习惯。

// empty() 判断是否为空
bool empty = s.empty();    // false
// 解析：等价于 s.size() == 0，但更直观。内部实现通常直接比较长度是否为0。

// capacity() 查看已分配容量
size_t cap = s.capacity(); 
// 解析：返回当前已分配的存储空间能容纳的字符数（不含 '\0'）。
// 通常 capacity >= size，因为要预留扩容空间。
// 注意：capacity() 不包含结尾的 '\0'，但底层确实会多分配一个字节存 '\0'。

// reserve() 预分配空间
s.reserve(100);
// 解析：请求将容量至少增加到 100。
// 如果 100 > 当前 capacity，触发重新分配，拷贝旧数据到新内存，释放旧内存。
// 如果 100 <= 当前 capacity，什么都不做。
// 用途：提前预知字符串大小，避免多次扩容导致性能损失。

// shrink_to_fit() 释放多余内存（C++11）
s.shrink_to_fit();
// 解析：请求将 capacity 缩小到接近 size。
// 但这是非强制性的（non-binding），编译器可能忽略。
// 且缩小可能触发重新分配和拷贝，开销较大，仅在内存紧张时使用。
```

**扩容机制详解：**
```cpp
string s;
cout << s.capacity() << endl;  // 可能是 0 或 15（取决于SSO）
s.push_back('a');              // 如果容量不足，触发扩容
// 常见扩容策略：新容量 = 旧容量 * 2（或 1.5倍），避免频繁分配。
// 例如：容量从 15 → 30 → 60 → 120 → ...
```

---

### 第七章：修改操作（增删改，含内存变化解析）

```cpp
string s = "hello";

// ---- 追加（尾部添加） ----
s += "abc";                
// 解析：重载的 operator+=，在尾部追加 "abc"。
// 如果剩余容量不足，触发扩容，拷贝所有旧数据到新内存，再追加新数据。
// 复杂度：均摊 O(1)，但单次可能 O(n)。

s.append("def");           
// 解析：等价于 +=，但支持更多参数。例如 s.append("xyz", 2) 只追加前2个字符。

s.append(3, 'z');          
// 解析：追加3个 'z'，结果 "zzz"。
// 参数顺序：(count, char)，同上。

s.push_back('!');          
// 解析：追加单个字符。比 += 或 append 更高效（少一次函数重载解析）。
// 常用于循环中逐个添加字符。

// ---- 插入（任意位置） ----
s.insert(2, "insert");     
// 解析：在下标2的位置插入 "insert"，原下标2及之后的元素后移。
// 执行过程：先检查是否需扩容，然后移动后续字符，最后拷贝插入内容。
// 复杂度 O(n)，因为要移动元素。

s.insert(0, 3, 'x');       
// 解析：在开头插入3个 'x'。
// 等价于 s.insert(s.begin(), 3, 'x')。

s.insert(s.begin() + 1, 'a');
// 解析：在第二个位置（下标1）插入单个字符 'a'。
// 使用迭代器版本，s.begin()+1 必须合法（即至少有一个字符）。

// ---- 删除 ----
s.erase(3, 2);             
// 解析：从下标3开始，删除2个字符。后续字符前移。
// 如果第二个参数省略，删除从下标3到末尾的所有字符。
// 复杂度 O(n)，因为要移动后续元素。

s.erase(s.begin() + 1);    
// 解析：删除第二个字符（下标1）。使用迭代器版本。

s.erase(s.begin(), s.begin() + 3); 
// 解析：删除前3个字符。区间为 [begin, begin+3)。

s.pop_back();              
// 解析：删除最后一个字符（C++11）。
// 如果字符串为空，调用 pop_back() 是未定义行为！使用前务必检查 !s.empty()。

s.clear();                 
// 解析：清空字符串，size() 变为0，但 capacity() 通常不变（保留已分配内存）。
// 如果希望释放内存，用 shrink_to_fit() 或 string().swap(s)。

// ---- 替换 ----
s.replace(1, 3, "new");    
// 解析：从下标1起，用 "new" 替换原来的3个字符。
// 如果替换后长度发生变化，底层会重新调整大小，可能触发内存重分配。
// 执行步骤：删除原3个字符 → 扩容（如果长度增加）→ 插入新字符串。

s.replace(0, 2, 4, 'x');   
// 解析：用4个 'x' 替换前2个字符。
// 参数：(起始下标, 删除个数, 填充个数, 填充字符)。

s.replace(s.begin(), s.begin()+2, "abc");
// 解析：迭代器版本，用 "abc" 替换前2个字符。
```

**修改操作的性能总结：**
- 尾部操作（`push_back`、`+=`）均摊 O(1)。
- 中间插入/删除 O(n)，因为要移动元素。
- 频繁在头部插入，考虑用 `deque<char>` 或反转逻辑。

---

### 第八章：查找与子串（含边界解析）

```cpp
string s = "hello world hello";

// ---- 查找 ----
size_t pos = s.find("world");        
// 解析：正向查找子串 "world"，返回首次出现的位置（6）。
// 如果未找到，返回 string::npos（静态常量，值为最大 size_t，即 -1）。
// 注意：string::npos 是 size_t 类型，判断时用 if (pos == string::npos)。

pos = s.find("abc");                 
// 返回 string::npos。

pos = s.find('o', 5);                
// 解析：从下标5开始查找字符 'o'，返回 7（第二个 'o' 在 "world" 中）。
// 如果省略第二个参数，默认从下标0开始查找。

// ---- 反向查找 ----
pos = s.rfind('o');                  
// 解析：反向查找（从末尾往前），返回最后一个 'o' 的位置（16，在最后一个 "hello" 中）。

// ---- 查找第一个属于集合的字符 ----
pos = s.find_first_of("aeiou");      
// 解析：查找第一个元音字母，返回 1（'e'）。
// 集合中的字符顺序不重要，只要出现任意一个即可。

// ---- 查找第一个不属于集合的字符 ----
pos = s.find_first_not_of("helo ");  
// 解析：在 "hello world hello" 中，前4个字符 'h','e','l','l' 都属于集合 "helo "，
// 第5个是 'o' 也属于，第6个是空格也属于，直到第7个是 'w' 不属于集合，所以返回 6。
// 常用于去除空白字符：s.find_first_not_of(" \t\n")。

// ---- 查找最后一个属于集合的字符 ----
pos = s.find_last_of("o");           
// 返回 16（最后一个 'o'）。

// ---- 查找最后一个不属于集合的字符 ----
pos = s.find_last_not_of("o");       
// 返回 15（最后一个 'l'，因为最后一个是 'o' 属于集合）。

// ---- 提取子串 ----
string sub = s.substr(6, 5);    
// 解析：从下标6开始取5个字符 -> "world"。
// 如果起始位置超出字符串长度，抛出 out_of_range 异常。
// 如果取的数量超过剩余长度，取到末尾为止（不抛异常）。

string sub2 = s.substr(6);      
// 解析：从下标6取到末尾 -> "world hello"。
// 如果 s.substr(100) 且 100 >= size()，抛出 out_of_range 异常。
```

**npos 的陷阱：**
```cpp
size_t pos = s.find("abc");
if (pos == -1) { }   // 错误！-1 会被转为 size_t 的大数，永远不相等。
if (pos == string::npos) { }  // 正确！
```

---

### 第九章：比较操作（详细解析）

```cpp
// ---- 关系运算符 ----
string a = "apple", b = "banana";
if (a == b) { }      // 比较每个字符，直到遇到不同或到达末尾。
if (a != b) { }      
if (a < b) { }       // 字典序比较：首先比较第一个字符 'a' vs 'b'，'a' < 'b'，所以 true。
// 同样支持 >, <=, >=。
// 时间复杂度 O(n)，最坏比较所有字符。

// ---- compare() 函数（更灵活，返回 int） ----
int res;
res = a.compare(b);          
// 解析：如果 a < b 返回负数；a == b 返回0；a > b 返回正数。
// 具体返回值不一定为 -1/0/1，只保证正负号。

res = a.compare(1, 3, b);    
// 解析：比较 a[1..3]（即 "ppl"）和整个 b（"banana"）的字典序。

res = a.compare(1, 3, b, 2, 4); 
// 解析：比较 a[1..3]（"ppl"）和 b[2..5]（"nana"）。

res = a.compare("apple");    
// 解析：与 C 字符串比较。等价于 a.compare(string("apple"))。

// ---- 比较的底层实现 ----
// 使用 char_traits<char>::compare，逐字符比较，遇到不同或到达 '\0' 停止。
// 如果两个字符串的前 n 个字符都相同，较短的字符串被认为更小。
```

---

### 第十章：与 C 字符串互转（含生命周期解析）

```cpp
string s = "hello";

// ---- 转为只读 C 字符串 ----
const char* cstr = s.c_str();   
// 解析：返回一个以 '\0' 结尾的 const char* 指针。
// 该指针指向 string 内部存储，**不能修改**其内容。
// 指针有效期：直到 s 被修改（重新分配内存）或销毁。

const char* data = s.data();    
// 解析：C++11 后，data() 与 c_str() 相同，也返回 const char*。
// C++17 起，data() 返回 char*（非 const），但仍然不推荐直接修改。

// ---- 重要：指针失效案例 ----
const char* p = s.c_str();      // p 指向内部存储
s += " world";                  // 可能触发重新分配，p 变成野指针
cout << p;                      // 未定义行为！可能崩溃或输出乱码

// ---- 正确做法：需要时再获取 ----
void use_c_str(const string& s) {
    const char* p = s.c_str();   // 局部使用，保证在其生命周期内不修改 s
    printf("%s", p);
}

// ---- 可写字符数组（不推荐） ----
char* buf = &s[0];              
// 解析：取第一个元素的地址，可以修改字符。
// 但要注意：需要确保 s.size() >= 你写入的长度，否则越界。
// 更安全的方式：先 s.resize(n)，再取 &s[0]。

// ---- C 字符串 → string（隐式转换） ----
string s2 = "hello";            
// 解析：自动调用 string(const char*) 构造函数。
string s3 = s2 + " world";      
// 解析：operator+ 的重载可以接受 const char*，自动构造临时 string。
```

**最佳实践：**
- 尽量不长期存储 `c_str()` 的返回值。
- 如果需要调用 C 函数，在调用时临时获取：
  ```cpp
  void c_api(const char*);
  c_api(s.c_str());  // 安全，调用期间不修改 s
  ```

---

### 第十一章：数值与字符串互转（含异常解析）

```cpp
// ---- 字符串 → 数值 ----
int i = std::stoi("123");        
// 解析：stoi = string to int。转换成功返回 123。
// 如果字符串以数字开头但后续有非数字，如 "123abc"，会转换 123，并设置指针参数指向 'a'。
// 如果字符串为空或无效（如 "abc"），抛出 invalid_argument 异常。
// 如果数值超出 int 范围，抛出 out_of_range 异常。

long l = std::stol("123456");
long long ll = std::stoll("123456789");
unsigned long ul = std::stoul("123");
float f = std::stof("3.14");
double d = std::stod("3.14159");

// 带参数版本：可指定转换停止位置和进制
size_t pos;  // 用于接收第一个未转换字符的位置
int hex = std::stoi("FF", &pos, 16);   // 解析十六进制，pos 指向字符串末尾
int oct = std::stoi("077", nullptr, 8); // 八进制，结果为 63

// ---- 数值 → 字符串 ----
string s1 = std::to_string(123);         // "123"
string s2 = std::to_string(3.14159);     // "3.141590"（默认精度）
string s3 = std::to_string(true);        // "1"（bool 转为 1/0）
```

**异常处理示例：**
```cpp
try {
    int x = std::stoi("abc");
} catch (const std::invalid_argument& e) {
    cout << "不是有效数字" << endl;
} catch (const std::out_of_range& e) {
    cout << "数值溢出" << endl;
}
```

---

### 第十二章：性能优化实例（带详细对比）

```cpp
// ---- 性能杀手版本（千万不能用） ----
string s;
for (int i = 0; i < 1000000; ++i) {
    s += 'a';   // 每次可能触发重分配，复制全部数据
}
// 解析：每次 += 都可能因为容量不足而重新分配内存。
// 假设初始容量为 15，扩容 1.5 倍，约需扩容 log_1.5(1e6) ≈ 34 次。
// 每次扩容要拷贝旧数据，总拷贝次数约为 O(n log n)，非常低效。

// ---- 优化版本（推荐） ----
string s;
s.reserve(1000000);          // 提前分配足够容量
for (int i = 0; i < 1000000; ++i) {
    s += 'a';                // 不会重分配，均摊 O(1)
}
// 解析：reserve 预分配 100 万个字符的空间，循环中始终容量充足。
// 总拷贝次数仅有一次（reserve 时），性能提升巨大（可达数十倍）。

// ---- 其他优化技巧 ----
// 1. 使用 append 替代多次 +=（少一次 operator= 解析）
s.append("abc");  // 比 s += "a" + "b" + "c" 更高效

// 2. 构建长字符串时，优先用 string 构造函数
string s = "hello";  // 比先创建空串再 assign 更高效

// 3. 传递只读参数用 const string& 或 string_view（避免拷贝）
void process(const string& s) { ... }  // 推荐
// void process(string s) { ... }      // 不推荐，会拷贝一次
```

---

### 第十三章：移动语义与返回值优化

```cpp
// ---- 返回 string 的函数 ----
string createString() {
    string s = "hello";
    return s;   // 这里触发 NRVO（命名返回值优化）或移动语义
}
// 解析：C++11 后，返回值不会拷贝，而是直接构造在调用者的栈帧中（NRVO），
// 或者移动构造（如果 NRVO 不适用）。无论哪种，都没有深拷贝。

string s1 = createString();   // 无拷贝，直接移动或 NRVO

// ---- 显式移动 ----
string s2 = "world";
string s3 = std::move(s2);    // s2 变为空，s3 获得资源
// 解析：移动构造函数交换内部指针，s2 变成有效但未指定状态（通常是空）。
// 之后访问 s2 是安全的（可以重新赋值），但内容不可预期。

// ---- 移动后不要再使用原对象 ----
s2 = "new value";  // 可以重新赋值，因为 s2 仍是一个有效对象
// 但不要用 s2 原来的数据，因为它已经被“偷走”了。
```

---

### 第十四章：常见陷阱补充（带详细案例）

```cpp
// 陷阱1：无符号比较问题
string s = "hello";
if (s.size() < -1) { }   // 永远为 false！
// 解析：-1 被隐式转换为 size_t（无符号整数），变成巨大的正数。
// 正确的比较：if ((int)s.size() < -1) 或 if (s.size() < 0)（但 size_t 永远 >=0）

// 陷阱2：substr 的异常
string s = "hello";
string sub = s.substr(100, 5);  // 抛出 out_of_range
// 正确做法：先检查 if (100 < s.size())

// 陷阱3：连续拼接字面量
string s = "hello" + "world";   // 编译错误！
// 解析：两个 const char* 不能直接相加，没有定义 operator+。
// 正确写法：string s = "hello"s + "world";   // C++14 字符串字面量
// 或 string s = string("hello") + "world";

// 陷阱4：修改字符串导致迭代器失效
string s = "hello";
auto it = s.begin();
s += " world";   // 可能重分配，it 失效
*it = 'a';       // 未定义行为！it 不再有效

// 陷阱5：c_str() 指针持有太久
const char* p = s.c_str();
s = "new string";   // 重分配，p 失效
cout << p;          // 崩溃或乱码

// 陷阱6：空字符串调用 back()
string empty;
char last = empty.back();   // 未定义行为（空串访问）
```

---

### 第十五章：C++17/20 新特性补充

```cpp
// ---- C++17: string_view（零拷贝只读视图） ----
#include <string_view>
void print(std::string_view sv) {
    cout << sv;   // 不会拷贝字符串
}
string s = "hello world";
print(s);         // 零拷贝，直接传递指针和长度
// 解析：string_view 只持有 const char* 和 size_t，不拥有内存。
// 适合作为函数参数，替代 const string&，避免隐式构造。

// ---- C++20: starts_with / ends_with ----
string s = "hello world";
if (s.starts_with("hello")) { }   // true
if (s.ends_with("world")) { }     // true

// ---- C++20: contains ----
if (s.contains("lo")) { }   // true，等价于 s.find("lo") != npos
```

---

### 第十六章：完整的实战示例（带逐行解析）

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 函数：按分隔符分割字符串（返回子串列表）
vector<string> split(const string& str, char delim) {
    vector<string> result;          // 存储分割后的子串
    size_t start = 0;               // 当前查找的起始位置
    while (true) {
        // 从 start 开始查找分隔符 delim
        size_t end = str.find(delim, start);
        // 提取从 start 到 end 之间的子串（如果 end==npos，则取到末尾）
        result.push_back(str.substr(start, end - start));
        // 如果没找到分隔符，循环结束
        if (end == string::npos) break;
        // 跳过分隔符，继续查找下一个子串
        start = end + 1;
    }
    return result;   // NRVO/移动语义，无拷贝
}

int main() {
    // ---- 示例1：分割 CSV 字符串 ----
    string text = "apple,banana,grape,orange";
    auto fruits = split(text, ',');
    // 遍历并输出每个水果
    for (const auto& f : fruits) {
        cout << f << endl;   // 输出 apple banana grape orange 每行一个
    }

    // ---- 示例2：大小写转换（C++ 风格） ----
    string s = "Hello World!";
    // 遍历每个字符，转换为大写
    for (char& c : s) {          // 注意是引用，才能修改原字符串
        c = toupper(c);          // toupper 返回 int，隐式转为 char
    }
    cout << s << endl;   // 输出：HELLO WORLD!

    // ---- 示例3：去除首尾空格（手动实现 trim） ----
    string ws = "  abc  ";
    // find_first_not_of 查找第一个非空格字符的位置
    size_t first = ws.find_first_not_of(' ');
    // 如果全是空格，first 会等于 npos，这里假设非空
    size_t last = ws.find_last_not_of(' ');
    // substr 提取从 first 到 last 的子串
    ws = ws.substr(first, last - first + 1);
    cout << "'" << ws << "'" << endl;   // 输出：'abc'

    return 0;
}
```

**逐行解析 `split` 函数：**
- `find(delim, start)`：从 `start` 位置开始查找分隔符，返回下标。
- `end - start`：计算当前子串的长度。
- `substr(start, end - start)`：提取从 `start` 开始的 `end-start` 个字符。
- 当 `end == npos` 时，`end - start` 等于从 `start` 到末尾的长度，`substr` 能正确处理。
- 每次找到分隔符后，`start = end + 1` 跳过它。
- 时间复杂度 O(n)，空间复杂度 O(n)（存储结果）。

---

## 最终总结

| 知识点 | 核心要点 |
|--------|----------|
| 构造 | 10 种方式，注意区分 `(count, char)` 顺序 |
| 访问 | `[]` 快但危险，`at()` 安全但慢 |
| 修改 | 尾部操作高效，中间操作 O(n) |
| 查找 | 返回 `size_t`，未找到为 `npos` |
| 性能 | `reserve()` 预分配，避免多次扩容 |
| 安全 | `c_str()` 临时用，迭代器注意失效 |
| 现代 C++ | `string_view` 作为参数，避免拷贝 |

---

现在，每个代码示例都有了详细的逐行解析，涵盖了“为什么这样写”、“内部发生了什么”、“有什么风险”、“如何优化”。如果你对其中某个具体函数（比如 `replace` 的多种重载、或者自定义 `char_traits`）还想更深入，我可以继续展开。你是在校学习还是工作中要用到？我可以根据你的水平调整深度。😊