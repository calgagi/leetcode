class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long long l = 0, r = num;
        while (l <= r) {
            unsigned long long m = l + (r-l)/2;
            if (m*m == num)
                return true;
            else if (m*m > num)
                r = m-1;
            else
                l = m+1;
        }
        return false;
    }
};
