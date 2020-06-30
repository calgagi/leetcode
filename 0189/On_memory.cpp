class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> r;
        k = k % nums.size();
        for (int i = (nums.size()-k) % nums.size(), j = 0; j < nums.size(); i = (i+1) % nums.size(), j++) { 
            r.push_back(nums[i]);
        }
        nums = r;
    }
};
