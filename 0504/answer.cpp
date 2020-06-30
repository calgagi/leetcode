class Solution {
public:
    string convertToBase7(int num) {
        string r = num >= 0 ? "" : "-";
        int i;
        num = abs(num);
        for (i = 0; pow(7, i) <= num; i++) ;
        int j = 0;
        if (i > 0) i--;
        while (i >= 0) {
            if (pow(7,i) <= num) {
                num -= pow(7,i);
                j++;
            }   
            else {
                r += to_string(j);
                i--;
                j = 0;
            }
        }
        return r;
    }
};
