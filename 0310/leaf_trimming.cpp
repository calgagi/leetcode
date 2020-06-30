class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> c(n, 0);
        
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
            c[edges[i][0]]++;
            c[edges[i][1]]++;
        }
        
        vector<int> leaves;
        
        for (int i = 0; i < n; i++)
            if (c[i] == 1 || c[i] == 0) {
                leaves.push_back(i);
            }
        
        while (true) {
            vector<int> new_leaves;
            for (int &l : leaves) {
                c[l]--;
                for (int& t : g[l]) {
                    c[t]--;
                    if (c[t] == 1) {
                        new_leaves.push_back(t);
                    }
                }
            }
            if (new_leaves.size() == 0) return leaves;
            leaves = new_leaves;
        }
        vector<int> r;
        return r;
    }
};
