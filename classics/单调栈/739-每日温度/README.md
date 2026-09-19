# 739. 每日温度

## 核心知识

- 单调栈
- 栈中保存下标
- 右边第一个更大的元素
- 摊还复杂度

## 思路

栈中保存“还没有找到下一个更高温度”的下标。

遍历到位置 `i` 时，如果：

```cpp
temperatures[i] > temperatures[st.top()]
```

说明当前位置就是栈顶位置右边第一个更高温度，因此：

```cpp
int j = st.top();
st.pop();
ans[j] = i - j;
```

一个当前温度可能同时解决多个之前的位置，所以使用 `while`。

## 核心模板

```cpp
for (int i = 0; i < n; i++) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int j = st.top();
        st.pop();
        ans[j] = i - j;
    }

    st.push(i);
}
```

## 复杂度

每个下标最多入栈一次、出栈一次：

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`
