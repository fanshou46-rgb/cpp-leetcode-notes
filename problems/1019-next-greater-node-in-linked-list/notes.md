# 1019. 链表中的下一个更大节点

## 核心知识

- 单调栈
- 链表遍历
- 节点值 + 下标
- 右侧第一个严格更大的元素

## 思路

题目要求为每个链表节点找到右侧第一个严格更大的节点。

遍历链表时，当前节点负责解决前面还没有找到答案、并且值比当前节点小的节点。

栈中保存：

```text
节点值 + 节点下标
```

并让栈中的值保持单调递减。

如果当前值大于栈顶值：

```cpp
cur->val > st.top().first
```

说明当前节点就是栈顶节点右侧第一个更大的节点，因此不断弹栈并填写答案。

## 核心模板

```cpp
stack<pair<int, int>> st;
vector<int> ans;
int index = 0;

while (head != nullptr) {
    ans.push_back(0);

    while (!st.empty() && head->val > st.top().first) {
        int j = st.top().second;
        st.pop();
        ans[j] = head->val;
    }

    st.push({head->val, index});
    head = head->next;
    index++;
}
```

遍历结束后仍留在栈中的节点，右侧不存在更大的值，因此答案保持为 0。

## 与 739 每日温度的关系

两题的模型相同：

```text
当前元素解决前面等待“下一个更大元素”的位置
```

区别只是 1019 的输入来自链表，因此需要自己维护下标。

## 复杂度

每个节点最多入栈一次、出栈一次：

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`
