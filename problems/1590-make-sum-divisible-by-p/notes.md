# 1590. 使数组和能被 P 整除

## 核心知识

- 前缀和取模
- 哈希表
- 目标余数
- 最短子数组

## 思路

设整个数组元素和对 `p` 的余数为：

```text
need = total % p
```

如果 `need == 0`，说明整个数组本来就能被 `p` 整除，直接返回 0。

否则需要删除一个子数组，使它的元素和对 `p` 的余数恰好为 `need`。

遍历到当前位置时，设当前前缀和余数为 `r`，希望找到之前的余数 `q`：

```text
(r - q + p) % p = need
```

因此：

```text
q = (r - need + p) % p
```

如果哈希表中存在这个 `q`，就得到一个可以删除的区间。

因为目标是最短区间，所以哈希表保存每个余数最近一次出现的位置。

## 核心模板

```cpp
unordered_map<int, int> pos;
pos[0] = -1;

long long prefix = 0;
int ans = nums.size();

for (int i = 0; i < nums.size(); i++) {
    prefix = (prefix + nums[i]) % p;
    int r = prefix;
    int target = (r - need + p) % p;

    if (pos.count(target)) {
        ans = min(ans, i - pos[target]);
    }

    pos[r] = i;
}
```

## 关键点

- 最短区间：保存最近一次位置。
- `pos[0] = -1` 表示数组开始前的空前缀。
- 最终不能删除整个数组，因此如果答案仍等于 `n`，返回 `-1`。

## 复杂度

- 时间复杂度：平均 `O(n)`
- 空间复杂度：`O(n)`
