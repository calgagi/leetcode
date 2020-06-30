class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int ans = INT_MAX;
        while(l <= r) {
            int m = l + (r-l)/2;
            ans = min(ans, nums[m]);
            if(nums[m] <= nums.back()) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};
