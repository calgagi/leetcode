class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int c[100010], n = nums.size();
        memset(c, -1, sizeof(c));
        int ans = 0, cur = 50005;
        c[cur] = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cur++;
            } else {
                cur--;
            }
            if (c[cur] != -1) {
                ans = max(ans, i-c[cur]+1);
            } else {
                c[cur] = i+1;
            }
        }
        return ans;
    }
};
