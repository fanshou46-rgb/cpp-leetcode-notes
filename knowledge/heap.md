# 堆（Heap）

## 1. 基本概念

堆是一种特殊的完全二叉树，常用于快速获取最大值或最小值。

- 大根堆：父节点 >= 子节点，堆顶最大
- 小根堆：父节点 <= 子节点，堆顶最小

C++ 中使用 `priority_queue` 实现。

---

## 2. priority_queue 基本操作

```cpp
priority_queue<int> q; // 默认大根堆

q.push(x);      // 插入元素
q.top();        // 查看堆顶
q.pop();        // 删除堆顶（无返回值）
q.size();
q.empty();
```

注意：
`pop()` 只删除元素，不返回值，需要提前保存：

```cpp
int x=q.top();
q.pop();
```

---

## 3. 小根堆

```cpp
priority_queue<int, vector<int>, greater<int>> q;
```

---

## 4. pair 与堆

pair 默认按照字典序比较：

```cpp
pair<int,int> p;
```

比较规则：
1. 先比较 first
2. first 相同比较 second

小根堆：

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
```

---

## 5. tuple

tuple 可以保存多个不同类型的数据。

```cpp
#include <tuple>

tuple<int,int,int> t;

q.push({sum,i,j});
```

访问：

```cpp
auto [sum,i,j]=q.top();
```

---

## 6. 经典题

### 1046 最后一块石头的重量

思路：
- 石头重量最大优先处理
- 使用大根堆
- 每次取两个最大值碰撞

复杂度：O(nlogn)

---

### 373 查找和最小的 K 对数字

思路：
- 小根堆维护当前最小组合
- 每次取最小值
- 推入同一行的下一个组合

复杂度：O(klogn)

---

### 1354 多次求和构造目标数组

思路：
- 逆向考虑
- 最大值一定来自最后一次操作
- 用大根堆维护最大元素
- 用总和 sum 快速计算之前的值

关键：
```cpp
prev = max % (sum-max)
```

避免重复减法。

---

## 堆适用场景

看到以下关键词考虑堆：

- 最大/最小的 K 个
- 第 K 大/小
- 动态维护最大值最小值
- 优先处理某些元素
