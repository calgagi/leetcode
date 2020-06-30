class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Binary search?
        int l = 1, r = INT_MAX, res;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int sum = 0;
            for (auto& x : nums) sum += x/m + (x % m != 0);
            if (sum > threshold) {
                l = m+1;
            } else {
                res = m;
                r = m-1;
            }
        }
        return res;
    }
};
