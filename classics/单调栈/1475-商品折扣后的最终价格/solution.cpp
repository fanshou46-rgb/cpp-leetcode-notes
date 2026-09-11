class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans = prices;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int j = st.top();
                st.pop();
                ans[j] = prices[j] - prices[i];
            }
            st.push(i);
        }

        return ans;
    }
};
