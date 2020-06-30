class Solution {
public:
    vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> graph;
    int color, ncolor;
    
    void dfs(int i, int j) {
        if (i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size() || graph[i][j] == ncolor || graph[i][j] != color) {
            return;
        }
        graph[i][j] = ncolor;
        for (pair<int,int>& d : dir) {
            dfs(i+d.first, j+d.second);
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        this->graph = image;
        color = image[sr][sc];
        ncolor = newColor;
        dfs(sr, sc);
        return graph;
    }
};
