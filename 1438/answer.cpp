class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> in;
        int n = nums.size(), ans = 1;
        for (int e = 0, b = 0; e < n; e++) {
            in.insert(nums[e]);
            while (!in.empty() && *in.rbegin()-*in.begin() > limit) {
                in.erase(in.lower_bound(nums[b]));
                b++;
            }
            ans = max(ans, e-b+1);
        }
        return ans;
    }
};
