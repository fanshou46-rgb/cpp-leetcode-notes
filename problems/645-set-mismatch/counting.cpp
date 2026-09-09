
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        // cnt[i] 表示数字 i 出现的次数
        vector<int> cnt(n + 1, 0);
        vector<int> ans(2);

        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 2) {
                ans[0] = i;  // 重复值
            }
            if (cnt[i] == 0) {
                ans[1] = i;  // 丢失值
            }
        }

        return ans;
    }
};
