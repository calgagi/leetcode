class Solution {
public:
    string removeKdigits(string num, int k) {
        string r = "";
        int keep = num.size()-k;
        for (int i = 0; i < num.size(); i++) {
            while (r.length() > 0 && k && r.back() > num[i]) {
                r.erase(r.end()-1);
                k--;
            }
            r += num[i];
        }
        r.erase(keep, string::npos);
        while (r != "" && r[0] == '0') {
            r.erase(r.begin());
        }
        if (r == "") 
            return "0";
        else
            return r;
    }
};
