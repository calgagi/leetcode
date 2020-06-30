class Solution {
public:
    vector<int> slices;
    int n;
    map<array<int,3>, int> dp;
    
    int dfs(int i, int j, int k, bool around) {
        if (j-i+1 < 2*k - 1) {
            return -1e9;
        }
        if (k == 1) {
            return *max_element(slices.begin()+i, slices.begin()+j+1);
        }
        if (dp[{i, j, k}] != 0) {
            return dp[{i, j, k}];
        }
        dp[{i, j, k}] = max(dfs(i+around, j-2, k-1, 0) + slices[j], dfs(i, j-1, k, 0));
        return dp[{i, j, k}];
    }
    
    int maxSizeSlices(vector<int>& slices) {
        n = slices.size();
        this->slices = slices;
        return dfs(0, n-1, n/3, 1);
    }
};
