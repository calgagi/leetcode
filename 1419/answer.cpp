class Solution {
public:
    int minNumberOfFrogs(string c) {
        map<char,char> prev;
        prev['r'] = 'c';
        prev['o'] = 'r';
        prev['a'] = 'o';
        prev['k'] = 'a';
        int n = c.length();
        map<char,int> seen;
        int ans = 0, in = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] != 'c' && seen[prev[c[i]]] == 0) {
                return -1;
            } else {
                if (c[i] != 'c') {
                    seen[prev[c[i]]]--;
                } else {
                    in++;
                }
                seen[c[i]]++;
            }
            if (c[i] == 'k') {
                in--;
            }
            ans = max(in, ans);
        }
        for (auto& p : prev) {
            if (seen[prev[p.first]] != 0) {
                return -1;
            }
        }
        return ans;
    }
};
