class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int,bool> seen;
            int it = nums[i], n = 1;
            seen[i] = true;
            while (!seen[it]) {
                seen[it] = true;
                it = nums[it];
                n++;
            }
            m = max(n, m);
        }
        return m;
    }
};
