class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (auto& i : nums) {
            int a = -1, b = -1;
            bool g = 1;
            for (int j = 2; j*j <= i; j++) {
                if (i % j == 0 && a == -1 && j*j != i) {
                    a = j;
                    b = i / j;
                } else if (i % j == 0) {
                    g = 0;
                }
            }
            if (g && a != -1 && b != -1) {
                res += i+1+a+b;
            }
        }
        return res;
    }
};
