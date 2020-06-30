class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # O(n) space and O(n) runtime
        from collections import defaultdict
        seen = defaultdict(int)
        for i in nums:
            seen[i] = 1
        rList = []
        for i in range(1, len(nums)+1):
            if seen[i] == 0:
                rList.append(i)

        return rList
