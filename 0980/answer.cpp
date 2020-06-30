class Solution {
public:
    
    int z = 0;
    unordered_map<int,unordered_map<int,bool>> s;
    
    void dfs(vector<vector<int>>& grid, int r, int c, int& counter) {
        counter++;
        s[r][c] = true;
        if (grid[r][c] == 2 && counter == grid.size()*grid[0].size()) {
            this->z++;
            counter--;
            s[r][c] = false;
            return;
        }
        if (r+1 < grid.size() && !s[r+1][c])
            dfs(grid, r+1, c, counter);
        if (c+1 < grid[0].size() && !s[r][c+1])
            dfs(grid, r, c+1, counter);
        if (c-1 >= 0 && !s[r][c-1])
            dfs(grid, r, c-1, counter);
        if (r-1 >= 0 && !s[r-1][c]) 
            dfs(grid, r-1, c, counter);
        counter--;
        s[r][c] = false;
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int counter = 0;
        int start[2], end[2];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    start[0] = i;
                    start[1] = j;
                } else if (grid[i][j] == 2) {
                    end[0] = i;
                    end[1] = j;
                } else if (grid[i][j] == -1) {
                    counter++;
                    s[i][j] = true;
                }
             }
        } 
        dfs(grid, start[0], start[1], counter);
        return this->z;
    }
};
