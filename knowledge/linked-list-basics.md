# C++ 链表基础

链表由一个个节点组成。节点在内存中不要求连续，每个节点通过指针保存下一个节点的位置。

## 一、节点结构

~~~cpp
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};
~~~

一个节点主要包含两部分：

- val：当前节点保存的数据。
- next：指向下一个节点的指针。

如果 next == nullptr，说明当前节点是链表最后一个节点。

## 二、链表和数组的区别

数组通常连续存储，可以通过下标 O(1) 访问任意元素。

链表不能直接通过下标跳到第 k 个元素，必须从头节点沿 next 一步步走，因此随机访问是 O(n)。

链表的优势是：如果已经拿到了要操作位置附近的节点，插入和删除只需要修改指针，可以做到 O(1)。

## 三、创建与尾插

创建节点：

~~~cpp
ListNode* node = new ListNode(x);
~~~

如果维护尾指针 tail，尾插可以直接：

~~~cpp
tail->next = node;
tail = node;
~~~

第一次插入时要特别处理 head，或者借助 dummy 节点统一逻辑。

## 四、遍历与查找

~~~cpp
ListNode* cur = head;

while (cur != nullptr) {
    cout << cur->val << endl;
    cur = cur->next;
}
~~~

查找第 k 个节点本质也是从头向后走，因此通常是 O(n)。

核心：

~~~text
cur 指向当前节点
cur = cur->next 进入下一个节点
nullptr 表示链表结束
~~~

## 五、插入节点

已知节点 cur，要在它后面插入 newNode：

~~~cpp
newNode->next = cur->next;
cur->next = newNode;
~~~

顺序不能随便反，否则可能丢失原来的后半段链表。

## 六、删除节点

已知 prev 是待删除节点的前一个节点：

~~~cpp
ListNode* del = prev->next;
prev->next = del->next;
delete del;
~~~

本质是让前一个节点直接跳过待删除节点。

## 七、反转链表

反转时最重要的是：修改 `cur->next` 之前，先保存原来的后继节点。

~~~cpp
ListNode* prev = nullptr;
ListNode* cur = head;

while (cur != nullptr) {
    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
}

return prev;
~~~

三个指针的职责：

~~~text
prev：已经反转好的部分
cur：当前正在处理的节点
next：暂存原链表后继，防止断链
~~~

## 八、dummy 虚拟头节点

如果删除的是第一个真实节点，head 本身会变化，容易产生特殊情况。

可以创建虚拟头节点：

~~~cpp
ListNode dummy(0);
dummy.next = head;
~~~

以后统一从 dummy 开始处理，最后返回：

~~~cpp
return dummy.next;
~~~

适合：

- 删除头节点。
- 在头部插入。
- 删除倒数第 k 个节点。
- 需要统一“前驱节点”逻辑的题目。

## 九、快慢指针

### 找链表中点

~~~cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
~~~

fast 走两步、slow 走一步，fast 到末尾时 slow 到中间附近。

### 判断是否有环

如果存在环，快指针最终会在环内追上慢指针。

~~~cpp
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
        return true;
    }
}
~~~

## 十、循环单链表判空

### 不带头结点

空链表：

~~~cpp
L == nullptr
~~~

### 带头结点

空表仍然保留头结点，头结点的 next 指回自身：

~~~cpp
L->next == L
~~~

注意区分：

- `L`：头指针保存的地址。
- `L->next`：头结点中的 next。
- `&L`：变量 L 自己的地址。

## 十一、常见链表题型

- 遍历、查找、计数。
- 删除指定节点。
- 插入节点。
- 反转链表。
- 合并两个有序链表。
- 快慢指针：找中点、判断环。
- 双指针：删除倒数第 k 个节点。
- 有序链表去重。

例如 83「删除排序链表中的重复元素」，因为重复值相邻，可直接比较：

~~~cpp
if (cur->val == cur->next->val) {
    cur->next = cur->next->next;
} else {
    cur = cur->next;
}
~~~

## 十二、复杂度

| 操作 | 单链表 |
| --- | --- |
| 访问第 k 个元素 | O(n) |
| 查找某个值 | O(n) |
| 已知位置后的插入 | O(1) |
| 已知前驱后的删除 | O(1) |
| 完整反转 | O(n) |

链表题最重要的不是背代码，而是随时明确：

~~~text
当前指针指向谁？
修改 next 后，会不会把后面的链表弄丢？
head 会不会发生变化？
~~~
