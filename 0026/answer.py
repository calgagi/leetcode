class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        hashmap = defaultdict(int)
        i = 0
        while i < len(nums):
            if hashmap[nums[i]] != 0:
                nums.pop(i)
            else:
                hashmap[nums[i]] = 1
                i += 1
        return len(nums)

        
