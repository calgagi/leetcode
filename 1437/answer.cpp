class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last1 = -1e9, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (i - last1 - 1 < k) {
                    return 0;
                }
                last1 = i;
            }
        }
        return 1;
    }
};
