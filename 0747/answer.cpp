class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0, prev_max = -10000;
        for (int i = 1; i < (int) nums.size(); i++) {
            if (nums[max] < nums[i]) {
                prev_max = nums[max];
                max = i;
            } else if (prev_max < nums[i]) {
                prev_max = nums[i];
            }
        }
        return nums[max] >= 2*prev_max ? max : -1;
    }
};
