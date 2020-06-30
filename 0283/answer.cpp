class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), z = 0;
        for (int i = 0; i < n-z; i++) {
            if (nums[i] == 0) {
                nums.push_back(0);
                nums.erase(nums.begin()+i);
                i--;
                z++;
            }
        }
    }
};
