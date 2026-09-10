class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;

        for (int i = 0; i < n; ++i) {
            diff ^= nums[i];
            diff ^= (i + 1);
        }

        int lowbit = diff & -diff;
        int a = 0, b = 0;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int y = i + 1;

            if (x & lowbit) a ^= x;
            else b ^= x;

            if (y & lowbit) a ^= y;
            else b ^= y;
        }

        for (int x : nums) {
            if (x == a) return {a, b};
        }

        return {b, a};
    }
};
