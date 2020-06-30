class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = accumulate(nums.begin(), nums.end(), 0.0);
        if (n % 2 == 1) 
            return false;
        n /= 2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(n+1, 0));
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (nums[i-1] <= j)
                    dp[i][j] = max(dp[i-1][j-nums[i-1]]+nums[i-1], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return n == dp[nums.size()][n];
    }
};
