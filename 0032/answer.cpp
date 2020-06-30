class Solution {
public:
    int longestValidParentheses(string s) {
        int resFor = 0, resBack = 0, stck = 0, prev = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') stck++;
            if (s[i] == ')') {
                stck--;
                if (stck == 0) {
                    resFor = max(resFor, i-prev);
                } else if (stck < 0) {
                    prev = i;
                    stck = 0;
                }
            }
        }
        prev = s.length();
        stck = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == ')') stck++;
            if (s[i] == '(') {
                stck--;
                if (stck == 0) {
                    resBack = max(resBack, prev-i);
                } else if (stck < 0) {
                    prev = i;
                    stck = 0;
                }
            }
        }
        return max(resBack, resFor);
    }
};
