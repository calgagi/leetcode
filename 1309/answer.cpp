class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for (int i = 0; i < (int) s.length(); i++) {
            if (i+2 < (int) s.length() && s[i+2] == '#') {
                res += (s[i] - '0') * 10 + (s[i+1] - '0') + 'a' - 1;
                i += 2;
            } else {
                res += 'a' + (s[i] - '1'); 
            }
        }
        return res;
    }
};
