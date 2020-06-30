class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n+2, 0), dp2(n+2, 0);
        if (nums.size() == 1) return nums[0];
        for (int i = 2; i < n+1; i++) {
            dp[i] = max(dp[i-2]+nums[i-2], dp[i-1]); 
        }
        for (int i = 3; i < n+2; i++) {
            dp2[i] = max(dp2[i-2]+nums[i-2], dp2[i-1]);
        }
        return max(dp[n], dp2[n+1]);
    }
};
