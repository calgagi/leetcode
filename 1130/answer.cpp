class Solution {
public:
    unordered_map<int, unordered_map<int,pair<int,int>>> dp;
    
    pair<int,int> helper(vector<int>& arr, int l, int r) {
        if (dp.count(l) && dp[l].count(r)) return dp[l][r];
        if (l == r) return {0, arr[l]};
        pair<int,int> res = {INT_MAX, INT_MAX};
        for (int i = l; i < r; i++) {
            auto left = helper(arr, l, i);
            auto right = helper(arr, i+1, r);
            if (left.first + right.first + (left.second * right.second) < res.first) {
                res = make_pair(left.first + right.first + (left.second * right.second), max(left.second, right.second));
            }
        }
        dp[l][r] = res;
        return res;
    }
    
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        auto p = helper(arr, 0, n-1);
        return p.first;
    }
};
