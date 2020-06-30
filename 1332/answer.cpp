class Solution {
public:
    int removePalindromeSub(string s) {
        if (s == "") {
            return 0;
        }
        bool good = 1;
        int n = s.length();
        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n-i-1]) {
                good = 0;
                break;
            }
        }
        return good ? 1 : 2;
    }
};
