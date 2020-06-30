class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int t = nums[(nums.size()-1) / 2], r = 0;
        for (int &a : nums) r += abs(a - t);
        return r;
    }
}; 
