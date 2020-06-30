class Solution {
public:
    struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[a.size()-1] > b[b.size()-1];
        }
    };
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<vector<int>, vector<vector<int>>, comp> q;
        vector<int> start(m+1, 0);
        for (int i = 0; i < m; i++) {
            start[m] += mat[i][0];
        }
        q.push(start);
        vector<int> ans;
        set<vector<int>> seen;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && seen.find(q.top()) != seen.end()) {
                q.pop();
            }
            ans = q.top();
            q.pop();
            seen.insert(ans);
            /*for (int j = 0; j < m; j++) {
                cout << ans[j] << " ";
            }
            cout << endl;*/
            for (int j = 0; j < m; j++) {
                if (ans[j] != n-1) {
                    ans[j]++;
                    ans[m] -= mat[j][ans[j]-1];
                    ans[m] += mat[j][ans[j]];
                    q.push(ans);
                    ans[m] -= mat[j][ans[j]];
                    ans[m] += mat[j][ans[j]-1];
                    ans[j]--;
                }
            }
        }
        return ans[m];
    }
};
