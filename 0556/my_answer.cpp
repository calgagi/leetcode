class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        string ss = s;
        sort(ss.begin(), ss.end(), greater<char>());
        if (ss == s) return -1;
        for (int i = s.length()-2; i >= 0; i--) {
            if (s[i] < s[i+1]) {
                int m = i+1;
                for (int j = i+2; j < s.length(); j++) 
                    if (s[j] < s[m] && s[j] > s[i]) m = j;
                char t = s[m];
                s[m] = s[i];
                s[i] = t;
                sort(s.begin()+i+1, s.end());
                break;
            }
        }
        long r = stol(s);
        if (r > INT_MAX) return -1;
        return r;
    }
};
