# C++ 前缀和与前缀和取模

前缀和的核心是：把连续区间的和转换成两个前缀状态的差。

## 一、基本定义
定义 prefix[i] = nums[0] + ... + nums[i]。
区间 [l, r] 的和可以由两个前缀和相减得到。
为了统一处理 l = 0，可以使用长度 n + 1 的前缀数组：
~~~cpp
vector<long long> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}
~~~
此时 sum(l, r) = prefix[r + 1] - prefix[l]。

## 二、只需要累计量时可以滚动
如果只需要当前累计和、最大前缀和或最终总和，就不必创建完整数组。
例如 1732 找到最高海拔：
~~~cpp
int cur = 0;
int ans = 0;
for (int x : gain) {
    cur += x;
    ans = max(ans, cur);
}
~~~
空间复杂度可以降到 O(1)。

## 三、前缀和取模
如果连续子数组的和需要是 k 的倍数，设两个前缀和为 P_i、P_j。
当 P_i % k == P_j % k 时：
~~~text
(P_i - P_j) % k == 0
~~~
所以两个前缀和的余数相同，就意味着它们之间的连续区间和是 k 的倍数。

## 四、前缀和 + 哈希表
需要快速回答以前是否出现过某个余数时，可以使用：
~~~cpp
unordered_map<int, int> mp;
~~~
523 的典型模板：
~~~cpp
unordered_map<int, int> mp;
mp[0] = -1;
long long sum = 0;
for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int r = sum % k;
    if (mp.count(r)) {
        if (i - mp[r] >= 2) return true;
    } else {
        mp[r] = i;
    }
}
return false;
~~~
mp[0] = -1 表示数组开始之前存在一个空前缀。

## 五、1590 与 523 的区别
523 要找相同余数。
1590 要先求整个数组和的余数 need，再寻找目标余数：
~~~text
q = (r - need + p) % p
~~~
如果目标是最短区间，通常保存最近一次出现的位置；如果要最长区间或只判断是否存在，通常保存第一次出现的位置。

## 六、vector 还是 unordered_map
如果 key 是原数组下标 0 到 n-1，vector 很自然。
如果 key 的值域小而连续，例如 0 到 9，也可以用 vector 计数。
如果 key 的理论范围很大但实际只出现少量值，例如 sum % k 且 k 很大，就应该考虑 unordered_map。
核心不是数组不能做映射，而是数组要求 key 能作为合理的连续下标。

## 七、复杂度
典型前缀和 + 哈希表：时间平均 O(n)，空间 O(n)。

## 核心记忆
前缀和的价值不是必须创建一个数组，而是把区间问题转换成两个前缀状态之间的关系。