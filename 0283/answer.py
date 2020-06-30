class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        num_zeros = 0
        i = 0
        while i < len(nums)-num_zeros:
            if nums[i] == 0:
                num_zeros += 1
                nums.append(nums.pop(i))
            else:
                i += 1
