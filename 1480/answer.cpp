class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            ans[i] = cur;
        }
        return ans;
    }
};
