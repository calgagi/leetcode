class Solution {
public:
    
    int balancedString(string s) {
        int t = s.length()/4;
        unordered_map<char, int> seen;
        for (char &c : s) seen[c]++;
        seen['Q'] = seen['Q']-t;
        seen['W'] = seen['W']-t;
        seen['E'] = seen['E']-t;
        seen['R'] = seen['R']-t;
        
        for (auto it = seen.begin(); it != seen.end(); it++) 
            cout << it->first << " " << it->second << endl;
        
        int b = 0, e = 0, res = INT_MAX;
        while (e < s.length()) {
            seen[s[e]]--;
            if (seen['Q'] <= 0 && seen['W'] <= 0 && seen['R'] <= 0 && seen['E'] <= 0) {
                while (b < e && seen['Q'] <= 0 && seen['W'] <= 0 && seen['R'] <= 0 && seen['E'] <= 0) {
                    res = min(res, e-(b-1));
                    seen[s[b]]++;
                    b++;
                }
                if (b == e) return 0;
            }
            e++;
        }
        return res;
    }
};
