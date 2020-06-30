class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, res;
        int i;
        for(i = 0; i < k; i++)
            sum += nums[i];
        res = sum;
        while(i < nums.size()) {
            sum = sum - nums[i-k] + nums[i];
            res = max(sum, res);
            i++;
        }
        return res/(double)k;
    }
};s
