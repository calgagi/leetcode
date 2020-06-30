class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size(), 1);
        int t = 1;
        for (int i = 0; i < nums.size(); i++) {
            r[i] = t;
            t *= nums[i];
        }
        t = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            r[i] *= t;
            t *= nums[i];
        }
        return r;
    }
};
