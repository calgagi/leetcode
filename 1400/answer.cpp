class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        int mn = 0, mx = n;
        vector<int> c(26, 0);
        for (int i = 0; i < n; i++) {
            c[s[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (c[i] % 2) {
                mn++;
            }
        }
        return k >= mn && k <= mx;
    }
};
