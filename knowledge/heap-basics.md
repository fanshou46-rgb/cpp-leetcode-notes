# 堆基础

## 1. 堆的核心

堆是一种完全二叉树，常用于动态维护当前最大值或最小值。

- 大根堆：父节点 >= 子节点，堆顶最大。
- 小根堆：父节点 <= 子节点，堆顶最小。

如果使用数组保存完全二叉树，下标从 0 开始：

```cpp
左孩子 = 2 * i + 1;
右孩子 = 2 * i + 2;
父节点 = (i - 1) / 2;
```

## 2. priority_queue

默认大根堆：

```cpp
priority_queue<int> pq;
```

小根堆：

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

常用操作：

| 操作 | 含义 | 复杂度 |
| --- | --- | --- |
| `push(x)` | 插入元素 | O(log n) |
| `pop()` | 删除堆顶 | O(log n) |
| `top()` | 查看堆顶 | O(1) |
| `empty()` | 判断为空 | O(1) |
| `size()` | 元素个数 | O(1) |

`pop()` 只删除，不返回值：

```cpp
int x = pq.top();
pq.pop();
```

## 3. pair

保存两个数据：

```cpp
pair<int,int> p = {a, b};
```

访问：

```cpp
p.first;
p.second;
```

`pair` 默认按字典序比较：先比较 `first`，相同时再比较 `second`。

小根堆：

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

## 4. tuple

当状态需要保存三个及以上数据时，可以使用：

```cpp
tuple<int,int,int>
```

例如：

```cpp
q.push({sum, i, j});
```

访问：

```cpp
get<0>(t);
get<1>(t);
get<2>(t);
```

C++17 推荐结构化绑定：

```cpp
auto [sum, i, j] = q.top();
```

`tuple` 也按字典序比较，因此：

```cpp
greater<tuple<int,int,int>>
```

可以直接构造小根堆。

## 5. 大括号 {}

`{}` 常用于初始化对象：

```cpp
pair<int,int> p = {1, 2};
vector<int> v = {1, 2};
tuple<int,int,int> t = {sum, i, j};
```

写：

```cpp
q.push({a, b, c});
```

时，先看容器中保存的元素类型。`{a,b,c}` 会被构造成那个类型。

## 6. 常见堆模型

### 不断取最大

使用大根堆。

代表题：1046「最后一块石头的重量」。

### 不断取最小

使用小根堆。

代表题：373「查找和最小的 K 对数字」。

### 每次取极值、修改后重新放回

代表题：1354「多次求和构造目标数组」。

1354 的逆向关键：

```cpp
rest = sum - x;
old = x % rest;
```

取模可以一次跳过多次重复减法。

### Top K

常见规律：

```text
找第 K 大 / 保留最大的 K 个
→ 维护大小为 K 的小根堆

找第 K 小 / 保留最小的 K 个
→ 维护大小为 K 的大根堆
```

## 7. 什么时候想到堆

看到这些信号时优先考虑：

- 反复获取当前最大值或最小值；
- 第 K 大 / 第 K 小；
- Top K；
- 动态加入元素，同时维护极值；
- 多个有序序列中不断取当前最小候选；
- 按优先级处理任务。

核心：

> 数据不断变化，但始终需要快速拿到当前最优元素时，考虑堆。
