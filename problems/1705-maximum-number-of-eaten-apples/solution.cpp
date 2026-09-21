class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        int cnt = 0;
        int i = 0;

        while (i < apples.size() || !q.empty()) {
            if (i < apples.size() && apples[i] > 0) {
                q.push({i + days[i], apples[i]});
            }

            while (!q.empty() && q.top().first <= i) {
                q.pop();
            }

            if (!q.empty()) {
                auto [expire, num] = q.top();
                q.pop();

                cnt++;
                num--;

                if (num > 0) {
                    q.push({expire, num});
                }
            }

            i++;
        }

        return cnt;
    }
};
