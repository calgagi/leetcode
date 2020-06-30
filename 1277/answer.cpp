class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Prefix?
        vector<vector<int>> pre = matrix;
        int res = 0;

        for (int i = 0; i < pre.size(); i++) {
            for (int j = 0; j < pre[0].size(); j++) {
                pre[i][j] += i>0?pre[i-1][j]:0;
                pre[i][j] += j>0?pre[i][j-1]:0;
                pre[i][j] -= j>0&&i>0?pre[i-1][j-1]:0;
                if (matrix[i][j] == 1) {
                    for (int k = 0; i-k >= 0 && j-k >=0; k++) {
                        if (pre[i][j] - ((i-k>0?pre[i-k-1][j]:0) + (j-k>0?pre[i][j-k-1]:0)) + (i-k>0&&j-k>0?pre[i-k-1][j-k-1]:0) == (k+1)*(k+1)) {
                            res++;
                        } else break;
                    }
                }
            }
        }
        return res;
    }
};
