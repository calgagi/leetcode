class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)  {
        // 6D dp?? I think so :)
        // Identical to coin problem
        for (int i = 0; i < special.size(); i++) {
            while (special[i].size() < 7)
                special[i].insert(special[i].end()-1, 0);
        }
        while (needs.size() != 6) needs.push_back(0);
        vector<vector<int>> prices(6, vector<int>(6, 0));
        for (int i = 0; i < price.size(); i++) {
            prices[i][i] = 1;
            prices[i].push_back(price[i]);
            special.push_back(prices[i]);
        }
        int dp[7][7][7][7][7][7];
        for (int a = 0; a < 7; a++)
            for (int b = 0; b < 7; b++)
                for (int c = 0; c < 7; c++)
                    for (int d = 0; d < 7; d++)
                        for (int e = 0; e < 7; e++)
                            for (int f = 0; f < 7; f++)
                                dp[a][b][c][d][e][f] = INT_MAX;
        dp[0][0][0][0][0][0] = 0;
        for (int f = 0; f <= needs[5]; f++)
           for (int e = 0; e <= needs[4]; e++)
               for (int d = 0; d <= needs[3]; d++)
                   for (int c = 0; c <= needs[2]; c++)
                       for (int b = 0; b <= needs[1]; b++)
                           for (int a = 0; a <= needs[0]; a++) {
                               if (dp[a][b][c][d][e][f] == INT_MAX) continue;
                               for (int i = 0; i < special.size(); i++) {
                                   vector<int> &s = special[i];
                                   if (a+s[0] < 7 && b+s[1] < 7 && c+s[2] < 7 && d+s[3] < 7 && e+s[4] < 7 && f+s[5] < 7)
                                       dp[a+s[0]][b+s[1]][c+s[2]][d+s[3]][e+s[4]][f+s[5]] = min(dp[a+s[0]][b+s[1]][c+s[2]][d+s[3]][e+s[4]][f+s[5]], dp[a][b][c][d][e][f] + s.back());
                               }
                           }
        return dp[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]][needs[5]];
    }
};
