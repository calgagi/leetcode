class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [0] + [float('inf')]*amount
        
        for i in range(1, len(dp)):
            for c in coins:
                if i - c >= 0:
                    dp[i] = min(dp[i], dp[i-c]+1)
                    
        if dp[amount] == float('inf'):
            return -1
        return dp[amount]
                    
        
