class Solution:
	def maxProfit(self, prices: List[int]) -> int:
		# If can't buy and sell, return 0
		if len(prices) < 2:
			return 0
		# Initialize variables
		buy, sell, prev_buy, prev_sell = float('-inf'), 0, 0, 0

		# For all the items
		for i in range(0, len(prices)):
			# Store previous buy (buy[i-1])
			prev_buy = buy
			# New buy = maximum of [prev_buy (no buy), prev_sell-prices[i] (buy)]
			buy = max(prev_buy, prev_sell - prices[i])
			# Store previous sell (sell[i-1])
			prev_sell = sell
			# New sell = maximum of [prev_sell (no sell), prices[i] + prev_buy (buy[i-2])]
			# This is where cooldown is incorporated	
			sell = max(prev_sell, prices[i] + prev_buy)
		return sell
