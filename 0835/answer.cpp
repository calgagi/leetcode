class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur1 = 0, cur2 = 0;
                for (int k = 0; i+k < n; k++) {
                    for (int l = 0; j+l < m; l++) {
                        if (A[k][l] == 1 && B[i+k][j+l] == 1) cur1++;
                        if (A[i+k][j+l] == 1 && B[k][l] == 1) cur2++;
                    }
                }
                res = max({cur1, cur2, res});
            }
        }
        return res;
    }
};
