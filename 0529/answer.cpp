class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        int m = board.size(), n = board[0].size();
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
        } else {
            set<pair<int, int>> v;
            stack<pair<int, int>> s;
            s.push({r, c});
            while (!s.empty()) {
                int x = s.top().first, y = s.top().second;
                s.pop();
                if (v.find({x,y}) != v.end()) continue;
                v.insert({x,y});
                int adj = 0;
                if (x+1 < m && board[x+1][y] == 'M') adj++;
                if (x-1 > -1 && board[x-1][y] == 'M') adj++;
                if (y+1 < n && board[x][y+1] == 'M') adj++;
                if (y-1 > -1 && board[x][y-1] == 'M') adj++;
                if (x+1 < m && y+1 < n && board[x+1][y+1] == 'M') adj++;
                if (x+1 < m && y-1 > -1 && board[x+1][y-1] == 'M') adj++;
                if (x-1 > -1 && y+1 < n && board[x-1][y+1] == 'M') adj++;
                if (x-1 > -1 && y-1 > -1 && board[x-1][y-1] == 'M') adj++;
                if (adj) {
                    board[x][y] = '0' + adj;
                    continue;
                } 
                board[x][y] = 'B';
                if (x+1 < m) s.push({x+1,y});
                if (x-1 > -1) s.push({x-1,y});
                if (y+1 < n) s.push({x, y+1});
                if (y-1 > -1) s.push({x, y-1});
                if (x+1 < m && y+1 < m) s.push({x+1, y+1});
                if (x+1 < m && y-1 > -1) s.push({x+1, y-1});
                if (x-1 > -1 && y+1 < m) s.push({x-1, y+1});
                if (x-1 > -1 && y-1 > -1) s.push({x-1, y-1});
            }
        }
        return board;
    }
};
