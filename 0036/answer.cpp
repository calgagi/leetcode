class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int b[3][3][10] = {};
        for (int i = 0; i < board.size(); i++) {
            int h[10] = {}, v[10] = {};
            for (int j = 0; j < board.size(); j++) {
                int t = 0;
                if (board[j][i] != '.') {
                    v[board[j][i] - '0']++;
                    if (v[board[j][i] - '0'] > 1) return false;
                }
                if (board[i][j] == '.') continue;
                else t = board[i][j] - '0'; 
                h[t]++;
                b[i/3][j/3][t]++;
                if (b[i/3][j/3][t] > 1 || h[t] > 1) return false;
            }
        }
        return true;
    }
};
