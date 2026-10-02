# 1019. 链表中的下一个更大节点

## 核心知识

- 单调递减栈
- 右边第一个更大的元素
- 链表转下标
- 摊还复杂度

## 思路

栈中保存还没有找到下一个更大节点的：

```text
节点值 + 节点下标
```

当前节点值大于栈顶值时，当前节点就是栈顶节点右侧第一个严格更大的节点：

```cpp
while (!st.empty() && head->val > st.top().first) {
    int j = st.top().second;
    st.pop();
    ans[j] = head->val;
}
```

因为输入是链表，没有天然数组下标，所以遍历时自己维护 `index`。

## 记忆点

这题与 739「每日温度」属于同一个模型：当前元素负责解决前面等待下一个更大元素的位置。

完整整理见：

- [problems/1019-next-greater-node-in-linked-list](../../../problems/1019-next-greater-node-in-linked-list/)
- [单调栈专题](../../../knowledge/monotonic-stack.md)
