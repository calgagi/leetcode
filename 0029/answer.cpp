class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long r = 0;
        bool neg = false;
        if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
            neg = true;
        long ldividend = labs(dividend);
        long ldivisor = labs(divisor);
        while (ldividend >= ldivisor) {
            int i = 0;
            for ( ; ldividend >= (ldivisor << i); i++) ;
            i--;
            ldividend -= (ldivisor << i);
            r += (1 << i);
        }
        if (neg) r *= -1;
        return r;
    }
};
