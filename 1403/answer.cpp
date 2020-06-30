class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int s = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            s += nums[i];
        }
        vector<int> ans;
        int s2 = 0;
        for (int i = 0; i < n; i++) {
            s -= nums[i];
            s2 += nums[i];
            ans.push_back(nums[i]);
            if (s2 > s) {
                return ans;
            }
        }
        return vector<int>();
    }
};
