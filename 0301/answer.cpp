class Solution {
public:
    
    vector<string> removeInvalidParentheses(string s) { 
        vector<string> res;
        
        queue<string> q;
        q.push(s);
        unordered_set<string> visited;

        
        
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (visited.count(cur)) continue;
            visited.insert(cur);
            int n = cur.length();
            if (!res.empty() && (int) res.back().length() > n) continue;
            int st = 0;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (cur[i] == '(') st++;
                if (cur[i] == ')') {
                    st--;
                    if (st < 0) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid && st == 0) {
                res.push_back(cur);
                continue;
            }
            string next = "";
            for (int i = 0; i < n; i++) {
                q.push(next + cur.substr(i+1));
                next += cur[i];
            }
        }
        return res;
    }
};
