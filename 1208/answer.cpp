class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // Sliding window?
        int b = 0, e = 0, r = 0;
        int c = 0;
        while (e < s.length()) {
            c += abs(s[e] - t[e]);
            while (c > maxCost) {
                c -= abs(s[b] - t[b]);
                b++;
            }
            r = max(r, e-(b-1));
            e++;
        }
        return r;
    }
};
