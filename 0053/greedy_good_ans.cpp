class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int t = nums[0], r = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (t < 0)
                t = 0;
            t += nums[i];
            r = max(r, t);
        }
        return r;
    }
};
