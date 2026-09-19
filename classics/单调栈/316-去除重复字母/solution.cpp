class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> remain(26, 0);
        vector<bool> used(26, false);

        for (char c : s)
            remain[c - 'a']++;

        string st;

        for (char c : s) {
            int x = c - 'a';
            remain[x]--;

            if (used[x])
                continue;

            while (!st.empty() &&
                   st.back() > c &&
                   remain[st.back() - 'a'] > 0) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[x] = true;
        }

        return st;
    }
};
