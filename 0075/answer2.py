class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        seen = collections.defaultdict(int)
        for i in nums:
            seen[i] += 1
        
        x = 0
        for i in range(len(nums)):
            while x < 3 and seen[x] == 0:
                x += 1
            nums[i] = x
            seen[x] -= 1
