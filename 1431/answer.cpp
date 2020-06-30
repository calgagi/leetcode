class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(candies[i], mx);
        }
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            if (candies[i]+extraCandies >= mx) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
        return ans;
    }
};
