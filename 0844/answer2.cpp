class Solution {
public:
    string get(string s) {
        int n = s.length(), b = 0;
        string ans = "";
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '#') {
                b++;
            } else if (b == 0) {
                ans += s[i];
            } else {
                b--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool backspaceCompare(string S, string T) {
        string r1 = get(S), r2 = get(T);
        //cout << r1 << " " << r2 << endl;
        return r1 == r2;
    }
};
