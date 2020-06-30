class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        mi, m = prices[0], 0
        for i in range(1, len(prices)):
            mi = min(prices[i], mi)
            m = max(m, prices[i] - mi)
                
        return m
