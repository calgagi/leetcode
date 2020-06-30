class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0, i = 0, s = nums.size();
        for (i = 0; i < s; i++)
            x = x ^ nums[i] ^ i;
        return i ^ x;
    }
};
