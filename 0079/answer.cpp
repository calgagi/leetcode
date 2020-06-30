class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    bool seen[board.size()][board[0].size()] = {};
                    stack<tuple<int,int,int>> s;
                    stack<tuple<int,int,int>> r;
                    s.push({i, j, 0});
                    while (!s.empty()) {
                        int x = get<1>(s.top());
                        int y = get<0>(s.top());
                        int k = get<2>(s.top());
                        s.pop();
                        if (board[y][x] != word[k]) continue;
                        if (k == word.size()-1) return true;
                        while (r.size() && get<2>(r.top()) >= k) {
                            seen[get<0>(r.top())][get<1>(r.top())] = false;
                            r.pop();
                        }  
                        seen[y][x] = true;
                        r.push({y, x, k});
                        if (y+1 < board.size() && !seen[y+1][x])    
                            s.push({y+1, x, k+1});
                        if (y-1 >= 0 && !seen[y-1][x])
                            s.push({y-1, x, k+1});
                        if (x+1 < board[0].size() && !seen[y][x+1])
                            s.push({y, x+1, k+1});
                        if (x-1 >= 0 && !seen[y][x-1])
                            s.push({y, x-1, k+1});
                    }
                }
            }
        }
        return false;
    }
};
