# 1590. 使数组和能被 P 整除

## 核心知识

- 前缀和取模
- 目标余数
- 哈希表
- 最短子数组

## 核心关系

整个数组和的余数为：

```text
need = total % p
```

当前前缀余数为 `r` 时，要找之前的余数：

```text
target = (r - need + p) % p
```

如果这个余数出现过，就可以删除两位置之间的区间。

## 模板

```cpp
unordered_map<int, int> pos;
pos[0] = -1;

for (int i = 0; i < n; i++) {
    prefix = (prefix + nums[i]) % p;
    int r = prefix;
    int target = (r - need + p) % p;

    if (pos.count(target))
        ans = min(ans, i - pos[target]);

    pos[r] = i;
}
```

## 记忆点

目标是最短区间，因此同一余数保存最近一次出现的位置。

完整整理见：

- [problems/1590-make-sum-divisible-by-p](../../../problems/1590-make-sum-divisible-by-p/)
- [前缀和专题](../../../knowledge/prefix-sum.md)
