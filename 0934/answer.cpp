class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        vector<vector<pair<int,int>>> islands(2);
        int x = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j]) {
                    dfs(A, i, j, islands, x);
                    x++;
                }
            }
        }
        int r = INT_MAX;
        for (int i = 0; i < islands[0].size(); i++) {
            for (int j = 0; j < islands[1].size(); j++) {
                r = min(r, abs(islands[0][i].first-islands[1][j].first)+abs(islands[0][i].second-islands[1][j].second));
            }
        }
        return r-1;
    }
    
    void dfs(vector<vector<int>>& A, int r, int c, vector<vector<pair<int,int>>>& islands, int x) {
        queue<pair<int,int>> q;
        q.push({r, c});
        while (!q.empty()) {
            int rt = q.front().first, ct = q.front().second;
            q.pop();
            if (A[rt][ct]) { 
                A[rt][ct] = 0;
                islands[x].push_back({rt, ct});
            } else continue;
            if (rt-1 >= 0 && A[rt-1][ct]) q.push({rt-1, ct});
            if (ct-1 >= 0 && A[rt][ct-1]) q.push({rt, ct-1});
            if (rt+1 < A.size() && A[rt+1][ct]) q.push({rt+1, ct});
            if (ct+1 < A[0].size() && A[rt][ct+1]) q.push({rt, ct+1});
        }
    }
};
