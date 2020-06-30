class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) break;
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l;
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) l = j;
        }
        iter_swap(nums.begin()+i, nums.begin()+l);
        reverse(nums.begin()+i+1, nums.end());
        return;
    }
};
