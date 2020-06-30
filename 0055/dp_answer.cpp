class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        int far = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (!dp[i]) continue;
            for (int j = far+1; j <= i+nums[i]; j++)
                dp[j] = true;
            far = max(far, i+nums[i]); 
        }
        return dp.back();
    }
};
