# 636. 函数的独占时间

## 核心思想

调用栈的栈顶表示当前正在占用 CPU 的函数。除了栈，还需要一个 `pre` 变量记录上一段尚未结算时间的起点。

日志先解析为：

```text
id / type / time
```

可使用 `find + substr + stoi`。

遇到 `start`：

```cpp
if (!st.empty()) ans[st.top()] += time - pre;
st.push(id);
pre = time;
```

遇到 `end`：

```cpp
ans[st.top()] += time - pre + 1;
st.pop();
pre = time + 1;
```

`end` 时间戳本身仍属于当前函数，因此要加 1；结束后的下一段从 `time+1` 开始。

## 复杂度

- 时间复杂度：`O(m)`，`m` 为日志数量。
- 空间复杂度：`O(n)`，主要来自调用栈和答案数组。

## 可迁移知识

这题体现了栈在“嵌套调用关系”中的作用：不仅保存数据，还能表示当前层级和当前执行对象。
