class Solution {
public:
    string intToRoman(int num) {
        string r = "";
        int vals[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string rom[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
        int i = 12;
        while (num != 0) {
            if (num >= vals[i]) {
                r += rom[i];
                num -= vals[i];
            } else {
                i--;
            }
        }
        return r;
    }
};
