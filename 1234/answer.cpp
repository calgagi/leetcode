class Solution {
public:
    
    int balancedString(string s) {
        int t = s.length()/4;
        unordered_map<char, int> seen;
        for (char &c : s) seen[c]++;
        
        int b = 0, e = 0, res = INT_MAX;
        while (e < s.length()) {
            seen[s[e]]--;
            while (b < s.length() && seen['Q'] <= t && seen['W'] <= t && seen['R'] <= t && seen['E'] <= t) {
                res = min(res, e-(b-1));
                seen[s[b]]++;
                b++;
            }
            e++;
        }
        return res;
    }
};
