class Solution {
public:
    
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        vector<int> moves(sqrt(n));
        dp[0] = INT_MAX;
        for (int i = 1; i <= sqrt(n); i++) {
            int x = pow(i, 2);
            dp[x] = 1;
            moves[i-1] = x;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < moves.size() && moves[j] < i; j++) {
                dp[i] = min(dp[i], dp[i-moves[j]]+1);
            } 
        }
        return dp.back();
    }
    
};
