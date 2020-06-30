class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int *c = new int[10001];  
        memset(c, 0, sizeof(int)*10001);
        for (int i = 0; i < nums.size(); i++) {
            c[nums[i]]++;
        }
        int m = 0, prev = 0, cur = 0;
        for (int i = 1; i < 10001; i++) {
            m = max(prev + c[i]*(i), cur);
            prev = cur;
            cur = m;
        }
        return m;
    }
};
