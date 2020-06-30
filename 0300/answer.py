class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [1]*len(nums)
        if len(nums) == 0:
            return 0
        for i in range(1, len(nums)):
            for x in range(0, i):
                if nums[i] > nums[x]:
                    dp[i] = max(dp[x]+1, dp[i])
        return max(dp)
            
