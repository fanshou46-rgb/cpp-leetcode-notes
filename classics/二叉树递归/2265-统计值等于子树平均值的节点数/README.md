# LeetCode 2265：统计值等于子树平均值的节点数

## 核心思想

对于每个节点，需要知道当前子树的两个信息：

- 子树节点值总和 `sum`
- 子树节点数量 `count`

因此递归函数可以返回：

```cpp
pair<int, int>
```

约定：

```text
first  = sum
second = count
```

处理当前节点前，先递归得到左右子树的信息，因此这是典型的后序遍历：

```text
左子树 -> 右子树 -> 当前节点
```

递推关系：

```cpp
sum = leftSum + rightSum + root->val;
count = leftCount + rightCount + 1;
```

如果：

```cpp
sum / count == root->val
```

则当前节点满足条件。

## 结构化绑定

C++17 可以写成：

```cpp
auto [leftSum, leftCount] = dfs(root->left);
auto [rightSum, rightCount] = dfs(root->right);
```

相比 `first`、`second` 更直观。

## 复杂度

- 时间复杂度：`O(n)`，每个节点只访问一次
- 空间复杂度：`O(h)`，其中 `h` 为树高；最坏退化为 `O(n)`

## 可迁移思路

这道题代表一种非常常见的树形递归模式：

```text
先递归左右子树
-> 获取左右子树信息
-> 计算当前节点信息
-> 返回给父节点
```

可迁移到求子树大小、树高、平衡二叉树等问题。

## 代码

见 [solution.cpp](solution.cpp)。
