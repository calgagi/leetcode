class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        int max_reach = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] == false) return false;
            int prev = max_reach;
            max_reach = max(max_reach, nums[i]+i);
            for (int j = prev+1; j <= max_reach; j++) {
                if (j == dp.size()-1) return true;
                dp[j] = true;
            }
        }
        return dp.back();
    }
};
