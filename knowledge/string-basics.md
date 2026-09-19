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

访问 `front()`、`back()` 前应确保字符串非空。

## 二、查找 find

```cpp
size_t pos = s.find(':');
```

`find()` 返回的是目标第一次出现的位置下标，不是指针。若未找到，返回：

```cpp
string::npos
```

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

## 九、复习清单

- [ ] 会使用 `size / empty / front / back`。
- [ ] 知道 `find()` 返回位置下标，未找到时为 `string::npos`。
- [ ] 会使用 `substr(pos, len)`。
- [ ] 会使用 `stoi / stoll / to_string`。
- [ ] 知道 `isdigit()` 判断的是字符。
- [ ] 会用 `const auto&` 遍历字符串数组以避免复制。
- [ ] 能独立解析 `id:start/end:time` 格式字符串。
