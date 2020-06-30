class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        for num in findNums:
            temp = 0
            idx = nums.index(num)
            for j in range(idx+1, len(nums)):
                if nums[j] > num:
                    res.append(nums[j])
                    temp += 1
                    break
            if temp == 0:
                res.append(-1)
        return res
                
