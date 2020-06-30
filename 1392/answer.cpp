class Solution {
public:
    string longestPrefix(string s) {
        long long n = s.length(), m = 1e9+7, x = 31;
        long long b = 0, e = 0, c = x;
        int r = -1;
        for (int i = 0; i < n-1; i++) {
            b = (b + s[i] * c) % m;
            e = (e * x) % m;
            e = (e + s[n-i-1] * x) % m;
            if (b == e) {
                r = i;
            }
            c = (c * x) % m;
            //cout << b << " " << e << endl;
        }
        return s.substr(0, r+1);
    }
};
