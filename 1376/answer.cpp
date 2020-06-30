class Solution {
public:
    vector<vector<int>> graph;
    vector<int> informTime;
    
    int dfs(int c) {
        int res = 0;
        for (int i = 0; i < (int) graph[c].size(); i++) {
            res = max(res, dfs(graph[c][i]));
        }
        return informTime[c]+res;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        graph.resize(n);
        this->informTime = informTime;
        for (int i = 0; i < n; i++) {
            if (i != headID) {
                graph[manager[i]].push_back(i);
            }
        }
        return dfs(headID);
    }
};
