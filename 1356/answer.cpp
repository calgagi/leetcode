class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> x;
        for (auto& a : arr) {
            x.push_back({__builtin_popcount(a), a});
        }
        sort(x.begin(), x.end());
        vector<int> res;
        for (auto& p : x) {
            res.push_back(p.second);
        }
        return res;
    }
};
