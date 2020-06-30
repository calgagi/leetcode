class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        maj = len(nums)/2
        seen = defaultdict(int)
        for i in nums:
            seen[i] += 1
            if seen[i] > maj:
                return i
