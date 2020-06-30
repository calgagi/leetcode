class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int cur = 0, n = nums.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (cur <= 0) {
                ans = max(ans, -cur + 1);
            }
        }
        return ans;
    }
};
