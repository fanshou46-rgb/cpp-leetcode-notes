class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // 左右各加一个高度为 0 的哨兵
        vector<int> h(n + 2, 0);
        for (int i = 0; i < n; i++) {
            h[i + 1] = heights[i];
        }

        stack<int> st;
        st.push(0);

        int ans = 0;

        for (int i = 1; i < n + 2; i++) {
            while (h[i] < h[st.top()]) {
                int height = h[st.top()];
                st.pop();

                int width = i - st.top() - 1;
                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }
};
