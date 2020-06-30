class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        seen = {}
        for i in nums:
            if i in seen:
                return True
            seen[i] = 1
        return False
