class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) <= 2:
            return max(nums)
        
        r = [nums[0], nums[1], nums[0]+nums[2]]
        if len(nums) == 3:
            return max(r)
        for i in range(3, len(nums)):
            r.append(max(r[i-1], r[i-3] + nums[i], r[i-2] + nums[i]))
        
        return r[-1]
