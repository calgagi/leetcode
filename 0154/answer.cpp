class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if(nums[l] == nums[r]) {
            while(nums[l] == nums[r] && l < r) r--;
            nums.erase(nums.begin()+r+1, nums.end());
        }
        int ans = INT_MAX;
        while(l <= r) {
            int m = l + (r-l)/2;
            ans = min(nums[m], ans);
            if (nums[m] == nums.back()) {
                r = m-1;
            } else if (nums[m] == nums.front()) {
                l = m+1;
            } else if (nums[m] < nums.back()) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
};
