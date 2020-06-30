class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) return 0;
        vector<vector<double>> a(query_row+1, vector<double>(query_row+2, 0));
        a[0][1] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = 1; j < i+2; j++) {
                if (a[i-1][j-1]-1 > 0)
                    a[i][j] += (a[i-1][j-1]-1)/(double)2;
                if (a[i-1][j]-1 > 0)
                    a[i][j] += (a[i-1][j]-1)/(double)2;
                if (a[i][j] < 1.0) 
                    a[i][j] *= -1;
            }
        }
        return min(1.0, abs(a[query_row][query_glass+1]));
    }
};
