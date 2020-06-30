class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix = matrix;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] += i > 0 ? prefix[i-1][j] : 0;
                prefix[i][j] += j > 0 ? prefix[i][j-1] : 0;
                prefix[i][j] -= i > 0 && j > 0 ? prefix[i-1][j-1] : 0;
                for (int r = 0; r <= i; r++) {
                    for (int c = 0; c <= j; c++) {
                        int sum = prefix[i][j];
                        sum -= c > 0 ? prefix[i][c-1] : 0;
                        sum -= r > 0 ? prefix[r-1][j] : 0;
                        if (r > 0 && c > 0)
                            sum += prefix[r-1][c-1];
                        if (sum == target)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};
