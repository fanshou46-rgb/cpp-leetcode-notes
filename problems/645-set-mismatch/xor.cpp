
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;

        // 正常数字成对抵消
        // diff = duplicate ^ missing
        for (int i = 0; i < n; i++) {
            diff ^= nums[i];
            diff ^= (i + 1);
        }

        // 提取两个目标数字不同的最低二进制位
        int lowbit = diff & -diff;

        int a = 0, b = 0;

        // 实际数组和正确集合使用相同规则分组
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int y = i + 1;

            if (x & lowbit) {
                a ^= x;
            } else {
                b ^= x;
            }

            if (y & lowbit) {
                a ^= y;
            } else {
                b ^= y;
            }
        }

        // a、b 是两个候选值，判断谁是重复值
        for (int x : nums) {
            if (x == a) {
                return {a, b};
            }
        }

        return {b, a};
    }
};
