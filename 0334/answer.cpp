class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Keep track of lowest 
        int b = INFINITY, m = INFINITY;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= b) 
                b = nums[i];
            else if (nums[i] <= m) 
                m = nums[i];
            else
                return true;
        }
        return false;
    }
};
