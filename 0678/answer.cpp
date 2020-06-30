class Solution {
public:
    bool checkValidString(string& s, int i, int j) {
        if (j < 0) return false;
        while (i < s.length()) {
            if (s[i] == ')') {
                j--;
                if (j < 0) return false;
            } else if (s[i] == '(') {
                j++;
            } else if (s[i] == '*') {
                return checkValidString(s, i+1, j+1) || 
                       checkValidString(s, i+1, j-1) || 
                       checkValidString(s, i+1, j);
            }
            i++;
        }
        return j == 0;
    }
    
    
    bool checkValidString(string s) {
        if (s == "") return true;
        return checkValidString(s, 0, 0);
    }
};
