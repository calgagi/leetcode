class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n && prev != nums[i]) {
                prev = nums[i];
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};
