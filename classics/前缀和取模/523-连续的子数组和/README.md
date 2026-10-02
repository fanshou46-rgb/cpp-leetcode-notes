# 523. 连续的子数组和

## 核心知识

- 前缀和取模
- 相同余数
- 哈希表
- 长度约束

## 核心关系

如果：

```text
prefix[i] % k == prefix[j] % k
```

那么：

```text
(prefix[i] - prefix[j]) % k == 0
```

因此再次遇到相同余数时，只要两个位置之间至少相隔 2 个元素即可。

## 模板

```cpp
unordered_map<int, int> first;
first[0] = -1;

for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int r = sum % k;

    if (first.count(r)) {
        if (i - first[r] >= 2)
            return true;
    } else {
        first[r] = i;
    }
}
```

## 记忆点

与 1590 相比：

- 523 找相同余数。
- 1590 找目标余数。
- 523 保存第一次位置。
- 1590 保存最近一次位置。

完整整理见：

- [problems/523-continuous-subarray-sum](../../../problems/523-continuous-subarray-sum/)
- [前缀和专题](../../../knowledge/prefix-sum.md)
