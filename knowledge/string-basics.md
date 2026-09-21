# C++ 字符串基础与刷题常用方法

## 一、基本访问

```cpp
string s = "hello";

s.size();      // 长度
s.length();    // 长度，与 size() 等价
s.empty();     // 是否为空
s.front();     // 第一个字符
s.back();      // 最后一个字符
s[i];          // 下标访问
```

`front()`、`back()` 还能直接修改首尾字符：

```cpp
s.front() = 'H';
s.back() = '!';
```

访问 `front()`、`back()` 前应确保字符串非空。

## 二、查找 find

```cpp
size_t pos = s.find(':');
```

`find()` 返回的是目标第一次出现的位置下标，不是指针。若未找到，返回：

```cpp
string::npos
```

标准判断：

```cpp
if (s.find("abc") != string::npos) {
    // 找到了
}
```

```cpp
if (s.find("abc") == string::npos) {
    // 没找到
}
```

`string::npos` 可以理解为 `size_t(-1)` 转换后的最大无符号值。因此有时与 `-1` 比较也会得到预期结果，但不推荐依赖这种隐式类型转换，应直接写 `string::npos`。

从指定位置继续查找：

```cpp
size_t p2 = s.find(':', p1 + 1);
```

## 三、截取 substr

格式：

```cpp
s.substr(pos, len)
```

例如：

```cpp
string s = "10:start:12";
int p1 = s.find(':');
int p2 = s.find(':', p1 + 1);

string idText = s.substr(0, p1);               // "10"
string type = s.substr(p1 + 1, p2 - p1 - 1);   // "start"
string timeText = s.substr(p2 + 1);             // "12"
```

## 四、字符串与整数转换

字符串转整数：

```cpp
stoi(s);   // string -> int
stol(s);   // string -> long
stoll(s);  // string -> long long
```

整数转字符串：

```cpp
to_string(123);   // "123"
```

数字字符转整数：

```cpp
char c = '7';
int x = c - '0';  // 7
```

## 五、字符分类

需要：

```cpp
#include <cctype>
```

常见函数：

```cpp
isdigit(c);  // 是否为数字字符
isalpha(c);  // 是否为字母
isalnum(c);  // 是否为字母或数字
isupper(c);  // 是否为大写字母
islower(c);  // 是否为小写字母
toupper(c);  // 转成大写
tolower(c);  // 转成小写
```

注意：`isdigit()` 接收的是字符，不是整个 `string`。对于 `"-13"` 这样的字符串，不应只检查第一个字符来判断整个字符串是否为数字。

## 六、范围 for 与引用

遍历 `vector<string>`：

```cpp
for (auto x : tokens) {
    // x 是一份副本
}
```

若不需要修改原元素，推荐：

```cpp
for (const auto& x : tokens) {
    // 不复制，也不能通过 x 修改原字符串
}
```

## 七、格式化字符串解析模板

对于：

```text
10:start:12
```

可以使用：

```cpp
int p1 = s.find(':');
int p2 = s.find(':', p1 + 1);

int id = stoi(s.substr(0, p1));
string type = s.substr(p1 + 1, p2 - p1 - 1);
int time = stoi(s.substr(p2 + 1));
```

思路可以概括为：

```text
find()   -> 找分隔符位置
substr() -> 截取字段
stoi()   -> 把数字字段转成整数
```

## 八、重复子字符串的 s+s 技巧

如果字符串 `s` 由某个更短子串重复构成，那么 `s+s` 去掉首尾字符后仍然包含完整的 `s`：

```cpp
string t = s + s;
t = t.substr(1, t.size() - 2);

bool ok = t.find(s) != string::npos;
```

这是 LeetCode 459「重复的子字符串」的经典判断方法。

## 九、旋转字符串的双倍串技巧

若两个字符串长度相同，`s` 是 `goal` 的旋转结果，当且仅当 `s` 是 `goal + goal` 的子串：

```cpp
bool rotateString(string s, string goal) {
    return s.size() == goal.size() &&
           (goal + goal).find(s) != string::npos;
}
```

例如：

```text
goal = "abcde"
goal + goal = "abcdeabcde"
```

其中包含所有长度为 5 的旋转结果。

## 十、重复拼接直到覆盖目标

对于“重复若干次 a，使 b 成为子串”的题型：

```cpp
string s = a;
int cnt = 1;

while (s.size() < b.size()) {
    s += a;
    cnt++;
}

if (s.find(b) != string::npos)
    return cnt;

s += a;

if (s.find(b) != string::npos)
    return cnt + 1;

return -1;
```

先重复到长度至少覆盖 `b`，如果仍未匹配，再补一份 `a` 处理跨边界情况。

不要把“每次追加原始 a”误写成：

```cpp
a += a;
```

因为这会使字符串长度不断翻倍。

## 十一、stringstream：按格式解析字符串

需要头文件：

~~~cpp
#include <sstream>
~~~

stringstream 可以把一个 string 当成输入流，像 cin 一样按顺序读取数据。

例如日期：

~~~cpp
string date = "2026-09-21";
stringstream ss(date);

int year, month, day;
char c1, c2;

ss >> year >> c1 >> month >> c2 >> day;
~~~

读取结果：

~~~text
year  = 2026
month = 9
day   = 21
c1、c2 读取分隔符 '-'
~~~

适合这种“数字 + 固定分隔符 + 数字”的格式。

如果需要按照某个分隔符切成多个字符串，也可以使用 getline：

~~~cpp
stringstream ss(s);
string part;

while (getline(ss, part, '-')) {
    // 每次得到一段
}
~~~

对固定格式日期，直接用 >> 读整数和分隔符通常最简洁。

## 十二、复习清单

- [ ] 会使用 `size / empty / front / back`。
- [ ] 知道 `front / back` 前需要保证字符串非空。
- [ ] 知道 `find()` 返回位置下标，未找到时为 `string::npos`。
- [ ] 判断查找结果时优先使用 `string::npos`，不依赖 `-1`。
- [ ] 会使用 `substr(pos, len)`。
- [ ] 会使用 `stoi / stoll / to_string`。
- [ ] 知道 `isdigit()` 判断的是字符。
- [ ] 会用 `const auto&` 遍历字符串数组以避免复制。
- [ ] 能独立解析 `id:start/end:time` 格式字符串。
- [ ] 能使用双倍字符串处理重复子串与旋转字符串。
- [ ] 能处理重复拼接后的跨边界子串匹配。
- [ ] 会用 stringstream 按格式读取日期等字符串。
- [ ] 会用 getline(ss, part, delimiter) 按分隔符切分字符串。
