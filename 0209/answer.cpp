class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // Sliding window
        int b = 0, n = nums.size(), c = 0, res = INT_MAX;
        for (int e = 0; e < n; e++) {
            c += nums[e];
            while (c >= s) {
                res = min(e-b+1, res);
                c -= nums[b];
                b++;
            }
        }
        return (res==INT_MAX?0:res);
    }
};
