class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n2 = sqrt(num+2);
        num += 2;
        vector<pair<int,int>> f;
        for (int i = 1; i <= n2; i++) {
            if (num % i == 0) {
                f.push_back({i, num / i});
            }
            if ((num-1) % i == 0) {
                f.push_back({i, (num-1) / i});
            }
        }
        vector<int> m = {num, 1};
        for (int i = 0; i < (int) f.size(); i++) {
            if (abs(f[i].first - f[i].second) < abs(m[0] - m[1])) {
                m = {f[i].first, f[i].second};
            }
        }
        return m;
    }
};
