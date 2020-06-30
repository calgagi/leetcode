class Solution {
public:
    vector<vector<int>> r;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> c;
        c.push_back(0);
        backtrack(graph, c);
        return r;
    }
    
    void backtrack(vector<vector<int>>& graph, vector<int>& c) {
        if (graph[c.back()].empty()) {
            r.push_back(c);
        }
        for (int i = 0; i < graph[c.back()].size(); i++) {
            c.push_back(graph[c.back()][i]);
            backtrack(graph, c);
            c.pop_back();
        }
        return;
    }
};
