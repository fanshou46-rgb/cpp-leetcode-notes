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

## 三、遍历链表

~~~cpp
ListNode* cur = head;

while (cur != nullptr) {
    cout << cur->val << endl;
    cur = cur->next;
}
~~~

核心：

~~~text
cur 指向当前节点
cur = cur->next 进入下一个节点
nullptr 表示链表结束
~~~

## 四、插入节点

已知节点 cur，要在它后面插入 newNode：

~~~cpp
newNode->next = cur->next;
cur->next = newNode;
~~~

顺序不能随便反，否则可能丢失原来的后半段链表。

## 五、删除节点

已知 prev 是待删除节点的前一个节点：

~~~cpp
ListNode* del = prev->next;
prev->next = del->next;
delete del;
~~~

本质是让前一个节点直接跳过待删除节点。

## 六、为什么常用 dummy 虚拟头节点

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

这样头节点和中间节点可以使用相同逻辑。

## 七、常见链表题型

- 遍历、查找、计数。
- 删除指定节点。
- 插入节点。
- 反转链表。
- 合并两个有序链表。
- 快慢指针：找中点、判断环。
- 双指针：删除倒数第 k 个节点。

## 八、复杂度

| 操作 | 单链表 |
| --- | --- |
| 访问第 k 个元素 | O(n) |
| 查找某个值 | O(n) |
| 已知位置后的插入 | O(1) |
| 已知前驱后的删除 | O(1) |

链表题最重要的不是背代码，而是随时明确：

~~~text
当前指针指向谁？
修改 next 后，会不会把后面的链表弄丢？
head 会不会发生变化？
~~~
