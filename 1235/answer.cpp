class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int,int>> a(startTime.size()+1);
        a[0] = {0, 0, 0};
        for (int i = 1; i <= startTime.size(); i++)
            a[i] = {endTime[i-1], startTime[i-1], profit[i-1]};
        sort(a.begin(), a.end());
        vector<int> dp(a.size(), 0);
        int res = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(dp[i-1], get<2>(a[i]));
            for (int j = i-1; j >= 0; j--) {
                if (get<0>(a[j]) <= get<1>(a[i])) {
                    dp[i] = max(dp[i], dp[j] + get<2>(a[i]));
                    break;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
