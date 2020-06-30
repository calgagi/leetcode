class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        buy, sell, rest = [-prices[0]], [0], [0]
        for i in range(1, len(prices)):
            buy.append(max(rest[i-1] - prices[i], buy[i-1]))
            sell.append(max(prices[i] + buy[i-1], sell[i-1]))
            rest.append(max(buy[i-1], sell[i-1], rest[i-1]))
        return max(buy[-1], sell[-1], rest[-1])
