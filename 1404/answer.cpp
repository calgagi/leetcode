class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s != "1") {
            if (s.back() == '1') {
                int n = s.length()-1;
                s[n] = '0';
                n--;
                while (n >= 0 && s[n] == '1') {
                    s[n] = '0';
                    n--;
                }
                if (n < 0) {
                    return ans+s.length()+1;
                }
                s[n] = '1';
            } else {
                s.pop_back();   
            }
            ans++;
        }
        return ans;
    }
};
