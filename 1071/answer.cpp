class Solution {
public:
    bool test(string& s, string& p) {
        for (int i = 0; i < (int) s.length(); i += p.length()) {
            if (s.substr(i, p.length()) != p) {
                return 0;
            }
        }
        return 1;
    }
    
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int n1 = str1.length(), n2 = str2.length();
        for (int i = 1; i <= min(n1, n2); i++) {
            if (n1 % i != 0 || n2 % i != 0) {
                continue;
            }
            string p = str1.substr(0, i);
            if (test(str1, p) && test(str2, p)) {
                ans = p;
            }
        }
        return ans;
    }
};
