class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> first;
        first[0] = -1;

        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r = sum % k;

            if (first.count(r)) {
                if (i - first[r] >= 2) {
                    return true;
                }
            } else {
                // 保留第一次出现的位置
                first[r] = i;
            }
        }

        return false;
    }
};
