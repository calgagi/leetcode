class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int t = 0;
        for (int &i : nums) t += i;
        int b = 0, e = nums.size()-1, r = t;
        while (b < e) {
            if (nums[b] < nums[e]) {
                t -= nums[b];
                b++;
            } else if (nums[e] <= nums[b]) {
                t -= nums[e];
                e--;
            }
            r = max(r, t); 
        }
        return r;
    }
};
