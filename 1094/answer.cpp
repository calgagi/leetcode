class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int MAX_N = 1000 + 5;
        int pre[MAX_N];
        memset(pre, 0, sizeof(pre));
        for (auto& v : trips) {
            pre[v[1]] += v[0];
            pre[v[2]] -= v[0];
        }
        long long so_far = 0;
        for (int i = 0; i < MAX_N; i++) {
            so_far += pre[i];
            if (so_far > capacity) return false;
        }
        return true;
    }
};
