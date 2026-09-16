class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum = 0;

        for (int x : target) {
            pq.push(x);
            sum += x;
        }

        while (true) {
            long long x = pq.top();
            pq.pop();

            long long rest = sum - x;

            if (x == 1 || rest == 1)
                return true;

            if (rest == 0 || x <= rest)
                return false;

            long long old = x % rest;

            if (old == 0)
                return false;

            pq.push(old);
            sum = rest + old;
        }
    }
};
