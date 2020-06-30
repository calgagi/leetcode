class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int n = (int) nums.size();
        if (n <= 1) return n;
        int streak = 1, res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) {
                streak++;
            } else {
                streak = 1;          
            }
            res = max(res, streak);
        }
        return res;
    }
};
