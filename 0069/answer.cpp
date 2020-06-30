class Solution {
public:
    int mySqrt(int x) {
        // Binary search
        long long l = 0, r = sqrt(INT_MAX), m;
        while (l <= r) {
            m = (l + r) / 2;
            long long a = m * m;
            
            if (a == x) return m;
            else if (a < x) l = m+1;
            else if (a > x) r = m-1;
        }
        return x - l*l < 0 ? l-1 : l;
    }
};
