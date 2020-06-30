class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        self.r = 0
        self.backtrack(nums, S, 0, 0)
        return self.r
        
    def backtrack(self, nums: List[int], S: int, curr: int, index: int) -> int:
        if len(nums) == index:
            if S == curr:
                self.r += 1
            return
        self.backtrack(nums, S, curr+nums[index], index+1)
        self.backtrack(nums, S, curr-nums[index], index+1)

