class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
        int res = 0;
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                prefix[i][j] = mat[i-1][j-1] +
                               prefix[i-1][j] +
                               prefix[i][j-1] -
                               prefix[i-1][j-1];
                for (int k = 0; i-k > 0 && j-k > 0; k++)
                    if (prefix[i][j]-prefix[i-k-1][j]-prefix[i][j-k-1]+prefix[i-k-1][j-k-1] <= threshold) {
                        res = max(k+1, res);
                    } else break;
            }
        }
        return res;
    }
};
