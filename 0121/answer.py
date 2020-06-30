class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        m, mi, ma = 0, prices[0], max(prices)
        mai = prices.index(ma)
        for i in range(1, len(prices)):
            if prices[i] < mi:
                mi = prices[i]
            if i > mai:
                ma = max(prices[i:])
                mai = prices[i:].index(ma)
            m = max(ma - mi, m)
                
        return m
