class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int res1 = i, res2 = n-i;
            bool good = true;
            while (res1) {
                if (res1 % 10 == 0) {
                    good = false;
                    break;
                }
                res1 /= 10;
            }
            while (res2) {
                if (res2 % 10 == 0) {
                    good = false;
                    break;
                }
                res2 /= 10;
            }
            if (good) {
                return {i, n-i};
            }
        }
        return {-1, -1};
    }
};
