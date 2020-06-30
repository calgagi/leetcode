class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pre = cardPoints;
        for (int i = 1; i < n; i++) {
            pre[i] += pre[i-1];
        }
        int sz = n-k-1;
        if (sz < 0) {
            return pre[n-1];
        }
        int ans = pre[sz];
        for (int i = 1; i+sz < n; i++) {
            ans = min(pre[i+sz]-pre[i-1], ans);
        }
        return pre[n-1]-ans;
    }
};
