class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 1));
        int r = nums[0];
        dp[0][0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j >= 0; j--) {
                dp[i][j] = dp[i-1][j] * nums[i];
                r = max(r, dp[i][j]);
            }
        }
        return r;
    }
};
