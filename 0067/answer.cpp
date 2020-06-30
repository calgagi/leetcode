class Solution {
public:
    string addBinary(string a, string b) {
        string r = "";
        r.reserve(max(a.length(), b.length()));
        int carry = 0;
        for (int j = a.length()-1, i = b.length()-1; j >= 0 || i >= 0; j--, i--) {
            if (i >= 0) carry += b[i] - '0';
            if (j >= 0) carry += a[j] - '0';
            r += (char) ((carry % 2) + '0');
            if (carry >= 2) carry = 1;
            else carry = 0;
        }
        if (carry) r += (char) (carry + '0');
        for (int i = r.length()-1; i >= 1; i--) {
            if (r[i] == '0') r.pop_back();
            else break;
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
