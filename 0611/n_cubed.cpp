class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i+1; j < nums.size(); j++)
                for (int k = j+1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] <= nums[k]) continue;
                    if (nums[i] + nums[k] <= nums[j]) continue;
                    if (nums[j] + nums[k] <= nums[i]) continue;
                    r++;
                }
        return r;
    }
};
