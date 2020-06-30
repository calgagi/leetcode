class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool seen[n+2] = {0};
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n+1) {
                seen[nums[i]] = 1;
            }
        }
        for (int i = 1; i < n+2; i++) {
            if (seen[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
