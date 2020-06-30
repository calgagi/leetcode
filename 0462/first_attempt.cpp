class Solution {
public:
    int minMoves2(vector<int>& nums) {
        double t = 0;
        for (int i = 0; i < nums.size(); i++) t += nums[i];
        t /= (double) nums.size();
        t = round(t);
        int r = 0;
        for (int i = 0; i < nums.size(); i++) r += abs(nums[i] - t);
        return r;
    }
};
