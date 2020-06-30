class Solution {
public:
    int r;
    
    void helper(int n, int l) {
        if (l >= r) return;
        if (n == 0)
            r = min(l, r);
        for (int i = sqrt(n); i > 0; i--) {
            helper(n-pow(i, 2), l+1);
        }
        return;
    }    
    
    
    int numSquares(int n) {
        this->r = INT_MAX;
        helper(n, 0);
        return this->r;
    }
};
