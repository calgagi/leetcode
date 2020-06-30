class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size(), minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = max(res, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};
