class Solution {
public:
    const int D = -1e9;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, D));
        dp[0][0] = 0;
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = max({
                    dp[i-1][j-1]+nums1[i-1]*nums2[j-1],
                    nums1[i-1]*nums2[j-1],
                    dp[i-1][j],
                    dp[i][j-1]
                });
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[n1][n2];
    }
};
