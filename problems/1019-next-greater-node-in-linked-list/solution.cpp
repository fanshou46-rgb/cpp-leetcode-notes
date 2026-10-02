class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, int>> st;

        int index = 0;

        while (head != nullptr) {
            ans.push_back(0);

            while (!st.empty() && head->val > st.top().first) {
                int j = st.top().second;
                st.pop();
                ans[j] = head->val;
            }

            st.push({head->val, index});

            head = head->next;
            index++;
        }

        return ans;
    }
};
