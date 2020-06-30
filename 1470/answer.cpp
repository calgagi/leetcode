class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n*2);
        for (int i = 0, j = n; i < n; i++, j++) {
            ans[i*2] = nums[i];
            ans[i*2+1] = nums[j];
        }
        return ans;
    }
};
