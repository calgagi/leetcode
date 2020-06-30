class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int *c = new int[10001];  
        memset(c, 0, sizeof(int)*10001);
        for (int i = 0; i < nums.size(); i++) {
            c[nums[i]]++;
        }
        int *dp = new int[10001];
        memset(dp, 0, sizeof(int)*10001);
        dp[0] = 0;
        for (int i = 2; i < 10001; i++) {
            dp[i] = max(dp[i-2] + c[i-1]*(i-1), dp[i-1]);
        }
        return dp[10000];
    }
};
