class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> c(n);
        for (int i = n-1; i >= 0; i--) {
            int m = nums[i].size();
            int sz = i+m;
            for (int j = c.size(); j <= sz; j++) {
                c.push_back(vector<int>());
            }
            for (int j = 0; j < m; j++) {
                c[i+j].push_back(nums[i][j]);
            }
        }
        for (auto& v : c) {
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};
