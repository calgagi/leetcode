class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        vector<vector<int>> n(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 1) {
                    if (i > 0) {
                        n[i-1][j]++;
                        if (j > 0) {
                            n[i-1][j-1]++;
                        }
                        if (j+1 < board[0].size()) {
                            n[i-1][j+1]++;
                        }
                    }
                    if (i+1 < board.size()) {
                        n[i+1][j]++;
                        if (j > 0) {
                            n[i+1][j-1]++;
                        }
                        if (j+1 < board[0].size()) {
                            n[i+1][j+1]++;
                        }
                    }
                    if (j > 0) {
                        n[i][j-1]++;
                    }
                    if (j+1 < board[0].size()) {
                        n[i][j+1]++;
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (n[i][j] < 2) board[i][j] = 0;
                else if (board[i][j] == 1 && (n[i][j] == 2 || n[i][j] == 3)) board[i][j] = 1;
                else if (n[i][j] > 3) board[i][j] = 0;
                else if (board[i][j] == 0 && n[i][j] == 3) board[i][j] = 1;
            }
        }
        return;
    }
};
