class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int r = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X') {
                    // BFS
                    r++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        pair<int,int> x = q.front();
                        q.pop();
                        board[x.first][x.second] = 'O';
                        if (x.first-1 >= 0 && board[x.first-1][x.second] == 'X') 
                            q.push(make_pair(x.first-1, x.second));
                        if (x.second-1 >= 0 && board[x.first][x.second-1] == 'X') 
                            q.push(make_pair(x.first, x.second-1));
                        if (x.first+1 < board.size() && board[x.first+1][x.second] == 'X')
                            q.push(make_pair(x.first+1, x.second));
                        if (x.second+1 < board[0].size() && board[x.first][x.second+1] == 'X')
                            q.push(make_pair(x.first, x.second+1));   

                    }
                }
            }
        }
        return r;

    }
};
