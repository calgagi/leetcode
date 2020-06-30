class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = 0, c = 0;
        bool way = true;
        if (matrix.size() == 0) return res;
        while (res.size() != matrix.size() * matrix[0].size()) {
            res.push_back(matrix[r][c]);
            if (way) {
                c++;
                r--;
            } else {
                c--;
                r++;
            }
            if (r == matrix.size()) {
                c += 2;
                r--;
                way = !way;
            } else if (c == matrix[0].size()) {
                r += 2;  
                c--;
                way = !way;
            } else if (r < 0) {
                r++;
                way = !way;
            } else if (c < 0) {
                c++;
                way = !way;
            }
        }
        return res;
    }
};
