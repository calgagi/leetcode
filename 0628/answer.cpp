class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MAX, e = INT_MAX, f = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= a) {
                c = b;
                b = a;
                a = nums[i];
            } else if (nums[i] >= b) {
                c = b;
                b = nums[i];
            } else if (nums[i] > c) {
                c = nums[i];
            } 
            if (nums[i] <= d) {
                f = e;
                e = d;
                d = nums[i];
            } else if (nums[i] <= e) {
                f = e;
                e = nums[i];
            } else if (nums[i] < f) {
                f = nums[i];
            }
        }
        return max(a * b * c, max(a * d * e, d * e * f));
    }
};
