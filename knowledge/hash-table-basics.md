# C++ 哈希表基础

哈希表的核心用途是：

> 根据 key 快速找到对应的数据，或快速判断某个 key 是否存在。

C++ 中刷题最常用的是 `unordered_map` 和 `unordered_set`。

## 一、unordered_map

~~~cpp
#include <unordered_map>

unordered_map<int, int> mp;
~~~

它保存 key-value 映射，例如：

~~~cpp
mp[5] = 10;
~~~

表示：

~~~text
key = 5
value = 10
~~~

同一个 key 只能对应一个当前 value，再次赋值会覆盖原值。

## 二、常用操作

### 插入或修改

~~~cpp
mp[x] = value;
~~~

### 查找

~~~cpp
if (mp.find(x) != mp.end()) {
    // x 存在
}
~~~

### 判断是否存在

~~~cpp
if (mp.count(x)) {
    // x 存在
}
~~~

### 删除

~~~cpp
mp.erase(x);
~~~

## 三、mp[x] 的注意点

如果 x 不存在：

~~~cpp
mp[x]
~~~

会自动创建这个 key，并给 value 一个默认值。

例如 `unordered_map<int, int>` 中默认值为 0。

因此只想判断 key 是否存在时，优先使用：

~~~cpp
mp.find(x) != mp.end()
~~~

或：

~~~cpp
mp.count(x)
~~~

不要随便用 `mp[x]` 做存在性判断。

## 四、unordered_map 和 map

| 容器 | 底层思想 | 是否有序 | 常见复杂度 |
| --- | --- | --- | --- |
| unordered_map | 哈希表 | 否 | 平均 O(1) |
| map | 平衡搜索树 | 按 key 有序 | O(log n) |

如果只关心快速查找，刷题中通常优先考虑 `unordered_map`。

如果需要 key 自动有序，再考虑 `map`。

## 五、哈希表为什么快

普通数组按下标访问很快，但 key 不一定能直接当下标。

哈希表通过哈希函数把 key 映射到某个位置：

~~~text
key
 ↓
hash(key)
 ↓
存储位置
~~~

理想情况下，可以接近 O(1) 完成查找、插入和删除。

不同 key 可能映射到相同位置，这叫哈希冲突，因此 O(1) 是平均复杂度，不是绝对最坏情况。

## 六、经典模型：两数之和

对于：

~~~text
nums[i] + nums[j] = target
~~~

扫描到 `nums[i]` 时：

~~~cpp
int need = target - nums[i];
~~~

如果 need 已经出现，就找到答案。

~~~cpp
unordered_map<int, int> mp;

for (int i = 0; i < nums.size(); i++) {
    int need = target - nums[i];

    if (mp.find(need) != mp.end()) {
        return {mp[need], i};
    }

    mp[nums[i]] = i;
}
~~~

为什么先查再存：

如果先存当前元素，某些情况下可能把当前下标和自己匹配。

## 七、常见使用场景

看到下面这些需求，可以想到哈希：

- 判断一个数是否出现过。
- 统计每个值出现次数。
- 建立“值 -> 下标”映射。
- 去重。
- 查找补数。
- 判断两个集合是否有对应关系。

计数模板：

~~~cpp
unordered_map<int, int> cnt;

for (int x : nums) {
    cnt[x]++;
}
~~~

## 八、复杂度

`unordered_map` 常见操作平均复杂度：

| 操作 | 平均复杂度 |
| --- | --- |
| 插入 | O(1) |
| 查找 | O(1) |
| 删除 | O(1) |

两数之和使用哈希表：

- 时间复杂度：平均 O(n)
- 空间复杂度：O(n)

核心思维：

> 用额外空间保存“已经见过的信息”，把后续查找从 O(n) 降到平均 O(1)。
