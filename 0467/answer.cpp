class Solution {
public:
    int findSubstringInWraproundString(string p) {
        unordered_map<char,int> x;
        int b = 0, e = 1;
        int res = 0;
        while (e <= p.length()) {
            if (e == p.length() || ((p[e-1] != 'z' || p[e] != 'a') && (p[e-1] != p[e]-1))) {
                bool flag = false;
                if (e == p.length()) {
                    flag = true;
                }
                e--;
                int ogb = b;
                while (e-b+1 > 0) {
                    if (x[p[b]] < e-b+1) {
                        res += (e-b+1)-x[p[b]];
                        x[p[b]] = e-b+1;
                    }
                    b++;
                }
                if (flag) break;
                e++;
            }
            e++;
        }
        return res;
    }
};
