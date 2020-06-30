class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto dp = triangle;
        for (int i = 1; i < dp.size(); i++)
            for (int j = 0; j < dp[i].size(); j++) {
                if (j < dp[i].size()-1 && j > 0)
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                else if (j < dp[i].size()-1)
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                else if (j > 0)
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j];
            }
        int res = dp.back()[0];
        for (auto& x : dp.back()) res = min(res, x);
        return res;
    }
};
