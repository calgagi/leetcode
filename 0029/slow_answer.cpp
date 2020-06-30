class Solution {
public:
    int divide(int dividend, int divisor) {
        int r = 0;
        while (dividend >= divisor) {
            dividend -= divisor;
            r++;
        }
        return r;
    }
};
