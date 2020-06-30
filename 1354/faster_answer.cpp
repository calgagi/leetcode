class Solution {
public:
    bool isPossible(vector<int>& target) {
        using ll = long long;
        ll sum = 0;
        ll n = target.size();
        priority_queue<ll> q;
        for (int i = 0; i < n; i++) {
            q.push(target[i]);
            sum += target[i];
        }
        while (sum > n) {
            ll b = q.top();
            q.pop();
            ll rest = sum - b;
            ll prev = b - rest;
            if (prev <= 0) {
                return 0;
            }
            b %= rest;
            sum = rest + b;
            q.push(b);
        }
        return 1;
    }
};
