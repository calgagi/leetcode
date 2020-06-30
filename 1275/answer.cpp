ass Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> board(3, vector<string>(3, " "));
        bool a = true;
        for (auto& p : moves) {
            board[p[0]][p[1]] = a ? "A" : "B";
            a = !a;
        }
        // verify if three in a row
        for (int i = 0; i < 3; i++) {
            string col = board[i][0];
            for (int j = 0; j < 3; j++) {
                if (col != board[i][j] || col == " ") col = "X";
            }
            if (col != "X") return col;
        }
        for (int i = 0; i < 3; i++) {
            string col = board[0][i];
            for (int j = 0; j < 3; j++) {
                if (col != board[j][i] || col == " ") col = "X";
            }
            if (col != "X") return col;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != " ") return board[1][1];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != " ") return board[1][1];
        return (moves.size() == 9 ? "Draw" : "Pending");
    }
};
