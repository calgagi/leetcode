class Solution {
public:
    int longestDecomposition(string text) {
        int l = 0, r = text.length()-1;
        string sL = "", sR = "";
        int res = 0;
        while (l < r) {
            sL += text[l];
            sR = text[r] + sR;
            if (sL == sR) {
                res += 2;
                sL = "";
                sR = "";
            }
            r--;
            l++;
        }
        if (r == l) res++;
        else if (r < l && sR != sL && sR != "") res++;
        return res;
    }
};
