class Solution {
public:   
    double knightProbability(int N, int K, int r, int c) {
        double dp[K+1][N][N];
        double moves[8][2] = {{2,1}, {1,2}, {-2,1}, {-1,2}, {-2,-1}, {-1,-2}, {2,-1}, {1,-2}};
        for (int i = 0; i <= K; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    dp[i][j][k] = i == 0 ? 1.0 : 0.0;
        for (int i = 1; i <= K; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    for (int m = 0; m < 8; m++) {
                        int row = j + moves[m][0];
                        int col = k + moves[m][1];
                        if (row < N && col < N && row >= 0 && col >= 0)
                            dp[i][j][k] += dp[i-1][row][col];
                    } 
                   
        return dp[K][r][c] / pow(8, K); 
    }
};
