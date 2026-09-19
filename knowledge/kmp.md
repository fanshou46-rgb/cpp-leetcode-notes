# KMP 字符串匹配

> 用于在线性时间内判断模式串是否出现在文本串中。核心：文本串指针不回退，模式串利用自身前后缀信息跳转。

## 一、基本问题

给定：

```cpp
string s; // 文本串
string p; // 模式串
```

目标：寻找 `p` 在 `s` 中第一次出现的位置。

暴力匹配失配后常会重新比较已经比较过的字符，最坏可达到 `O(nm)`。

KMP 通过预处理模式串，构造 `lps` 数组，将匹配复杂度降为 `O(n+m)`。

---

## 二、LPS 是什么

LPS：Longest Proper Prefix which is also Suffix。

`lps[i]` 表示：

> 模式串 `p[0...i]` 中，最长相等真前缀和后缀的长度。

“真前缀”不能包含整个字符串本身。

例如：

```text
"ababa"

前缀：a, ab, aba, abab
后缀：a, ba, aba, baba

最长相等项：aba
长度：3
```

所以：

```text
"ababa" 的 LPS = 3
```

对于：

```text
p   = a b a b a c a
下标  0 1 2 3 4 5 6
lps = 0 0 1 2 3 0 1
```

---

## 三、构造 LPS

使用：

```cpp
int i = 1;   // 当前计算的位置
int len = 0; // 当前相等前后缀长度
```

如果：

```cpp
p[i] == p[len]
```

说明前后缀可以继续延长：

```cpp
len++;
lps[i] = len;
i++;
```

如果失配，但 `len > 0`：

```cpp
len = lps[len - 1];
```

不要直接把 `len` 清零，因为较长前后缀失败后，还可能存在较短的可用前后缀。

如果失配且 `len == 0`：

```cpp
lps[i] = 0;
i++;
```

完整代码：

```cpp
vector<int> buildLPS(const string& p) {
    vector<int> lps(p.size(), 0);

    int i = 1;
    int len = 0;

    while (i < p.size()) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len > 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}
```

---

## 四、KMP 匹配过程

使用：

```cpp
int i = 0; // 文本串
int j = 0; // 模式串
```

### 1. 字符相等

```cpp
if (s[i] == p[j]) {
    i++;
    j++;
}
```

### 2. 失配且 j > 0

```cpp
j = lps[j - 1];
```

关键：

```text
i 不回退
```

因为前面已经比较成功的内容中，有一部分后缀与模式串前缀相同，可以直接复用。

### 3. 失配且 j == 0

说明模式串第一个字符都无法匹配：

```cpp
i++;
```

---

## 五、为什么是 lps[j - 1]

当 `s[i] != p[j]` 时，说明：

```text
p[0 ... j-1]
```

已经匹配成功，只有 `p[j]` 失配。

因此我们研究的是“已经匹配成功部分”的最长相等前后缀，所以看：

```cpp
lps[j - 1]
```

而不是 `lps[j]`。

例如：

```text
已匹配：ababa
最长相等前后缀：aba
长度：3
```

于是：

```cpp
j = 3;
```

文本串当前位置 `i` 保持不变，再与新的 `p[j]` 比较。

---

## 六、完整 KMP 模板

```cpp
int kmp(const string& s, const string& p) {
    if (p.empty())
        return 0;

    vector<int> lps = buildLPS(p);

    int i = 0;
    int j = 0;

    while (i < s.size()) {
        if (s[i] == p[j]) {
            i++;
            j++;

            if (j == p.size())
                return i - j;
        }
        else if (j > 0) {
            j = lps[j - 1];
        }
        else {
            i++;
        }
    }

    return -1;
}
```

---

## 七、最重要的两句

构造 LPS 时：

```cpp
len = lps[len - 1];
```

正式匹配时：

```cpp
j = lps[j - 1];
```

本质完全相同：

> 当前较长匹配失败，就尝试当前已匹配部分的更短相等前后缀。

---

## 八、复杂度

设：

```text
n = s.size()
m = p.size()
```

则：

```text
构造 LPS：O(m)
匹配：    O(n)
总时间：  O(n + m)
空间：    O(m)
```

---

## 九、与重复字符串匹配结合

对于无限重复字符串：

```text
a = "abcd"
abcdabcdabcdabcd...
```

第 `i` 个字符可以直接写成：

```cpp
a[i % a.size()]
```

所以在某些重复字符串匹配题里，可以在“虚拟重复字符串”上跑 KMP，而不必真的反复构造长字符串。

---

## 十、复习清单

- [ ] 能解释 LPS 表示什么。
- [ ] 能手算 `ababaca` 的 LPS：`0 0 1 2 3 0 1`。
- [ ] 能解释为什么失配时文本指针 `i` 不回退。
- [ ] 能解释为什么使用 `lps[j - 1]`。
- [ ] 能独立写出 LPS 构造。
- [ ] 能独立写出 KMP 匹配模板。
- [ ] 知道 KMP 时间复杂度为 `O(n+m)`。
