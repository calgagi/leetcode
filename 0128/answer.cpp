class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> n;
        int r = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (n.find(nums[i]) != n.end()) continue;
            if (n.find(nums[i]+1) != n.end() && n.find(nums[i]-1) != n.end()) {
                n[nums[i]] = n[nums[i]+1] + n[nums[i]-1] + 1;
                n[nums[i]+n[nums[i]+1]] = n[nums[i]];
                n[nums[i]-n[nums[i]-1]] = n[nums[i]];
            } else if (n.find(nums[i]+1) != n.end()) {
                n[nums[i]] = n[nums[i]+1] + 1;
                n[nums[i]+n[nums[i]+1]] = n[nums[i]]; 
            } else if (n.find(nums[i]-1) != n.end()) {
                n[nums[i]] = n[nums[i]-1] + 1;
                n[nums[i]-n[nums[i]-1]] = n[nums[i]];
            } else {
                n[nums[i]] = 1;
            }
            r = max(n[nums[i]], r);
        }

        return r;
    }
};
