class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0, diff = n-m;
        for (int i = 0; i < 32; i++) {
            if (diff < (1 << i) && ((n & (1 << i)) && (m & (1 << i)))) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
