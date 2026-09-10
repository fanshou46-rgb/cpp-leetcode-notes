class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        int pre = 0;

        for (const auto& x : logs) {
            int p1 = x.find(':');
            int p2 = x.find(':', p1 + 1);

            int id = stoi(x.substr(0, p1));
            string type = x.substr(p1 + 1, p2 - p1 - 1);
            int time = stoi(x.substr(p2 + 1));

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += time - pre;
                }
                st.push(id);
                pre = time;
            } else {
                ans[st.top()] += time - pre + 1;
                st.pop();
                pre = time + 1;
            }
        }

        return ans;
    }
};
