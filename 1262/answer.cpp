class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> saved_vals(3, 0);
        for (int i = 0; i < (int) nums.size(); i++) {
            vector<int> new_vals = saved_vals;
            for (int j = 0; j < 3; j++) {
                new_vals[(saved_vals[j] + nums[i]) % 3] = 
                    max(new_vals[(saved_vals[j] + nums[i]) % 3], 
                        saved_vals[saved_vals[j] % 3] + nums[i]);
            }
            saved_vals = new_vals;
        }    
        return saved_vals[0];
    }
};
