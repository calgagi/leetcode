class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Prefix
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i-1];
        int res = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            res += m[nums[i] - k];
            m[nums[i]]++;
        }
        return res;
    }
};
