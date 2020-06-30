class Solution {
public:
    int countTriplets(vector<int>& A) {
        int res = 0;
        int n = A.size();
        unordered_map<int,int> dp;
        for (auto& x : A) dp[x]++;
        for (int step = 1; step < 3; step++) {
            unordered_map<int,int> temp;
            for (int i = 0; i < n; i++) {
                for (auto& it : dp) {
                    temp[(it.first & A[i])] += it.second;
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};
