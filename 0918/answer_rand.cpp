class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans = A[0], n = A.size();
        for (int test = 0; test < 100; test++) {
            int start = rand() % n, cur = A[start];
            for (int i = (start+1)%n, j = 1; j < n; j++, i = (i+1)%n) {
                if (cur < 0) {
                    cur = 0;
                }
                cur += A[i];
                ans = max(cur, ans);
            }
        }
        return ans;
    }
};
