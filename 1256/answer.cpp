class Solution {
public:
    string encode(int num) {
        string res = "";
        for(int i = 0; num - pow(2, i) >= 0; i++) {
            res += "0";
            num -= pow(2, i);
        }
        for(int i = 0; i < res.length(); i++) {
            if ((num & (1 << i))) res[res.length()-1-i] = '1';
        }
        return res;
    }
};
