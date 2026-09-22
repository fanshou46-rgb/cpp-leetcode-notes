# C++ 算法刷题知识库

记录 LeetCode 练习、C++ 知识点与错题复盘，重在理解算法、分析复杂度和积累可迁移的解题方法。

## 学习记录

| 日期 | 学习主题 | 记录 |
| --- | --- | --- |
| 2026-09-09 | 数组、vector、计数、位运算 | [查看笔记](daily/2026-09-09.md) |
| 2026-09-10 | 二叉树、前缀和、原地标记、栈、字符串解析 | [查看笔记](daily/2026-09-10.md) |
| 2026-09-11 | 频次数组、状态恢复、单调栈 | [查看笔记](daily/2026-09-11.md) |
| 2026-09-13 | 单调栈、柱状图最大矩形、双 0 哨兵 | [查看笔记](daily/2026-09-13.md) |
| 2026-09-14 | 队列、循环模拟、双栈实现队列、摊还复杂度 | [查看笔记](daily/2026-09-14.md) |
| 2026-09-15 | 堆、priority_queue、pair、tuple | [查看笔记](knowledge/heap-basics.md) |
| 2026-09-16 | 堆逆向恢复、大小写判断 | [查看笔记](daily/2026-09-16.md) |
| 2026-09-17 | 字符串格式化、字符过滤、重复子串判断 | [查看笔记](daily/2026-09-17.md) |
| 2026-09-19 | 数组、单调栈、字符串匹配、旋转字符串、KMP | [查看笔记](daily/2026-09-19.md) |
| 2026-09-20 | 贪心、小根堆、最早过期优先、循环队列原理 | [查看笔记](daily/2026-09-20.md) |
| 2026-09-21 | 循环队列、短路求值、链表、stringstream 日期解析 | [查看笔记](daily/2026-09-21.md) |
| 2026-09-22 | 链表进阶、循环链表、存储结构、哈希表、两数之和 | [查看笔记](daily/2026-09-22.md) |

## 重点题目

- [84. 柱状图中最大的矩形](problems/84-largest-rectangle-in-histogram/)：单调栈、左右双 0 哨兵。
- [373. 查找和最小的 K 对数字](problems/373-k-smallest-pairs/)：小根堆、tuple、多路归并。
- [622. 设计循环队列](problems/622-design-circular-queue/)：数组、循环下标、front + count。
- [645. 错误的集合](problems/645-set-mismatch/)：计数、原地标记、位运算。
- [1046. 最后一块石头的重量](problems/1046-last-stone-weight/)：大根堆。
- [1354. 多次求和构造目标数组](problems/1354-construct-target-array-with-multiple-sums/)：大根堆、逆向思维、取模优化。
- [1705. 吃苹果的最大数目](problems/1705-maximum-number-of-eaten-apples/)：贪心、小根堆、最早过期优先。

## 知识专题

- [位运算](knowledge/bit-operations.md)：补码、Lowbit、位掩码与异或分组。
- [字符串基础](knowledge/string-basics.md)：find、string::npos、substr、旋转与重复拼接。
- [KMP 字符串匹配](knowledge/kmp.md)：LPS、失配跳转与 O(n+m) 匹配。
- [数组原地标记](knowledge/in-place-marking.md)：值到下标映射与正负号标记。
- [栈基础](knowledge/stack-basics.md)：基础操作、表达式求值与调用栈。
- [队列基础](knowledge/queue-basics.md)：FIFO、queue 基本操作、循环队列、模拟与 BFS。
- [链表基础](knowledge/linked-list-basics.md)：节点、next 指针、反转、dummy、快慢指针与循环链表。
- [哈希表基础](knowledge/hash-table-basics.md)：unordered_map、查找/计数、复杂度与两数之和模型。
- [单调栈](knowledge/monotonic-stack.md)：寻找左右第一个更大/更小元素与摊还复杂度。
- [堆基础](knowledge/heap-basics.md)：priority_queue、大小根堆、pair、tuple、最早截止优先与常见堆模型。
- [经典题精选](classics/README.md)：按知识类型整理值得反复复习的代表题。

## 记录原则

简单题记在 daily，重点题单独整理到 problems，通用知识归档到 knowledge，代表性经典题额外进入 classics。保留自己的思路、真正有价值的错误原因和复杂度分析；小笔误不作为错误复盘重点，也不以单次运行时间或内存排名作为唯一优化标准。
