class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r = 0;
        int row, col;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == 'R') { row = i; col = j; }
        for (int i = row+1; i < board.size(); i++) {
            if (board[i][col] == 'p') {
                r++;
                break;
            } else if (board[i][col] == 'B') break;
        }
        for (int i = row-1; i >= 0; i--) {
            if (board[i][col] == 'p') {
                r++;
                break;
            } else if (board[i][col] == 'B') break;
        }
        for (int i = col-1; i >= 0; i--) {
            if (board[row][i] == 'p') {
                r++;
                break;
            } else if (board[row][i] == 'B') break;
        }
        for (int i = col+1; i < board[0].size(); i++) {
            if (board[row][i] == 'p') {
                r++;
                break;
            } else if (board[row][i] == 'B') break;
        }
        return r;       
    }
};
