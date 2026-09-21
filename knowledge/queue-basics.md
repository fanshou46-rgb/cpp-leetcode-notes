# 队列基础

## 1. 队列特点

Queue 遵循 FIFO（First In First Out）：先进先出。

- 队尾进入
- 队头删除

## 2. C++ 基本操作

```cpp
queue<int> q;
```

入队：

```cpp
q.push(x);
```

查看队头：

```cpp
q.front();
```

出队：

```cpp
q.pop();
```

注意：`pop()` 没有返回值，需要先保存 `front()`。

```cpp
int x = q.front();
q.pop();
```

其他：

```cpp
q.back();   // 队尾
q.empty();  // 是否为空
q.size();   // 元素数量
```

## 3. 复杂度

- push：O(1)
- pop：O(1)
- front：O(1)

## 4. 循环队列

循环队列使用固定长度数组，并让下标到达末尾后重新回到 0。

核心：

```cpp
index = (index + 1) % capacity;
```

例如容量为 3：

```text
0 → 1 → 2 → 0 → 1 → 2 ...
```

### 推荐状态

只维护：

```cpp
int front;      // 当前队首
int count;      // 当前元素数量
int capacity;   // 容量
```

下一个插入位置：

```cpp
(front + count) % capacity
```

当前队尾：

```cpp
(front + count - 1) % capacity
```

出队：

```cpp
front = (front + 1) % capacity;
count--;
```

判断：

```cpp
count == 0          // 空
count == capacity   // 满
```

代表题：622「设计循环队列」。

## 5. 常见应用

- BFS 广度优先搜索
- 二叉树层序遍历
- 循环模拟
- 滑动窗口

## 6. 刷题识别

遇到：

- 按顺序处理
- 处理后移动到队尾
- 模拟排队过程

优先考虑 queue。

代表题：

- 1700 无法吃午餐的学生数量
- 2073 买票需要的时间
- 232 用栈实现队列
- 622 设计循环队列
