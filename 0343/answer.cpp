class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        return max(2 * helper(n-2), 3 * helper(n-3));
    }
    
    int helper(int n) {
        if (n <= 3)
            return n;
        return max(2 * helper(n-2), 3 * helper(n-3));
    }
};
