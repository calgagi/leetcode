class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1 || matrix[0].size() < 1) {
            return false;
        }
        int col = matrix[0].size()-1, row = 0;
        while (row < matrix.size() && col >= 0) {
            if (target == matrix[row][col]){
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};
