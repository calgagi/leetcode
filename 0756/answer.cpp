class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator () (const pair<T1,T2> &p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;  
        }
    };
    
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<pair<char,char>, vector<char>, pair_hash> m;
        for (auto& a : allowed) {
            m[make_pair(a[0], a[1])].push_back(a[2]);
        }
        stack<string> s;
        s.push(bottom);
        while (!s.empty()) {
            string b = s.top(); s.pop();
            if ((int) b.length() == 1) return true;
            queue<pair<string, int>> q;
            q.push({"", 0});
            while (!q.empty()) {
                string a = q.front().first; 
                int p = q.front().second; 
                q.pop();
                if (p == (int) b.length()-1) {
                    s.push(a);
                    continue;
                }
                pair<char,char> l = make_pair(b[p], b[p+1]);
                for (int j = 0; j < (int) m[l].size(); j++) {
                    q.push({a + m[l][j], p+1});
                }
            }
        }
        return false;
    }
};
