class Solution {
public:
    string reformat(string s) {
        string l = "", d = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                d += s[i];
            } else {
                l += s[i];
            }
        }
        if (abs((int) l.length() - (int) d.length()) > 1) {
            return "";
        }
        if (l.length() > d.length()) {
            swap(d, l);
        }
        string ans = "";
        //cout << d << " " << l << endl;
        for (int i = 0; i < n; i++) {
            //cout << i << " " << l[i/2] << " " << d[i/2] << endl;
            if ((i & 1)) {
                ans += l[i/2];
            } else {
                ans += d[i/2];
            }
        }
        return ans;
    }
};
