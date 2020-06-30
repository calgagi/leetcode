class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        finalSum = 0
        for i, c in enumerate(nums):
            if i % 2 == 0:
                finalSum += c
        return finalSum
