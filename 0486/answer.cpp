class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int r = getmax(nums, 0, nums.size()-1, 0);
        int t = 0;
        for (int i = 0; i < nums.size(); i++) t += nums[i];
        if (r > (t/2)) {
            return true;
        } else if (r == (t/2) && t % 2 == 0) {
            return true;
        } else {
            return false;
        }
    } 
    
    int getmax(vector<int>& nums, int i, int j, int c) {
        if (i > j) return c;
        return max(getmin(nums, i+1, j, nums[i]+c), getmin(nums, i, j-1, nums[j]+c));
    }
    
    int getmin(vector<int>& nums, int i, int j, int c) {
        if (i > j) return c;
        return min(getmax(nums, i+1, j, c), getmax(nums, i, j-1, c));
    }
};
