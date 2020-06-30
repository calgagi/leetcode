class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cs(26, 0);
        vector<int> ts = cs;
        for (auto& c : s) {
            cs[c-'a']++;
        }
        for (auto& c : t) {
            ts[c-'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += abs(ts[i] - cs[i]);
        }
        return ans/2;
    }
};
