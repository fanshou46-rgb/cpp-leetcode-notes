# 堆基础

## 1. 堆的核心

堆是一种完全二叉树结构，常用于快速获取当前最大值或最小值。

- 大根堆：父节点 >= 子节点，堆顶最大。
- 小根堆：父节点 <= 子节点，堆顶最小。

C++ 中常用 `priority_queue` 实现。

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

- `push(x)`：加入元素，O(log n)
- `pop()`：删除堆顶，O(log n)
- `top()`：访问堆顶，O(1)
- `empty()`：判断为空，O(1)

注意：`pop()` 只删除，不返回值。

## 3. pair 和 tuple

### pair

保存两个数据：
```cpp
pair<int,int>
```
访问：
```cpp
p.first
p.second
```

### tuple

保存多个数据：
```cpp
tuple<int,int,int>
```

例如：
```cpp
tuple<int,int,int> t={sum,i,j};
```
表示：
- 当前值 sum
- 第一个下标 i
- 第二个下标 j

访问：
```cpp
get<0>(t)
get<1>(t)
get<2>(t)
```

C++17 推荐：
```cpp
auto [sum,i,j]=t;
```

## 4. 大括号 {} 使用

`{}` 用于初始化对象。

例如：

```cpp
pair<int,int> p={1,2};

vector<int> v={1,2};

q.push({sum,i,j});
```

能否使用 `{}` 取决于容器保存的类型。

- `vector<vector<int>>` 中：`{1,2}` 会自动转换为 `vector<int>`。
- `priority_queue<tuple<int,int,int>>` 中：`{a,b,c}` 会自动构造成 tuple。

## 5. 堆常见模型

### 不断取最大

使用大根堆：

例如：1046 最后一块石头的重量。

### 不断取最小

使用小根堆：

例如：373 查找和最小的 K 对数字。

核心思想：

> 需要动态维护当前最大值/最小值，就考虑堆。
