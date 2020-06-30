class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(0);
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            priority_queue<int, vector<int>, greater<int>> new_q;
            while (!q.empty()) {
                int r = q.top();
                q.pop();
                for (int j = 0; j < n; j++) {
                    new_q.push(r + mat[i][j]);
                }
            }
            int s = new_q.size();
            for (int j = 0; j < min(k, s); j++) {
                q.push(new_q.top());
                new_q.pop();
            }
        }
        while (q.size() != 1) {
            q.pop();
        }
        return q.top();
    }
};
