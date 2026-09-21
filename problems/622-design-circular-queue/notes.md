# 622. 设计循环队列

## 核心

用固定长度数组实现 FIFO，并通过取模重复利用前面已经空出的空间。

推荐只维护：

```cpp
front
count
capacity
```

## 关键公式

下一个插入位置：

```cpp
(front + count) % capacity
```

当前队尾：

```cpp
(front + count - 1) % capacity
```

队首出队后：

```cpp
front = (front + 1) % capacity;
```

## 判断

```cpp
isEmpty(): count == 0
isFull():  count == capacity
```

## 易错点

- 构造函数中不要重新定义同名局部变量。
- `deQueue()` 移动的是 `front`。
- 数组下标前进要取模，否则到末尾会越界。
