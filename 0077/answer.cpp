class Solution {
public:
    vector<vector<int>> r;
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> x;
        helper(x, 0, n, k);
        return r;
    }
    
    void helper(vector<int>& x, int i, int n, int k) {
        if (x.size() == k) {
            r.push_back(vector<int>(x.begin(), x.end()));
            return;
        }
        for (int j = i+1; j <= n; j++) {
            x.push_back(j);
            helper(x, j, n, k);
            x.erase(x.end()-1);
        }
        return;
    }
};
