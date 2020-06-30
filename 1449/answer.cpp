class Solution {
public:    
    string comp(const string& x, const string& y) {
        if (x.length() == y.length()) {
            return (x < y ? y : x);
        }
        return (x.length() < y.length() ? y : x);
    }
    
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1, "");
        for (int i = 1; i < target+1; i++) {
            for (int j = 1; j < 10; j++) {
                if ((i-cost[j-1] > 0 && dp[i-cost[j-1]] != "") || i-cost[j-1] == 0) {
                    string z = dp[i-cost[j-1]];
                    z += (char) (j + '0');
                    dp[i] = comp(dp[i], z);
                }
            }
            //cout << dp[i] << endl;
        }
        return (dp[target] == "" ? "0" : dp[target]);
    }
};
