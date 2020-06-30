class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bitset<100000000> r;
        for (int i = 0; i < nums.size(); i++) {
            r[nums[i]] = 1;
        }
        for (int i = 0; i <= nums.size(); i++) {
            if (!r[i]) return i;
        }
        return -1;
    }
};
