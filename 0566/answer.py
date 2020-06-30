class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if r*c != len(nums[0])*len(nums):
            return nums
        oned = [i for j in nums for i in j]
        m = []
        pos = 0
        for x in range(r):
            temp = []
            for i in range(c):
                temp.append(oned[pos])
                pos += 1
            m.append(temp)
        return m
