class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (2*i < n && 2*i+1 < n) {
                for (int j = 0; j < nums[2*i]; j++) {
                    res.push_back(nums[2*i+1]);
                }
            } else {
                break;
            }
        }
        return res;
    }
};
