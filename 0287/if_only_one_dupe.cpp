class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int total = 0;
        for (int i = 1; i < nums.size(); i++) {
            total += i;
        }
        for (int i = 0; i < nums.size(); i++) {
            total -= nums[i];
        }
        return abs(total);
    }
};
