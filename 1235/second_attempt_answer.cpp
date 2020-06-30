class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int,int>> v(startTime.size()+1);
        for (int i = 1; i < startTime.size()+1; i++)
            v[i] = {endTime[i-1], startTime[i-1], profit[i-1]};
        v[0] = {0, 0, 0};
        sort(v.begin(), v.end());
        vector<int> dp(startTime.size()+1, 0);
        int res = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = get<2>(v[i]);
            for (int j = i-1; j >= 0; j--) {
                dp[i] = max(dp[j], dp[i]);
                if (get<0>(v[j]) <= get<1>(v[i])) {
                    dp[i] = max(dp[i], dp[j]+get<2>(v[i]));
                    break;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
