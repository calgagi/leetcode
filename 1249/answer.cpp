class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int st = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st++;
            if (s[i] == ')') {
                if (st == 0) {
                    s.erase(s.begin()+i);
                    i--;
                } else {
                    st--;
                }
            }
        }
        st = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == ')') st++;
            if (s[i] == '(') {
                if (st == 0) {
                    s.erase(s.begin()+i);
                } else {
                    st--;
                }
            }
        }
        return s;
    }
};
