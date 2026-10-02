class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) {
            total += x;
        }

        int need = total % p;
        if (need == 0) {
            return 0;
        }

        unordered_map<int, int> pos;
        pos[0] = -1;

        long long prefix = 0;
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;
            int r = prefix;
            int target = (r - need + p) % p;

            if (pos.count(target)) {
                ans = min(ans, i - pos[target]);
            }

            // 求最短区间，所以保存最近一次出现的位置
            pos[r] = i;
        }

        return ans == n ? -1 : ans;
    }
};
