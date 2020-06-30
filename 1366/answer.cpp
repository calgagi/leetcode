class Solution {
public:
    struct compare {
        bool operator()(const pair<vector<int>,char>& p, const pair<vector<int>,char>& q) {
            if (p.first < q.first) {
                return 0;
            } else if (p.first > q.first) {
                return 1;
            }
            return q.second > p.second;
        }
    };
    
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<map<char,int>> v(n);
        set<char> seen;
        for (auto& s : votes) {
            for (int i = 0; i < n; i++) {
                v[i][s[i]]++;
                seen.insert(s[i]);
            }
        }
        vector<pair<vector<int>, char>> p;
        for (auto& c : seen) {
            vector<int> b; 
            for (int i = 0; i < n; i++) {
                b.push_back(v[i][c]);
            }
            p.push_back({b, c});
        }
        sort(p.begin(), p.end(), compare());
        string res = "";
        for (auto& x : p) {
            res += x.second;
        }
        return res;
    }
};
