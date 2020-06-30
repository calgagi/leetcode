class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length(), cur = 0, res = 0;
        string v = "aeiou";
        map<int,int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++) {
            int vowel = v.find(s[i]);
            if (vowel != -1) {
                cur ^= (1 << vowel);
            }
            if (m.count(cur)) {
                res = max(res, i-m[cur]);
            } else {
                m[cur] = i;
            }
        }
        return res;
    }
};
