class Solution {
public:
    const int MOD = 1e9 + 7;
    
    using ll = long long;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<ll,ll>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {efficiency[i], speed[i]};
        }
        sort(p.begin(), p.end(), greater<pair<ll,ll>>());
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        long long res = 0, sum_so_far = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (sum_so_far + p[i].second) * 1LL * p[i].first);
            pq.push(p[i].second);
            sum_so_far += p[i].second;
            if (pq.size() == k) {
                sum_so_far -= pq.top();
                pq.pop();
            }
        }
        return res % MOD;
    }
};
