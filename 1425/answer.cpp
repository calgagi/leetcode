class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = nums[0];
        priority_queue<pair<int,int>> q;
        q.push({0, INT_MAX});
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.top().second < i-k) {
                q.pop();
            }
            int m = q.top().first;
            ans = max(ans, m + nums[i]);
            q.push({nums[i]+m, i});
        }
        return ans;
    }
};
