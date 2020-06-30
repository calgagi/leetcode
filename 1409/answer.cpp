class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans, p(m);
        for (int i = 0; i < m; i++) {
            p[i] = i+1;
        }
        for (auto& q : queries) {
            // find
            for (int i = 0; i < m; i++) {
                if (p[i] == q) {
                    ans.push_back(i);
                    p.erase(p.begin()+i);
                    p.insert(p.begin(), q);
                    break;
                }
            }
        }
        return ans;
    }
};
