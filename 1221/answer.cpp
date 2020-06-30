class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int t = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') t++;
            else if (s[i] == 'L') t--;
            if (t == 0) res++;
        }
        return res;
    }
};
