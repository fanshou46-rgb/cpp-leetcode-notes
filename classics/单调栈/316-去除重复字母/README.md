# 316. 去除重复字母

## 核心知识

- 单调栈
- 贪心
- 字符频次
- 去重状态

## 目标

结果需要同时满足：

1. 每个字母只出现一次；
2. 在所有合法结果中字典序最小。

## 状态

```cpp
vector<int> remain(26, 0);   // 后面还剩多少个
vector<bool> used(26, false); // 是否已经在答案中
string st;                    // 当作栈使用
```

## 贪心弹栈条件

如果：

```cpp
st.back() > c
```

说明把更小的 `c` 提前有利于字典序。

但只有当栈顶字符后面还会再次出现时，才能把它弹掉：

```cpp
remain[st.back() - 'a'] > 0
```

因此：

```cpp
while (!st.empty() &&
       st.back() > c &&
       remain[st.back() - 'a'] > 0) {
    used[st.back() - 'a'] = false;
    st.pop_back();
}
```

如果当前字符已经在答案中：

```cpp
if (used[c - 'a'])
    continue;
```

## 复杂度

每个字符最多入栈一次、出栈一次：

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`，因为只维护 26 个字母状态
