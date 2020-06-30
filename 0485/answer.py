class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_ones = 0
        streak = 0
        for i in nums:
            if i == 1:
                streak += 1
            elif i == 0:
                max_ones = max(streak, max_ones)
                streak = 0
        return max(streak, max_ones)
